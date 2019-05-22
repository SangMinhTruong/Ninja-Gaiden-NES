#include "Cell.h"
#include "Grid.h"


void Cell::ExtractTiles(vector<Tile *> &output)
{
	output.insert(output.end(), this->tiles.begin(), this->tiles.end());
}

void Cell::ExtractGameObjects(vector<GameObject *> &output)
{
	output.insert(output.end(), this->gameObjects.begin(), this->gameObjects.end());
}

void Cell::Update(DWORD dt)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		int flagX = gameObjects[i]->GetPositionX();
		int flagY = gameObjects[i]->GetPositionY();
		gameObjects[i]->SetActive();
		gameObjects[i]->Update(dt);
	}
}
void Cell::RenderTiles()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		TiledMap::GetInstance()->RenderTile(tiles[i]);
	}
}

void Cell::RenderObjects()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Render();
	}
}
void Cell::Clear()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
}
Cell::~Cell()
{

}
