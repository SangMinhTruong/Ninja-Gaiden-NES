#include "Boss.h"
//Boss * Boss::__instance = NULL;
Boss::Boss(int x, int y)
{
	LoadResources();

	this->id = GAME_OBJ_ID_BOSS;
	this->x = x;
	this->y = y;
	this->initX = x;
	this->initY = y;
	this->width = BOSS_SPRITE_WIDTH;
	this->height = BOSS_SPRITE_HEIGHT;
	this->isLeft = true;
	this->isJumpingLeft = true;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = BOSS_SPRITE_WIDTH;
	collider.height = BOSS_SPRITE_HEIGHT;
}
//Boss * Boss::GetInstance()
//{
//	if (__instance == NULL)
//		__instance = new Boss();
//	return __instance;
//}
void Boss::LoadResources()
{
	// Idle
	Animation * anim = new Animation(150);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % BOSS_TEXTURE_COLUMNS) * BOSS_SPRITE_WIDTH;
		rect.right = rect.left + BOSS_SPRITE_WIDTH;
		rect.top = (i / BOSS_TEXTURE_COLUMNS) * BOSS_SPRITE_HEIGHT;
		rect.bottom = rect.top + BOSS_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(BOSS_TEXTURE_LOCATION, rect, BOSS_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// Walking
	anim = new Animation(300);
	for (int i = 1; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % BOSS_TEXTURE_COLUMNS) * BOSS_SPRITE_WIDTH;
		rect.right = rect.left + BOSS_SPRITE_WIDTH;
		rect.top = (i / BOSS_TEXTURE_COLUMNS) * BOSS_SPRITE_HEIGHT;
		rect.bottom = rect.top + BOSS_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(BOSS_TEXTURE_LOCATION, rect, BOSS_TEXTURE_TRANS_COLOR);

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
int Boss::GetIdleAnimID()
{
	return BOSS_ANI_IDLE;
}
int Boss::GetWalkAnimID()
{
	return BOSS_ANI_WALKING;
}
int Boss::GetJumpAnimID()
{
	return BOSS_ANI_JUMPING;
}
int Boss::GetCrouchAnimID()
{
	return BOSS_ANI_CROUCHING;
}
int Boss::GetStandAttackAnimID()
{
	return BOSS_ANI_STANDING_ATTACKING;
}
int Boss::GetCrouchAttackAnimID()
{
	return BOSS_ANI_CROUCHING_ATTACKING;
}
int Boss::GetDyingAnimID()
{
	return BOSS_ANI_DYING;
}


void Boss::CreateThrownWeapon(int x, int y)
{
	BossBullet * bullet;
	bullet = new BossBullet(x, y, this->isLeft);
	bullet->SetBoss(this);

	this->bullets.push_back(bullet);
}
void Boss::RemoveBullet(BossBullet * bullet)
{
	auto it = find(bullets.begin(), bullets.end(), bullet);
	delete *it;
	if (it != bullets.end())
		bullets.erase(it);
}
//Hàm cập nhật
void Boss::Update(DWORD dt)
{
	state->Update(dt); 
	
	if (this->isInvincible)
	{
		this->AddInvincibleTimer(dt);
		if (this->invincibleTimer > 300)
		{
			this->SetIsInvincible(false);
			this->SetIsHurt(false);
		}
	}
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
}
//Hàm render
void Boss::Render()
{
	state->Render();
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Render();
	}
	Explosion::Render();
}