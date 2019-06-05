#include "Item.h"
#include "Ninja.h"
#include "TiledMap.h"
Item::Item(int x, int y, int dropID)
{
	this->id = GAME_OBJ_ID_ITEM;
	this->dropID = dropID;
	this->x = x;
	this->y = y; 
	this->initX = x;
	this->initY = y;
	this->width = ITEM_SPRITE_WIDTH;
	this->height = ITEM_SPRITE_HEIGHT;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = ITEM_SPRITE_WIDTH;
	collider.height = ITEM_SPRITE_HEIGHT;

	LoadResources();
}
void Item::LoadResources()
{
	int mapID = TiledMap::GetInstance()->GetMapID();
	if (mapID == TILED_MAP_ID_3_1)
	{
		this->type = ITEM_BUTTERFLY;
		// ButterFly
		Animation * anim = new Animation(50);
		for (int i = 0; i < 2; i++)
		{
			RECT rect;
			rect.left = (i % ITEM_TEXTURE_COLUMNS) * ITEM_SPRITE_WIDTH;
			rect.right = rect.left + ITEM_SPRITE_WIDTH;
			rect.top = (i / ITEM_TEXTURE_COLUMNS) * ITEM_SPRITE_HEIGHT;
			rect.bottom = rect.top + ITEM_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ITEM_TEXTURE_LOCATION_BUTTERFLY, rect, ITEM_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
	}
	else if (mapID == TILED_MAP_ID_3_2)
	{
		this->type = ITEM_BUTTERFLY;
		// Bird
		Animation * anim = new Animation(50);
		for (int i = 0; i < 2; i++)
		{
			RECT rect;
			rect.left = (i % ITEM_TEXTURE_COLUMNS) * ITEM_SPRITE_WIDTH;
			rect.right = rect.left + ITEM_SPRITE_WIDTH;
			rect.top = (i / ITEM_TEXTURE_COLUMNS) * ITEM_SPRITE_HEIGHT;
			rect.bottom = rect.top + ITEM_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(ITEM_TEXTURE_LOCATION_BIRD, rect, ITEM_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
	}
}
void Item::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Item::ResetAnim()
{
	for (int i = 0; i < animations.size(); i++)
		animations[i]->Reset();
}

ItemDrop * Item::CreateItemDrop()
{
	ItemDrop * itemDrop = NULL;
	switch (this->dropID)
	{
	case GAME_OBJ_ID_BLUE_SPIRIT_POINT:
		itemDrop = new ItemDrop(this->x, this->y, dropID);
		break;
	case GAME_OBJ_ID_RED_SPIRIT_POINT:
		itemDrop = new ItemDrop(this->x, this->y, dropID);
		break;
	case GAME_OBJ_ID_SHURIKEN_DROP:
		itemDrop = new ItemDrop(this->x, this->y, dropID);
		break;
	case GAME_OBJ_ID_WINDMILL_DROP:
		itemDrop = new ItemDrop(this->x, this->y, dropID);
		break;
	case GAME_OBJ_ID_FIREWHEEL_DROP:
		itemDrop = new ItemDrop(this->x, this->y, dropID);
		break;
	case GAME_OBJ_ID_FREEZE_DROP:
		itemDrop = new ItemDrop(this->x, this->y, dropID);
		break;
	case GAME_OBJ_ID_HEALTH_DROP:
		itemDrop = new ItemDrop(this->x, this->y, dropID);
		break;
	case GAME_OBJ_ID_BLUE_BONUS_DROP:
		itemDrop = new ItemDrop(this->x, this->y, dropID);
		break;
	case GAME_OBJ_ID_RED_BONUS_DROP:
		itemDrop = new ItemDrop(this->x, this->y, dropID);
		break;
	}
	return itemDrop;
}
#include "Grid.h"
bool AABB(const Collider &c1, const Collider &c2);
//Hàm cập nhật
void Item::Update(DWORD dt)
{
	Ninja * ninja = Ninja::GetInstance();
	if (ninja->IsAttacking())
	{
		Whip * sword = ninja ->GetWhip();
		if (AABB(this->collider, sword->GetCollider()))
		{
			GameObject * itemDrop = this->CreateItemDrop();
			Grid::GetInstance()->AddObject(itemDrop);

			this->isActive = false;
			return;
		}
	}
	//Xét va chạm với subweapon
	vector<Subweapon*> subweapons;
	subweapons = ninja->GetSubweapon();
	for (int i = 0; i < subweapons.size(); i++) {
		if (AABB(this->collider, subweapons.at(i)->GetCollider()))
		{
			GameObject * itemDrop = this->CreateItemDrop();
			Grid::GetInstance()->AddObject(itemDrop);

			this->isActive = false;
			return;
		}
	}

}
//Hàm render
void Item::Render()
{
	SpriteData spriteData;
	spriteData.width = ITEM_SPRITE_WIDTH;
	spriteData.height = ITEM_SPRITE_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;
	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;

	this->animations[0]->Render(spriteData);
}
Item::~Item()
{

}