#include "ItemDrop.h"
#include "Ninja.h"

ItemDrop::ItemDrop(int x, int y, int type)
{
	this->id = type;
	this->type = type;

	this->x = x;
	this->y = y;
	this->initX = x;
	this->initY = y;


	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;

	switch (type)
	{
	case GAME_OBJ_ID_BLUE_SPIRIT_POINT:
		this->width = ITEM_BLUE_SPIRIT_POINT_SPRITE_WIDTH;
		this->height = ITEM_BLUE_SPIRIT_POINT_SPRITE_HEIGHT;

		collider.width = ITEM_BLUE_SPIRIT_POINT_SPRITE_WIDTH;
		collider.height = ITEM_BLUE_SPIRIT_POINT_SPRITE_HEIGHT;
		break;
	case GAME_OBJ_ID_RED_SPIRIT_POINT:
		this->width = ITEM_RED_SPIRIT_POINT_SPRITE_WIDTH;
		this->height = ITEM_RED_SPIRIT_POINT_SPRITE_HEIGHT;

		collider.width = ITEM_RED_SPIRIT_POINT_SPRITE_WIDTH;
		collider.height = ITEM_RED_SPIRIT_POINT_SPRITE_HEIGHT;
		break;
	case GAME_OBJ_ID_BLUE_BONUS_DROP:
		this->width = ITEM_BLUE_BONUS_DROP_SPRITE_WIDTH;
		this->height = ITEM_BLUE_BONUS_DROP_SPRITE_HEIGHT;

		collider.width = ITEM_BLUE_BONUS_DROP_SPRITE_WIDTH;
		collider.height = ITEM_BLUE_BONUS_DROP_SPRITE_HEIGHT;
		break;
	case GAME_OBJ_ID_RED_BONUS_DROP:
		this->width = ITEM_RED_BONUS_DROP_SPRITE_WIDTH;
		this->height = ITEM_RED_BONUS_DROP_SPRITE_HEIGHT;

		collider.width = ITEM_RED_BONUS_DROP_SPRITE_WIDTH;
		collider.height = ITEM_RED_BONUS_DROP_SPRITE_HEIGHT;
		break;
	case GAME_OBJ_ID_FREEZE_DROP:
		this->width = ITEM_FREEZE_DROP_SPRITE_WIDTH;
		this->height = ITEM_FREEZE_DROP_SPRITE_HEIGHT;

		collider.width = ITEM_FREEZE_DROP_SPRITE_WIDTH;
		collider.height = ITEM_FREEZE_DROP_SPRITE_HEIGHT;
		break;
	case GAME_OBJ_ID_HEALTH_DROP:
		this->width = ITEM_HEALTH_DROP_SPRITE_WIDTH;
		this->height = ITEM_HEALTH_DROP_SPRITE_HEIGHT;

		collider.width = ITEM_HEALTH_DROP_SPRITE_WIDTH;
		collider.height = ITEM_HEALTH_DROP_SPRITE_HEIGHT;
		break;
	case GAME_OBJ_ID_SHURIKEN_DROP:
		this->width = ITEM_SHURIKEN_DROP_SPRITE_WIDTH;
		this->height = ITEM_SHURIKEN_DROP_SPRITE_HEIGHT;

		collider.width = ITEM_SHURIKEN_DROP_SPRITE_WIDTH;
		collider.height = ITEM_SHURIKEN_DROP_SPRITE_HEIGHT;
		break;
	case GAME_OBJ_ID_WINDMILL_DROP:
		this->width = ITEM_SHURIKEN_DROP_SPRITE_WIDTH;
		this->height = ITEM_SHURIKEN_DROP_SPRITE_HEIGHT;

		collider.width = ITEM_SHURIKEN_DROP_SPRITE_WIDTH;
		collider.height = ITEM_SHURIKEN_DROP_SPRITE_HEIGHT;
		break;
	case GAME_OBJ_ID_FIREWHEEL_DROP:
		this->width = ITEM_SHURIKEN_DROP_SPRITE_WIDTH;
		this->height = ITEM_SHURIKEN_DROP_SPRITE_HEIGHT;

		collider.width = ITEM_SHURIKEN_DROP_SPRITE_WIDTH;
		collider.height = ITEM_SHURIKEN_DROP_SPRITE_HEIGHT;
		break;
	}

	LoadResources();
}

void ItemDrop::LoadResources()
{
	Animation * anim;
	switch (type)
	{
	case GAME_OBJ_ID_BLUE_SPIRIT_POINT:
		// Blue Spirit Point
		anim = new Animation(50);
		for (int i = 0; i < 1; i++)
		{
			RECT rect;
			rect.left = (i % ITEM_BLUE_SPIRIT_POINT_TEXTURE_COLUMNS) * ITEM_BLUE_SPIRIT_POINT_SPRITE_WIDTH;
			rect.right = rect.left + ITEM_BLUE_SPIRIT_POINT_SPRITE_WIDTH;
			rect.top = (i / ITEM_BLUE_SPIRIT_POINT_TEXTURE_COLUMNS) * ITEM_BLUE_SPIRIT_POINT_SPRITE_HEIGHT;
			rect.bottom = rect.top + ITEM_BLUE_SPIRIT_POINT_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ITEM_BLUE_SPIRIT_POINT_TEXTURE_LOCATION, rect, ITEM_BLUE_SPIRIT_POINT_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
		break;
	case GAME_OBJ_ID_RED_SPIRIT_POINT:
		// Red Spirit Point
		anim = new Animation(50);
		for (int i = 0; i < 1; i++)
		{
			RECT rect;
			rect.left = (i % ITEM_RED_SPIRIT_POINT_TEXTURE_COLUMNS) * ITEM_RED_SPIRIT_POINT_SPRITE_WIDTH;
			rect.right = rect.left + ITEM_RED_SPIRIT_POINT_SPRITE_WIDTH;
			rect.top = (i / ITEM_RED_SPIRIT_POINT_TEXTURE_COLUMNS) * ITEM_RED_SPIRIT_POINT_SPRITE_HEIGHT;
			rect.bottom = rect.top + ITEM_RED_SPIRIT_POINT_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ITEM_RED_SPIRIT_POINT_TEXTURE_LOCATION, rect, ITEM_RED_SPIRIT_POINT_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
		break;
	case GAME_OBJ_ID_SHURIKEN_DROP:
		// Shuriken
		anim = new Animation(50);
		for (int i = 0; i < 1; i++)
		{
			RECT rect;
			rect.left = (i % ITEM_SHURIKEN_DROP_TEXTURE_COLUMNS) * ITEM_SHURIKEN_DROP_SPRITE_WIDTH;
			rect.right = rect.left + ITEM_SHURIKEN_DROP_SPRITE_WIDTH;
			rect.top = (i / ITEM_SHURIKEN_DROP_TEXTURE_COLUMNS) * ITEM_SHURIKEN_DROP_SPRITE_HEIGHT;
			rect.bottom = rect.top + ITEM_SHURIKEN_DROP_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ITEM_SHURIKEN_DROP_TEXTURE_LOCATION, rect, ITEM_SHURIKEN_DROP_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
		break;
	case GAME_OBJ_ID_WINDMILL_DROP:
		// Windmill
		anim = new Animation(50);
		for (int i = 0; i < 1; i++)
		{
			RECT rect;
			rect.left = (i % ITEM_WINDMILL_DROP_TEXTURE_COLUMNS) * ITEM_WINDMILL_DROP_SPRITE_WIDTH;
			rect.right = rect.left + ITEM_WINDMILL_DROP_SPRITE_WIDTH;
			rect.top = (i / ITEM_WINDMILL_DROP_TEXTURE_COLUMNS) * ITEM_WINDMILL_DROP_SPRITE_HEIGHT;
			rect.bottom = rect.top + ITEM_WINDMILL_DROP_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ITEM_WINDMILL_DROP_TEXTURE_LOCATION, rect, ITEM_WINDMILL_DROP_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
		break;
	case GAME_OBJ_ID_FIREWHEEL_DROP:
		// Firewheel
		anim = new Animation(50);
		for (int i = 0; i < 1; i++)
		{
			RECT rect;
			rect.left = (i % ITEM_FIREWHEEL_DROP_TEXTURE_COLUMNS) * ITEM_FIREWHEEL_DROP_SPRITE_WIDTH;
			rect.right = rect.left + ITEM_FIREWHEEL_DROP_SPRITE_WIDTH;
			rect.top = (i / ITEM_FIREWHEEL_DROP_TEXTURE_COLUMNS) * ITEM_FIREWHEEL_DROP_SPRITE_HEIGHT;
			rect.bottom = rect.top + ITEM_FIREWHEEL_DROP_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ITEM_FIREWHEEL_DROP_TEXTURE_LOCATION, rect, ITEM_FIREWHEEL_DROP_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
		break;
	case GAME_OBJ_ID_FREEZE_DROP:
		// Freeze
		anim = new Animation(50);
		for (int i = 0; i < 1; i++)
		{
			RECT rect;
			rect.left = (i % ITEM_FREEZE_DROP_TEXTURE_COLUMNS) * ITEM_FREEZE_DROP_SPRITE_WIDTH;
			rect.right = rect.left + ITEM_FREEZE_DROP_SPRITE_WIDTH;
			rect.top = (i / ITEM_FREEZE_DROP_TEXTURE_COLUMNS) * ITEM_FREEZE_DROP_SPRITE_HEIGHT;
			rect.bottom = rect.top + ITEM_FREEZE_DROP_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ITEM_FREEZE_DROP_TEXTURE_LOCATION, rect, ITEM_FREEZE_DROP_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
		break;
	case GAME_OBJ_ID_HEALTH_DROP:
		// Health
		anim = new Animation(50);
		for (int i = 0; i < 1; i++)
		{
			RECT rect;
			rect.left = (i % ITEM_HEALTH_DROP_TEXTURE_COLUMNS) * ITEM_HEALTH_DROP_SPRITE_WIDTH;
			rect.right = rect.left + ITEM_HEALTH_DROP_SPRITE_WIDTH;
			rect.top = (i / ITEM_HEALTH_DROP_TEXTURE_COLUMNS) * ITEM_HEALTH_DROP_SPRITE_HEIGHT;
			rect.bottom = rect.top + ITEM_HEALTH_DROP_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ITEM_HEALTH_DROP_TEXTURE_LOCATION, rect, ITEM_HEALTH_DROP_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
		break;
	case GAME_OBJ_ID_BLUE_BONUS_DROP:
		// Blue Bonus
		anim = new Animation(50);
		for (int i = 0; i < 1; i++)
		{
			RECT rect;
			rect.left = (i % ITEM_BLUE_BONUS_DROP_TEXTURE_COLUMNS) * ITEM_BLUE_BONUS_DROP_SPRITE_WIDTH;
			rect.right = rect.left + ITEM_BLUE_BONUS_DROP_SPRITE_WIDTH;
			rect.top = (i / ITEM_BLUE_BONUS_DROP_TEXTURE_COLUMNS) * ITEM_BLUE_BONUS_DROP_SPRITE_HEIGHT;
			rect.bottom = rect.top + ITEM_BLUE_BONUS_DROP_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ITEM_BLUE_BONUS_DROP_TEXTURE_LOCATION, rect, ITEM_BLUE_BONUS_DROP_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
		break;
	case GAME_OBJ_ID_RED_BONUS_DROP:
		// Red Bonus
		anim = new Animation(50);
		for (int i = 0; i < 1; i++)
		{
			RECT rect;
			rect.left = (i % ITEM_RED_BONUS_DROP_TEXTURE_COLUMNS) * ITEM_RED_BONUS_DROP_SPRITE_WIDTH;
			rect.right = rect.left + ITEM_RED_BONUS_DROP_SPRITE_WIDTH;
			rect.top = (i / ITEM_RED_BONUS_DROP_TEXTURE_COLUMNS) * ITEM_RED_BONUS_DROP_SPRITE_HEIGHT;
			rect.bottom = rect.top + ITEM_RED_BONUS_DROP_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ITEM_RED_BONUS_DROP_TEXTURE_LOCATION, rect, ITEM_RED_BONUS_DROP_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
		break;
	}
}
bool AABB(const Collider &c1, const Collider &c2);
#include "Grid.h"
//Hàm cập nhật
void ItemDrop::Update(DWORD dt)
{
	if (AABB(this->collider, Ninja::GetInstance()->GetCollider()))
	{
		this->isActive = false;
		Ninja::GetInstance()->PowerUp(this->type);
		return;
	}
	this->vy -= ITEM_BLUE_SPIRIT_POINT_GRAVITY;
	this->vx = 0;

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;
	vector<GameObject *> coObjects;

	vector<Tile *> tiles = Grid::GetInstance()->GetCurTiles();

	coEvents.clear();
	this->SetDt(dt);
	this->CalcPotentialCollisions(tiles, coObjects, coEvents);

	if (coEvents.size() == 0)
	{
		this->x += trunc(vx * dt);
		this->y += trunc(vy * dt);
	}
	else
	{
		float min_tx, min_ty, nx, ny;

		this->FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		// Xử lí va chạm
		this->x = (int)(this->x + min_tx * this->vx * dt + nx * 0.4);
		this->y = (int)(this->y + min_ty * this->vy * dt + ny * 0.4);

		if (nx != 0) this->vx = 0;
		if (ny != 0) this->vy = 0;
	}
	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];

}
//Hàm render
void ItemDrop::Render()
{
	SpriteData spriteData;
	spriteData.width = this->width;
	spriteData.height = this->height;
	spriteData.x = this->x;
	spriteData.y = this->y;
	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = false;

	this->animations[0]->Render(spriteData);
}
