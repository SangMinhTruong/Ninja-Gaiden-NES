#include "JumpingState.h"


JumpingState::JumpingState(StateGameObject * gameObject)
{
	this->gameObject = gameObject;
}
void JumpingState::Idle()
{
	
}
void JumpingState::Attack()
{
	//Tiếng kiếm kêu
	if (this->gameObject->GetID() == GAME_OBJ_ID_NINJA)
		GameSound::GetInstance()->Play(IDSound::SWORD);
	gameObject->SetState(gameObject->GetAttackingState());
}
void JumpingState::Walk()
{
	if ((!gameObject->IsLeft() && gameObject->IsJumpingLeft()) ||
		(gameObject->IsLeft() && !gameObject->IsJumpingLeft()))
		gameObject->SetSpeedX(gameObject->GetDefaultWalkSpeed() * (gameObject->IsJumpingLeft() ? -1 : 1) * 0.5f);
	else
		gameObject->SetSpeedX(gameObject->GetDefaultWalkSpeed() * (gameObject->IsJumpingLeft() ? -1 : 1));
}
void JumpingState::Climb()
{
	gameObject->SetSpeedX(0);
	gameObject->SetSpeedY(0);
	gameObject->SetState(gameObject->GetClimbingState());
}
void JumpingState::Throw()
{
	gameObject->SetState(gameObject->GetThrowingState());
}
void JumpingState::Jump()
{

}
void JumpingState::Crouch()
{

}
void JumpingState::Hurt()
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
void JumpingState::Update(DWORD dt)
{
	State::Update(dt);
	
	if (gameObject->IsGrounded())
	{
		gameObject->SetSpeedX(0);
		gameObject->SetSpeedY(0);

		gameObject->SetState(gameObject->GetIdleState());
	}
}
void JumpingState::Render()
{
	State::Render();

	if (gameObject->GetJumpAnimID() != -1)
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

		gameObject->GetAnimationsList()[gameObject->GetJumpAnimID()]->Render(spriteData);
	}
}