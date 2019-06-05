#pragma once


#include<string>
#include<vector>

#include"Sprite.h"
#include"Graphics.h"
#include"Constants.h"
#include"Game.h"
#include"Debug.h" 
 
class Game;

class UIUtility {

	int moveX = 0;
	int moveY = 0;
	UIUtility() {};
	static UIUtility *  __instance;
public:
	static UIUtility *getInstance() { if (!__instance) __instance = new UIUtility(); return __instance; };
	void ShiftRightX(int offset) { moveX += offset; DebugOut(L"MoveX = %d MoveY = %d \n", moveX, moveY); }
	void ShiftLeftX(int offset) { moveX -= offset; DebugOut(L"MoveX = %d MoveY = %d \n", moveX,  moveY);}
	void ShiftUpY(int offset) { moveY -= offset; DebugOut(L"MoveX = %d MoveY = %d \n", moveX, moveY); }
	void ShiftDownY(int offset) { moveY += offset; DebugOut(L"MoveX = %d MoveY = %d \n", moveX, moveY); }
	int getMoveX() { return moveX; }
	int getMoveY() { return moveY; }

};



class UI {
private:
	static UI*  _instance;

	UI() {};

	DWORD Score;
	DWORD Timer;
	DWORD NinjaHP;
	DWORD EnemyHP;
	std::string Stage;
	DWORD LiveCount;
	DWORD SpiritPoint;
	DWORD currentItem;

	std::vector<Sprite*> items;
	std::vector<Sprite *> HPs;
	std::vector<Sprite *> noHPs;
	Sprite *spirit;
	Sprite *itemFrame;
	std::string displayText;
	RECT displayRect;

	LPDIRECT3DDEVICE9 d3ddv;
	ID3DXFont *font;
public:
	~UI() {};
	static UI* GetInstance();
	void LoadResources();

	void Draw(Sprite* sprite, float scaleX, float scaleY, int offsetY = 0);

	//Hàm set
	void SetDirectDevice(LPDIRECT3DDEVICE9 device) { d3ddv = device; }

	//Cập nhật thay đổi của các chỉ số
	void Update(DWORD dt);

	//Hàm render
	void Render();
};