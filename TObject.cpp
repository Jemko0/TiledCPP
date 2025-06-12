#include "TObject.h"
#include "TScene.h"
#include "TWorld.h"

void TObject::SetScene(TScene& scene)
{
	m_ParentScene = &scene;
}

void TObject::BeginDestroy()
{
	bPendingDestroy = true;
}

std::vector<std::unique_ptr<TComponent>>* TObject::GetComponents()
{
	return &m_Components;
}

/// <summary>
/// Handles updates, by default will update components
/// </summary>
/// <param name="deltaTime"></param>
void TObject::Update(float deltaTime)
{
	for (std::unique_ptr<TComponent>& c : m_Components)
	{
		c->Update(deltaTime);
		if (c->CanRender())
		{
			c->Render();
		}
	}
}

template<typename T, typename... Args>
static T* TObject::CreateObject(Args&&... args)
{
	static_assert(std::is_base_of_v<TObject, T>, "T must derive from TObject");
	auto obj = std::make_unique<T>(std::forward<Args>(args)...);

	static_cast<TObject*>(obj.get())->Initialize();

	T* rawPtr = obj.get();
	TWorld::Instance().GetScene()->GetObjects().push_back(std::move(obj));

	return rawPtr;
}

template<typename T, typename... Args>
T* TObject::AddComponent(Args&&... args)
{
	static_assert(std::is_base_of_v<TComponent, T>);
	auto component = std::make_unique<T>(std::forward<Args>(args)...);
	static_cast<TComponent*>(component.get())->SetOwner(this);
	T* ptr = component.get();
	m_Components.push_back(std::move(component));
	return ptr;
}

template<typename T>
T* TObject::GetComponent() const
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