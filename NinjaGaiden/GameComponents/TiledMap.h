#pragma once

#include <d3dx9.h>
#include <d3d9.h>
#include <vector>
#include <unordered_map> 
#include <iostream>
#include <fstream>
#include <string>

#include "Sprite.h"
#include "Debug.h"
#include "Constants.h"
#include "GameObject.h"
using namespace std;


const vector<int> _31SolidIds{ 24, 25, 26, 39, 58, 63, 65,67, 68, 69, 70 };
const vector<int> _32SolidIds{ 8, 18, 19, 20, 21, 25, 26, 27, 28, 29, 30, 31, 32, 33, 38 };
const vector<int> _33SolidIds{ 2, 8, 9, 13, 17, 23, 25, 29, 36, 37, 38, 39, 40 };

const vector<int> _32ClimbableIds{ 21, 25, 38 };
const vector<int> _32StickableIds{ 8, 18, 20, 24, 26, 32, 33 };

struct Tile {
	int tileId;
	int type; // 0 = background, 1 = solid
	int x, y;
	int width = 16, height = 16;
};

typedef GameObject * SolidTile;

typedef vector<SolidTile> SolidTileSet;

typedef vector<Tile> Row;
typedef vector<Row> Matrix;

class TiledMap
{
private:
	static int mapID;
	static TiledMap * __instance;

	TiledMap(LPCWSTR filePath);

	void LoadMap(LPCWSTR filePath);
	string LoadMatrix(LPCWSTR filePath);
	void LoadTileSet(LPCWSTR tilesLocation);

	Row GetMatrixRow(int lineNum, string line, string delimiter);

	Matrix matrix;

	int mapWidth, mapHeight;
	int tileSetWidth, tileSetHeight;
	LPCWSTR infoLocation;
	string gridInfoLocation;

	unordered_map<int, Sprite *> tileSet;

public:
	static TiledMap * GetInstance(int id = 0);

	void ChangeMap(int id);

	int GetMapID() { return mapID; }

	int GetWidth();
	int GetHeight();
	int GetTileWidth();
	int GetTileHeight();

	vector<int> Get32Climbables() { return vector<int> { 21, 25, 38 }; }
	vector<int> Get32Stickables() { return vector<int> { 8, 18, 20, 24, 26, 32, 33 }; }

	string GetGridInfoLocation() { return gridInfoLocation; }

	Matrix & GetMatrix() { return matrix; }


	void Update(DWORD dt);
	void Render();

	void RenderTile(Tile * curTile);

	~TiledMap();
};