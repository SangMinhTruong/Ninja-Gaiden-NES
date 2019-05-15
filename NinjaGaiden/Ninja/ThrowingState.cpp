#include "ThrowingState.h"

ThrowingState::ThrowingState(StateGameObject * gameObject)
{
	this->gameObject = gameObject;
	//gameObject->GetAnimationsList()[NINJA_ANI_STANDING_ATTACKING]->Reset();
	//gameObject->GetAnimationsList()[NINJA_ANI_CROUCHING_ATTACKING]->Reset();
}
void ThrowingState::Idle()
{

}
void ThrowingState::Attack()
{

}
void ThrowingState::Walk()
{

}
void ThrowingState::Throw()
{

}
void ThrowingState::Jump()
{

}
void ThrowingState::Crouch()
{

}
void ThrowingState::Update(DWORD dt)
{
	State::Update(dt);

}
void ThrowingState::Render()
{
	State::Render();

	if (gameObject->GetStandAttackAnimID() != -1 ||
		gameObject->GetCrouchAttackAnimID() != -1)
	{

		SpriteData spriteData;
		spriteData.width = gameObject->GetWidth();
		spriteData.height = gameObject->GetHeight();
		spriteData.x = gameObject->GetPositionX();
		spriteData.y = gameObject->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = gameObject->IsLeft();

		if (gameObject->IsCrouching())
		{
			gameObject->GetAnimationsList()[gameObject->GetCrouchAttackAnimID()]->Render(spriteData);

			if (gameObject->GetAnimationsList()[gameObject->GetCrouchAttackAnimID()]->IsDone())
			{
				//gameObject->CreateThrownWeapon();
				gameObject->GetAnimationsList()[gameObject->GetCrouchAttackAnimID()]->Reset();
				gameObject->SetIsCrouching(true);
				gameObject->SetState(gameObject->GetCrouchingState());
			}
		}
		else
		{
			gameObject->GetAnimationsList()[gameObject->GetStandAttackAnimID()]->Render(spriteData);

			if (gameObject->GetAnimationsList()[gameObject->GetStandAttackAnimID()]->IsDone())
			{
				//gameObject->CreateThrownWeapon();
				gameObject->GetAnimationsList()[gameObject->GetStandAttackAnimID()]->Reset();
				gameObject->SetState(gameObject->GetIdleState());
			}
		}
	}
}
