#include "ThrowingState.h"
#include "Game.h"
ThrowingState::ThrowingState(StateGameObject * gameObject)
{
	this->gameObject = gameObject;
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
void ThrowingState::Climb()
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
void ThrowingState::Hurt()
{
	//Ninja dính vũ khí
	if (this->gameObject == GAME_OBJ_ID_NINJA)
		GameSound::GetInstance()->Play(IDSound::NINJA_HURT);
	float vx = gameObject->GetDefaultWalkSpeed() * (gameObject->IsLeft() ? 1 : -1) / 1.25f;
	float vy = gameObject->GetDefautJumpSpeed() / 1.5f;

	gameObject->SetSpeedY(vx);
	gameObject->SetSpeedY(vy);
	if (gameObject->GetID() == GAME_OBJ_ID_NINJA)
	{
		gameObject->SetIsInvincible(true);
		gameObject->ResetInvincibleTimer();
	}

	gameObject->GetAnimationsList()[gameObject->GetThrowingAttackAnimID()]->Reset();
	gameObject->SetIsGrounded(false);
	gameObject->SetIsHurt(true);
	gameObject->SetState(gameObject->GetHurtState());
}
void ThrowingState::Update(DWORD dt)
{
	State::Update(dt);
}
void ThrowingState::Render()
{
	State::Render();

	if (gameObject->GetThrowingAttackAnimID() != -1)
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

		gameObject->GetAnimationsList()[gameObject->GetThrowingAttackAnimID()]->Render(spriteData);

		if (gameObject->GetAnimationsList()[gameObject->GetThrowingAttackAnimID()]->IsDone())
		{
			if (gameObject->GetID() == GAME_OBJ_ID_NINJA)
			{
				GameInformation gameInfo = Game::GetInstance()->GetInformation();
				if (gameInfo.SpiritPoint > 0 &&
					gameInfo.currentItem != -1)
				{
					gameObject->CreateThrownWeapon();
					Game::GetInstance()->LoseSpirit(5);
				}
			}
			else
				gameObject->CreateThrownWeapon();
			gameObject->GetAnimationsList()[gameObject->GetThrowingAttackAnimID()]->Reset();
				
			if (gameObject->IsGrounded())
			{
				gameObject->SetSpeedX(0);
				gameObject->SetState(gameObject->GetIdleState());
			}
			else
				gameObject->SetState(gameObject->GetJumpingState());
		}
	}
}
