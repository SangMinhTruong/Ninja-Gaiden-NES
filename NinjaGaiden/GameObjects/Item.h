#pragma once
#include "GameObject.h"
#include "Constants.h"
#include "ItemDrop.h"

class Item : public GameObject
{
	vector<Animation *> animations;
	int type;

	int dropID;
public:
	Item() {}
	Item(int x, int y, int dropID);
	virtual void LoadResources();
	void ResetAnim();

	void SetPosition(float x, float y);
	void SetType(int type) { this->type = type; }
	void SetDropID(int id) { this->dropID = id; }

	ItemDrop * CreateItemDrop();
	//Hàm cập nhật
	void Update(DWORD dt);
	//Hàm render
	void Render();
	~Item();
};

