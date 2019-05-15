#include "Ninja.h"

vector<Subweapon *> Ninja::subweapons = vector<Subweapon *>();
Ninja * Ninja::__instance = NULL;
Ninja::Ninja()
{
	LoadResources(); 

	this->id = GAME_OBJ_ID_NINJA;
	this->x = 100;
	this->y = 100;
	this->width = NINJA_SPRITE_WIDTH;
	this->height = NINJA_SPRITE_HEIGHT;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = NINJA_SPRITE_WIDTH;
	collider.height = NINJA_SPRITE_HEIGHT;
}
Ninja * Ninja::GetInstance()
{
	if (__instance == NULL)
		__instance = new Ninja();
	return __instance;
}
void Ninja::LoadResources()
{
	// 0
	Animation * anim = new Animation(50);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
		rect.right = rect.left + NINJA_SPRITE_WIDTH;
		rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
		rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// 1
	anim = new Animation(50);
	for (int i = 1; i < 4; i++)
	{
		RECT rect;
		rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
		rect.right = rect.left + NINJA_SPRITE_WIDTH;
		rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
		rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// 2
	anim = new Animation(50);
	for (int i = 10; i < 15; i++)
	{
		if (i == 10)
		{
			RECT rect;
			rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
			rect.right = rect.left + NINJA_SPRITE_WIDTH;
			rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
			rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		else if (i == 11 || i == 13)
		{
			RECT rect;
			rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
			rect.right = rect.left + NINJA_SPRITE_WIDTH * 2;
			rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
			rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
	}
	animations.push_back(anim);

	// 3
	anim = new Animation(50);
	for (int i = 25; i < 30; i++)
	{
		if (i == 25)
		{
			RECT rect;
			rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
			rect.right = rect.left + NINJA_SPRITE_WIDTH;
			rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
			rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		else if (i == 26 || i == 28)
		{
			RECT rect;
			rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
			rect.right = rect.left + NINJA_SPRITE_WIDTH * 2;
			rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
			rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
	}
	animations.push_back(anim);

	// 4
	anim = new Animation(50);
	for (int i = 6; i < 10; i++)
	{
		RECT rect;
		rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
		rect.right = rect.left + NINJA_SPRITE_WIDTH;
		rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
		rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// 5
	anim = new Animation(50);
	for (int i = 24; i < 25; i++)
	{
		RECT rect;
		rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
		rect.right = rect.left + NINJA_SPRITE_WIDTH;
		rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
		rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);
}
void Ninja::CreateThrownWeapon()
{
	Subweapon * subweapon;
	switch (curSubweapon)
	{
	case SUBWEAPON_KNIFE:
		subweapon = new Knife();
		if (isLeft) 
			subweapon->TurnLeft();
		else 
			subweapon->TurnRight();
		subweapon->SetThrownPosition(this->x, this->y, isCrouching);
		this->subweapons.push_back(subweapon);
		break;
	}
}

int Ninja::GetIdleAnimID()
{
	return NINJA_ANI_IDLE;
}
int Ninja::GetWalkAnimID()
{
	return NINJA_ANI_WALKING;
}
int Ninja::GetJumpAnimID()
{
	return NINJA_ANI_JUMPING;
}
int Ninja::GetCrouchAnimID()
{
	return NINJA_ANI_CROUCHING;
}
int Ninja::GetStandAttackAnimID()
{
	return NINJA_ANI_STANDING_ATTACKING;
}
int Ninja::GetCrouchAttackAnimID()
{
	return NINJA_ANI_CROUCHING_ATTACKING;
}


//Hàm cập nhật
void Ninja::Update(DWORD dt)
{
	state->Update(dt);
}
//Hàm render
void Ninja::Render()
{
	state->Render();
}