#pragma once
#include "State.h"
#include "StateGameObject.h"

class ThrowingState : public State
{
public:
	ThrowingState(StateGameObject * gameObject);
	void Idle();
	void Attack();
	void Walk();
	void Throw();
	void Jump();
	void Crouch();
	void Update(DWORD dt);
	void Render();
};


