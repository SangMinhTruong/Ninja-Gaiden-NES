#include "State.h"
#include "StateGameObject.h"
#include "Game.h"

void UpdateYellowBird(DWORD dt, StateGameObject * gameObject);
void UpdateBat(DWORD dt, StateGameObject * gameObject);
void UpdateZombie(DWORD dt, StateGameObject * gameObject);
void UpdateMachineGunner(DWORD dt, StateGameObject * gameObject);
void UpdateCannonShooter(DWORD dt, StateGameObject * gameObject);
#include "Boss.h"
void State::Update(DWORD dt)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	vector<Tile *> tiles = Grid::GetInstance()->GetCurTiles();
	vector<GameObject *> coObjects = Grid::GetInstance()->GetCurGameObjects();



	if (Ninja::GetInstance()->IsAttacking())
		coObjects.push_back(Ninja::GetInstance()->GetWhip());

	vector<Subweapon *>subweapons = Ninja::GetInstance()->GetSubweapon();
	if (subweapons.size() > 0)
		coObjects.insert(coObjects.end(), subweapons.begin(), subweapons.end());

	gameObject->SetSpeedY(gameObject->GetSpeedY() - NINJA_GRAVITY);


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
	case GAME_OBJ_ID_MACHINE_GUNNER: // Machine Gunner
	{
		UpdateMachineGunner(dt, gameObject);
		break;
	}
	case GAME_OBJ_ID_CANNON_SHOOTER: // Cannon Shooter
	{
		UpdateCannonShooter(dt, gameObject);
		break;
	}
	}
	coEvents.clear();
	gameObject->SetDt(dt);
	gameObject->CalcPotentialCollisions(tiles, coObjects, coEvents);

	if (coEvents.size() == 0)
	{
		int moveX = 0;
		int moveY = 0;
		if (gameObject->GetID() == GAME_OBJ_ID_BAT)
		{
			moveX = gameObject->GetPositionX() + trunc(gameObject->GetSpeedX()* dt);
			moveY = 25 * cos(moveX * 2 * 3.14 * 30) + gameObject->GetInitPosY();
		}
		else if (gameObject->GetID() == GAME_OBJ_ID_BOSS)
		{
			if (Game::GetInstance()->GetInformation().EnemyHP > 0)
			{

				if (Boss * boss = dynamic_cast<Boss *>(gameObject))
				{
					if (boss->GetJumpTimer() >= 1000)
					{
						moveX = boss->GetPositionX() + trunc(0.25f * dt * (boss->IsJumpingLeft() ? -1 : 1));
						moveY = (int)(-0.015f * moveX * moveX + 3.36f * moveX - 12.16f);

						gameObject->SetPositionX(moveX);
						gameObject->SetPositionY(moveY);

						if (boss->GetAttackTimer() >= 3)
						{
							boss->CreateThrownWeapon(boss->GetPositionX() + 10, boss->GetPositionY() - 15);
							boss->CreateThrownWeapon(boss->GetPositionX() + 10, boss->GetPositionY() - 30);
							boss->CreateThrownWeapon(boss->GetPositionX() + 10, boss->GetPositionY() - 45);

							boss->ResetAttackTimer();
						}
						boss->SetIsGrounded(false);
						boss->SetState(boss->GetJumpingState());
					}
					else
					{
						boss->AddJumpTimer(dt);
						if (!boss->IsGrounded()) {
							GameSound::GetInstance()->Play(IDSound::BOSS_JUMP);
							boss->SetIsGrounded(true);
						}
						boss->SetState(boss->GetIdleState());
						return;
					}
					if ((boss->GetPositionX() <= 32 || boss->GetPositionX() >= 192))
					{
						boss->AddAttackTimer(1);

						moveX = gameObject->IsJumpingLeft() ? 32 : 192;
						moveY = (int)(-0.015f * moveX * moveX + 3.36f * moveX - 12.16f);

						gameObject->SetPositionX(moveX);
						gameObject->SetPositionY(moveY);

						boss->ResetJumpTimer();
						boss->SetIsLeft(!boss->IsLeft());
						boss->SetIsJumpingLeft(!boss->IsJumpingLeft());
					}
				}
			}
			else
			{
				//Tránh boss bị rơi ?!
				moveX = gameObject->GetPositionX();
				moveY = gameObject->GetPositionY();
				gameObject->SetSpeedX(0);
				gameObject->SetSpeedY(NINJA_GRAVITY);
			}

		}
		else
		{
			moveX = gameObject->GetPositionX() + trunc(gameObject->GetSpeedX()* dt);
			moveY = gameObject->GetPositionY() + trunc(gameObject->GetSpeedY()* dt);
		}

		gameObject->SetPositionX(moveX);
		gameObject->SetPositionY(moveY);

		if (trunc(gameObject->GetSpeedY()* dt) < 0)
		{
			gameObject->SetIsGrounded(false);
			if (gameObject->GetID() == GAME_OBJ_ID_NINJA && !gameObject->IsClimbing() && !gameObject->IsAttacking() && !gameObject->IsHurt())
				gameObject->SetState(gameObject->GetJumpingState());
		}
	}
	else
	{
		float min_tx, min_ty, nx, ny;

		gameObject->FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		if (coEventsResult[0]->collisionID == 2) // Kiểm tra quái va chạm vũ khí
		{
			if (gameObject->GetID() == GAME_OBJ_ID_BOSS)
			{
				if (Game::GetInstance()->GetInformation().EnemyHP <= 0) {
					Explosion::CreateExplosions(gameObject->GetPositionX(), gameObject->GetPositionY());

					//gameObject->SetState(gameObject->GetIdleState());
					GameSound::GetInstance()->Play(IDSound::BOSS_DESTROYED);
					Game::GetInstance()->GameWon();
				}
				else if (!gameObject->IsInvincible())
				{
					gameObject->SetIsInvincible(true);
					gameObject->ResetInvincibleTimer();
					Game::GetInstance()->LoseBossHP(1);
				}
			}
			else
			{
				GameSound::GetInstance()->Play(IDSound::ENEMYDESTROYED);
				gameObject->SetState(gameObject->GetDyingState());
				Game::GetInstance()->GainPoint(100);
			}
			return;
		}
		else if (coEventsResult[0]->collisionID == 3) // Kiểm tra ninja va chạm quái
		{
			if (gameObject->GetID() == GAME_OBJ_ID_NINJA)
			{
				GameSound::GetInstance()->Play(IDSound::NINJA_HURT);
				Game::GetInstance()->LoseNinjaHP(1);
				gameObject->Hurt();
			}
		}
		else if (coEventsResult[0]->collisionID == 1) // Kiểm tra chạm đất
		{
			if (ny == 1)
			{
				gameObject->SetIsGrounded(true);

				if (gameObject->IsClimbing() || gameObject->IsSticking())
				{
					gameObject->SetIsClimbing(false);
					gameObject->SetIsSticking(false);

					gameObject->SetSpeedY(0);
					gameObject->SetState(gameObject->GetIdleState());
				}
			}
		}
		else if (coEventsResult[0]->collisionID == 4) // Kiểm tra leo tường
		{
			vector<Tile *> tiles = Grid::GetInstance()->GetCurTiles();
			for (int i = 0; i < tiles.size(); i++)
			{
				if (tiles[i]->tileId == 21)
				{
					gameObject->SetUpperClimbingLimit(tiles[i]->y);
					break;
				}
			}
			if (nx == -1)
				gameObject->SetIsLeft(false);
			else if (nx == 1)
				gameObject->SetIsLeft(true);

			gameObject->SetIsClimbing(true);
			gameObject->Climb();
			return;
		}
		else if (coEventsResult[0]->collisionID == 5) // Kiểm tra bám tường
		{
			if (nx == -1)
				gameObject->SetIsLeft(false);
			else if (nx == 1)
				gameObject->SetIsLeft(true);

			gameObject->SetIsSticking(true);
			gameObject->Climb();
			return;
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

	if ((gameObject->GetPositionY() < 0 ||
		gameObject->GetPositionX() < 0 ||
		gameObject->GetPositionY() > 256) &&
		gameObject->GetID() != GAME_OBJ_ID_NINJA)
	{
		gameObject->Reset();
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

	float vx = gameObject->GetSpeedX() + (Ninja::GetInstance()->GetPositionX() - gameObject->GetPositionX()) / 20000;
	float vy = (Ninja::GetInstance()->GetPositionY() - gameObject->GetPositionY() - 15) / 500;
	if (abs(vx) >= 0.2f)
	{
		vx = ((float)SIGN(vx)) * 0.2f;
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
	i = rand();

	if (i % 100 < 2)
	{
		gameObject->Throw();
	}


}
#include "MachineGunner.h"
void UpdateMachineGunner(DWORD dt, StateGameObject * gameObject)
{
	//Di chuyển theo hướng ninja
	Ninja * ninja = Ninja::GetInstance();
	if ((ninja->GetPositionX() - gameObject->GetPositionX()) > 10)
		gameObject->SetIsLeft(false);
	else if ((ninja->GetPositionX() - gameObject->GetPositionX()) < -10)
		gameObject->SetIsLeft(true);

	//gameObject->SetPositionX(gameObject->GetPositionX() + vx * dt);
	//gameObject->SetPositionY(gameObject->GetPositionY() + vy * dt);
	if (MachineGunner * gunner = dynamic_cast<MachineGunner *>(gameObject))
	{
		gunner->SetAttackTimer(gunner->GetAttackTimer() + dt);
		if (gunner->GetAttackTimer() >= 3000 &&
			gunner->GetAttackTimer() < 3150)
		{
			gunner->SetSpeedX(0);
			gunner->Throw();
		}
		else if (gunner->GetAttackTimer() >= 3150 &&
			gunner->GetAttackTimer() < 3300)
		{
			gunner->SetSpeedX(0);
			gunner->Throw();
		}
		else if (gunner->GetAttackTimer() >= 3300)
		{
			gunner->SetSpeedX(0);
			gunner->Throw();
			gunner->SetAttackTimer(0);
		}
	}

}
#include "CannonShooter.h"
void UpdateCannonShooter(DWORD dt, StateGameObject * gameObject)
{
	//Di chuyển theo hướng ninja
	Ninja * ninja = Ninja::GetInstance();
	if ((ninja->GetPositionX() - gameObject->GetPositionX()) > 10)
		gameObject->SetIsLeft(false);
	else if ((ninja->GetPositionX() - gameObject->GetPositionX()) < -10)
		gameObject->SetIsLeft(true);

	//gameObject->SetPositionX(gameObject->GetPositionX() + vx * dt);
	//gameObject->SetPositionY(gameObject->GetPositionY() + vy * dt);
	if (CannonShooter * gunner = dynamic_cast<CannonShooter *>(gameObject))
	{
		gunner->SetAttackTimer(gunner->GetAttackTimer() + dt);
		if (gunner->GetAttackTimer() >= 2000)
		{
			gunner->SetSpeedX(0);
			gunner->Throw();
			gunner->SetAttackTimer(0);
		}
	}
}