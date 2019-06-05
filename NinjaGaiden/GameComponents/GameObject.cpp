#include "GameObject.h"
#include "Game.h"

GameObject::GameObject()
{
	x = y = 0;
	this->initX = x;
	this->initY = y;
	vx = vy = 0;
	isLeft = false;
	isFlipped = false;
	isActive = true;

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = 0;
	collider.height = 0;
}
GameObject::GameObject(float x, float y, float width, float height) 
{ 
	this->x = x; 
	this->y = y; 
	this->width = width;
	this->height = height;
	vx = vy = 0;
	isLeft = false;
	isFlipped = false;

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = width;
	collider.height = height;
}
LPCOLLISIONEVENT GameObject::SweptAABBEx(LPGAMEOBJECT coO)
{
	float t, nx, ny;

	t = Game::SweptAABB(
		this->collider,
		coO->GetCollider(),
		nx,
		ny
	);

	LPCOLLISIONEVENT e = new CollisionEvent(t, nx, ny, coO);
	return e;
}

bool AABB(const Collider &c1, const Collider &c2);
void GameObject::CalcPotentialGameObjectCollisions(
	vector<LPGAMEOBJECT> &coObjects, 
	vector<LPCOLLISIONEVENT> &coEvents)
{
	for (int i = 0; i < coObjects.size(); i++)
	{
		GameObject * curObject = coObjects[i];
		curObject->UpdateObjectCollider();

		if (curObject->GetID() == GAME_OBJ_ID_SWORD ||
			curObject->GetID() == GAME_OBJ_ID_SHURIKEN ||
			curObject->GetID() == GAME_OBJ_ID_WINDMILLSHURIKEN ||
			curObject->GetID() == GAME_OBJ_ID_FIREWHEEL)
		{	
			if (this->id != GAME_OBJ_ID_NINJA &&
				!IS_ITEM_DROP(this->id))
				if (AABB(this->collider, curObject->GetCollider()))
				{
					LPCOLLISIONEVENT e = new CollisionEvent();
					e->collisionID = 2;

					coEvents.push_back(e);
				}
		}
		else if (this->id == GAME_OBJ_ID_NINJA)
		{
			if (curObject->GetID() != GAME_OBJ_ID_ITEM &&
				!IS_ITEM_DROP(curObject->GetID()))
			{
				LPCOLLISIONEVENT e = SweptAABBEx(curObject);
				e->collisionID = 3;

				if (e->t >= 0 && e->t < 1.0f)
				{
					if (Ninja * ninja = dynamic_cast<Ninja *>(this))
					{
						if (!ninja->IsInvincible())
						{
							coEvents.push_back(e);
						}
						else
							delete e;
					}
				}
				else
				{
					delete e;
				}
			}
		}
	}
}
void GameObject::CalcPotentialMapCollisions(
	vector<Tile *> &tiles,
	vector<LPCOLLISIONEVENT> &coEvents)
{
	if (this->id != GAME_OBJ_ID_YELLOW_BIRD &&
		this->id != GAME_OBJ_ID_BAT &&
		this->id != GAME_OBJ_ID_BOSS)
	{
		LPGAMEOBJECT solidTileDummy = new GameObject(0, 0, 16, 16);
		for (int i = 0; i < tiles.size(); i++)
		{
			Tile * curTile = tiles[i];
			if (curTile->type == 1)
			{
				int id = this->id;
				solidTileDummy->SetPositionX(curTile->x);
				solidTileDummy->SetPositionY(curTile->y);
				solidTileDummy->UpdateTileCollider();

				LPCOLLISIONEVENT e = SweptAABBEx(solidTileDummy);
				e->collisionID = 1;

				if (e->t >= 0 && e->t < 1.0f)
				{
					if (TiledMap::GetInstance()->GetMapID() == TILED_MAP_ID_3_1)
					{
						if (e->ny == 1)
							coEvents.push_back(e);
						else
							delete e;
					}
					else
					{
						if (this->id == GAME_OBJ_ID_NINJA)
						{
							if (TiledMap::GetInstance()->GetMapID() == TILED_MAP_ID_3_2)
							{
								if (Ninja * ninja = dynamic_cast<Ninja *>(this))
								{
									TiledMap * tiledMap = TiledMap::GetInstance();
									vector<int> _32Climbables = tiledMap->Get32Climbables();
									vector<int> _32Stickables = tiledMap->Get32Stickables();
									if (find(_32Climbables.begin(), _32Climbables.end(), curTile->tileId) != _32Climbables.end() &&
										e->nx != 0 &&
										!ninja->IsHurt() &&
										!ninja->IsGrounded())
									{
										e->collisionID = 4;
									}
									else if (find(_32Stickables.begin(), _32Stickables.end(), curTile->tileId) != _32Stickables.end() &&
										e->nx != 0 &&
										!ninja->IsHurt() &&
										!ninja->IsGrounded())
									{
										e->collisionID = 5;
									}

									if ((ninja->IsClimbing() || ninja->IsSticking()) &&
										(curTile->tileId == 28 || curTile->tileId == 29))
									{
										delete e;
										return;
									}
								}
							}
						}
						if (e->ny != -1)
							coEvents.push_back(e);
						else
							delete e;
					}
				}
				else
				{
					delete e;
				}
			}
		}
	}
}

void GameObject::CalcPotentialCollisions(
	vector<Tile *> &tiles,
	vector<LPGAMEOBJECT> &coObjects,
	vector<LPCOLLISIONEVENT> &coEvents)
{
	this->UpdateObjectCollider();
	CalcPotentialMapCollisions(tiles, coEvents);
	CalcPotentialGameObjectCollisions(coObjects, coEvents);

	sort(coEvents.begin(), coEvents.end(), CollisionEvent::compare);
}

void GameObject::FilterCollision(
	vector<LPCOLLISIONEVENT> &coEvents,
	vector<LPCOLLISIONEVENT> &coEventsResult,
	float &min_tx, float &min_ty,
	float &nx, float &ny)
{
	min_tx = 1.0f;
	min_ty = 1.0f;
	int min_ix = -1;
	int min_iy = -1;

	nx = 0.0f;
	ny = 0.0f;

	coEventsResult.clear();

	for (UINT i = 0; i < coEvents.size(); i++)
	{
		LPCOLLISIONEVENT c = coEvents[i];

		if (c->collisionID == 2)
		{
			coEventsResult.push_back(coEvents[i]);
			return;
		}
		if (c->collisionID == 3)
		{
			coEventsResult.push_back(coEvents[i]);
			return;
		}

		if (c->t < min_tx && c->nx != 0) 
		{
			min_tx = c->t; nx = c->nx; min_ix = i;
		}

		if (c->t < min_ty  && c->ny != 0) 
		{
			min_ty = c->t; ny = c->ny; min_iy = i;
		}
	}

	if (min_ix >= 0) coEventsResult.push_back(coEvents[min_ix]);
	if (min_iy >= 0) coEventsResult.push_back(coEvents[min_iy]);
}


void GameObject::Reset()
{
	x = initX;
	y = initY;
	isActive = false;
}

GameObject::~GameObject()
{
}

//Hàm cập nhật
void GameObject::Update(DWORD dt)
{

}

void GameObject::UpdateObjectCollider()
{
	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.dt = dt;
}
void GameObject::UpdateTileCollider()
{
	collider.x = x;
	collider.y = y - 8;
	collider.vx = vx;
	collider.vy = vy;
	collider.dt = dt;
	collider.height = 8;
}
//Hàm render
void GameObject::Render()
{

}

RECT GameObject::GetRect()
{
	RECT rect;
	rect.top = y;
	rect.left = x;
	rect.right = x + width;
	rect.bottom = y - height;
	return rect;
}