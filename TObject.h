#pragma once

#include "Engine.h"
#include "TComponent.h"
#include "TObjectBase.h"
#include "TWorld.h"

FORWARD_DECLARE(TScene);

class ENGINE_API TObject : TObjectBase
{
public:
    TObject() = default;

    void SetScene(TScene& scene)
    {
        m_ParentScene = &scene;
    }

    template<typename T, typename... Args>
    T* AddComponent(Args&&... args)
    {
        static_assert(std::is_base_of_v<TComponent, T>);
        auto component = std::make_unique<T>(std::forward<Args>(args)...);
        component.SetOwner(this);
        T* ptr = component.get();
        m_Components.push_back(std::move(component));
        return ptr;
    }

    template<typename T>
    T* GetComponent() const
    {
        for (auto& comp : m_Components)
        {
            if (auto* result = dynamic_cast<T*>(comp.get()))
            {
                return result;
            }
        }
        return nullptr;
    }
    
    std::vector<std::unique_ptr<TComponent>>* GetComponents()
    {
        return &m_Components;
    }


    template<typename T, typename... Args>
    static T* CreateObject(Args&&... args)
    {
        static_assert(std::is_base_of_v<TObject, T>, "T must derive from TObject");
        auto obj = std::make_unique<T>(std::forward<Args>(args)...);
        T* rawPtr = obj.get();
        TWorld::Instance().GetObjects().push_back(std::move(obj));

        return rawPtr;
    }

    virtual void Update(float deltaTime);

private:
    std::string m_Name;
    std::vector<std::unique_ptr<TComponent>> m_Components;
    TScene* m_ParentScene;
};