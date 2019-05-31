#include "Ninja.h"

vector<Subweapon *> Ninja::subweapons = vector<Subweapon *>();
Ninja * Ninja::__instance = NULL;
Ninja::Ninja()
{
	LoadResources(); 

	this->whip = new Whip();

	this->id = GAME_OBJ_ID_NINJA;
	this->x = 1980;
	this->y = 100;
	this->initX = 32;
	this->initY = 100;
	this->width = NINJA_SPRITE_WIDTH;
	this->height = NINJA_SPRITE_HEIGHT;
	this->isActive = true;
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
	// Idle
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

	// Walking
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

	
	// Standing Attack
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

	// Crouching Attack
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

	// Jumping
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

	// Crouching
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
	// Hurt
	anim = new Animation(50);
	for (int i = 6; i < 7; i++)
	{
		RECT rect;
		rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
		rect.right = rect.left + NINJA_SPRITE_WIDTH;
		rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
		rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	for (int i = 19; i < 20; i++)
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
	// Climbing
	anim = new Animation(150);
	for (int i = 4; i < 6; i++)
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
	case SUBWEAPON_SHURIKEN:

		subweapon = new Shuriken();
		if (isLeft)
			subweapon->TurnLeft();
		else
			subweapon->TurnRight();
		subweapon->SetThrownPosition(this->x, this->y, isCrouching);
		this->subweapons.push_back(subweapon);
		break;
	case SUBWEAPON_WINDMILLSHURIKEN:
		subweapon = new WindmillShuriken();
		if (isLeft)
			subweapon->TurnLeft();
		else
			subweapon->TurnRight();
		subweapon->SetThrownPosition(this->x, this->y, isCrouching);
		this->subweapons.push_back(subweapon);
		break;
	case SUBWEAPON_FIREWHEEL:
		vector<Subweapon*> fireWheels = FireWheel::Create(x, y, isLeft);
		this->subweapons.insert(subweapons.end(), fireWheels.begin(), fireWheels.end());
		break;
	}
}

bool Ninja::RemoveSubweapon(Subweapon * subweapon)
{
	if (subweapon->GetID() == GAME_OBJ_ID_WINDMILLSHURIKEN)
		if (!((WindmillShuriken *)(subweapon))->IsNinjaCollision())
			return false;
	for (std::vector<Subweapon*>::iterator it = subweapons.begin(); it != subweapons.end(); it++) {

		if (*it == subweapon) {

			subweapons.erase(it);
			return true;
		}
	}
	return false;
}
int Ninja::GetIdleAnimID()
{
	return NINJA_ANI_IDLE;
}
int Ninja::GetWalkAnimID()
{
	return NINJA_ANI_WALKING;
}
int Ninja::GetClimbAnimID()
{
	return NINJA_ANI_CLIMBING;
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
int Ninja::GetHurtAnimID()
{
	return NINJA_ANI_HURT;
}
int Ninja::GetDyingAnimID()
{
	return NINJA_ANI_DYING;
}

#include "Debug.h"
//Hàm cập nhật
void Ninja::Update(DWORD dt)
{
	state->Update(dt);

	//Cập nhật vũ khí
	this->GetWhip()->Update(dt);
	for (int i = 0; i < this->subweapons.size(); i++) {
		subweapons.at(i)->Update(dt);
	}

	if (this->isInvincible)
	{
		this->AddInvincibleTimer(dt);
		if (this->invincibleTimer > NINJA_INVINSIBLE_TIME)
		{
			this->SetIsInvincible(false);
			this->SetIsHurt(false);
		}
	}
}
//Hàm render
void Ninja::Render()
{
	state->Render();
	for (int i = 0; i < this->subweapons.size(); i++) {
		subweapons.at(i)->Render();
	}
}