#include "YellowBird.h"

//YellowBird * YellowBird::__instance = NULL;
YellowBird::YellowBird(int x, int y)
{
	LoadResources();

	this->id = GAME_OBJ_ID_YELLOW_BIRD;
	this->x = x;
	this->y = y;
	this->initX = x;
	this->initY = y;
	this->width = YELLOW_BIRD_SPRITE_WIDTH;
	this->height = YELLOW_BIRD_SPRITE_HEIGHT;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = YELLOW_BIRD_SPRITE_WIDTH;
	collider.height = YELLOW_BIRD_SPRITE_HEIGHT;
}
//YellowBird * YellowBird::GetInstance()
//{
//	if (__instance == NULL)
//		__instance = new YellowBird();
//	return __instance;
//}
void YellowBird::LoadResources()
{
	// Idle
	Animation * anim = new Animation(50);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % YELLOW_BIRD_TEXTURE_COLUMNS) * YELLOW_BIRD_SPRITE_WIDTH;
		rect.right = rect.left + YELLOW_BIRD_SPRITE_WIDTH;
		rect.top = (i / YELLOW_BIRD_TEXTURE_COLUMNS) * YELLOW_BIRD_SPRITE_HEIGHT;
		rect.bottom = rect.top + YELLOW_BIRD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(YELLOW_BIRD_TEXTURE_LOCATION, rect, YELLOW_BIRD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// Flying
	anim = new Animation(50);
	for (int i = 0; i < 2; i++)
	{
		if (i == 0 || i == 1)
		{
			RECT rect;
			rect.left = (i % YELLOW_BIRD_TEXTURE_COLUMNS) * YELLOW_BIRD_SPRITE_WIDTH;
			rect.right = rect.left + YELLOW_BIRD_SPRITE_WIDTH;
			rect.top = (i / YELLOW_BIRD_TEXTURE_COLUMNS) * YELLOW_BIRD_SPRITE_HEIGHT;
			rect.bottom = rect.top + YELLOW_BIRD_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(YELLOW_BIRD_TEXTURE_LOCATION, rect, YELLOW_BIRD_TEXTURE_TRANS_COLOR);

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
int YellowBird::GetIdleAnimID()
{
	return YELLOW_BIRD_ANI_IDLE;
}
int YellowBird::GetWalkAnimID()
{
	return YELLOW_BIRD_ANI_WALKING;
}
int YellowBird::GetJumpAnimID()
{
	return YELLOW_BIRD_ANI_JUMPING;
}
int YellowBird::GetCrouchAnimID()
{
	return YELLOW_BIRD_ANI_CROUCHING;
}
int YellowBird::GetStandAttackAnimID()
{
	return YELLOW_BIRD_ANI_STANDING_ATTACKING;
}
int YellowBird::GetCrouchAttackAnimID()
{
	return YELLOW_BIRD_ANI_CROUCHING_ATTACKING;
}
int YellowBird::GetDyingAnimID()
{
	return YELLOW_BIRD_ANI_DYING;
}


//Hàm cập nhật
void YellowBird::Update(DWORD dt)
{
	state->Update(dt);
}
//Hàm render
void YellowBird::Render()
{
	state->Render();
}