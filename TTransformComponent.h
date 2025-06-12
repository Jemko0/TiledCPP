#pragma once

#include "Engine.h"
#include "TComponent.h"
#include "DataTypes.h"

class ENGINE_API TTransformComponent : TComponent
{
public:
	Vector2 position = {0.0f, 0.0f};
	float angle = 0.0f;
	float scale = 0.0f;
};