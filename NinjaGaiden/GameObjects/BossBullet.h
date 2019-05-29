#pragma once
#include "GameObject.h"
#include "Constants.h"

class Boss;
class BossBullet : public GameObject
{
	vector<Animation *> animations;
	Boss * gunner;
public:
	BossBullet(int x, int y, bool isLeft);

	void LoadResources();

	void SetBoss(Boss * gunner) { this->gunner = gunner; }

	int GetWidth() { return MACHINE_GUNNER_BULLET_SPRITE_WIDTH; }
	int GetHeight() { return MACHINE_GUNNER_BULLET_SPRITE_WIDTH; }
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
	~BossBullet();
};

