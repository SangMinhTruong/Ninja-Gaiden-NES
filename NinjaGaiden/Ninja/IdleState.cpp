#include "IdleState.h"


IdleState::IdleState(StateGameObject * gameObject)
{
	this->gameObject = gameObject;
}
void IdleState::Idle()
{
	//gameObject->SetState(gameObject->GetIdleState());
}
void IdleState::Attack()
{
	gameObject->SetState(gameObject->GetAttackingState());
}
void IdleState::Walk()
{
	gameObject->SetSpeedX(gameObject->GetDefaultWalkSpeed() * (gameObject->IsLeft() ? -1 : 1));

	gameObject->SetState(gameObject->GetWalkingState());
}
void IdleState::Throw()
{
	gameObject->SetState(gameObject->GetThrowingState());
}
void IdleState::Jump()
{
	if (gameObject->IsGrounded())
	{
		gameObject->SetIsGrounded(false);
		gameObject->SetSpeedY(gameObject->GetDefautJumpSpeed());
		gameObject->SetState(gameObject->GetJumpingState());
	}
}
void IdleState::Crouch()
{
	gameObject->SetIsCrouching(true);
	gameObject->SetState(gameObject->GetCrouchingState());
}
void IdleState::Update(DWORD dt)
{
	State::Update(dt);
	if (gameObject->GetID() == GAME_OBJ_ID_THUG)
	{
		gameObject->Walk();
	}
}
void IdleState::Render()
{
	State::Render();

	if (gameObject->GetIdleAnimID() != -1)
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

		gameObject->GetAnimationsList()[gameObject->GetIdleAnimID()]->Render(spriteData);
	}
}
