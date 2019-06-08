#include"ExtraScene.h"

ExtraScene * ExtraScene::__instance = NULL;

ExtraScene * ExtraScene::GetInstance() {
	if (__instance == NULL) {
		__instance = new ExtraScene;
		__instance->LoadResources();
	}
	return __instance;
}

void ExtraScene::LoadResources() {

	// 
	//Load Game Sound
	//

	sound = GameSound::GetInstance();


	//
	//Load các sprite
	//
	//Chữ ninja
	RECT r;
	SetRect(&r, 0, 0, 890, 218);
	NinjaText.sprite = new Sprite(EXTRA_SCENE_PATH_NINJA, r, EXTRA_SCENE_COMPONENT_TRANSCOLOR);

	//Chữ gaiden

	SetRect(&r, 0, 0, 796, 230);
	Gaiden.sprite = new Sprite(EXTRA_SCENE_PATH_GAIDEN, r, EXTRA_SCENE_COMPONENT_TRANSCOLOR);

	//Scene TechoLogo

	//Logo 
	SetRect(&r, 0, 0, 434, 70);
	techmoLogo.sprite = new Sprite(EXTRA_SCENE_PATH_TECMOLOGO, r, EXTRA_SCENE_COMPONENT_TRANSCOLOR);

	//Present 1989

	SetRect(&r, 0, 0, 479, 124);
	Present.sprite = new Sprite(EXTRA_SCENE_PATH_PRESENT, r, EXTRA_SCENE_COMPONENT_TRANSCOLOR);

	//Scene ActIII

	//Hình ninja
	SetRect(&r, 0, 0, 661, 389);
	Ninja.sprite = new Sprite(EXTRA_SCENE_PATH_BIGNINJA, r, EXTRA_SCENE_COMPONENT_TRANSCOLOR);

	//Act III
	SetRect(&r, 0, 0, 497, 117);
	Actiii.sprite = new Sprite(EXTRA_SCENE_PATH_ACTIII, r, EXTRA_SCENE_COMPONENT_TRANSCOLOR);

	//Scene PUSH START

	//Chữ push start
	SetRect(&r, 0, 0, 1480, 344);
	Pushstart.sprite = new Sprite(EXTRA_SCENE_PATH_PUSHSTART, r, EXTRA_SCENE_COMPONENT_TRANSCOLOR);


	//Scene GAMEOVER
	SetRect(&r, 0, 0, 569, 78);
	gameOver.sprite = new Sprite(EXTRA_SCENE_PATH_GAMEOVER, r, EXTRA_SCENE_COMPONENT_TRANSCOLOR);

	//Khởi tạo scene TECHOMO
	currentScene = -1;
	ChangeScene();

}

//Debug
// -->
void ExtraScene::ChangeScene(int id) {

	sound->Stop(IDSound::PRESS_START);
	sound->Stop(IDSound::ACTIII);
	sound->Stop(IDSound::STAGE_31);
	sound->Stop(IDSound::STAGE_32);
	sound->Stop(IDSound::STAGE_33);

	sceneTimer = 0;

	currentScene = id;


	ResetComponents();

	switch (currentScene) {
	case EXTRA_SCENE_ID_TECHMOLOGO: TECHOMOSCENESETUP();
		break;
	case EXTRA_SCENE_ID_PUSHSTART: PUSHSTARTSCENESETUP();
		break;
	case EXTRA_SCENE_ID_ACTIII: ACTIIISCENESETUP();
		break;
	case EXTRA_SCENE_ID_GAMEOVER: GAMEOVERSCENESETUP();
		break;
	default:
		break;
	}
}

void ExtraScene::ResetComponents() {

	NinjaText.Reset();
	Ninja.Reset();
	techmoLogo.Reset();
	Present.Reset();
	Gaiden.Reset();
	gameOver.Reset();
	Pushstart.Reset();
	Actiii.Reset();
}


void ExtraScene::TECHOMOSCENESETUP() {
	//Reset lại các component
	this->ResetComponents();

	//Scene này có Techmo logo và chữ present
	techmoLogo.isActive = true;
	Present.isActive = true;

	//Setup vị trí của techomo logo và chữ present
	techmoLogo.destinationX = 100;
	techmoLogo.destinationY = 100;

	techmoLogo.scaleX = 0.15f;
	techmoLogo.scaleY = 0.2f;

	techmoLogo.colorOffset = 0;
	techmoLogo.isFadingIn = true;
	techmoLogo.fadeInTime = 3000;


	Present.destinationX = 97;
	Present.destinationY = 120;
	Present.scaleX = 0.15f;
	Present.scaleY = 0.2f;

	Present.isFadingIn = true;
	Present.colorOffset = 0;
	Present.fadeInTime = 1500;
}

void ExtraScene::PUSHSTARTSCENESETUP() {
	if (!sound->isPlaying(IDSound::PRESS_START)) {
		sound->PlayLoop(IDSound::PRESS_START);
	}
	if (!NinjaText.isActive || !Gaiden.isActive || !Pushstart.isActive) {

		//Khởi tạo ninja text
		NinjaText.isActive = true;
		NinjaText.destinationX = 7;
		NinjaText.destinationY = 20;
		NinjaText.scaleX = 0.145f;
		NinjaText.scaleY = 0.3f;

		//Khởi tạo gaiden text


		Gaiden.isActive = true;

		Gaiden.destinationX = 140;
		Gaiden.destinationY = 20;
		Gaiden.scaleX = 0.145f;
		Gaiden.scaleY = 0.3f;

		//Khởi tạo chữ push start


		Pushstart.isActive = true;
		Pushstart.destinationX = 30;
		Pushstart.destinationY = 100;
		Pushstart.scaleX = 0.145f;
		Pushstart.scaleY = 0.3f;
	}
	else {
		NinjaText.Persistent = false;
		Gaiden.Persistent = false;
		Pushstart.Persistent = false;
	}

}

void ExtraScene::ACTIIISCENESETUP() {
	//Ở scene này thì Ninja lướt qua trái , Ninja Gaiden lướt qua phải và Act III hiện lên (Fade In)

	//Ninja

	Ninja.isActive = true;
	Ninja.initX = 300;
	Ninja.initY = 50;
	Ninja.currentX = Ninja.initX;
	Ninja.currentY = Ninja.initY;
	Ninja.scaleX = 0.145f;
	Ninja.scaleY = 0.25f;
	Ninja.destinationX = 20;
	Ninja.destinationY = 50;
	Ninja.isMoving = true;
	Ninja.moveTime = 1200;




}

void ExtraScene::Update(DWORD dt) {
	sceneTimer += dt;
	switch (currentScene) {
	case EXTRA_SCENE_ID_TECHMOLOGO: TECHOMOSCENEUPDATE(dt);
		break;
	case EXTRA_SCENE_ID_PUSHSTART: PUSHSTARTSCENEUPDATE(dt);
		break;
	case EXTRA_SCENE_ID_ACTIII: ACTIIISCENEUPDATE(dt);
		break;
	case EXTRA_SCENE_ID_GAMEOVER: GAMEOVERSCENEUPDATE(dt);
		break;
	default:
		break;
	}


	NinjaText.Update(dt);
	Ninja.Update(dt);
	techmoLogo.Update(dt);
	Present.Update(dt);
	Gaiden.Update(dt);
	gameOver.Update(dt);
	Pushstart.Update(dt);
	Actiii.Update(dt);
}



void ExtraScene::TECHOMOSCENEUPDATE(DWORD dt) {
	//
	//Sau khi hiển thị techmo và present thì fadeout present và di chuyển techmo xuống dưới 
	//

	//TechmoLogo đổi màu
	if (sceneTimer > 1700)
		techmoLogo.isFadingInRedOpt = true;

	//Fade out presents 1989
	if (sceneTimer > 3500 && !Present.isFadingOut) {
		Present.isFadingIn = false;
		Present.isFadingOut = true;
		Present.fadeOutTime = 1000;
	}
	//Di chuyển TechmoLogo xuống dưới

	if (sceneTimer > 4500 && !techmoLogo.isMoving) {
		Present.isActive = false;

		techmoLogo.initX = techmoLogo.currentX;
		techmoLogo.initY = techmoLogo.currentY;

		techmoLogo.isMoving = true;
		techmoLogo.destinationX = 100;
		techmoLogo.destinationY = 220;
		techmoLogo.moveTime = 3000;
	}

	//Hiển thị chữ ninja

	if (sceneTimer > 5000 && !NinjaText.isActive) {
		NinjaText.isActive = true;
		NinjaText.Persistent = true;
		NinjaText.initX = 7;
		NinjaText.initY = 150;
		NinjaText.currentX = NinjaText.initX;
		NinjaText.currentY = NinjaText.initY;
		NinjaText.destinationX = 7;
		NinjaText.destinationY = 20;
		NinjaText.scaleX = 0.145f;
		NinjaText.scaleY = 0.3f;
		NinjaText.moveTime = 2500;
		NinjaText.isMoving = true;
	}

	//Chữ ninja đổi màu 
	if (sceneTimer > 6000 && !NinjaText.isFadingIn) {
		NinjaText.colorOffset = 0;
		NinjaText.fadeInTime = 500;
		NinjaText.isFadingIn = true;
		NinjaText.isFadingInRedOpt = true;
	}
	//Hiển thị biểu tượng Gaiden và Push start

	if (sceneTimer > 7000 && !sound->isPlaying(IDSound::START) && !Gaiden.isActive)
		sound->Play(IDSound::START);
	if (sceneTimer > 7450 && !Gaiden.isActive) {

		//Gaiden

		Gaiden.isActive = true;
		Gaiden.Persistent = true;
		Gaiden.destinationX = 140;
		Gaiden.destinationY = 20;
		Gaiden.scaleX = 0.145f;
		Gaiden.scaleY = 0.3f;
		Gaiden.colorOffset = 0;
		Gaiden.isFadingIn = true;
		Gaiden.fadeInTime = 150;
		Gaiden.isFadingInRedOpt = true;



		//Push Start

		Pushstart.isActive = true;
		Pushstart.Persistent = true;
		Pushstart.destinationX = 30;
		Pushstart.destinationY = 100;
		Pushstart.scaleX = 0.145f;
		Pushstart.scaleY = 0.3f;

	}

	if (sceneTimer > 8000)
		ChangeScene();



}


void ExtraScene::Render() {
	NinjaText.Render();
	Ninja.Render();
	techmoLogo.Render();
	Present.Render();
	Gaiden.Render();
	gameOver.Render();
	Pushstart.Render();
	Actiii.Render();
}

void ExtraScene::ChangeScene() {
	sceneTimer = 0;
	sound->Stop(IDSound::PRESS_START);
	sound->Stop(IDSound::ACTIII);
	if (active == false)
		return;
	if (currentScene == EXTRA_SCENE_ID_GAMEOVER) {
		currentScene = EXTRA_SCENE_ID_TECHMOLOGO;
		sound->Stop(IDSound::PRESS_START);
		sound->Stop(IDSound::ACTIII);
		sound->Stop(IDSound::STAGE_31);
		sound->Stop(IDSound::STAGE_32);
		sound->Stop(IDSound::STAGE_33);

	}
	else if (currentScene == EXTRA_SCENE_ID_ACTIII) {
		active = false;
		currentScene = -1;
		sound->PlayLoop(IDSound::STAGE_31);
		return;
	}
	else
		currentScene++;

	ResetComponents();

	switch (currentScene) {
	case EXTRA_SCENE_ID_TECHMOLOGO: TECHOMOSCENESETUP();
		break;
	case EXTRA_SCENE_ID_PUSHSTART: PUSHSTARTSCENESETUP();
		break;
	case EXTRA_SCENE_ID_ACTIII: ACTIIISCENESETUP();
		break;
	case EXTRA_SCENE_ID_GAMEOVER: GAMEOVERSCENESETUP();
		break;
	default:
		break;
	}
}

void ExtraScene::PUSHSTARTSCENEUPDATE(DWORD dt) {

}

void ExtraScene::ACTIIISCENEUPDATE(DWORD dt) {
	//
	//Hiển thị Ninja Gaiden chạy
	//


	if (!sound->isPlaying(IDSound::ACTIII)) {
		sound->Play(IDSound::ACTIII);
	}


	//Ninja
	if (sceneTimer > 1400 && !NinjaText.isActive) {
		NinjaText.isActive = true;
		NinjaText.destinationX = 150;
		NinjaText.destinationY = 200;
		NinjaText.initX = 0;
		NinjaText.initY = 200;
		NinjaText.currentX = NinjaText.initX;
		NinjaText.currentY = NinjaText.initY;
		NinjaText.isMoving = true;
		NinjaText.moveTime = 1000;
		NinjaText.scaleX = 0.05f;
		NinjaText.scaleY = 0.1f;
	}


	//Gaiden
	if (sceneTimer > 1400 && !Gaiden.isActive) {
		Gaiden.isActive = true;
		Gaiden.destinationX = 195;
		Gaiden.destinationY = 200;
		Gaiden.initX = 45;
		Gaiden.initY = 200;
		Gaiden.currentX = Gaiden.initX;
		Gaiden.currentY = NinjaText.initY;
		Gaiden.isMoving = true;
		Gaiden.moveTime = 1000;
		Gaiden.scaleX = 0.05f;
		Gaiden.scaleY = 0.1f;
	}

	//Hiện ACT III
	if (sceneTimer > 2400 && !Actiii.isActive) {
		Actiii.isActive = true;
		Actiii.destinationX = 150;
		Actiii.destinationY = 100;
		Actiii.scaleX = 0.15f;
		Actiii.scaleY = 0.25f;

		Actiii.isFadingIn = true;
		Actiii.fadeInTime = 2000;
		Actiii.colorOffset = 0;
	}
	if (sceneTimer > 3400 && !Actiii.isFadingInGreenBlueOpt)
		Actiii.isFadingInGreenBlueOpt = true;

	if (sceneTimer > 4500) {
		ChangeScene();
		ResetComponents();
	}


}

void ExtraScene::GAMEOVERSCENESETUP() {



}

void ExtraScene::GAMEOVERSCENEUPDATE(DWORD dt) {
	if (sceneTimer > 120) {
		sound->Stop(IDSound::PRESS_START);
		sound->Stop(IDSound::ACTIII);
		sound->Stop(IDSound::STAGE_31);
		sound->Stop(IDSound::STAGE_32);
		sound->Stop(IDSound::STAGE_33);

		active = true;
		//Chữ game over hiện giữa màn hình
		gameOver.isActive = true;
		gameOver.destinationX = 80;
		gameOver.destinationY = 100;
		gameOver.scaleX = 0.2f;
		gameOver.scaleY = 0.4f;
	}
	if (sceneTimer > 2500) {
		ChangeScene();
	}
}