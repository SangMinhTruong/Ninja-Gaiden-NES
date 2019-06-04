#include "MachineGunner.h"

//MachineGunner * MachineGunner::__instance = NULL;
MachineGunner::MachineGunner(int x, int y)
{
	LoadResources();

	this->id = GAME_OBJ_ID_MACHINE_GUNNER;
	this->x = x;
	this->y = y;
	this->initX = x;
	this->initY = y;
	this->width = MACHINE_GUNNER_SPRITE_WIDTH;
	this->height = MACHINE_GUNNER_SPRITE_HEIGHT;
	this->attackTimer = 0;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = MACHINE_GUNNER_SPRITE_WIDTH;
	collider.height = MACHINE_GUNNER_SPRITE_HEIGHT;
}
//MachineGunner * MachineGunner::GetInstance()
//{
//	if (__instance == NULL)
//		__instance = new MachineGunner();
//	return __instance;
//}
void MachineGunner::LoadResources()
{
	// Idle
	Animation * anim = new Animation(150);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % MACHINE_GUNNER_TEXTURE_COLUMNS) * MACHINE_GUNNER_SPRITE_WIDTH;
		rect.right = rect.left + MACHINE_GUNNER_SPRITE_WIDTH;
		rect.top = (i / MACHINE_GUNNER_TEXTURE_COLUMNS) * MACHINE_GUNNER_SPRITE_HEIGHT;
		rect.bottom = rect.top + MACHINE_GUNNER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(MACHINE_GUNNER_TEXTURE_LOCATION, rect, MACHINE_GUNNER_TEXTURE_TRANS_COLOR);

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
			rect.left = (i % MACHINE_GUNNER_TEXTURE_COLUMNS) * MACHINE_GUNNER_SPRITE_WIDTH;
			rect.right = rect.left + MACHINE_GUNNER_SPRITE_WIDTH;
			rect.top = (i / MACHINE_GUNNER_TEXTURE_COLUMNS) * MACHINE_GUNNER_SPRITE_HEIGHT;
			rect.bottom = rect.top + MACHINE_GUNNER_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(MACHINE_GUNNER_TEXTURE_LOCATION, rect, MACHINE_GUNNER_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
	}
	animations.push_back(anim);
	// Standing Shoot
	anim = new Animation(50);
	for (int i = 2; i < 4; i++)
	{
		RECT rect;
		rect.left = (i % MACHINE_GUNNER_TEXTURE_COLUMNS) * MACHINE_GUNNER_SPRITE_WIDTH;
		rect.right = rect.left + MACHINE_GUNNER_SPRITE_WIDTH;
		rect.top = (i / MACHINE_GUNNER_TEXTURE_COLUMNS) * MACHINE_GUNNER_SPRITE_HEIGHT;
		rect.bottom = rect.top + MACHINE_GUNNER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(MACHINE_GUNNER_TEXTURE_LOCATION, rect, MACHINE_GUNNER_TEXTURE_TRANS_COLOR);

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
int MachineGunner::GetIdleAnimID()
{
	return MACHINE_GUNNER_ANI_IDLE;
}
int MachineGunner::GetWalkAnimID()
{
	return MACHINE_GUNNER_ANI_WALKING;
}
int MachineGunner::GetJumpAnimID()
{
	return MACHINE_GUNNER_ANI_JUMPING;
}
int MachineGunner::GetCrouchAnimID()
{
	return MACHINE_GUNNER_ANI_CROUCHING;
}
int MachineGunner::GetStandAttackAnimID()
{
	return MACHINE_GUNNER_ANI_STANDING_ATTACKING;
}
int MachineGunner::GetCrouchAttackAnimID()
{
	return MACHINE_GUNNER_ANI_CROUCHING_ATTACKING;
}
int MachineGunner::GetThrowingAttackAnimID()
{
	return MACHINE_GUNNER_ANI_THROWING;
}
int MachineGunner::GetDyingAnimID()
{
	return MACHINE_GUNNER_ANI_DYING;
}


void MachineGunner::CreateThrownWeapon()
{
	
	MachineGunnerBullet * bullet;
	bullet = new MachineGunnerBullet(this->x, this->y, this->isLeft);
	bullet->SetMachineGunner(this);

	this->bullets.push_back(bullet);

	GameSound::GetInstance()->Play(IDSound::MACHINE_GUNNER);
}
void MachineGunner::RemoveBullet(MachineGunnerBullet * bullet)
{
	auto it = find(bullets.begin(), bullets.end(), bullet);
	delete *it;
	if (it != bullets.end())
		bullets.erase(it);
}
#include "Debug.h"
//Hàm cập nhật
void MachineGunner::Update(DWORD dt)
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
void MachineGunner::Render()
{
	state->Render();

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Render();
	}
}