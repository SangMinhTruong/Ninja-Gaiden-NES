#include "HurtState.h"
#include "Explosion.h"
#include "Ninja.h"
HurtState::HurtState(StateGameObject * gameObject)
{
	this->gameObject = gameObject;
	if (gameObject->GetID() != GAME_OBJ_ID_NINJA)
		gameObject->GetAnimationsList()[gameObject->GetDyingAnimID()]->Reset();
}
void HurtState::Idle()
{

}
void HurtState::Attack()
{

}
void HurtState::Walk()
{

}
void HurtState::Climb()
{

}
void HurtState::Throw()
{

}
void HurtState::Jump()
{

}
void HurtState::Crouch()
{

}
void HurtState::Hurt()
{

}
void HurtState::Update(DWORD dt)
{
	State::Update(dt); 
}
void HurtState::Render()
{
	State::Render();
	if (gameObject->GetHurtAnimID() != -1)
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

		gameObject->GetAnimationsList()[gameObject->GetHurtAnimID()]->Render(spriteData);

		if (gameObject->IsGrounded())
		{
			gameObject->GetAnimationsList()[gameObject->GetHurtAnimID()]->Reset();
			gameObject->SetIsHurt(false);
			gameObject->SetSpeedX(0);
			gameObject->SetState(gameObject->GetIdleState());
		}
	}

}