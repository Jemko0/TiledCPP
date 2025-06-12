#pragma once

#include "Engine.h"
#include "TComponent.h"
#include "raylib.h"

class ENGINE_API TSpriteRendererComponent : TComponent
{
public:
	typedef TComponent Super;
	Texture2D texture;
	Color tint = WHITE;

	void Initialize() override;

	void SetTint(const Color& newTint);
	void SetTexture(const Texture2D& tex);
	bool CanRender() override;
	void Render() override;
};