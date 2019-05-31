#pragma once
#include "GameObject.h"

#include "IdleState.h"
#include "WalkingState.h"
#include "JumpingState.h"
#include "CrouchingState.h"
#include "ClimbingState.h"
#include "AttackingState.h"
#include "ThrowingState.h"
#include "HurtState.h"
#include "DyingState.h"

#include "Constants.h"
class StateGameObject : public GameObject
{
protected:
	StateGameObject();

	State * idleState;
	State * walkingState;
	State * crouchingState;
	State * jumpingState;
	State * climbingState;
	State * attackingState;
	State * throwingState;
	State * hurtState;
	State * dyingState;

	State * state;
	
	//Bất tử
	bool isInvincible = false;
	DWORD invincibleTimer = 0;

	bool isUp = false;
	bool isJumpingLeft = false;
	bool isSticking = false;
	bool isClimbing = false;
	bool isGrounded = false;
	bool isCrouching = false;
	bool isHurt = false;
	//Vector chứa các animations
	vector<Animation *> animations;
	DWORD lastFrameTime;
public:
	virtual void LoadResources() = 0;
	//Hàm set
	void Reset() override;

	void ResetInvincibleTimer() { this->invincibleTimer = 0;}
	void AddInvincibleTimer(DWORD dt) { this->invincibleTimer += dt; }

	void SetIsInvincible(bool isInvincible) { this->isInvincible = isInvincible; }
	void SetIsHurt(bool isHurt) { this->isHurt = isHurt; }
	void SetIsSticking(bool isSticking) { this->isSticking = isSticking; }
	void SetIsClimbing(bool isClimbing) { this->isClimbing = isClimbing; }
	void SetIsJumpingLeft(bool isJumpingLeft) { this->isJumpingLeft = isJumpingLeft; }
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
	State * GetClimbingState();
	State * GetCrouchingState();
	State * GetJumpingState();
	State * GetHurtState();
	State * GetDyingState();

	virtual int GetIdleAnimID() { return NULL; };
	virtual int GetWalkAnimID() { return NULL; };
	virtual int GetClimbAnimID() { return NULL; };
	virtual int GetJumpAnimID() { return NULL; };
	virtual int GetCrouchAnimID() { return NULL; };
	virtual int GetStandAttackAnimID() { return NULL; };
	virtual int GetCrouchAttackAnimID() { return NULL; };
	virtual int GetHurtAnimID() { return NULL; };
	virtual int GetDyingAnimID() { return NULL; };


	virtual float GetDefaultWalkSpeed() = 0;
	virtual float GetDefautJumpSpeed() = 0;
	virtual float GetDefaultClimbingSpeed() { return NULL; };

	//Hàm trạng thái
	bool IsAttacking() { return state == attackingState || state == throwingState; }
	bool IsInvincible() { return isInvincible; }
	bool IsHurt() { return isHurt; }
	bool IsSticking() { return isSticking; }
	bool IsClimbing() { return isClimbing; }
	bool IsJumpingLeft() { return isJumpingLeft; }
	bool IsGrounded() { return isGrounded; }
	bool IsCrouching() { return isCrouching; }
	bool IsUp() { return isUp; }
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
	void Hurt();
	void Climb();

	virtual void CreateThrownWeapon() {}

	void TurnLeft();
	void TurnRight();

	void HeadUp();
	void HeadDown();
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};

