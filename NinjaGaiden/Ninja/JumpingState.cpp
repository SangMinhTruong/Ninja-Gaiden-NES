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
	gameObject->SetState(gameObject->GetAttackingState());
}
void JumpingState::Walk()
{

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
	float vx = gameObject->GetDefaultWalkSpeed() * (gameObject->IsLeft() ? 1 : -1);
	float vy = gameObject->GetDefautJumpSpeed() / 1.25f;

	gameObject->SetSpeedY(vx);
	gameObject->SetSpeedY(vy);

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