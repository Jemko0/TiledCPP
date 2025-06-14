#include "Entity.h"

TEntity::TEntity()
{
	spriteRendererComp = AddComponent<TSpriteRendererComponent>();
	Texture2D t = LoadTexture("../Assets/Tiles/debugTile.png");
	spriteRendererComp->SetTexture(t);
}

void TEntity::Cleanup()
{
	Super::Cleanup();
	return;
}

void TEntity::ReceiveTick()
{
}

void TEntity::Update(float deltaTime)
{
	transform->position.x += 1.0;
	std::cout << transform->position.x << std::endl;
}
