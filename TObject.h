#pragma once

#include "Engine.h"
#include "TComponent.h"
#include "TObjectBase.h"
#include "TWorld.h"

FORWARD_DECLARE(TScene);

class ENGINE_API TObject : TObjectBase
{

private:
    std::string m_Name;
    std::vector<std::unique_ptr<TComponent>> m_Components;
    TScene* m_ParentScene = nullptr;

public: 
    typedef TObject Super;
    TObject() = default;

    bool bPendingDestroy = false;

    void SetScene(TScene& scene);
    virtual void BeginDestroy();
    virtual void Cleanup();

    template<typename T>
    T* GetComponent() const
    {
        for (auto& component : m_Components)
        {
            // Use .get() to access the raw pointer from unique_ptr
            if (T* comp = dynamic_cast<T*>(component.get()))
            {
                return comp;
            }
        }
        return nullptr;
    }

    template<typename T>
    T* AddComponent()
    {
        // Create unique_ptr directly
        auto newComponent = std::make_unique<T>();
        T* rawPtr = newComponent.get(); // Get raw pointer before moving

        newComponent->SetOwner(this);
        m_Components.push_back(std::move(newComponent));

        return rawPtr;
    }
    
    std::vector<std::unique_ptr<TComponent>>* GetComponents();

    template<typename T, typename... Args>
    static T* CreateObject(Args&&... args)
    {
        static_assert(std::is_base_of_v<TObject, T>, "T must derive from TObject");
        auto obj = std::make_unique<T>(std::forward<Args>(args)...);

        static_cast<TObject*>(obj.get())->Initialize();

        T* rawPtr = obj.get();
        TWorld::Instance().GetScene()->GetObjects().push_back(std::move(obj));

        return rawPtr;
    }

    virtual void Update(float deltaTime);
};