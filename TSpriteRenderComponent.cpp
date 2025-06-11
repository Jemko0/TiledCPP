#include "TSpriteRendererComponent.h"
#include "TObject.h"

void TSpriteRendererComponent::Update(float deltaTime)
{
}

void TSpriteRendererComponent::Initialize()
{
}

void TSpriteRendererComponent::Render()
{
	DrawTexture(texture, m_Owner->GetComponent<TTransformComponent>());
}
