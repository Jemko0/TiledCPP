#pragma once

#include "Engine.h"
#include "TComponent.h"
#include "TObjectBase.h"

FORWARD_DECLARE(TScene);
FORWARD_DECLARE(TWorld);

class ENGINE_API TObject : TObjectBase
{

public: 
    typedef TObject Super;
    TObject() = default;

    bool bPendingDestroy = false;

    void SetScene(TScene& scene);
    virtual void BeginDestroy();
    virtual void Cleanup() = 0;

    template<typename T, typename... Args>
    T* AddComponent(Args&&... args);

    template<typename T>
    T* GetComponent() const;
    
    std::vector<std::unique_ptr<TComponent>>* GetComponents();

    template<typename T, typename... Args>
    static T* CreateObject(Args&&... args);

    virtual void Update(float deltaTime);

private:
    std::string m_Name;
    std::vector<std::unique_ptr<TComponent>> m_Components;
    TScene* m_ParentScene;
};