#pragma once

#include "StateGameObject.h"

#include "Shuriken.h"
#include "WindmillShuriken.h"
#include "Whip.h"
#include "FireWheel.h"

#include"Sound.h"

class Subweapon;
class Shuriken;
class Windmill;
class FireWheel;

class Ninja : public StateGameObject
{
	Ninja();
	static Ninja * __instance;
	
	//Roi
	Whip * whip;
	//Vũ khí phụ
	int curSubweapon = -1;
	static vector<Subweapon *> subweapons;
public:
	void LoadResources() override;
	//Hàm set
	void SetCurrentSubweapon(int i) { this->curSubweapon = i; }
	void SetWhip(int type) { this->whip->SetType(type); }
	//Hàm get
	int GetIdleAnimID() override;
	int GetWalkAnimID() override;
	int GetClimbAnimID() override;
	int GetJumpAnimID() override;
	int GetCrouchAnimID() override;
	int GetStandAttackAnimID() override;
	int GetCrouchAttackAnimID() override;
	int GetThrowingAttackAnimID() override;
	int GetHurtAnimID() override;
	int GetDyingAnimID() override;

	DWORD GetInvincibleTimer() { return this->invincibleTimer; }

	float GetDefaultWalkSpeed() override { return NINJA_WALKING_SPEED; }
	float GetDefautJumpSpeed() override { return NINJA_JUMP_SPEED_Y; }
	float GetDefaultClimbingSpeed() override { return NINJA_CLIMBING_SPEED; };



	static Ninja * GetInstance();
	int GetCurrentSubweapon() { return this->curSubweapon; }
	vector<Subweapon *> GetSubweapon() { return this->subweapons; }
	Whip * GetWhip() { return this->whip; }
	//Hàm trạng thái

	//Các hàm hành động nhân vật
	void PowerUp(int type);
	void CreateThrownWeapon() override;
	bool RemoveSubweapon(Subweapon * subweapon);
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};

