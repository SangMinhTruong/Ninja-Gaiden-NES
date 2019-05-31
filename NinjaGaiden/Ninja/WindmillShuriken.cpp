#include "WindmillShuriken.h"

Animation * WindmillShuriken::animation = NULL;

WindmillShuriken::WindmillShuriken()
{
	this->id = GAME_OBJ_ID_WINDMILLSHURIKEN;

	this->width = SUBWEAPON_WINDMILLSHURIKEN_SPRITE_WIDTH;
	this->height = SUBWEAPON_WINDMILLSHURIKEN_SPRITE_HEIGHT;

	this->vy = 0;
	this->vx = 0;


	//Khởi tạo hộp va chạm

	collider.vx = vx;
	collider.vy = vy;
	collider.width = SUBWEAPON_WINDMILLSHURIKEN_SPRITE_WIDTH;
	collider.height = SUBWEAPON_WINDMILLSHURIKEN_SPRITE_HEIGHT;

	this->type = NULL;



	if (animation == NULL)
		LoadResources();
}


WindmillShuriken::~WindmillShuriken()
{

}

void WindmillShuriken::Hit() {
	if (nCollision)
		onHit = true;
}

void WindmillShuriken::LoadResources()
{
	animation = new Animation(50);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % SUBWEAPON_WINDMILLSHURIKEN_TEXTURE_COLUMNS) * SUBWEAPON_WINDMILLSHURIKEN_SPRITE_WIDTH;
		rect.right = rect.left + SUBWEAPON_WINDMILLSHURIKEN_SPRITE_WIDTH;
		rect.top = (i / SUBWEAPON_WINDMILLSHURIKEN_TEXTURE_COLUMNS) * SUBWEAPON_WINDMILLSHURIKEN_SPRITE_HEIGHT;
		rect.bottom = rect.top + SUBWEAPON_WINDMILLSHURIKEN_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(SUBWEAPON_WINDMILLSHURIKEN_TEXTURE_LOCATION, rect, SUBWEAPON_WINDMILLSHURIKEN_TEXTURE_TRANS_COLOR);

		animation->AddFrame(sprite);
	}
}
//Hàm cập nhật
void WindmillShuriken::Update(DWORD dt)
{

	Ninja * ninja = Ninja::GetInstance();


	//Vô hiệu vũ khí khi va chạm
	if (onHit)
		ninja->RemoveSubweapon(this);


	//Kích hoạt va chạm với ninja khi rời khỏi khoảng 50

	if (!nCollision)
		if (abs(ninja->GetPositionX() - this->x) >= 50)
			nCollision = true;



	//Dao động điều hoà
	oT = oT + 1;

	this->vx = (100 * cos(2 * 3.14*0.009*oT + (isLeft ? 3.14 / 2 : -3.14 / 2)) + ninja->GetPositionX()) / dt;
	this->vy = (ninja->GetPositionY() - 10 - this->y) / 2000;

	this->x = this->vx*dt;
	this->y += this->vy*dt;

	this->UpdateObjectCollider();
}
//Hàm render
void WindmillShuriken::Render()
{
	SpriteData spriteData;
	spriteData.width = SUBWEAPON_WINDMILLSHURIKEN_SPRITE_WIDTH;
	spriteData.height = SUBWEAPON_WINDMILLSHURIKEN_SPRITE_HEIGHT;
	spriteData.x = x;
	spriteData.y = y;
	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = this->isLeft;

	this->animation->Render(spriteData);

}