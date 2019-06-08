#pragma once
#include"Animation.h"
#include"Constants.h"
#include"Graphics.h"
#include"Debug.h"
#include"Sound.h"
struct SceneComponent {
	bool isActive = false;
	Sprite *sprite;
	int initX = 0;
	int initY = 0;
	bool Persistent = false;
	float currentX = 0;
	float currentY = 0;
	int destinationX;
	int destinationY;
	float scaleX = 1;
	float scaleY = 1;
	bool isMoving = false;
	bool isFadingIn = false;
	bool isFadingOut = false;
	bool isFadingInRedOpt = false;
	bool isFadingInGreenBlueOpt = false;
	float colorOffset = 255;
	DWORD moveTime;
	DWORD fadeInTime;
	DWORD fadeOutTime;
	DWORD accumulatedMoveTime = 0;
	DWORD accumulatedFadeInTime = 0;
	DWORD accumulatedFadeOutTime = 0;

	void Reset() {
		if (Persistent)
			return;
		accumulatedMoveTime = 0;
		accumulatedFadeInTime = 0;
		accumulatedFadeOutTime = 0;
		isFadingInGreenBlueOpt = false;
		isFadingInRedOpt = false;

		currentX = 0;
		currentY = 0;

		colorOffset = 255;
		isMoving = false;
		isFadingIn = false;
		isFadingOut = false;
		isActive = false;
	}

	void Update(DWORD dt) {
		if (!isActive) return;
		if (isMoving)
			accumulatedMoveTime += dt;
		if (isFadingIn)
			accumulatedFadeInTime += dt;
		if (isFadingOut)
			accumulatedFadeOutTime += dt;


		//Di chuyển theo dòng thời gian 
		if (accumulatedMoveTime <= moveTime && isMoving) {

			//Nếu đủ thời gian di chuyển thì ngừng
			currentX += float(dt) / moveTime * float(destinationX - initX);
			currentY += float(dt) / moveTime * float(destinationY - initY);
		}
		else if (currentX != destinationX || currentY != destinationY) {
			currentX = destinationX;
			currentY = destinationY;
		}

		//Hiệu ứng Fade in
		if ((accumulatedFadeInTime <= fadeInTime) && isFadingIn) {
			colorOffset += float(dt) / fadeInTime * float(255);
			if (colorOffset > 255)
				colorOffset = 255;
		}

		//Hiệu ứng Fade out
		if (accumulatedFadeOutTime <= fadeOutTime && isFadingOut) {
			colorOffset -= float(dt) / fadeOutTime * float(255);
			if (colorOffset < 0) {
				colorOffset = 0;
				isActive = false;
			}
		}


	}

	void Render() {
		if (!isActive) return;
		LPD3DXSPRITE spriteHandler = Graphics::GetInstance()->GetSpriteHandler();

		D3DXMATRIX matrix;
		D3DXMatrixIdentity(&matrix);

		D3DXMatrixScaling(&matrix, scaleX, scaleY, .0f);

		spriteHandler->SetTransform(&matrix);
		D3DCOLOR blendColor;
		if (isFadingInRedOpt)
			blendColor = D3DCOLOR_XRGB(255, int(colorOffset), int(colorOffset));
		else if (isFadingInGreenBlueOpt)
			blendColor = D3DCOLOR_XRGB(int(colorOffset), 255, 255);
		else
			blendColor = D3DCOLOR_XRGB(int(colorOffset), int(colorOffset), int(colorOffset));
		HRESULT result = spriteHandler->Draw(sprite->GetTexture(),
			&sprite->GetRect(),
			NULL,
			new D3DXVECTOR3((currentX)*(1 / scaleX),
			(currentY)*(1 / scaleY), 0),
			blendColor);
	}
};

class ExtraScene {
private:
	ExtraScene() {};
	static ExtraScene * __instance;
	int currentScene;
	bool active = true;
	DWORD sceneTimer = 0;
	SceneComponent Ninja;
	SceneComponent NinjaText;
	SceneComponent Actiii;
	SceneComponent Gaiden;
	SceneComponent Present;
	SceneComponent Pushstart;
	SceneComponent techmoLogo;
	SceneComponent gameOver;

	GameSound *sound;


public:
	static ExtraScene * GetInstance();

	void LoadResources();

	void TECHOMOSCENESETUP();
	void PUSHSTARTSCENESETUP();
	void ACTIIISCENESETUP();
	void GAMEOVERSCENESETUP();

	void TECHOMOSCENEUPDATE(DWORD dt);
	void PUSHSTARTSCENEUPDATE(DWORD dt);
	void ACTIIISCENEUPDATE(DWORD dt);
	void GAMEOVERSCENEUPDATE(DWORD dt);

	void ChangeScene();

	//Debug
	void ChangeScene(int id);


	void Update(DWORD dt);

	void ResetComponents();

	bool IsActive() { return active; }

	void Active() { active = true; }

	void Render();

};