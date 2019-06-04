#include"SceneEffect.h"

SceneEffect * SceneEffect::__instance = nullptr;
SceneEffect *SceneEffect::GetInstance() {
	if (__instance == nullptr) {
		__instance = new SceneEffect();

	}
	return __instance;
}


void SceneEffect::Update(unsigned long dt) {
	if (!isTrigger)
		return;
	timeAccumulator += dt;
	if (timeAccumulator > 100) {
		currentOffsetValue += 15;
		timeAccumulator = 0;
	}
	if (currentOffsetValue >= 255) {
		this->Reset();
		this->Done();
	}
	
}