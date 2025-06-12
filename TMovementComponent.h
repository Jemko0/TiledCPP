#pragma once

#include "Engine.h"
#include "TComponent.h"
#include "TTransformComponent.h"

class ENGINE_API TMovementComponent : TComponent
{
	TTransformComponent* m_ParentTransform;
	Vector2 Velocity;
	Vector2 Bounds;

	virtual void Initialize() override;

public:
	void SetPosition(Vector2 newPos);

	Vector2 GetPosition();
	Vector2 GetVelocity();
	Vector2 GetBounds();
};