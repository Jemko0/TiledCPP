#include "TTransformComponent.h"

void TTransformComponent::Initialize()
{
	position = { 0, 0 };
	angle = 0;
	scale = 1;
	return;
}

void TTransformComponent::Update(float deltaTime)
{
	return;
}

void TTransformComponent::Render()
{
	return;
}

bool TTransformComponent::CanRender()
{
	return false;
}
