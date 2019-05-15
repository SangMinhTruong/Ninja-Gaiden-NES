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
	gameObject->SetState(gameObject->GetAttackingState());
}
void CrouchingState::Walk()
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
		spriteData.width = NINJA_SPRITE_WIDTH;
		spriteData.height = NINJA_SPRITE_HEIGHT;
		spriteData.x = gameObject->GetPositionX();
		spriteData.y = gameObject->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = gameObject->IsLeft();
		spriteData.isFlipped = gameObject->IsFlipped();

		gameObject->GetAnimationsList()[gameObject->GetCrouchAnimID()]->Render(spriteData);
	}
}