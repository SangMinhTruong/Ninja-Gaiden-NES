﻿#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Constants.h" 
#include "Cell.h"
 
#include <vector>

#include"Sound.h"

#define POSTOCELL(K) (int)(K/GRID_SIZE);
#define POSXTOCELL(K) (int)(K/GRID_SIZE);
#define POSYTOCELL(K) (int)(K % GRID_SIZE == 0 ? K/GRID_SIZE - 1 : K/GRID_SIZE);


class Cell;

typedef vector<Cell *> CellRow;
typedef vector<CellRow> CellMatrix;
class Grid {
private:
	static Grid * __instance;
	int width, height;

	string gridInfoLocation;

	CellMatrix cells;

	vector<GameObject *> allGameObjects;

	vector<Tile *> curTiles;
	vector<GameObject *> curGameObjects;

	Viewport *viewport;
	Ninja * ninja;
	TiledMap * tiledMap;

	Grid();

	void LoadCells();
	void LoadObjects();
	void LoadMap();

public:

	static Grid * GetInstance();

	void AddObject(GameObject * gameObject);

	void GetCameraPosOnGrid(int &l, int &r, int &t, int &b);
	void GetNinjaPosOnGrid(int &l, int &r, int &t, int &b);

	vector<Tile *> GetCurTiles() { return this->curTiles; }
	vector<GameObject *> GetCurGameObjects() { return this->curGameObjects; }

	void ChangeMap(int id);

	void Update(DWORD dt);
	void Render();
	//void add(Unit * unit);
	////Cap nhat lai vi tri cua object trong grid
	//void update_unit(Unit * unit, double x, double y);
	////Cap nhat lai vi tri cua toan bo objects trong grid
	//void update();
	////Khoanh vung cac o trong viewport
	//void getCameraPosOnGrid(int &l, int &r, int &t, int &b);
	////Lay danh sach object trong viewport 
	//void getObjList(vector<GameObject*>*list);
	////Lay danh sach cac Unit trong viewport
	//void getUnitList(vector<Unit*>* list);
	////Xử lý các ô nằm trên viewport
	//void handleCells(void(*handler)(Unit*)) {};
	////Xử lý va chạm các objects trong viewport 
	//void colliOnCell(Unit *unit, Unit * other);
	//void detectCollision();

	~Grid() 
	{
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
			{
				if (cells[i][j] != NULL)
				{
					cells[i][j]->Clear();
					delete cells[i][j];
				}
			}
	}
};