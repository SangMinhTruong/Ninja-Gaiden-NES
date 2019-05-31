#pragma once  
#include "Subweapon.h"
#include"Ninja.h" 

class Ninja;
class FireWheel : public Subweapon
{
	static Animation * animation;
	float rotateAngle;
	float flyAngle;
public:
	FireWheel();

	void LoadResources() override;
	void ResetAnim() override { this->animation->Reset(); }

	static vector<Subweapon*> Create(int x, int y, bool isLeft);
	int GetWidth() { return SUBWEAPON_FIREWHEEL_SPRITE_WIDTH; }
	int GetHeight() { return SUBWEAPON_FIREWHEEL_SPRITE_HEIGHT; }
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
	~FireWheel();
};

