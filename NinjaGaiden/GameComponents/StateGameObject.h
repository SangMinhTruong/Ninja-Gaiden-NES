#pragma once
#include "GameObject.h"

#include "Whip.h"
#include "Knife.h"

#include "IdleState.h"
#include "WalkingState.h"
#include "JumpingState.h"
#include "CrouchingState.h"
#include "AttackingState.h"
#include "ThrowingState.h"

#include "Constants.h"
class StateGameObject : public GameObject
{
protected:
	StateGameObject();

	State * idleState;
	State * walkingState;
	State * crouchingState;
	State * jumpingState;
	State * attackingState;
	State * throwingState;

	State * state;

	bool isGrounded = false;
	bool isCrouching = false;
	//Vector chứa các animations
	vector<Animation *> animations;
	DWORD lastFrameTime;
public:
	virtual void LoadResources() = 0;
	//Hàm set
	void SetIsGrounded(bool isGrounded) { this->isGrounded = isGrounded; }
	void SetIsCrouching(bool isCrouching) { this->isCrouching = isCrouching; }
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
	void SetState(State * state);
	//Hàm get

	DWORD GetLastFrameTime() { return this->lastFrameTime; }

	State * GetIdleState();
	State * GetWalkingState();
	State * GetAttackingState();
	State * GetThrowingState();
	State * GetCrouchingState();
	State * GetJumpingState();

	virtual int GetIdleAnimID() { return NULL; };
	virtual int GetWalkAnimID() { return NULL; };
	virtual int GetJumpAnimID() { return NULL; };
	virtual int GetCrouchAnimID() { return NULL; };
	virtual int GetStandAttackAnimID() { return NULL; };
	virtual int GetCrouchAttackAnimID() { return NULL; };


	virtual float GetDefaultWalkSpeed() = 0;
	virtual float GetDefautJumpSpeed() = 0;

	//Hàm trạng thái
	bool IsAttacking() { return state == attackingState || state == throwingState; }
	bool IsGrounded() { return isGrounded; }
	bool IsCrouching() { return isCrouching; }
	bool IsLeft() { return isLeft; }
	bool IsFlipped() { isFlipped = isLeft ? true : false; return isFlipped; }

	vector<Animation *> GetAnimationsList() { return animations; }
	//Các hàm hành động nhân vật
	void Idle();
	void Attack();
	void Walk();
	void Throw();
	void Jump();
	void Crouch();

	void TurnLeft();
	void TurnRight();
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};

