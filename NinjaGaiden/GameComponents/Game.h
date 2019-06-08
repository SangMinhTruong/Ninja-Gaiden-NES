#pragma once
#include "Constants.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "UI.h"
#include "Ninja.h"
#include "TiledMap.h"
#include "Grid.h" 
#include "Sound.h"
#include "ExtraScene.h"

#include <chrono>
class Graphics;
class Keyboard;
class Grid;
class UI;

struct GameInformation {
	DWORD Score;
	DWORD Timer;
	DWORD previousTimer;
	DWORD NinjaHP;
	DWORD EnemyHP;
	std::string Stage;
	DWORD LiveCount;
	DWORD SpiritPoint;
	DWORD currentItem;
	DWORD frozenTimer;

	void ResetInfo()
	{
		Score = 0;
		Timer = 145000;
		NinjaHP = 16;
		EnemyHP = 16;
		Stage = "3-1";
		currentItem = -1;
		LiveCount = 2;
		SpiritPoint = 0;
		previousTimer = Timer;
	}
};

class Game
{
	bool initialized = false;

	bool isMapLoaded = false;
	bool isChangingMap = false;
	int curMapID = 0;
	DWORD changingMapTimer = 0;

	bool isDying = false;
	bool isGameOver = false;
	DWORD dyingTimer = 0;
	int gameOverColor = 0;

	bool isWinning = false;
	DWORD winningTimer = 0;

	static Game * __instance;
	static HINSTANCE hInstance;
	HWND hWnd;									//Xử lí cửa sổ

	Keyboard * keyboard;
	Graphics * graphics;
	UI * ui;
	GameInformation gameInfo;

	GameSound *gameSound;

	Ninja * ninja;
	Viewport * viewport;
	Grid * grid;

	ExtraScene *extraScene;
public:
	//Khởi tạo game chính
	void Init();
	HWND CreateGameWindow(HINSTANCE hInstance, int ScreenWidth, int ScreenHeight);
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void LoadResources();
	void ChangeMap(int id);
	void GameOver();
	void NinjaDies();
	void GameWon();
	//Xử lí
	void GainPoint(DWORD score) { gameInfo.Score += score; }
	void CountDownTimer(DWORD dt) { gameInfo.Timer > dt ? gameInfo.Timer -= dt : gameInfo.Timer = 0; }
	void GainNinjaHP(DWORD amount) { if (gameInfo.NinjaHP + amount >= 16) gameInfo.NinjaHP = 16; else gameInfo.NinjaHP += amount; }
	void LoseNinjaHP(DWORD amount) { if (gameInfo.NinjaHP - amount <= 0) gameInfo.NinjaHP = 0; else gameInfo.NinjaHP -= amount; }
	void LoseBossHP(DWORD amount) { if (gameInfo.EnemyHP - amount <= 0) gameInfo.EnemyHP = 0; else gameInfo.EnemyHP -= amount; }
	void LoseSpirit(DWORD amount) { gameInfo.SpiritPoint -= amount; }
	void GainSpirit(DWORD amount) { gameInfo.SpiritPoint += amount; }
	void FreezeTimer() { gameInfo.frozenTimer = 5; gameInfo.previousTimer = gameInfo.Timer; }

	void UpdateItem() { gameInfo.currentItem = ninja->GetCurrentSubweapon(); }


	void ResetGrid();

	void Update(DWORD dt);
	void Render();
	int Run();

	static float SweptAABB(Collider c1, Collider c2, float &normalx, float &normaly);
	//Lấy đối tượng
	GameInformation GetInformation() { return gameInfo; }
	Ninja * GetNinja();
	static Game * GetInstance();

	bool IsFrozenTime() { return gameInfo.frozenTimer; }


	//Hàm hủy đối tượng
	~Game();
};


