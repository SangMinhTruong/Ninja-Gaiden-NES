#include "BossBullet.h"
#include "Ninja.h"
#include "Boss.h"

BossBullet::BossBullet(int x, int y, bool isLeft)
{
	LoadResources();

	this->id = GAME_OBJ_ID_BOSS_BULLET;
	this->x = x;
	this->y = y;
	this->vx = BOSS_BULLET_SPEED_X * (isLeft ? -1 : 1);
	this->vy = BOSS_BULLET_SPEED_Y;
	this->initX = x;
	this->initY = y;
	this->width = BOSS_BULLET_SPRITE_WIDTH;
	this->height = BOSS_BULLET_SPRITE_HEIGHT;
	this->isLeft = isLeft;
	this->isActive = true;
	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = BOSS_BULLET_SPRITE_WIDTH;
	collider.height = BOSS_BULLET_SPRITE_HEIGHT;
}

void BossBullet::LoadResources()
{
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % BOSS_BULLET_TEXTURE_COLUMNS) * BOSS_BULLET_SPRITE_WIDTH;
		rect.right = rect.left + BOSS_BULLET_SPRITE_WIDTH;
		rect.top = (i / BOSS_BULLET_TEXTURE_COLUMNS) * BOSS_BULLET_SPRITE_HEIGHT;
		rect.bottom = rect.top + BOSS_BULLET_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(BOSS_BULLET_TEXTURE_LOCATION, rect, BOSS_BULLET_TEXTURE_TRANS_COLOR);

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

bool AABB(const Collider &c1, const Collider &c2);
//Hàm cập nhật
void BossBullet::Update(DWORD dt)
{
	if (this->isActive)
	{
		this->vy -= BOSS_BULLET_GRAVITY;
		this->x += this->vx * dt;
		this->y += this->vy * dt;

		Ninja * ninja = Ninja::GetInstance();

		this->UpdateObjectCollider();
		ninja->UpdateObjectCollider();

		if (Ninja::GetInstance()->IsAttacking())
		{
			Whip * sword = ninja->GetWhip();
			if (AABB(this->collider, sword->GetCollider()))
			{
				this->isActive = false;
				return;
			}
		}

		LPCOLLISIONEVENT e = ninja->SweptAABBEx(this);
		if (e->t >= 0 && e->t < 1.0f)
		{
			if (!ninja->IsHurt()) {
				GameSound::GetInstance()->Play(IDSound::NINJA_HURT);
				ninja->Hurt();
			}
		}
	}
}
//Hàm render
void BossBullet::Render()
{
	SpriteData spriteData;
	spriteData.width = BOSS_BULLET_SPRITE_WIDTH;
	spriteData.height = BOSS_BULLET_SPRITE_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;
	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = this->isLeft;

	if (isActive)
		this->animations[0]->Render(spriteData);
	else
	{

		this->animations[1]->Render(spriteData);
		if (this->animations[1]->IsDone())
			this->gunner->RemoveBullet(this);
	}
}
BossBullet::~BossBullet()
{

}
