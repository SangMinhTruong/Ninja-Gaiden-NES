#pragma once
#include "State.h"
#include "StateGameObject.h"

class CrouchingState : public State
{
public:
	CrouchingState(StateGameObject * gameObject);
	void Idle();
	void Attack();
	void Walk();
	void Throw();
	void Jump();
	void Crouch();
	void Update(DWORD dt);
	void Render();
};