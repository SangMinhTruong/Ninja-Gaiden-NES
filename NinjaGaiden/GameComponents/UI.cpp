#include"UI.h"
UI* UI::_instance = NULL;
UIUtility *  UIUtility::__instance = NULL;

UI* UI::GetInstance() {
	if (_instance == NULL) {
		_instance = new UI();
		_instance->LoadResources();
	}

	return _instance;
}


void UI::LoadResources() {
	//Khởi tạo thiết bị vẽ
	d3ddv = Graphics::GetInstance()->GetDirect3DDevice();

	 
	//Khởi tạo thông số
	SetRect(&displayRect, 4  , 5  , SCREEN_WIDTH, SCREEN_HEIGHT);
	Score = 0;
	Timer = 0;
	NinjaHP = 0;
	EnemyHP = 0;
	currentItem = -1;
	Stage = "0-0";

	//Khởi tạo font
	font = NULL;
	AddFontResourceEx(GAME_FONT, FR_PRIVATE, NULL);
	
	HRESULT result = D3DXCreateFont(
		d3ddv, 16, 0, FW_BOLD, 1, false,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY, FF_DONTCARE, L"ArcadeClassic", &font);
	if (!SUCCEEDED(result))
		OutputDebugString(L"[ERROR] Loading font failed !!!!!!!!!!");

	//Load các sprite hiển thị
	RECT r;
	SpriteData spriteData;

	

	//Spirit

	SetRect(&r, 0, 0, 60, 31);
	spirit = new Sprite(SPIRIT_SYMBOL, r, D3DCOLOR_XRGB(0, 0, 0));
	spriteData.x = 50;
	spriteData.y = 40;
	spriteData.width = 60;
	spriteData.height = 31;
	spriteData.angle = 0;
	spriteData.scale = 1;
	spriteData.isLeft = false;

	spirit->SetData(spriteData);


	//Items
	for (int i = 0; i < 5; i++) {
		SetRect(&r, 0, 16 * i, 16, 16 * (i + 1));
		Sprite *item = new Sprite(ITEM_SYMBOL, r, D3DCOLOR_XRGB(0, 128, 128));

		spriteData.x = 100;
		spriteData.y = 27;
		spriteData.width = 16;
		spriteData.height = 16;
		spriteData.angle = 0;
		spriteData.scale = 1;
		spriteData.isLeft = false;

		item->SetData(spriteData);

		items.push_back(item);
	}
	//HP & noHP
	SetRect(&r, 0, 0, 3, 7);
	int baseX = 191;
	int baseY = 24;
	for (int i = 0; i < 16; i++) {
		Sprite *HP = new Sprite(HP_SYMBOL, r, D3DCOLOR_XRGB(0, 0, 0));
		Sprite *noHP = new Sprite(NOHP_SYMBOL, r, D3DCOLOR_XRGB(0, 0, 0));
		spriteData.x = baseX + i * 4;
		spriteData.y = baseY;
		spriteData.width = 4;
		spriteData.height = 7;
		spriteData.angle = 0;
		spriteData.scale = 1;
		spriteData.isLeft = false;


		HP->SetData(spriteData);
		noHP->SetData(spriteData);

		HPs.push_back(HP);
		noHPs.push_back(noHP);
	}



	//Item frame

	SetRect(&r, 0, 0, 195, 63);
	itemFrame = new Sprite(ITEM_FRAME_SYMBOL, r, D3DCOLOR_XRGB(0, 0, 0));

	spriteData.x = 98;
	spriteData.y = 25;
	spriteData.width = 195;
	spriteData.height = 63;
	spriteData.angle = 0;
	spriteData.scale = 1;
	spriteData.isLeft = false;
	itemFrame->SetData(spriteData);

}

void UI::Update(DWORD dt) {
	//Lấy thông tin hiển thị
	Game * game = Game::GetInstance();
	GameInformation gameInfo = game->GetInformation();
	

	//Cập nhật thông tin
	this->Score = gameInfo.Score;
	this->Timer = gameInfo.Timer;
	this->currentItem = gameInfo.currentItem;
	this->LiveCount = gameInfo.LiveCount;
	this->Stage = gameInfo.Stage;
	this->EnemyHP = gameInfo.EnemyHP;
	this->NinjaHP = gameInfo.NinjaHP;
	this->SpiritPoint = gameInfo.SpiritPoint;

	//Tạo format để hiển thị
	std::string scoreStr = std::to_string(Score);
	while (scoreStr.size() < 6)
		scoreStr = "0" + scoreStr;
	std::string timerStr = std::to_string(Timer / 1000);
	while (timerStr.size() < 3)
		timerStr = "0" + timerStr;
	std::string pStr = std::to_string(LiveCount);
	while (pStr.size() < 2)
		pStr = "0" + pStr;

	std::string spiritStr = std::to_string(SpiritPoint);
	while (spiritStr.size() < 2)
		spiritStr = "0" + spiritStr;

	displayText = "";
	displayText += "SCORE - " + scoreStr + "  STAGE - " + gameInfo.Stage + "\n";
	displayText += "TIMER - " + timerStr + "            NINJA - " + "\n";
	displayText += "P - " + pStr + "       - " + spiritStr + "            ENEMY - " + "\n";




}

void UI::Draw(Sprite *sprite, float scaleX, float scaleY, int offsetY) {

	//UIUtility
	UIUtility * uiu = UIUtility::getInstance();

	/*int massMoveX = 0;
	int massMoveY = 0;
	if (sprite == spirit | true) {
		massMoveX = uiu->getMoveX();
		massMoveY = uiu->getMoveY();
	}*/

	 
	int colorOffset = 0;

	LPD3DXSPRITE spriteHandler = Graphics::GetInstance()->GetSpriteHandler();

	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);

	D3DXMatrixScaling(&matrix, scaleX, scaleY, .0f);

	spriteHandler->SetTransform(&matrix);
	HRESULT result = spriteHandler->Draw(sprite->GetTexture(), 
		&sprite->GetRect(), 
		NULL, 
		new D3DXVECTOR3((sprite->GetTranslate().x  )*(1 / scaleX)  , 
			(sprite->GetTranslate().y +  offsetY)*(1 / scaleY) , 0), 
		D3DCOLOR_XRGB(255-colorOffset,255-colorOffset, 255-colorOffset));
	
	/*if (SUCCEEDED(result))
		DebugOut(L"[SUCCESSFUL] Render sprite successfully !");
	else
		DebugOut(L"[ERROR] Failed to render sprite !");*/
}
void UI::Render() {
	//Vẽ thông tin lên màn hình
	 
	
	if ((font) ) {
		font->DrawTextA(NULL, displayText.c_str(), -1, &displayRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	}

	//Vẽ các sprite thông tin

	//Vẽ khung item
	Draw(itemFrame, 0.15, 0.42);

	//Vẽ HP  
	int offset = 17;
	for (int i = 0; i < 16; i++) {
		if (i < NinjaHP)
			Draw(HPs.at(i), 1.f, 1.3f);
		else
			Draw(noHPs.at(i), 1.f, 1.3f);
		if (i < EnemyHP)
			Draw(HPs.at(i), 1.f, 1.3f, offset);
		else
			Draw(noHPs.at(i), 1.f, 1.3f, offset);
	}

	//Vẽ spirit

	Draw(spirit, 0.2f, 0.3f);

	//Vẽ item
	if (currentItem != -1)
		Draw(items.at(currentItem), 1.58f, 1.5f);



}
