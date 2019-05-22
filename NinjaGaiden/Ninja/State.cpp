#include "State.h"
#include "StateGameObject.h"
#include "Game.h"

void UpdateYellowBird(DWORD dt, StateGameObject * gameObject);
void UpdateBat(DWORD dt, StateGameObject * gameObject);
void UpdateZombie(DWORD dt, StateGameObject * gameObject);

void State::Update(DWORD dt)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	vector<Tile *> tiles = Grid::GetInstance()->GetCurTiles();
	vector<GameObject *> coObjects = Grid::GetInstance()->GetCurGameObjects();


	int id = gameObject->GetID();

	if (Ninja::GetInstance()->IsAttacking())
		coObjects.push_back(Ninja::GetInstance()->GetWhip());

	gameObject->SetSpeedY(gameObject->GetSpeedY() - NINJA_GRAVITY);

	coEvents.clear();
	gameObject->SetDt(dt);
	gameObject->CalcPotentialCollisions(tiles, coObjects, coEvents);
	
	switch (gameObject->GetID())
	{
	case GAME_OBJ_ID_YELLOW_BIRD: // Yellow bird
	{
		UpdateYellowBird(dt, gameObject);
		break;
	}
	case GAME_OBJ_ID_ZOMBIE: // Zombie
	{
		UpdateZombie(dt, gameObject);
		break;
	}
	}

	if (coEvents.size() == 0)
	{
		int moveX = 0;
		int moveY = 0;
		if (gameObject->GetID() != GAME_OBJ_ID_BAT)
		{
			moveX = gameObject->GetPositionX() + trunc(gameObject->GetSpeedX()* dt);
			moveY = gameObject->GetPositionY() + trunc(gameObject->GetSpeedY()* dt);
		}
		else
		{
			moveX = gameObject->GetPositionX() + trunc(gameObject->GetSpeedX()* dt);
			moveY = 25 * cos(moveX * 2 * 3.14 * 30) + gameObject->GetInitPosY();
		}

		gameObject->SetPositionX(moveX);
		gameObject->SetPositionY(moveY);
	}
	else
	{
		float min_tx, min_ty, nx, ny;

		gameObject->FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		if (coEventsResult[0]->collisionID == 2) // Kiểm tra quái va chạm vũ khí
		{
			gameObject->SetState(gameObject->GetDyingState());
			return;
		}
		if (coEventsResult[0]->collisionID == 3) // Kiểm tra ninja va chạm quái
		{
			float vx = gameObject->GetDefaultWalkSpeed() * nx;
			float vy = gameObject->GetDefautJumpSpeed() / 1.25f;

			gameObject->SetSpeedY(vx);
			gameObject->SetSpeedY(vy);

			gameObject->SetIsGrounded(false);
			gameObject->SetIsHurt(true);
			gameObject->SetState(gameObject->GetHurtState());
			return;
		}
		if (coEventsResult[0]->collisionID == 1) // Kiểm tra chạm đất
		{
			if (ny == 1)
			{
				gameObject->SetIsGrounded(true);
			}
		}
		// Xử lí va chạm
		int moveX = min_tx * gameObject->GetSpeedX() * dt + nx * 0.4;
		int moveY = min_ty * gameObject->GetSpeedY() * dt + ny * 0.4;

		gameObject->SetPositionX((int)(gameObject->GetPositionX() + moveX));
		gameObject->SetPositionY((int)(gameObject->GetPositionY() + moveY));


		if (nx != 0) gameObject->SetSpeedX(0);
		if (ny != 0) gameObject->SetSpeedY(0);

	}
	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];

	if (gameObject->GetPositionY() < 0 ||
		gameObject->GetPositionX() < 0 ||
		gameObject->GetPositionY() > 256)
	{
		gameObject->Reset();
		Viewport::GetInstance()->ResetPosition();
	}
	/*vector<Subweapon *> subweapons = gameObject->GetSubweapon();
	if (subweapons.size() > 0)
	{
		for (int i = 0; i < subweapons.size(); i++)
		{
			if (subweapons[i]->GetSpeedX() > 0 && subweapons[i]->GetPositionX() > SCREEN_WIDTH - NINJA_SPRITE_WIDTH)
				subweapons.erase(subweapons.begin() + i);
			else if (subweapons[i]->GetSpeedX() < 0 && subweapons[i]->GetPositionX() < 0)
				subweapons.erase(subweapons.begin() + i);
		}
	}*/
}

void State::Render()
{

}

void UpdateYellowBird(DWORD dt, StateGameObject * gameObject)
{
	//Di chuyển theo hướng ninja
	Ninja * ninja = Ninja::GetInstance();
	if ((ninja->GetPositionX() - gameObject->GetPositionX()) > 10)
		gameObject->SetIsLeft(false);
	else if ((ninja->GetPositionX() - gameObject->GetPositionX()) < -10)
		gameObject->SetIsLeft(true);

	float vx = gameObject->GetSpeedX() + (Ninja::GetInstance()->GetPositionX() - gameObject->GetPositionX()) / 10000;
	float vy = (Ninja::GetInstance()->GetPositionY() - gameObject->GetPositionY() - 15) / 500;
	if (abs(vx) >= 0.3f)
	{
		vx = ((float)SIGN(vx)) * 0.3f;
	}

	gameObject->SetSpeedX(vx);
	gameObject->SetSpeedY(vy);

	//gameObject->SetPositionX(gameObject->GetPositionX() + vx * dt);
	//gameObject->SetPositionY(gameObject->GetPositionY() + vy * dt);
}
void UpdateBat(DWORD dt, StateGameObject * gameObject)
{
	float vx = gameObject->GetSpeedX();
	float vy = cos(vx);
	if (abs(vx) >= 0.3f)
	{
		vx = ((float)SIGN(vx)) * 0.3f;
	}

	gameObject->SetSpeedX(vx);
	gameObject->SetSpeedY(vy);
}
void UpdateZombie(DWORD dt, StateGameObject * gameObject)
{
	//Di chuyển theo hướng ninja
	Ninja * ninja = Ninja::GetInstance();
	if ((ninja->GetPositionX() - gameObject->GetPositionX()) > 10)
		gameObject->SetIsLeft(false);
	else if ((ninja->GetPositionX() - gameObject->GetPositionX()) < -10)
		gameObject->SetIsLeft(true);

	//Random di chuyen
	int i = rand();
	float vx = gameObject->GetSpeedX(), vy = gameObject->GetSpeedY();
	if (abs(vx) < gameObject->GetDefaultWalkSpeed())
	{
		if (i % 100 < 50)
			vx = -(gameObject->IsLeft() ? -1 : 1) * gameObject->GetDefaultWalkSpeed();
		else
			vx = (gameObject->IsLeft() ? -1 : 1)  * gameObject->GetDefaultWalkSpeed();
	}
	i = rand();
	if (abs(vx) > 0.05f)
	{
		if (i % 100 < 50)
			vx = -(gameObject->IsLeft() ? -1 : 1) * 0.05f;
		else
			vx = (gameObject->IsLeft() ? -1 : 1)  * 0.05f;
	}
	i = rand();
	if (i % 100 < 50)
		vx += -(gameObject->IsLeft() ? -1 : 1) * ZOMBIE_WALKING_ACCEL;
	else
		vx += (gameObject->IsLeft() ? -1 : 1)  * ZOMBIE_WALKING_ACCEL;

	gameObject->SetSpeedX(vx);
	gameObject->SetSpeedY(vy);

	//gameObject->SetPositionX(gameObject->GetPositionX() + vx * dt);
	//gameObject->SetPositionY(gameObject->GetPositionY() + vy * dt);
	//Random phong dao

	/*if (rand() % 80 == 10 && isAvailable) {
		isActivated = 2;
		isAvailable = false;
		CreateBullet();
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Update(dt);
	}*/
}