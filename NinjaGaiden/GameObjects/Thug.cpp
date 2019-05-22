#include "Thug.h"

//Thug * Thug::__instance = NULL;
Thug::Thug(int x, int y)
{
	LoadResources();

	this->id = GAME_OBJ_ID_THUG;
	this->x = x;
	this->y = y;
	this->initX = x;
	this->initY = y;
	this->width = THUG_SPRITE_WIDTH;
	this->height = THUG_SPRITE_HEIGHT;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = THUG_SPRITE_WIDTH;
	collider.height = THUG_SPRITE_HEIGHT;
}
//Thug * Thug::GetInstance()
//{
//	if (__instance == NULL)
//		__instance = new Thug();
//	return __instance;
//}
void Thug::LoadResources()
{
	// Idle
	Animation * anim = new Animation(150);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % THUG_TEXTURE_COLUMNS) * THUG_SPRITE_WIDTH;
		rect.right = rect.left + THUG_SPRITE_WIDTH;
		rect.top = (i / THUG_TEXTURE_COLUMNS) * THUG_SPRITE_HEIGHT;
		rect.bottom = rect.top + THUG_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(THUG_TEXTURE_LOCATION, rect, THUG_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// Walking
	anim = new Animation(300);
	for (int i = 0; i < 3; i++)
	{
		if (i == 0 || i == 1)
		{
			RECT rect;
			rect.left = (i % THUG_TEXTURE_COLUMNS) * THUG_SPRITE_WIDTH;
			rect.right = rect.left + THUG_SPRITE_WIDTH;
			rect.top = (i / THUG_TEXTURE_COLUMNS) * THUG_SPRITE_HEIGHT;
			rect.bottom = rect.top + THUG_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(THUG_TEXTURE_LOCATION, rect, THUG_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (i == 0 || i == 2)
		{
			RECT rect;
			rect.left = (i % THUG_TEXTURE_COLUMNS) * THUG_SPRITE_WIDTH;
			rect.right = rect.left + THUG_SPRITE_WIDTH;
			rect.top = (i / THUG_TEXTURE_COLUMNS) * THUG_SPRITE_HEIGHT;
			rect.bottom = rect.top + THUG_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(THUG_TEXTURE_LOCATION, rect, THUG_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
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
int Thug::GetIdleAnimID()
{
	return THUG_ANI_IDLE;
}
int Thug::GetWalkAnimID()
{
	return THUG_ANI_WALKING;
}
int Thug::GetJumpAnimID()
{
	return THUG_ANI_JUMPING;
}
int Thug::GetCrouchAnimID()
{
	return THUG_ANI_CROUCHING;
}
int Thug::GetStandAttackAnimID()
{
	return THUG_ANI_STANDING_ATTACKING;
}
int Thug::GetCrouchAttackAnimID()
{
	return THUG_ANI_CROUCHING_ATTACKING;
}
int Thug::GetDyingAnimID()
{
	return THUG_ANI_DYING;
}


//Hàm cập nhật
void Thug::Update(DWORD dt)
{
	state->Update(dt);
}
//Hàm render
void Thug::Render()
{
	state->Render();
}