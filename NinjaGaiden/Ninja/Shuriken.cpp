#include "Shuriken.h"

Animation * Shuriken::animation = NULL;

Shuriken::Shuriken()
{
	this->id = GAME_OBJ_ID_SHURIKEN;

	this->width = SUBWEAPON_SHURIKEN_SPRITE_WIDTH;
	this->height = SUBWEAPON_SHURIKEN_SPRITE_HEIGHT;

	this->vy = 0;
	this->vx = SUBWEAPON_SPEED_X;


	//Khởi tạo hộp va chạm

	collider.vx = vx;
	collider.vy = vy;
	collider.width = SUBWEAPON_SHURIKEN_SPRITE_WIDTH;
	collider.height = SUBWEAPON_SHURIKEN_SPRITE_HEIGHT;

	this->type = NULL;



	if (animation == NULL)
		LoadResources();
}


Shuriken::~Shuriken()
{

}

void Shuriken::LoadResources()
{
	animation = new Animation(50);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % SUBWEAPON_SHURIKEN_TEXTURE_COLUMNS) * SUBWEAPON_SHURIKEN_SPRITE_WIDTH;
		rect.right = rect.left + SUBWEAPON_SHURIKEN_SPRITE_WIDTH;
		rect.top = (i / SUBWEAPON_SHURIKEN_TEXTURE_COLUMNS) * SUBWEAPON_SHURIKEN_SPRITE_HEIGHT;
		rect.bottom = rect.top + SUBWEAPON_SHURIKEN_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(SUBWEAPON_SHURIKEN_TEXTURE_LOCATION, rect, SUBWEAPON_SHURIKEN_TEXTURE_TRANS_COLOR);

		animation->AddFrame(sprite);
	}
}
//Hàm cập nhật
void Shuriken::Update(DWORD dt)
{
	this->x += this->vx * (isLeft ? -1 : 1) * dt;
	this->y += this->vy * dt;

	Ninja * ninja = Ninja::GetInstance();

	//Vô hiệu hoá subweapon
	if (onHit)
		ninja->RemoveSubweapon(this);

	//Khi chạy ra xa ninja thì xoá subweapon

	if (abs(this->x - ninja->GetPositionX()) > 170)
		ninja->RemoveSubweapon(this);
	this->UpdateObjectCollider();
}
//Hàm render
void Shuriken::Render()
{
	SpriteData spriteData;
	spriteData.width = SUBWEAPON_SHURIKEN_SPRITE_WIDTH;
	spriteData.height = SUBWEAPON_SHURIKEN_SPRITE_HEIGHT;
	spriteData.x = x;
	spriteData.y = y;
	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = this->isLeft;

	this->animation->Render(spriteData);

}