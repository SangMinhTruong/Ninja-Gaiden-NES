#pragma once
#include <vector>
#include "GameObject.h"
#include "TiledMap.h"

class Cell
{
private:
	vector<GameObject *> gameObjects;
	vector<Tile *> tiles;

	int iX;
	int iY;
public:
	Cell(int iX, int iY) { this->iX = iX; this->iY = iY; }

	void AddTile(Tile * tile) { this->tiles.push_back(tile); }
	void AddGameObject(GameObject * gameObject) { this->gameObjects.push_back(gameObject); }

	int GetPositionX() { return iX * GRID_SIZE; }
	int GetPositionY() { return (iY + 1) * GRID_SIZE; }

	void ExtractTiles(vector<Tile *> &output);
	void ExtractGameObjects(vector<GameObject *> &output);
	
	void FlushGameObjects() { this->gameObjects.clear(); }

	void Update(DWORD dt);
	void RenderTiles();
	void RenderObjects();
	~Cell();
};

