#include "TCharacterMovementComponent.h"
#include "TCharacter.h"

void TCharacterMovementComponent::PerformMove(float deltaTime)
{
	if (m_CharacterOwner)
	{
		TTileColliderComponent* colliderComp = m_CharacterOwner->GetTileColliderComponent();
		if (colliderComp)
		{
			colliderComp->Update(deltaTime);
		}
	}
	Super::PerformMove(deltaTime);
}

void TCharacterMovementComponent::SetCharacter(TCharacter* newChar)
{
	m_CharacterOwner = newChar;
}
