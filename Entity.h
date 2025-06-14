#pragma once

#include "Engine.h"
#include "TPlaceable.h"
#include "TSpriteRendererComponent.h"

class ENGINE_API TEntity : public TPlaceable
{
public:
	typedef TPlaceable Super;
	TSpriteRendererComponent* spriteRendererComp;

	TEntity();
	virtual void Cleanup() override;
	virtual void ReceiveTick() override;
	virtual void Update(float deltaTime) override;
};