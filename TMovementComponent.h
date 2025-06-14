#pragma once

#include "Engine.h"
#include "TComponent.h"
#include "TTransformComponent.h"

class ENGINE_API TMovementComponent : public TComponent
{
protected:
	TTransformComponent* m_ParentTransform;
	Vector2 m_Velocity;
	Vector2 m_Bounds;

	virtual void Initialize() override;
	virtual void PerformMove(float deltaTime);

public:
	void SetPosition(Vector2 newPos);

	Vector2 GetPosition() const;
	Vector2 GetVelocity() const;
	Vector2 GetBounds() const;
	virtual void Update(float deltaTime) override;
};