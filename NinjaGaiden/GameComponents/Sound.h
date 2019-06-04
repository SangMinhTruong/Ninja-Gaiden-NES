#pragma once
#include <windows.h>
#include<map>

#include "dsutil.h" 
#include"Constants.h"
#include"Debug.h"

#include<string>

class GameSound {
private:
	static GameSound * __instance;
	std::map<IDSound, CSound*> sounds;
	CSoundManager *dSound;
public:
	static GameSound * GetInstance();
	int InitGameSound(HWND);
	void LoadResources();
	CSound* LoadSound(std::string );
	void Play(IDSound);
	void PlayLoop(IDSound);
	void Stop(IDSound);
	bool isPlaying(IDSound);
};