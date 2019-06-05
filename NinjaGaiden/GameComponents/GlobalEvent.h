#pragma once


class GlobalEvent {
private:
	GlobalEvent() {};
	static GlobalEvent  * __instance;
	bool isRenderingNinja;
	 
public :
	static GlobalEvent *GetInstance();
	void SetIsRenderingNinja(bool flag) ;
	bool IsNinjaInvincible();
};