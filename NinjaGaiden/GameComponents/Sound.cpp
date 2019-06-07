#include"Sound.h"

GameSound * GameSound::__instance = NULL;

GameSound * GameSound::GetInstance() {
	if (__instance == NULL) {
		__instance = new GameSound();
	}
	return __instance;
}
int GameSound::InitGameSound(HWND hWnd) {
	HRESULT result;

	//Tạo sound manager
	dSound = new CSoundManager();

	//Khởi tạo direct sound
	result = dSound->Initialize(hWnd, DSSCL_PRIORITY);
	if (SUCCEEDED(result))
		DebugOut(L"[INFO] Loaded sound manager successfully !!!");
	else {
		DebugOut(L"[ERROR] Failed to load sound manager !!!!!");
		return 0;
	}
	//Khởi tạo bộ đệm sơ cấp
	result = dSound->SetPrimaryBufferFormat(2, 22050, 16);
	if (result != S_OK)
		return 0;

	//return success
	return 1;
}

CSound* GameSound::LoadSound(std::string  fileName) {
	HRESULT result;
	//Tạo con trỏ tham chiếu tới file âm thanh
	CSound *wave;
	
	wchar_t wfileName[100];
	mbstowcs(wfileName, const_cast<char *>(fileName.c_str()), strlen(fileName.c_str()) + 1);


	//Load file
	result = dSound->Create(&wave, wfileName );
	if (result != S_OK) {
		DebugOut(L"[ERROR] Failed to load sound  !!!!!!!!!!!!!!!\n");
		return 0;
	}
	else
		DebugOut(L"[INFO] Loaded sound successfully !!!!!!!!!!!!!!!!!\n");
	 
	return wave;
}
void GameSound::Play(IDSound id) { 
	CSound *sound = sounds[id];
	if (sound != NULL   )
		sound->Play();
};
void GameSound::PlayLoop(IDSound id) {
	CSound *sound = sounds[id];
	if (sound != NULL & !isPlaying(id))
		sound->Play(0, DSBPLAY_LOOPING);
};
void GameSound::Stop(IDSound id) {
	CSound *sound = sounds[id];
	if (sound != NULL & isPlaying(id))
		sound->Stop();
}
bool GameSound::isPlaying(IDSound id) {
	CSound *sound = sounds[id];
	if (sound != NULL)
		return sound->IsSoundPlaying();
}

void GameSound::LoadResources() {
	CSound * sound;
	 
	//Hiệu ứng đánh kiếm
	 
	sound = LoadSound(SOUND_PATH_SWORD);
	sounds[IDSound::SWORD] = sound;

	//Tiếng windmill shuriken
	sound = LoadSound(SOUND_PATH_WINDMILL);
	sounds[IDSound::WINDMILL] = sound;

	//Tiếng shuriken
	sound = LoadSound(SOUND_PATH_SHURIKEN);
	sounds[IDSound::SHURIKEN] = sound;

	//Tiếng timer tick tick
	sound = LoadSound(SOUND_PATH_TIMER);
	sounds[IDSound::TIMER] = sound;

	//Tiếng ninja bị văng
	sound = LoadSound(SOUND_PATH_NINJA_HURT);
	sounds[IDSound::NINJA_HURT] = sound;
	
	//Tiếng ninja nhảy
	sound = LoadSound(SOUND_PATH_NINJA_JUMP);
	sounds[IDSound::NINJA_JUMP] = sound;

	//Tiếng Machine Gunner
	sound = LoadSound(SOUND_PATH_MACHINE_GUNNER);
	sounds[IDSound::MACHINE_GUNNER] = sound;

	// Hiệu ứng thu thập item
	sound = LoadSound(SOUND_PATH_ITEM_COLLECT);
	sounds[IDSound::ITEM_COLLECT] = sound;

	//Âm thanh vòng lửa vèo vèo
	sound = LoadSound(SOUND_PATH_FIREWHEEL);
	sounds[IDSound::FIREWHEEL] = sound;


	//Hiệu ứng kẻ địch bị dính đòn
	sound = LoadSound(SOUND_PATH_ENEMYDESTROYED);
	sounds[IDSound::ENEMYDESTROYED] = sound;

	//Tiếng súng của cannon shooter
	sound = LoadSound(SOUND_PATH_CANNONSHOOTER);
	sounds[IDSound::CANNONSHOOTER] = sound;


	//Tiếng boss nhảy chạm đất
	sound = LoadSound(SOUND_PATH_BOSS_JUMP);
	sounds[IDSound::BOSS_JUMP] = sound;

	//Tiếng boss bị out
	sound = LoadSound(SOUND_PATH_BOSS_DESTROYED);
	sounds[IDSound::BOSS_DESTROYED] = sound;

	//Tiếng đếm tính điểm lúc thắng
	sound = LoadSound(SOUND_PATH_WINNING_TIMER);
	sounds[IDSound::WINNING_TIMER] = sound;

	//Nhạc hay Stage 31
	sound = LoadSound(SOUND_PATH_STAGE_31);
	sounds[IDSound::STAGE_31] = sound;

	//Nhạc hay Stage 32
	sound = LoadSound(SOUND_PATH_STAGE_32);
	sounds[IDSound::STAGE_32] = sound;

	//Nhạc hay Stage 33
	sound = LoadSound(SOUND_PATH_STAGE_33);
	sounds[IDSound::STAGE_33] = sound;

	//Nhạc hay Game Over 
	sound = LoadSound(SOUND_PATH_GAME_OVER);
	sounds[IDSound::GAME_OVER] = sound;
	

	//Nhạc press start
	sound = LoadSound(SOUND_PATH_PRESS_START);
	sounds[IDSound::PRESS_START] = sound;

	//Nhạc start
	sound = LoadSound(SOUND_PATH_START);
	sounds[IDSound::START] = sound;


}