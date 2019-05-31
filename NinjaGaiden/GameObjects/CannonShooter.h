#pragma once
#include "StateGameObject.h"
#include "CannonShooterBullet.h"

class CannonShooterBullet;
class CannonShooter : public StateGameObject
{
private:
	//Vũ khí phụ
	int curBullet;
	vector<CannonShooterBullet *> bullets;

	DWORD attackTimer;
	//static CannonShooter * __instance;
public:
	CannonShooter(int x, int y);
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

	float GetDefaultWalkSpeed() override { return CANNON_SHOOTER_WALKING_SPEED; }
	float GetDefautJumpSpeed() override { return CANNON_SHOOTER_JUMP_SPEED_Y; }

	vector<CannonShooterBullet *> GetBulletList() { return bullets; }
	DWORD GetAttackTimer() { return attackTimer; }

	//static CannonShooter * GetInstance();
	//Hàm trạng thái

	//Các hàm hành động nhân vật
	void CreateThrownWeapon() override;
	void RemoveBullet(CannonShooterBullet * bullet);
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};


