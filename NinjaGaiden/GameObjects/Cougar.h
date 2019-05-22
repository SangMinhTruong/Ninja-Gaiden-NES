#pragma once
#include "StateGameObject.h"

class Cougar : public StateGameObject
{
private:
	//static Cougar * __instance;
public:
	Cougar(int x, int y);
	void LoadResources() override;
	//Hàm set
	//Hàm get
	int GetIdleAnimID() override;
	int GetWalkAnimID() override;
	int GetJumpAnimID() override;
	int GetCrouchAnimID() override;
	int GetStandAttackAnimID() override;
	int GetCrouchAttackAnimID() override;
	int GetDyingAnimID() override;

	float GetDefaultWalkSpeed() override { return COUGAR_WALKING_SPEED; }
	float GetDefautJumpSpeed() override { return COUGAR_JUMP_SPEED_Y; }

	//static Cougar * GetInstance();
	//Hàm trạng thái

	//Các hàm hành động nhân vật
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};

