#include "Whip.h"
#include "Ninja.h"

vector<Animation *> Whip::animations = vector<Animation *>();
Whip::Whip()
{
	this->id = GAME_OBJ_ID_SWORD;

	this->width = WHIP_SPRITE_WIDTH;
	this->height = WHIP_SPRITE_HEIGHT;

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = WHIP_SPRITE_WIDTH;
	collider.height = WHIP_SPRITE_HEIGHT;

	type = WHIP_NORMAL;
	LoadResources();
}
void Whip::LoadResources()
{
	// 0
	Animation * anim = new Animation(50);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % WHIP_TEXTURE_COLUMNS) * WHIP_SPRITE_WIDTH;
		rect.right = rect.left + WHIP_SPRITE_WIDTH;
		rect.top = (i / WHIP_TEXTURE_COLUMNS) * WHIP_SPRITE_HEIGHT;
		rect.bottom = rect.top + WHIP_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(WHIP_TEXTURE_LOCATION, rect, WHIP_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);
}
void Whip::SetPosition(float x, float y, bool isCrouching, bool isLeft)
{
	if (isLeft)
		this->x = x - WHIP_SPRITE_WIDTH;
	else
		this->x = x + 32;

	if (isCrouching)
		this->y = y - 32;
	else
		this->y = y;
}

void Whip::ResetAnim()
{
	for (int i = 0; i < animations.size(); i++)
		animations[i]->Reset();
}
void Whip::TurnLeft()
{
	isLeft = true;
}
void Whip::TurnRight()
{
	isLeft = false;
}
//Hàm cập nhật
void Whip::Update(DWORD dt)
{
	this->SetPosition(Ninja::GetInstance()->GetPositionX(),
		Ninja::GetInstance()->GetPositionY(),
		Ninja::GetInstance()->IsCrouching(),
		Ninja::GetInstance()->IsLeft());
	this->UpdateObjectCollider();
}
//Hàm render
void Whip::Render()
{
	SpriteData spriteData;
	spriteData.width = WHIP_SPRITE_WIDTH;
	spriteData.height = WHIP_SPRITE_HEIGHT;
	spriteData.x = this->x;
	spriteData.y = this->y;
	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = Ninja::GetInstance()->IsLeft();

	this->animations[type]->Render(spriteData);
}
Whip::~Whip()
{

}