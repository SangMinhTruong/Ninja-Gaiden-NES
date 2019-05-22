#pragma once
#include "State.h"
#include "StateGameObject.h"

class DyingState : public State
{
public:
	DyingState(StateGameObject * gameObject);
	void Idle();
	void Attack();
	void Walk();
	void Throw();
	void Jump();
	void Crouch();
	void Update(DWORD dt);
	void Render();
};