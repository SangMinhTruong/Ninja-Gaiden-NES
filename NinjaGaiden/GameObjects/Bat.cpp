#include "Bat.h"

//Bat * Bat::__instance = NULL;
Bat::Bat(int x, int y)
{
	LoadResources();

	this->id = GAME_OBJ_ID_BAT;
	this->x = x;
	this->y = y;
	this->initX = x;
	this->initY = y;
	this->width = BAT_SPRITE_WIDTH;
	this->height = BAT_SPRITE_HEIGHT;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = BAT_SPRITE_WIDTH;
	collider.height = BAT_SPRITE_HEIGHT;
}
//Bat * Bat::GetInstance()
//{
//	if (__instance == NULL)
//		__instance = new Bat();
//	return __instance;
//}
void Bat::LoadResources()
{
	// Idle
	Animation * anim = new Animation(50);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % BAT_TEXTURE_COLUMNS) * BAT_SPRITE_WIDTH;
		rect.right = rect.left + BAT_SPRITE_WIDTH;
		rect.top = (i / BAT_TEXTURE_COLUMNS) * BAT_SPRITE_HEIGHT;
		rect.bottom = rect.top + BAT_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(BAT_TEXTURE_LOCATION, rect, BAT_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// Flying
	anim = new Animation(100);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % BAT_TEXTURE_COLUMNS) * BAT_SPRITE_WIDTH;
		rect.right = rect.left + BAT_SPRITE_WIDTH;
		rect.top = (i / BAT_TEXTURE_COLUMNS) * BAT_SPRITE_HEIGHT;
		rect.bottom = rect.top + BAT_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(BAT_TEXTURE_LOCATION, rect, BAT_TEXTURE_TRANS_COLOR);

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
int Bat::GetIdleAnimID()
{
	return BAT_ANI_IDLE;
}
int Bat::GetWalkAnimID()
{
	return BAT_ANI_WALKING;
}
int Bat::GetJumpAnimID()
{
	return BAT_ANI_JUMPING;
}
int Bat::GetCrouchAnimID()
{
	return BAT_ANI_CROUCHING;
}
int Bat::GetStandAttackAnimID()
{
	return BAT_ANI_STANDING_ATTACKING;
}
int Bat::GetCrouchAttackAnimID()
{
	return BAT_ANI_CROUCHING_ATTACKING;
}
int Bat::GetDyingAnimID()
{
	return BAT_ANI_DYING;
}


//Hàm cập nhật
void Bat::Update(DWORD dt)
{
	state->Update(dt);
}
//Hàm render
void Bat::Render()
{
	state->Render();
}