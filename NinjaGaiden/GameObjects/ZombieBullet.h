#pragma once
#include "GameObject.h"
#include "Constants.h"

class Zombie;
class ZombieBullet : public GameObject
{
	vector<Animation *> animations;
	Zombie * zombie;
public:
	ZombieBullet(int x, int y, bool isLeft);

	void LoadResources();

	void SetZombie(Zombie * zombie) { this->zombie = zombie; }

	int GetWidth() { return ZOMBIE_BULLET_SPRITE_WIDTH; }
	int GetHeight() { return ZOMBIE_BULLET_SPRITE_HEIGHT; }
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
	~ZombieBullet();
};

