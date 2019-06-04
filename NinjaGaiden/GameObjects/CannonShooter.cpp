#include "CannonShooter.h"

//CannonShooter * CannonShooter::__instance = NULL;
CannonShooter::CannonShooter(int x, int y)
{
	LoadResources();

	this->id = GAME_OBJ_ID_CANNON_SHOOTER;
	this->x = x;
	this->y = y;
	this->initX = x;
	this->initY = y;
	this->width = CANNON_SHOOTER_SPRITE_WIDTH;
	this->height = CANNON_SHOOTER_SPRITE_HEIGHT;
	this->attackTimer = 0;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = CANNON_SHOOTER_SPRITE_WIDTH;
	collider.height = CANNON_SHOOTER_SPRITE_HEIGHT;
}
//CannonShooter * CannonShooter::GetInstance()
//{
//	if (__instance == NULL)
//		__instance = new CannonShooter();
//	return __instance;
//}
void CannonShooter::LoadResources()
{
	// Idle
	Animation * anim = new Animation(150);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % CANNON_SHOOTER_TEXTURE_COLUMNS) * CANNON_SHOOTER_SPRITE_WIDTH;
		rect.right = rect.left + CANNON_SHOOTER_SPRITE_WIDTH;
		rect.top = (i / CANNON_SHOOTER_TEXTURE_COLUMNS) * CANNON_SHOOTER_SPRITE_HEIGHT;
		rect.bottom = rect.top + CANNON_SHOOTER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(CANNON_SHOOTER_TEXTURE_LOCATION, rect, CANNON_SHOOTER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// Walking
	anim = new Animation(300);
	for (int i = 0; i < 1; i++)
	{
		if (i == 0 || i == 1)
		{
			RECT rect;
			rect.left = (i % CANNON_SHOOTER_TEXTURE_COLUMNS) * CANNON_SHOOTER_SPRITE_WIDTH;
			rect.right = rect.left + CANNON_SHOOTER_SPRITE_WIDTH;
			rect.top = (i / CANNON_SHOOTER_TEXTURE_COLUMNS) * CANNON_SHOOTER_SPRITE_HEIGHT;
			rect.bottom = rect.top + CANNON_SHOOTER_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(CANNON_SHOOTER_TEXTURE_LOCATION, rect, CANNON_SHOOTER_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
	}
	animations.push_back(anim);
	// Standing Shoot
	anim = new Animation(200);
	for (int i = 1; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % CANNON_SHOOTER_TEXTURE_COLUMNS) * CANNON_SHOOTER_SPRITE_WIDTH;
		rect.right = rect.left + CANNON_SHOOTER_SPRITE_WIDTH;
		rect.top = (i / CANNON_SHOOTER_TEXTURE_COLUMNS) * CANNON_SHOOTER_SPRITE_HEIGHT;
		rect.bottom = rect.top + CANNON_SHOOTER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(CANNON_SHOOTER_TEXTURE_LOCATION, rect, CANNON_SHOOTER_TEXTURE_TRANS_COLOR);

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
int CannonShooter::GetIdleAnimID()
{
	return CANNON_SHOOTER_ANI_IDLE;
}
int CannonShooter::GetWalkAnimID()
{
	return CANNON_SHOOTER_ANI_WALKING;
}
int CannonShooter::GetJumpAnimID()
{
	return CANNON_SHOOTER_ANI_JUMPING;
}
int CannonShooter::GetCrouchAnimID()
{
	return CANNON_SHOOTER_ANI_CROUCHING;
}
int CannonShooter::GetStandAttackAnimID()
{
	return CANNON_SHOOTER_ANI_STANDING_ATTACKING;
}
int CannonShooter::GetCrouchAttackAnimID()
{
	return CANNON_SHOOTER_ANI_CROUCHING_ATTACKING;
}
int CannonShooter::GetThrowingAttackAnimID()
{
	return CANNON_SHOOTER_ANI_THROWING;
}
int CannonShooter::GetDyingAnimID()
{
	return CANNON_SHOOTER_ANI_DYING;
}


void CannonShooter::CreateThrownWeapon()
{
	GameSound::GetInstance()->Play(IDSound::CANNONSHOOTER);
	CannonShooterBullet * bullet;
	bullet = new CannonShooterBullet(this->x, this->y, this->isLeft);
	bullet->SetCannonShooter(this);

	this->bullets.push_back(bullet);
}
void CannonShooter::RemoveBullet(CannonShooterBullet * bullet)
{
	auto it = find(bullets.begin(), bullets.end(), bullet);
	delete *it;
	if (it != bullets.end())
		bullets.erase(it);
}
#include "Debug.h"
//Hàm cập nhật
void CannonShooter::Update(DWORD dt)
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
void CannonShooter::Render()
{
	state->Render();

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Render();
	}
}