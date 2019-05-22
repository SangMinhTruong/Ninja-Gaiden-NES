#include "Cougar.h"

//Cougar * Cougar::__instance = NULL;
Cougar::Cougar(int x, int y)
{
	LoadResources();

	this->id = GAME_OBJ_ID_COUGAR;
	this->x = x;
	this->y = y;
	this->initX = x;
	this->initY = y;
	this->width = COUGAR_SPRITE_WIDTH;
	this->height = COUGAR_SPRITE_HEIGHT;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = COUGAR_SPRITE_WIDTH;
	collider.height = COUGAR_SPRITE_HEIGHT;
}
//Cougar * Cougar::GetInstance()
//{
//	if (__instance == NULL)
//		__instance = new Cougar();
//	return __instance;
//}
void Cougar::LoadResources()
{
	// Idle
	Animation * anim = new Animation(150);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % COUGAR_TEXTURE_COLUMNS) * COUGAR_SPRITE_WIDTH;
		rect.right = rect.left + COUGAR_SPRITE_WIDTH;
		rect.top = (i / COUGAR_TEXTURE_COLUMNS) * COUGAR_SPRITE_HEIGHT;
		rect.bottom = rect.top + COUGAR_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(COUGAR_TEXTURE_LOCATION, rect, COUGAR_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// Walking
	anim = new Animation(200);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % COUGAR_TEXTURE_COLUMNS) * COUGAR_SPRITE_WIDTH;
		rect.right = rect.left + COUGAR_SPRITE_WIDTH;
		rect.top = (i / COUGAR_TEXTURE_COLUMNS) * COUGAR_SPRITE_HEIGHT;
		rect.bottom = rect.top + COUGAR_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(COUGAR_TEXTURE_LOCATION, rect, COUGAR_TEXTURE_TRANS_COLOR);

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
int Cougar::GetIdleAnimID()
{
	return COUGAR_ANI_IDLE;
}
int Cougar::GetWalkAnimID()
{
	return COUGAR_ANI_WALKING;
}
int Cougar::GetJumpAnimID()
{
	return COUGAR_ANI_JUMPING;
}
int Cougar::GetCrouchAnimID()
{
	return COUGAR_ANI_CROUCHING;
}
int Cougar::GetStandAttackAnimID()
{
	return COUGAR_ANI_STANDING_ATTACKING;
}
int Cougar::GetCrouchAttackAnimID()
{
	return COUGAR_ANI_CROUCHING_ATTACKING;
}
int Cougar::GetDyingAnimID()
{
	return COUGAR_ANI_DYING;
}


//Hàm cập nhật
void Cougar::Update(DWORD dt)
{
	state->Update(dt);
}
//Hàm render
void Cougar::Render()
{
	state->Render();
}