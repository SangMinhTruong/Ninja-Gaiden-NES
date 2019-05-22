#pragma once

#include "StateGameObject.h"

class Ninja : public StateGameObject
{
	Ninja();
	static Ninja * __instance;
	//Roi
	Whip * whip;
	//Vũ khí phụ
	int curSubweapon;
	static vector<Subweapon *> subweapons;
public:
	void LoadResources() override;
	//Hàm set
	void SetWhip(int type) { this->whip->SetType(type); }
	//Hàm get
	int GetIdleAnimID() override;
	int GetWalkAnimID() override;
	int GetJumpAnimID() override;
	int GetCrouchAnimID() override;
	int GetStandAttackAnimID() override;
	int GetCrouchAttackAnimID() override;
	int GetHurtAnimID() override;
	int GetDyingAnimID() override;

	float GetDefaultWalkSpeed() override { return NINJA_WALKING_SPEED; }
	float GetDefautJumpSpeed() override { return NINJA_JUMP_SPEED_Y; }

	static Ninja * GetInstance();
	vector<Subweapon *> GetSubweapon() { return this->subweapons; }
	Whip * GetWhip() { return this->whip; }
	//Hàm trạng thái

	//Các hàm hành động nhân vật
	void CreateThrownWeapon();
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};

