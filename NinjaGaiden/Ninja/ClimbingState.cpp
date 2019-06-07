#include "ClimbingState.h"

ClimbingState::ClimbingState(StateGameObject * gameObject)
{
	this->gameObject = gameObject;
}
void ClimbingState::Idle()
{
	gameObject->SetSpeedY(0);
}
void ClimbingState::Attack()
{

}
void ClimbingState::Walk()
{

}
void ClimbingState::Climb()
{
	if (gameObject->IsClimbing())
	{
		if (gameObject->GetPositionY() >= gameObject->GetUpperClimbingLimit() &&
			gameObject->IsUp())
			gameObject->SetSpeedY(0);
		else
			gameObject->SetSpeedY(gameObject->GetDefaultClimbingSpeed() * (gameObject->IsUp() ? 1 : -1));
	}
}
void ClimbingState::Throw()
{

}
void ClimbingState::Jump()
{
	//Là ninja thì nhảy phải kêu
	if (this->gameObject->GetID() == GAME_OBJ_ID_NINJA)
		GameSound::GetInstance()->Play(IDSound::NINJA_JUMP);
	if (gameObject->IsClimbing() || gameObject->IsSticking())
	{
		gameObject->SetIsClimbing(false);
		gameObject->SetIsSticking(false);
		gameObject->SetIsGrounded(false);

		gameObject->SetSpeedY(gameObject->GetDefautJumpSpeed() / 2.0f);
		gameObject->SetState(gameObject->GetJumpingState());
	}
}
void ClimbingState::Crouch()
{

}
void ClimbingState::Hurt()
{
	 
	float vx = gameObject->GetDefaultWalkSpeed() * (gameObject->IsLeft() ? 1 : -1) / 1.25f;
	float vy = gameObject->GetDefautJumpSpeed() / 1.5f;

	gameObject->SetSpeedX(vx);
	gameObject->SetSpeedY(vy);
	if (gameObject->GetID() == GAME_OBJ_ID_NINJA)
	{
		gameObject->SetIsInvincible(true);
		gameObject->ResetInvincibleTimer();
	}

	gameObject->SetIsClimbing(false);
	gameObject->SetIsSticking(false);
	gameObject->SetIsGrounded(false);

	gameObject->SetIsHurt(true);

	gameObject->SetState(gameObject->GetHurtState());
}
void ClimbingState::Update(DWORD dt)
{
	gameObject->SetSpeedY(gameObject->GetSpeedY() + NINJA_GRAVITY);
	State::Update(dt);
}
void ClimbingState::Render()
{
	State::Render();
	if (gameObject->GetClimbAnimID() != -1)
	{
		SpriteData spriteData;
		spriteData.width = gameObject->GetWidth();
		spriteData.height = gameObject->GetHeight();
		spriteData.x = gameObject->GetPositionX() + (gameObject->IsLeft() ? -7 : 7);
		spriteData.y = gameObject->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = gameObject->IsLeft();
		spriteData.isFlipped = gameObject->IsFlipped();

		if (gameObject->GetSpeedY() == 0)
			gameObject->GetAnimationsList()[gameObject->GetClimbAnimID()]->Reset();
		gameObject->GetAnimationsList()[gameObject->GetClimbAnimID()]->Render(spriteData);
	}
}
