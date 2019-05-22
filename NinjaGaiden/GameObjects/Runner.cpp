#include "Runner.h"

//Runner * Runner::__instance = NULL;
Runner::Runner(int x, int y)
{
	LoadResources();

	this->id = GAME_OBJ_ID_RUNNER;
	this->x = x;
	this->y = y;
	this->initX = x;
	this->initY = y;
	this->width = RUNNER_SPRITE_WIDTH;
	this->height = RUNNER_SPRITE_HEIGHT;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = RUNNER_SPRITE_WIDTH;
	collider.height = RUNNER_SPRITE_HEIGHT;
}
//Runner * Runner::GetInstance()
//{
//	if (__instance == NULL)
//		__instance = new Runner();
//	return __instance;
//}
void Runner::LoadResources()
{
	// Idle
	Animation * anim = new Animation(150);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % RUNNER_TEXTURE_COLUMNS) * RUNNER_SPRITE_WIDTH;
		rect.right = rect.left + RUNNER_SPRITE_WIDTH;
		rect.top = (i / RUNNER_TEXTURE_COLUMNS) * RUNNER_SPRITE_HEIGHT;
		rect.bottom = rect.top + RUNNER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(RUNNER_TEXTURE_LOCATION, rect, RUNNER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// Walking
	anim = new Animation(200);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % RUNNER_TEXTURE_COLUMNS) * RUNNER_SPRITE_WIDTH;
		rect.right = rect.left + RUNNER_SPRITE_WIDTH;
		rect.top = (i / RUNNER_TEXTURE_COLUMNS) * RUNNER_SPRITE_HEIGHT;
		rect.bottom = rect.top + RUNNER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(RUNNER_TEXTURE_LOCATION, rect, RUNNER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);
	// Dying
	anim = new Animation(50);
	for (int i = 0; i < 3; i++)
	{
		RECT rect;
		rect.left = (i % EXPLOSION_TEXTURE_COLUMNS) * EXPLOSION_SPRITE_WIDTH;
		rect.right = rect.left + EXPLOSION_SPRITE_WIDTH;
		rect.top = (i / EXPLOSION_TEXTURE_COLUMNS) * EXPLOSION_SPRITE_HEIGHT;
		rect.bottom = rect.top + EXPLOSION_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(EXPLOSION_TEXTURE_LOCATION, rect, EXPLOSION_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);
}
int Runner::GetIdleAnimID()
{
	return RUNNER_ANI_IDLE;
}
int Runner::GetWalkAnimID()
{
	return RUNNER_ANI_WALKING;
}
int Runner::GetJumpAnimID()
{
	return RUNNER_ANI_JUMPING;
}
int Runner::GetCrouchAnimID()
{
	return RUNNER_ANI_CROUCHING;
}
int Runner::GetStandAttackAnimID()
{
	return RUNNER_ANI_STANDING_ATTACKING;
}
int Runner::GetCrouchAttackAnimID()
{
	return RUNNER_ANI_CROUCHING_ATTACKING;
}
int Runner::GetDyingAnimID()
{
	return RUNNER_ANI_DYING;
}


//Hàm cập nhật
void Runner::Update(DWORD dt)
{
	state->Update(dt);
}
//Hàm render
void Runner::Render()
{
	state->Render();
}