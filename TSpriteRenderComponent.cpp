#include "TSpriteRendererComponent.h"
#include "TObject.h"
#include "TTransformComponent.h"

void TSpriteRendererComponent::Initialize()
{
}

void TSpriteRendererComponent::SetTint(const Color& newTint)
{
	tint = newTint;
}

void TSpriteRendererComponent::SetTexture(const Texture2D& tex)
{
	texture = tex;
}

bool TSpriteRendererComponent::CanRender()
{
	return true;
}

void TSpriteRendererComponent::Render()
{
	TTransformComponent* transform = m_Owner->GetComponent<TTransformComponent>();
	DrawTextureEx(texture, transform->position, transform->angle, transform->scale, tint);
}