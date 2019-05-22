﻿#include "TiledMap.h"

TiledMap * TiledMap::__instance = NULL;
int TiledMap::mapID = 0;
TiledMap * TiledMap::GetInstance(int id)
{
	LPCWSTR filePath = NULL;
	
	if (id != NULL)
	{
		mapID = id;
		switch (id)
		{
		case TILED_MAP_ID_3_1:
			filePath = TILES_MATRIX_3_1;
			break;
		case TILED_MAP_ID_3_2:
			filePath = TILES_MATRIX_3_2;
			break;
		case TILED_MAP_ID_3_3:
			filePath = TILES_MATRIX_3_3;
			break;
		}
	}

	if (__instance == NULL || filePath != NULL)
	{
		if (__instance != NULL)
		{
			delete __instance;
		}
		__instance = new TiledMap(filePath);
	}
	return __instance;
}

void TiledMap::ChangeMap(int id)
{
	LPCWSTR filePath = NULL;

	mapID = id;
	switch (id)
	{
	case TILED_MAP_ID_3_1:
		filePath = TILES_MATRIX_3_1;
		break;
	case TILED_MAP_ID_3_2:
		filePath = TILES_MATRIX_3_2;
		break;
	case TILED_MAP_ID_3_3:
		filePath = TILES_MATRIX_3_3;
		break;
	}

	for (auto it = tileSet.begin(); it != tileSet.end(); it++)
	{
		if (it->second != NULL)
			delete it->second;
	}

	if (__instance != NULL)
	{
		delete __instance;
		__instance = NULL;
	}
	__instance = new TiledMap(filePath);
}
//-------------------
//Lấy dữ liệu đọc chuyển thành dòng trong ma trận
Row TiledMap::GetMatrixRow(int lineNum, string line, string delimiter)
{
	size_t pos = 0;
	string token;
	Row result = Row();
	int rowNum = 0;
	while ((pos = line.find(delimiter)) != string::npos)
	{
		token = line.substr(0, pos);

		Tile curTile;
		curTile.x = rowNum * TILES_WIDTH_PER_TILE;
		curTile.y = this->mapHeight - lineNum * TILES_HEIGHT_PER_TILE;
		curTile.tileId = stoi(token);

		switch (mapID)
		{
		case TILED_MAP_ID_3_1:
			if (find(_31SolidIds.begin(), _31SolidIds.end(), curTile.tileId) != _31SolidIds.end())
				curTile.type = 1;
			else
				curTile.type = 0;
			break;
		case TILED_MAP_ID_3_2:
			if (find(_32SolidIds.begin(), _32SolidIds.end(), curTile.tileId) != _32SolidIds.end())
				curTile.type = 1;
			else
				curTile.type = 0;
			break;
		case TILED_MAP_ID_3_3:
			//
			break;
		}
		

		result.push_back(curTile);
		line.erase(0, pos + delimiter.length());
		rowNum++;
	}

	return result;
}/*
void TiledMap::AddSolidTiles(int lineNum, string line, string delimiter)
{
	size_t pos = 0;
	string token;
	int rowNum = 0;
	while ((pos = line.find(delimiter)) != string::npos)
	{
		token = line.substr(0, pos);

		if (find(_31SolidIds.begin(), _31SolidIds.end(), stoi(token)) != _31SolidIds.end())
		{
			SolidTile tile = SolidTile();

			float x = rowNum * TILES_WIDTH_PER_TILE;
			float y = lineNum * TILES_HEIGHT_PER_TILE;
			tile = new GameObject(x, y, TILES_WIDTH_PER_TILE, TILES_HEIGHT_PER_TILE);

			this->solidTiles.push_back(tile);
		}
		line.erase(0, pos + delimiter.length());

		rowNum++;
	}
}*/
// -> stackoverflow.com => chuyển string thành wstring
std::wstring s2ws(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
//-------------------

TiledMap::TiledMap(LPCWSTR filePath)
{
	infoLocation = filePath;
	
	LoadMap(filePath);
}
void TiledMap::LoadMap(LPCWSTR filePath)
{
	string tilesLocation = LoadMatrix(filePath);

	std::wstring stemp = s2ws(tilesLocation);
	LPCWSTR wstrTilesLocation = stemp.c_str();
	LoadTileSet(wstrTilesLocation);
}
string TiledMap::LoadMatrix(LPCWSTR filePath)
{
	string tilesLocation;

	ifstream tilesInfo;
	DebugOut(L"filepath: %s\n", filePath);
	tilesInfo.open(filePath);
	this->mapWidth = 0;
	this->mapHeight = 0;

	if (tilesInfo.is_open())
	{
		//Đọc thông tin vị trí tileset
		getline(tilesInfo, tilesLocation);
		//Đọc thông tin vị trí grid tương ứng với map
		getline(tilesInfo, gridInfoLocation);
		//Đọc thông tin width, height của map
		string tmp;
		getline(tilesInfo, tmp);
		this->mapWidth = stoi(tmp);
		getline(tilesInfo, tmp);
		this->mapHeight = stoi(tmp);
		//Đọc map
		string line;
		Row matrixRow;

		this->matrix.clear();
		int lineNum = 0;
		while (getline(tilesInfo, line))
		{
			matrixRow = GetMatrixRow(lineNum, line, TILES_MATRIX_DELIMITER);
			//AddSolidTiles(lineNum, line, TILES_MATRIX_DELIMITER);

			this->matrix.push_back(matrixRow);

			lineNum++;
		}
		/*for (int i = 0; i < solidTiles.size(); i++)
		{
			solidTiles[i]->SetPositionY(this->mapHeight - solidTiles[i]->GetPositionY());
		}*/
		tilesInfo.close();
	}
	return tilesLocation;

}
void TiledMap::LoadTileSet(LPCWSTR tilesLocation)
{
	HRESULT result;
	//Thông tin tileset
	D3DXIMAGE_INFO info;
	//Lấy thông tin texture từ đường dẫn file
	result = D3DXGetImageInfoFromFile(tilesLocation, &info);
	//Kiểm tra lỗi khi lấy thông tin
	if (result != D3D_OK)
	{
		DebugOut(L"[ERROR] Load Map Tileset failed: %s\n", tilesLocation);
		return;
	}
	this->tileSetWidth = info.Width / TILES_WIDTH_PER_TILE;
	this->tileSetHeight = info.Height / TILES_HEIGHT_PER_TILE;

	tileSet[0] = NULL;
	for (int i = 0; i < this->tileSetWidth; i++)
	{
		RECT rect;
		rect.left = (i % this->tileSetWidth) * TILES_WIDTH_PER_TILE;
		rect.right = rect.left + TILES_WIDTH_PER_TILE;
		rect.top = (i / this->tileSetWidth) * TILES_HEIGHT_PER_TILE;
		rect.bottom = rect.top + TILES_HEIGHT_PER_TILE;

		Sprite * tileSprite = new Sprite(tilesLocation, rect, TILES_TRANSCOLOR);
		tileSet[i + 1] = tileSprite;
	}
}


TiledMap::~TiledMap()
{

}

int TiledMap::GetWidth()
{
	return mapWidth;
}
int TiledMap::GetHeight()
{
	return mapHeight;
}
int TiledMap::GetTileWidth()
{
	return this->tileSetWidth;
}
int TiledMap::GetTileHeight()
{
	return this->tileSetHeight;
}

void TiledMap::Update(DWORD dt)
{

}
void TiledMap::Render()
{
	for (int i = 0; i < matrix.size(); i++)
	{
		Row curRow = matrix[i];
		for (int j = 0; j < curRow.size(); j++)
		{
			if (curRow[j].tileId != 0)
			{
				SpriteData spriteData;
				spriteData.width = TILES_WIDTH_PER_TILE;
				spriteData.height = TILES_HEIGHT_PER_TILE;
				spriteData.x = j * TILES_WIDTH_PER_TILE;
				spriteData.y = (matrix.size() - i) * TILES_HEIGHT_PER_TILE;
				spriteData.scale = 1;
				spriteData.angle = 0;
				spriteData.isLeft = true;

				tileSet.at(curRow[j].tileId)->SetData(spriteData);
				Graphics::GetInstance()->Draw(tileSet.at(curRow[j].tileId));
			}
		}
	}
}
void TiledMap::RenderTile(Tile * curTile)
{
	SpriteData spriteData;
	spriteData.width = TILES_WIDTH_PER_TILE;
	spriteData.height = TILES_HEIGHT_PER_TILE;
	spriteData.x = curTile->x;
	spriteData.y = curTile->y;
	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = true;


	tileSet.at(curTile->tileId)->SetData(spriteData);
	Graphics::GetInstance()->Draw(tileSet.at(curTile->tileId));

}