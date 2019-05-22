#include "StateGameObject.h"


StateGameObject::StateGameObject()
{
	idleState = new IdleState(this);
	walkingState = new WalkingState(this);
	crouchingState = new CrouchingState(this);
	jumpingState = new JumpingState(this);
	attackingState = new AttackingState(this);
	throwingState = new ThrowingState(this);
	hurtState = new HurtState(this);
	dyingState = new DyingState(this);

	state = idleState;
}
void StateGameObject::SetState(State * state)
{
	this->state = state;
}
State * StateGameObject::GetIdleState()
{
	return idleState;
}
State * StateGameObject::GetWalkingState()
{
	return walkingState;
}
State * StateGameObject::GetAttackingState()
{
	return attackingState;
}
State * StateGameObject::GetThrowingState()
{
	return throwingState;
}
State * StateGameObject::GetCrouchingState()
{
	return crouchingState;
}
State * StateGameObject::GetJumpingState()
{
	return jumpingState;
}
State * StateGameObject::GetHurtState()
{
	return hurtState;
}
State * StateGameObject::GetDyingState()
{
	return dyingState;
}

void StateGameObject::Reset() 
{
	GameObject::Reset(); 
	this->SetIsHurt(false);
	this->SetState(this->GetIdleState());
}
//Các hàm hành động nhân vật
void StateGameObject::Idle()
{
	state->Idle();
}
void StateGameObject::Attack()
{
	state->Attack();
}
void StateGameObject::Walk()
{
	state->Walk();
}
void StateGameObject::Throw()
{
	state->Throw();
}
void StateGameObject::Jump()
{
	state->Jump();
}
void StateGameObject::Crouch()
{
	state->Crouch();
}
void StateGameObject::Hurt()
{
	state->Hurt();
}
void StateGameObject::TurnLeft()
{
	isLeft = true;
}
void StateGameObject::TurnRight()
{
	isLeft = false;
}
//Hàm cập nhật
void StateGameObject::Update(DWORD dt)
{
	state->Update(dt);
}
//Hàm render
void StateGameObject::Render()
{
	state->Render();
}