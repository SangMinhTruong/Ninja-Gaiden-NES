#include "CrouchingState.h"


CrouchingState::CrouchingState(StateGameObject * gameObject)
{
	this->gameObject = gameObject;
}
void CrouchingState::Idle()
{
	gameObject->SetIsCrouching(false);
	gameObject->SetState(gameObject->GetIdleState());
}
void CrouchingState::Attack()
{
	//Tiếng kiếm kêu
	if (this->gameObject->GetID() == GAME_OBJ_ID_NINJA)
		GameSound::GetInstance()->Play(IDSound::SWORD);
	gameObject->SetState(gameObject->GetAttackingState());
}
void CrouchingState::Walk()
{

}
void CrouchingState::Climb()
{

}
void CrouchingState::Throw()
{
	gameObject->SetState(gameObject->GetThrowingState());
}
void CrouchingState::Jump()
{

}
void CrouchingState::Crouch()
{

}
void CrouchingState::Hurt()
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
void CrouchingState::Update(DWORD dt)
{
	State::Update(dt);
}
void CrouchingState::Render()
{
	State::Render();

	if (gameObject->GetCrouchAnimID() != -1)
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

		gameObject->GetAnimationsList()[gameObject->GetCrouchAnimID()]->Render(spriteData);
	}
}