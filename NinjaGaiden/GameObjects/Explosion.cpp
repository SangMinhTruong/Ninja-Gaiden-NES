#include "Explosion.h"

Explosion * Explosion::__instance = NULL;
unordered_map<GameObject *, int> Explosion::explosionsList;
Explosion::Explosion()
{
	LoadResources();

	this->id = GAME_OBJ_ID_EXPLOSION;
	this->x = 0;
	this->y = 0;
	this->initX = 0;
	this->initY = 0;
	this->width = EXPLOSION_SPRITE_WIDTH;
	this->height = EXPLOSION_SPRITE_HEIGHT;
	this->isActive = true;
	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = EXPLOSION_SPRITE_WIDTH;
	collider.height = EXPLOSION_SPRITE_HEIGHT;
}

void Explosion::LoadResources()
{	
	// 0
	Animation * anim = new Animation(30);
	for (int i = 0; i < 2; i++)
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
Explosion * Explosion::GetInstance()
{
	if (__instance == NULL)
		__instance = new Explosion();
	return __instance;
}

void Explosion::AddExplosion(GameObject * gameObject)
{
	explosionsList.at(gameObject) = 0;
}
//Hàm cập nhật
void Explosion::Update(DWORD dt)
{

}
//Hàm render
void Explosion::Render(SpriteData spriteData)
{
	this->animations[0]->Render(spriteData);
}