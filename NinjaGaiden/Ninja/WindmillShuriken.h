#pragma once 
#include "Subweapon.h"
#include "Ninja.h"

class Ninja;
class WindmillShuriken : public Subweapon
{
private:
	static Animation * animation;
	int oT = 0;
	bool nCollision = false;
public:
	WindmillShuriken();

	void LoadResources() override;
	void ResetAnim() override { this->animation->Reset(); }

	bool IsNinjaCollision() { return nCollision; }

	bool isnCollistion() { return nCollision; }
	void Hit();

	int GetWidth() { return SUBWEAPON_WINDMILLSHURIKEN_SPRITE_WIDTH; }
	int GetHeight() { return SUBWEAPON_WINDMILLSHURIKEN_SPRITE_HEIGHT; }
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
	~WindmillShuriken();
};
