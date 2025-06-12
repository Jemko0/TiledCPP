#include "TPlaceable.h"

TPlaceable::TPlaceable()
{
	transform = AddComponent<TTransformComponent>();
}

void TPlaceable::Update(float deltaTime)
{
	Super::Update(deltaTime);
	ReceiveTick();
}