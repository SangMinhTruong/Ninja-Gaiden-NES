#include"GlobalEvent.h"
#include"Ninja.h"

GlobalEvent * GlobalEvent::__instance = nullptr;
GlobalEvent *GlobalEvent::GetInstance() {
	if (__instance == nullptr) {
		__instance = new GlobalEvent();

	}
	return __instance;
}


bool GlobalEvent::IsNinjaInvincible() {
	return Ninja::GetInstance()->IsInvincible();
}

void GlobalEvent::SetIsRenderingNinja(bool flag) {
	
}