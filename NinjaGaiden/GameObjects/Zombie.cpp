#include "Zombie.h"

//Zombie * Zombie::__instance = NULL;
Zombie::Zombie(int x, int y)
{
	LoadResources();

	this->id = GAME_OBJ_ID_ZOMBIE;
	this->x = x;
	this->y = y;
	this->initX = x;
	this->initY = y;
	this->width = ZOMBIE_SPRITE_WIDTH;
	this->height = ZOMBIE_SPRITE_HEIGHT;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = ZOMBIE_SPRITE_WIDTH;
	collider.height = ZOMBIE_SPRITE_HEIGHT;
}
//Zombie * Zombie::GetInstance()
//{
//	if (__instance == NULL)
//		__instance = new Zombie();
//	return __instance;
//}
void Zombie::LoadResources()
{
	// Idle
	Animation * anim = new Animation(150);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % ZOMBIE_TEXTURE_COLUMNS) * ZOMBIE_SPRITE_WIDTH;
		rect.right = rect.left + ZOMBIE_SPRITE_WIDTH;
		rect.top = (i / ZOMBIE_TEXTURE_COLUMNS) * ZOMBIE_SPRITE_HEIGHT;
		rect.bottom = rect.top + ZOMBIE_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(ZOMBIE_TEXTURE_LOCATION, rect, ZOMBIE_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// Walking
	anim = new Animation(300);
	for (int i = 0; i < 2; i++)
	{
		if (i == 0 || i == 1)
		{
			RECT rect;
			rect.left = (i % ZOMBIE_TEXTURE_COLUMNS) * ZOMBIE_SPRITE_WIDTH;
			rect.right = rect.left + ZOMBIE_SPRITE_WIDTH;
			rect.top = (i / ZOMBIE_TEXTURE_COLUMNS) * ZOMBIE_SPRITE_HEIGHT;
			rect.bottom = rect.top + ZOMBIE_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ZOMBIE_TEXTURE_LOCATION, rect, ZOMBIE_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
	}
	animations.push_back(anim);
	// Standing Throw
	anim = new Animation(150);
	for (int i = 2; i < 3; i++)
	{
		RECT rect;
		rect.left = (i % ZOMBIE_TEXTURE_COLUMNS) * ZOMBIE_SPRITE_WIDTH;
		rect.right = rect.left + ZOMBIE_SPRITE_WIDTH;
		rect.top = (i / ZOMBIE_TEXTURE_COLUMNS) * ZOMBIE_SPRITE_HEIGHT;
		rect.bottom = rect.top + ZOMBIE_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(ZOMBIE_TEXTURE_LOCATION, rect, ZOMBIE_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % ZOMBIE_TEXTURE_COLUMNS) * ZOMBIE_SPRITE_WIDTH;
		rect.right = rect.left + ZOMBIE_SPRITE_WIDTH;
		rect.top = (i / ZOMBIE_TEXTURE_COLUMNS) * ZOMBIE_SPRITE_HEIGHT;
		rect.bottom = rect.top + ZOMBIE_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(ZOMBIE_TEXTURE_LOCATION, rect, ZOMBIE_TEXTURE_TRANS_COLOR);

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
int Zombie::GetIdleAnimID()
{
	return ZOMBIE_ANI_IDLE;
}
int Zombie::GetWalkAnimID()
{
	return ZOMBIE_ANI_WALKING;
}
int Zombie::GetJumpAnimID()
{
	return ZOMBIE_ANI_JUMPING;
}
int Zombie::GetCrouchAnimID()
{
	return ZOMBIE_ANI_CROUCHING;
}
int Zombie::GetStandAttackAnimID()
{
	return ZOMBIE_ANI_STANDING_ATTACKING;
}
int Zombie::GetCrouchAttackAnimID()
{
	return ZOMBIE_ANI_CROUCHING_ATTACKING;
}
int Zombie::GetThrowingAttackAnimID()
{
	return ZOMBIE_ANI_THROWING;
}
int Zombie::GetDyingAnimID()
{
	return ZOMBIE_ANI_DYING;
}


void Zombie::CreateThrownWeapon()
{
	ZombieBullet * bullet;
	bullet = new ZombieBullet(this->x, this->y, this->isLeft);
	bullet->SetZombie(this);

	this->bullets.push_back(bullet);
}
void Zombie::RemoveBullet(ZombieBullet * bullet)
{
	auto it = find(bullets.begin(), bullets.end(), bullet);
	delete *it;
	if (it != bullets.end())
		bullets.erase(it);
}
#include "Debug.h"
//Hàm cập nhật
void Zombie::Update(DWORD dt)
{
	state->Update(dt);

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Update(dt);
	}
	Viewport * viewport = Viewport::GetInstance();
	for (int i = 0; i < bullets.size(); i++)
	{
		RECT rect = viewport->GetRect();

		if (bullets[i]->GetPositionX() > rect.right ||
			bullets[i]->GetPositionX() < rect.left ||
			bullets[i]->GetPositionY() < rect.bottom)
				this->RemoveBullet(bullets[i]);
	}
	/*vector<Subweapon *> subweapons = gameObject->GetSubweapon();
	if (subweapons.size() > 0)
	{
		
	}*/
}
//Hàm render
void Zombie::Render()
{
	state->Render();

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Render();
	}
}