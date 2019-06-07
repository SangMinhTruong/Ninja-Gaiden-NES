#pragma once
#include "StateGameObject.h"
#include "BossBullet.h"
#include "Explosion.h"
class Boss : public StateGameObject
{
private:
	//Vũ khí phụ
	int curBullet;
	vector<BossBullet *> bullets;

	DWORD jumpTimer = 0;
	DWORD attackTimer = 0;
public:
	Boss(int x, int y);
	void LoadResources() override;
	//Hàm set
	void AddJumpTimer(DWORD dt) { this->jumpTimer += dt; }
	void AddAttackTimer(int time) { this->attackTimer += time; }
	void ResetJumpTimer() { this->jumpTimer = 0; }
	void ResetAttackTimer() { this->attackTimer = 0; }
	//Hàm get
	int GetIdleAnimID() override;
	int GetWalkAnimID() override;
	int GetJumpAnimID() override;
	int GetCrouchAnimID() override;
	int GetStandAttackAnimID() override;
	int GetCrouchAttackAnimID() override;
	int GetDyingAnimID() override;

	DWORD GetJumpTimer() { return this->jumpTimer; }
	DWORD GetAttackTimer() { return this->attackTimer; }

	float GetDefaultWalkSpeed() override { return BOSS_WALKING_SPEED; }
	float GetDefautJumpSpeed() override { return BOSS_JUMP_SPEED_Y; }

	//Các hàm hành động nhân vật
	void CreateThrownWeapon(int x, int y);
	void RemoveBullet(BossBullet * bullet);

	//Các hàm hành động nhân vật
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};

