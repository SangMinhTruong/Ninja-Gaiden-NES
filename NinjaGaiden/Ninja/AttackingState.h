#pragma once
#include "State.h"
#include "StateGameObject.h"

class AttackingState : public State
{
public:
	AttackingState(StateGameObject * gameObject);
	void Idle();
	void Attack();
	void Walk();
	void Climb();
	void Throw();
	void Jump();
	void Crouch();
	void Hurt();
	void Update(DWORD dt);
	void Render();
};
