#pragma once
#include "GameObject.h"
#include "Constants.h"

class MachineGunner;
class MachineGunnerBullet : public GameObject
{
	vector<Animation *> animations;
	MachineGunner * gunner;
public:
	MachineGunnerBullet(int x, int y, bool isLeft);

	void LoadResources();

	void SetMachineGunner(MachineGunner * gunner) { this->gunner = gunner; }

	int GetWidth() { return MACHINE_GUNNER_BULLET_SPRITE_WIDTH; }
	int GetHeight() { return MACHINE_GUNNER_BULLET_SPRITE_WIDTH; }
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
	~MachineGunnerBullet();
};

