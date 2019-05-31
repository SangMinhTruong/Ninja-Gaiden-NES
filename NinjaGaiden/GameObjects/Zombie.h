#pragma once
#include "StateGameObject.h"
#include "ZombieBullet.h"

class ZombieBullet;
class Zombie : public StateGameObject
{
private:
	//Vũ khí phụ
	int curBullet;
	vector<ZombieBullet *> bullets;
	//static Zombie * __instance;
public:
	Zombie(int x, int y);
	void LoadResources() override;
	//Hàm set
	//Hàm get
	int GetIdleAnimID() override;
	int GetWalkAnimID() override;
	int GetJumpAnimID() override;
	int GetCrouchAnimID() override;
	int GetStandAttackAnimID() override;
	int GetCrouchAttackAnimID() override;
	int GetThrowingAttackAnimID() override;
	int GetDyingAnimID() override;

	float GetDefaultWalkSpeed() override { return ZOMBIE_WALKING_SPEED; }
	float GetDefautJumpSpeed() override { return ZOMBIE_JUMP_SPEED_Y; }

	vector<ZombieBullet *> GetBulletList() { return bullets; }

	//static Zombie * GetInstance();
	//Hàm trạng thái

	//Các hàm hành động nhân vật
	void CreateThrownWeapon() override;
	void RemoveBullet(ZombieBullet * bullet);
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};


