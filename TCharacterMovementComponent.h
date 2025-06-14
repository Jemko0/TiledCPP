#pragma once

#include "TMovementComponent.h"

FORWARD_DECLARE(TCharacter);

enum EMovementMode {
	MOVE_NONE,
	MOVE_WALKING,
	MOVE_FALLING,
	MOVE_MAX
};

/// <summary>
/// TCharacterMovementComponent handles collisions with the tilemap and the character before moving
/// </summary>
class ENGINE_API TCharacterMovementComponent : public TMovementComponent
{
private:
	typedef TMovementComponent Super;
	TCharacter* m_CharacterOwner;
	EMovementMode m_MovementMode;

public:
	virtual void PerformMove(float deltaTime) override;

	void SetCharacter(TCharacter* newChar);
};