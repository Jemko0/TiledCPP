#include "Entity.h"

TEntity::TEntity()
{
	spriteRendererComp = AddComponent<TSpriteRendererComponent>();
	Texture2D* t = GEngine.GAssetManager->LoadTexture("debugTile", "Assets/Tiles/DebugTile.png");
	spriteRendererComp->SetTexture(*t);
}

void TEntity::Cleanup()
{
	Super::Cleanup();
	return;
}

void TEntity::ReceiveTick()
{
}
