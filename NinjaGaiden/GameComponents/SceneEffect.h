#pragma once


class SceneEffect {
private:
	SceneEffect() { isTrigger = false; timeAccumulator = 0; currentOffsetValue = 0; isDone = false; }
	static SceneEffect  * __instance;
	unsigned long timeAccumulator;
	int currentOffsetValue;
	bool isTrigger;
	bool isDone;
public :
	static SceneEffect *GetInstance();
	void Update(unsigned long dt);
	int GetCurrentOffset() { return currentOffsetValue % 255; };
	void Trigger() {isTrigger = true;}
	void Reset() {  currentOffsetValue = 0; timeAccumulator = 0; }
	bool IsDone() { return isDone; }
	void Done() { isDone = true; }
	void ResetDone() { isDone = false; }
	void UnTrigger() { isTrigger = false; }
};