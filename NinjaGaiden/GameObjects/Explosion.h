#pragma once
#include "Constants.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Animation.h"
#include "Debug.h"

class Explosion : public GameObject
{
private:
	Explosion(int x, int y);
	static vector<Explosion*> explosions;
	static bool tickExplosion;
	//Vector chứa các animations
	Animation * animation;
	void LoadResources();
public:
	static void  CreateExplosions(int x, int y);

	//Hàm cập nhật
	void Update(DWORD dt) override;

	static void Reset() { explosions.clear(); }

	//Hàm render
	void UnitRender();
	static void Render();
};

