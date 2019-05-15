#pragma once
#include "d3d9.h"

class StateGameObject;
class State
{
protected:
	StateGameObject * gameObject;
public:
	virtual void Idle() = 0;
	virtual void Attack() = 0;
	virtual void Walk() = 0;
	virtual void Throw() = 0;
	virtual void Jump() = 0;
	virtual void Crouch() = 0;
	virtual void Update(DWORD dt);
	virtual void Render();
};

