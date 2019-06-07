#include "Explosion.h"

bool Explosion::tickExplosion = false;
vector<Explosion*> Explosion::explosions = vector<Explosion*>();
Explosion::Explosion(int x, int y)
{
	LoadResources();

	this->id = GAME_OBJ_ID_EXPLOSION;
	this->x = x;
	this->y = y;
	this->initX = 0;
	this->initY = 0;
	this->width = EXPLOSION_BOSS_SPRITE_WIDTH;
	this->height = EXPLOSION_BOSS_SPRITE_HEIGHT;
	this->isActive = true;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = EXPLOSION_BOSS_SPRITE_WIDTH;
	collider.height = EXPLOSION_BOSS_SPRITE_HEIGHT;
}

void Explosion::LoadResources()
{
	// 0
	animation = new Animation(50);
	if (tickExplosion)
		for (int i = 0; i < 2; i++)
		{
			RECT rect;
			rect.left = (i % EXPLOSION_BOSS_TEXTURE_COLUMNS) * EXPLOSION_BOSS_SPRITE_WIDTH;
			rect.right = rect.left + EXPLOSION_BOSS_SPRITE_WIDTH;
			rect.top = (i / EXPLOSION_BOSS_TEXTURE_COLUMNS) * EXPLOSION_BOSS_SPRITE_HEIGHT;
			rect.bottom = rect.top + EXPLOSION_BOSS_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(EXPLOSION_BOSS_TEXTURE_LOCATION, rect, EXPLOSION_BOSS_TEXTURE_TRANS_COLOR);

			animation->AddFrame(sprite);
		}
	else
		for (int i = 0; i < 2; i++)
		{
			RECT rect;
			rect.left = (i % EXPLOSION_BOSS_TEXTURE_COLUMNS) * EXPLOSION_BOSS_SPRITE_WIDTH;
			rect.right = rect.left + EXPLOSION_BOSS_SPRITE_WIDTH;
			rect.top = (i / EXPLOSION_BOSS_TEXTURE_COLUMNS) * EXPLOSION_BOSS_SPRITE_HEIGHT;
			rect.bottom = rect.top + EXPLOSION_BOSS_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(EXPLOSION_BOSS_TEXTURE_LOCATION, rect, EXPLOSION_BOSS_TEXTURE_TRANS_COLOR);

			animation->AddFrame(sprite);
		}

}
void  Explosion::CreateExplosions(int x, int y) {
	x = x - 5;
	y = y - 5;
	if (explosions.size() == 0) {
		for (int i = 0; i < 4; i++) {
			explosions.push_back(new Explosion(x + (i % 2) * 15, y - (i / 2) * 15));
		}
	}
}

//Hàm cập nhật
void Explosion::Update(DWORD dt)
{

}



//Hàm render
void Explosion::UnitRender()
{
	SpriteData spriteData;
	spriteData.x = x;
	spriteData.y = y;
	spriteData.width = width;
	spriteData.height = height;
	spriteData.angle = 0;
	spriteData.scale = 1;
	spriteData.isLeft = false;
	this->animation->Render(spriteData);
}


void Explosion::Render() {
	for (int i = 0; i < explosions.size(); i++) {
		explosions.at(i)->UnitRender();
	}
}