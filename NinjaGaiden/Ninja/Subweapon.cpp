#include "Subweapon.h"

void Subweapon::SetThrownPosition(float x, float y, bool isCrouching)
{
	int offset = 0;

	this->x = (isLeft ? x - 16 : x + 42);

	this->y = y - 7;

	//Khởi tạo hộp va chạm
	this->collider.x = this->x;
	this->collider.y = this->y;
}