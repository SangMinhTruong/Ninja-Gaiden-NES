#pragma once
#include "Constants.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Animation.h"

class Explosion : public GameObject
{
private:
	Explosion();
	static Explosion * __instance;
	static unordered_map<GameObject *, int> explosionsList;

	//Vector chứa các animations
	vector<Animation *> animations;
	DWORD lastFrameTime;

	void LoadResources();
public:
	static Explosion * GetInstance();

	vector<Animation *> GetAnimationsList() { return animations; }
	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	
	void AddExplosion(GameObject * gameObject);
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render(SpriteData spriteData);
};

