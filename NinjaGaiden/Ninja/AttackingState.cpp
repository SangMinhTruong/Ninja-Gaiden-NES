#include "AttackingState.h"
#include "Ninja.h"
AttackingState::AttackingState(StateGameObject * gameObject)
{
	this->gameObject = gameObject;
	if (gameObject->GetID() == GAME_OBJ_ID_NINJA)
		if (Ninja * ninja = dynamic_cast<Ninja *>(gameObject))
		{
			ninja->GetAnimationsList()[NINJA_ANI_STANDING_ATTACKING]->Reset();
			ninja->GetAnimationsList()[NINJA_ANI_CROUCHING_ATTACKING]->Reset();
		}
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
void AttackingState::Climb()
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
void AttackingState::Hurt()
{
	float vx = gameObject->GetDefaultWalkSpeed() * (gameObject->IsLeft() ? 1 : -1) / 1.25f;
	float vy = gameObject->GetDefautJumpSpeed() / 1.5f;

	gameObject->SetSpeedY(vx);
	gameObject->SetSpeedY(vy);

	if (gameObject->GetID() == GAME_OBJ_ID_NINJA)
	{
		gameObject->SetIsInvincible(true);
		gameObject->ResetInvincibleTimer();
	}

	gameObject->SetIsGrounded(false);
	gameObject->SetIsHurt(true);
	gameObject->SetState(gameObject->GetHurtState());
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
			//Render vũ khí
			if (gameObject->GetID() == GAME_OBJ_ID_NINJA)
				if (Ninja * ninja = dynamic_cast<Ninja * >(gameObject))
				{
					//ninja->GetWhip()->Render();
				}

			if (gameObject->GetAnimationsList()[gameObject->GetCrouchAttackAnimID()]->IsDone())
			{
				if (gameObject->GetID() == GAME_OBJ_ID_NINJA)
					if (Ninja * ninja = dynamic_cast<Ninja *>(gameObject))
					{
						//ninja->GetWhip()->ResetAnim();
					}

				gameObject->GetAnimationsList()[gameObject->GetCrouchAttackAnimID()]->Reset();
				gameObject->SetIsCrouching(true);
				gameObject->SetState(gameObject->GetCrouchingState());
			}
		}
		else
		{
			gameObject->GetAnimationsList()[gameObject->GetStandAttackAnimID()]->Render(spriteData);
			//Render vũ khí
			if (gameObject->GetID() == GAME_OBJ_ID_NINJA)
				if (Ninja * ninja = dynamic_cast<Ninja *>(gameObject))
				{
					//ninja->GetWhip()->Render();
				}

			if (gameObject->GetAnimationsList()[gameObject->GetStandAttackAnimID()]->IsDone())
			{
				if (gameObject->GetID() == GAME_OBJ_ID_NINJA)
					if (Ninja * ninja = dynamic_cast<Ninja *>(gameObject))
					{
						//ninja->GetWhip()->ResetAnim();
					}

				gameObject->GetAnimationsList()[gameObject->GetStandAttackAnimID()]->Reset();

				if (gameObject->IsGrounded())
					gameObject->SetState(gameObject->GetIdleState());
				else
					gameObject->SetState(gameObject->GetJumpingState());
			}
		}
	}
}
