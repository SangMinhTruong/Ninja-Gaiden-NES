#include "AttackingState.h"

AttackingState::AttackingState(StateGameObject * gameObject)
{
	this->gameObject = gameObject;
	//gameObject->GetAnimationsList()[NINJA_ANI_STANDING_ATTACKING]->Reset();
	//gameObject->GetAnimationsList()[NINJA_ANI_CROUCHING_ATTACKING]->Reset();
}
void AttackingState::Idle()
{

}
void AttackingState::Attack()
{

}
void AttackingState::Walk()
{
	
}
void AttackingState::Throw()
{

}
void AttackingState::Jump()
{

}
void AttackingState::Crouch()
{

}
void AttackingState::Update(DWORD dt)
{
	State::Update(dt);

}
void AttackingState::Render()
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
		spriteData.isFlipped = gameObject->IsFlipped();

		if (gameObject->IsCrouching())
		{
			gameObject->GetAnimationsList()[gameObject->GetCrouchAttackAnimID()]->Render(spriteData);
			//gameObject->GetWhip()->Render(spriteData);

			if (gameObject->GetAnimationsList()[gameObject->GetCrouchAttackAnimID()]->IsDone())
			{
				gameObject->GetAnimationsList()[gameObject->GetCrouchAttackAnimID()]->Reset();
				gameObject->SetIsCrouching(true);
				gameObject->SetState(gameObject->GetCrouchingState());
			}
		}
		else
		{
			gameObject->GetAnimationsList()[gameObject->GetStandAttackAnimID()]->Render(spriteData);
			//gameObject->GetWhip()->Render(spriteData);

			if (gameObject->GetAnimationsList()[gameObject->GetStandAttackAnimID()]->IsDone())
			{
				gameObject->GetAnimationsList()[gameObject->GetStandAttackAnimID()]->Reset();
				gameObject->SetState(gameObject->GetIdleState());
			}
		}
	}
}
