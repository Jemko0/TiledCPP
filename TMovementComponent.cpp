#include "TMovementComponent.h"
#include "TObject.h"

void TMovementComponent::Initialize()
{
	m_ParentTransform = m_Owner->GetComponent<TTransformComponent>();
}

void TMovementComponent::SetPosition(Vector2 newPos)
{
	m_ParentTransform->position = newPos;
}

Vector2 TMovementComponent::GetPosition()
{
	return m_ParentTransform->position;
}

Vector2 TMovementComponent::GetVelocity()
{
	return Velocity;
}

Vector2 TMovementComponent::GetBounds()
{
	return Bounds;
}
