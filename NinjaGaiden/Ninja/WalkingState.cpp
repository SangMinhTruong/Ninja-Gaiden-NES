#include "WalkingState.h"

WalkingState::WalkingState(StateGameObject * gameObject)
{
	this->gameObject = gameObject;
}
void WalkingState::Idle()
{
	gameObject->SetSpeedX(0);

	gameObject->SetState(gameObject->GetIdleState());
}
void WalkingState::Attack()
{
	//Tiếng kiếm kêu
	if (this->gameObject->GetID() == GAME_OBJ_ID_NINJA)
		GameSound::GetInstance()->Play(IDSound::SWORD);
	gameObject->SetSpeedX(0);
	gameObject->SetState(gameObject->GetAttackingState());
}
void WalkingState::Walk()
{
	gameObject->SetSpeedX(gameObject->GetDefaultWalkSpeed() * (gameObject->IsLeft() ? -1 : 1));
}
void WalkingState::Climb()
{

}
void WalkingState::Throw()
{
	gameObject->SetSpeedX(0);
	gameObject->SetState(gameObject->GetThrowingState());
}
void WalkingState::Jump()
{
	//Là ninja thì nhảy phải kêu
	if (this->gameObject->GetID() == GAME_OBJ_ID_NINJA)
		GameSound::GetInstance()->Play(IDSound::NINJA_JUMP);
	if (gameObject->IsGrounded())
	{
		gameObject->SetIsGrounded(false);
		gameObject->SetSpeedY(gameObject->GetDefautJumpSpeed());
		gameObject->SetState(gameObject->GetJumpingState());
	}
}
void WalkingState::Crouch()
{
	gameObject->SetSpeedX(0);
	gameObject->SetIsCrouching(true);
	gameObject->SetState(gameObject->GetCrouchingState());
}
void WalkingState::Hurt()
{
	//Ninja dính vũ khí
	if (this->gameObject->GetID() == GAME_OBJ_ID_NINJA) 
		GameSound::GetInstance()->Play(IDSound::NINJA_HURT);
	float vx = gameObject->GetDefaultWalkSpeed() * (gameObject->IsLeft() ? 1 : -1) / 1.25f;
	float vy = gameObject->GetDefautJumpSpeed() / 1.5f;

	gameObject->SetSpeedX(vx);
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
void WalkingState::Update(DWORD dt)
{
	State::Update(dt);
}
void WalkingState::Render()
{
	State::Render();
	if (gameObject->GetWalkAnimID() != -1)
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

		gameObject->GetAnimationsList()[gameObject->GetWalkAnimID()]->Render(spriteData);
	}
}
