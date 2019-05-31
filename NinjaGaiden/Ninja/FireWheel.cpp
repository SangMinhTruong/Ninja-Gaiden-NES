
#include "Firewheel.h"
#include"Debug.h"
Animation * FireWheel::animation = NULL;

FireWheel::FireWheel()
{
	this->id = GAME_OBJ_ID_FIREWHEEL;

	this->width = SUBWEAPON_FIREWHEEL_SPRITE_WIDTH;
	this->height = SUBWEAPON_FIREWHEEL_SPRITE_HEIGHT;

	this->vy = SUBWEAPON_SPEED_Y / 0.75f;
	this->vx = SUBWEAPON_SPEED_X / 1.5f;

	flyAngle = 0;
	rotateAngle = 0;
	//Khởi tạo hộp va chạm

	collider.vx = vx;
	collider.vy = vy;
	collider.width = SUBWEAPON_FIREWHEEL_SPRITE_WIDTH;
	collider.height = SUBWEAPON_FIREWHEEL_SPRITE_HEIGHT;

	this->type = NULL;



	if (animation == NULL)
		LoadResources();
}


FireWheel::~FireWheel()
{

}

void FireWheel::LoadResources()
{
	animation = new Animation(50);
	for (int i = 0; i < 4; i++)
	{
		RECT rect;
		rect.left = (i % SUBWEAPON_FIREWHEEL_TEXTURE_COLUMNS) * SUBWEAPON_FIREWHEEL_SPRITE_WIDTH;
		rect.right = rect.left + SUBWEAPON_FIREWHEEL_SPRITE_WIDTH;
		rect.top = (i / SUBWEAPON_FIREWHEEL_TEXTURE_COLUMNS) * SUBWEAPON_FIREWHEEL_SPRITE_HEIGHT;
		rect.bottom = rect.top + SUBWEAPON_FIREWHEEL_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(SUBWEAPON_FIREWHEEL_TEXTURE_LOCATION, rect, SUBWEAPON_FIREWHEEL_TEXTURE_TRANS_COLOR);

		animation->AddFrame(sprite);
	}
}
//Hàm cập nhật
void FireWheel::Update(DWORD dt)
{

	this->vy = this->vy * flyAngle;
	DebugOut(L"Angle = %f", this->vy);
	this->x += (int)(this->vx * (isLeft ? -1 : 1) * dt);
	this->y += (int)(this->vy*dt);

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
void FireWheel::Render()
{
	SpriteData spriteData;
	spriteData.width = SUBWEAPON_FIREWHEEL_SPRITE_WIDTH;
	spriteData.height = SUBWEAPON_FIREWHEEL_SPRITE_HEIGHT;
	spriteData.x = x;
	spriteData.y = y;
	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = this->isLeft;
	this->animation->Render(spriteData);

}

vector<Subweapon*> FireWheel::Create(int x, int y, bool isLeft) {
	vector<Subweapon*> subweapons;
	for (int i = 0; i < 3; i++) {
		FireWheel *fireWheel = new FireWheel();
		fireWheel->flyAngle = float(i * 2000 + 20) / 100000 + 1.0f;


		fireWheel->SetThrownPosition(x - 20, y, false);
		isLeft ? fireWheel->TurnLeft() : fireWheel->TurnRight();
		subweapons.push_back(fireWheel);
	}
	return subweapons;
}