#pragma once
#include "State.h"
#include "StateGameObject.h"
class IdleState : public State
{
public:
	IdleState(StateGameObject * gameObject);
	void Idle();
	void Attack();
	void Walk();
	void Throw();
	void Jump();
	void Crouch();
	void Hurt();
	void Update(DWORD dt);
	void Render();
};

