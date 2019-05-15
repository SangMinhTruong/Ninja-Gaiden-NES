﻿#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>
#include <algorithm>

#include "Sprite.h"
#include "Animation.h"

using namespace std;
struct Collider
{
	float x, y;
	float width, height;
	float vx = 0, vy = 0;
	float dt = 0;
};
class GameObject;
typedef GameObject * LPGAMEOBJECT;
struct CollisionEvent;
typedef CollisionEvent * LPCOLLISIONEVENT;
struct CollisionEvent
{
	int collisionID; 
	//0 = other objects
	//1 = tiles
	//.... <placeholder>
	LPGAMEOBJECT coO;
	float t, nx, ny;
	CollisionEvent(float t, float nx, float ny, LPGAMEOBJECT coO = NULL) { this->t = t; this->nx = nx; this->ny = ny; this->coO = coO; }

	static bool compare(const LPCOLLISIONEVENT &a, LPCOLLISIONEVENT &b)
	{
		return a->t < b->t;
	}
};

struct Tile;

typedef vector<Tile> Row;
typedef vector<Row> Matrix;

class GameObject
{

protected:
	int id;

	//Các giá trị vị trí, tốc độ, trạng thái
	float x;
	float y;

	int width;
	int height;

	float vx;
	float vy;

	float dt;

	bool isLeft;
	bool isFlipped;
	Collider collider;
public:
	//Hàm đặt vị trí
	void SetPositionX(float x) { this->x = x; }
	void SetPositionY(float y) { this->y = y; }
	//Hàm đặt tốc độ
	void SetSpeedX(float vx) { this->vx = vx; }
	void SetSpeedY(float vy) { this->vy = vy; }

	void SetDt(float dt) { this->dt = dt; }

	void SetCollider(Collider col) { this->collider = col; }

	void UpdateObjectCollider();
	void UpdateTileCollider();

	int GetID() { return id; }

	float GetPositionX() { return this->x; }
	float GetPositionY() { return this->y; }

	int GetWidth() { return this->width; }
	int GetHeight() { return this->height; }

	float GetSpeedX() { return this->vx; }
	float GetSpeedY() { return this->vy; }

	float GetDt() { return dt; }
	RECT GetRect();

	Collider GetCollider() { return this->collider; }
	LPCOLLISIONEVENT SweptAABBEx(LPGAMEOBJECT coO);

	void CalcPotentialGameObjectCollisions(
		vector<LPGAMEOBJECT> &coObjects, 
		vector<LPCOLLISIONEVENT> &coEvents);

	void CalcPotentialMapCollisions(
		vector<Tile *> &tiles,
		vector<LPCOLLISIONEVENT> &coEvents);

	void CalcPotentialCollisions(
		vector<Tile *> &tiles,
		vector<LPGAMEOBJECT> &coObjects, 
		vector<LPCOLLISIONEVENT> &coEvents);

	void FilterCollision(
		vector<LPCOLLISIONEVENT> &coEvents,
		vector<LPCOLLISIONEVENT> &coEventsResult,
		float &min_tx,
		float &min_ty,
		float &nx,
		float &ny);

	//Hàm khởi tạo
	GameObject();
	GameObject(float x, float y, float width, float height);
	//Hàm cập nhật
	virtual void Update(DWORD dt);
	//Hàm render
	virtual void Render();
	//Hàm hủy đối tượng
	~GameObject();
};

