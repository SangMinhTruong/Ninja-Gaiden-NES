#pragma once
#include "StateGameObject.h"
#include "MachineGunnerBullet.h"

class MachineGunnerBullet;
class MachineGunner : public StateGameObject
{
private:
	//Vũ khí phụ
	int curBullet;
	vector<MachineGunnerBullet *> bullets;

	DWORD attackTimer;
	//static MachineGunner * __instance;
public:
	MachineGunner(int x, int y);
	void LoadResources() override;
	//Hàm set
	void SetAttackTimer(DWORD lastAttackTime) { this->attackTimer = lastAttackTime; }
	//Hàm get
	int GetIdleAnimID() override;
	int GetWalkAnimID() override;
	int GetJumpAnimID() override;
	int GetCrouchAnimID() override;
	int GetStandAttackAnimID() override;
	int GetCrouchAttackAnimID() override;
	int GetThrowingAttackAnimID() override;
	int GetDyingAnimID() override;

	float GetDefaultWalkSpeed() override { return MACHINE_GUNNER_WALKING_SPEED; }
	float GetDefautJumpSpeed() override { return MACHINE_GUNNER_JUMP_SPEED_Y; }

	vector<MachineGunnerBullet *> GetBulletList() { return bullets; }
	DWORD GetAttackTimer() { return attackTimer; }

	//static MachineGunner * GetInstance();
	//Hàm trạng thái

	//Các hàm hành động nhân vật
	void CreateThrownWeapon() override;
	void RemoveBullet(MachineGunnerBullet * bullet);
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};


