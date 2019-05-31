#pragma once
#include "GameObject.h"
#include "Constants.h"

class Item : public GameObject
{
	vector<Animation *> animations;
	int type;
public:
	Item(int x, int y);
	void LoadResources();
	void ResetAnim();

	void SetPosition(float x, float y);
	void SetType(int type) { this->type = type; }
	//Hàm cập nhật
	void Update(DWORD dt);
	//Hàm render
	void Render();
	~Item();
};

