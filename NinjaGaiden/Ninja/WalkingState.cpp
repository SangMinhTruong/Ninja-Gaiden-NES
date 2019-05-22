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
	gameObject->SetSpeedX(0);
	gameObject->SetState(gameObject->GetAttackingState());
}
void WalkingState::Walk()
{
	gameObject->SetSpeedX(gameObject->GetDefaultWalkSpeed() * (gameObject->IsLeft() ? -1 : 1));
}
void WalkingState::Throw()
{
	gameObject->SetSpeedX(0);
	gameObject->SetState(gameObject->GetThrowingState());
}
void WalkingState::Jump()
{
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
		spriteData.width = NINJA_SPRITE_WIDTH;
		spriteData.height = NINJA_SPRITE_HEIGHT;
		spriteData.x = gameObject->GetPositionX();
		spriteData.y = gameObject->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = gameObject->IsLeft();
		spriteData.isFlipped = gameObject->IsFlipped();

		gameObject->GetAnimationsList()[gameObject->GetWalkAnimID()]->Render(spriteData);
	}
}
