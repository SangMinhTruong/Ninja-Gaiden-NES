#pragma once
#include "GameObject.h"
#include "Constants.h"

class CannonShooter;
class CannonShooterBullet : public GameObject
{
	vector<Animation *> animations;
	CannonShooter * gunner;
public:
	CannonShooterBullet(int x, int y, bool isLeft);

	void LoadResources();

	void SetCannonShooter(CannonShooter * gunner) { this->gunner = gunner; }

	int GetWidth() { return CANNON_SHOOTER_BULLET_SPRITE_WIDTH; }
	int GetHeight() { return CANNON_SHOOTER_BULLET_SPRITE_WIDTH; }
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
	~CannonShooterBullet();
};

