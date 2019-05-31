#pragma once
#include "GameObject.h"
#include "Constants.h"

class ItemDrop : public GameObject
{
protected:
	vector<Animation *> animations;
	int type;
public:
	ItemDrop() { }
	ItemDrop(int x, int y, int type);
	void LoadResources();

	//Hàm cập nhật
	void Update(DWORD dt);
	//Hàm render
	void Render();
};

