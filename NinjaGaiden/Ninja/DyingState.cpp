#include "DyingState.h"
#include "Explosion.h"
#include "Ninja.h"
DyingState::DyingState(StateGameObject * gameObject)
{
	this->gameObject = gameObject;
	if (gameObject->GetID() != GAME_OBJ_ID_NINJA)
		gameObject->GetAnimationsList()[gameObject->GetDyingAnimID()]->Reset();
}
void DyingState::Idle()
{

}
void DyingState::Attack()
{

}
void DyingState::Walk()
{

}
void DyingState::Climb()
{

}
void DyingState::Throw()
{

}
void DyingState::Jump()
{

}
void DyingState::Crouch()
{

}
void DyingState::Hurt()
{

}
void DyingState::Update(DWORD dt)
{

}
void DyingState::Render()
{
	State::Render();
	if (gameObject->GetDyingAnimID() != -1)
	{
		SpriteData spriteData;
		spriteData.width = gameObject->GetWidth();
		spriteData.height = gameObject->GetHeight();
		spriteData.x = gameObject->GetPositionX() + gameObject->GetWidth() / 2 - EXPLOSION_SPRITE_WIDTH / 2;
		spriteData.y = gameObject->GetPositionY() - gameObject->GetHeight() / 2 + EXPLOSION_SPRITE_HEIGHT / 2;
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = gameObject->IsLeft();
		spriteData.isFlipped = false;

		gameObject->GetAnimationsList()[gameObject->GetDyingAnimID()]->Render(spriteData);

		if (gameObject->GetAnimationsList()[gameObject->GetDyingAnimID()]->IsDone())
		{
			gameObject->GetAnimationsList()[gameObject->GetDyingAnimID()]->Reset();
			gameObject->Reset();
			gameObject->SetActive(false);
			gameObject->SetState(gameObject->GetIdleState());
		}
	}

}