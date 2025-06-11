#pragma once

#include "Engine.h"
#include "TComponent.h"
#include "raylib.h"

class ENGINE_API TSpriteRendererComponent : TComponent
{
public:
	typedef TComponent Super;
	Texture2D texture;

	void Update(float deltaTime) override;
	void Initialize() override;

	void Render() override;
	
};