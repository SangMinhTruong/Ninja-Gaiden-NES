#include "State.h"
#include "StateGameObject.h"
#include "Game.h"

void State::Update(DWORD dt)
{
	vector<LPGAMEOBJECT> coObjects; //Placeholder
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	int flagX = gameObject->GetPositionX();
	int flagY = gameObject->GetPositionY();
	vector<Tile *> tiles = Grid::GetInstance()->GetCurTiles();

	gameObject->SetSpeedY(gameObject->GetSpeedY() - NINJA_GRAVITY);

	coEvents.clear();
	gameObject->SetDt(dt);
	gameObject->CalcPotentialCollisions(tiles, coObjects, coEvents);

	if (coEvents.size() == 0)
	{
		int moveX = trunc(gameObject->GetSpeedX()* dt);
		int moveY = trunc(gameObject->GetSpeedY()* dt);

		gameObject->SetPositionX(gameObject->GetPositionX() + moveX);
		gameObject->SetPositionY(gameObject->GetPositionY() + moveY);

	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		gameObject->FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		int moveX = min_tx * gameObject->GetSpeedX() * dt + nx * 0.4;
		int moveY = min_ty * gameObject->GetSpeedY() * dt + ny * 0.4;

		gameObject->SetPositionX((int)(gameObject->GetPositionX() + moveX));
		gameObject->SetPositionY((int)(gameObject->GetPositionY() + moveY));


		if (nx != 0) gameObject->SetSpeedX(0);
		if (ny != 0) gameObject->SetSpeedY(0);

		if (coEventsResult[0]->collisionID == 1)
		{
			if (ny == 1)
			{
				gameObject->SetIsGrounded(true);
			}
		}
	}
	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];


	DebugOut(L"X, Y: %d, %d\n", flagX, flagY);
	if (gameObject->GetPositionY() < 0)
	{
		gameObject->SetPositionX(100);
		gameObject->SetPositionY(100);
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