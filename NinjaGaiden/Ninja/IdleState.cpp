#include "IdleState.h"
#include "Ninja.h"

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
	//Tiếng kiếm kêu
	if (this->gameObject->GetID() == GAME_OBJ_ID_NINJA)
		GameSound::GetInstance()->Play(IDSound::SWORD);
	gameObject->SetState(gameObject->GetAttackingState());
}
void IdleState::Walk()
{
	gameObject->SetSpeedX(gameObject->GetDefaultWalkSpeed() * (gameObject->IsLeft() ? -1 : 1));

	gameObject->SetState(gameObject->GetWalkingState());
}
void IdleState::Climb()
{

}
void IdleState::Throw()
{
	gameObject->SetState(gameObject->GetThrowingState());
}
void IdleState::Jump()
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
void IdleState::Crouch()
{
	gameObject->SetIsCrouching(true);
	gameObject->SetState(gameObject->GetCrouchingState());
}
void IdleState::Hurt()
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
void IdleState::Update(DWORD dt)
{
	State::Update(dt);
	if (gameObject->GetID() == GAME_OBJ_ID_THUG ||
		gameObject->GetID() == GAME_OBJ_ID_YELLOW_BIRD ||
		gameObject->GetID() == GAME_OBJ_ID_ZOMBIE ||
		gameObject->GetID() == GAME_OBJ_ID_COUGAR ||
		gameObject->GetID() == GAME_OBJ_ID_BAT ||
		gameObject->GetID() == GAME_OBJ_ID_RUNNER ||
		gameObject->GetID() == GAME_OBJ_ID_MACHINE_GUNNER ||
		gameObject->GetID() == GAME_OBJ_ID_CANNON_SHOOTER)
	{
		int id = gameObject->GetID();
		//Di chuyển theo hướng ninja
		Ninja * ninja = Ninja::GetInstance();
		if ((ninja->GetPositionX() - gameObject->GetPositionX()) > 10)
			gameObject->SetIsLeft(false);
		else if ((ninja->GetPositionX() - gameObject->GetPositionX()) < -10)
			gameObject->SetIsLeft(true);

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
