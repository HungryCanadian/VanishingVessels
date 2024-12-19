#pragma once
#include "StartScreen.h"
#include "PlayScreen.h"
#include "CharacterCreator.h"
#include "InventoryScreen.h"
#include "Tavern.h"
#include "Blacksmith.h"

class ScreenManager {
public:
	static ScreenManager* Instance();
	static void Release();
	enum Screens { Start, Play, NewCharacter, Inventory, Blacksmith,
					Tavern, Merchant};

	void Update();
	void Render();
	void SetScreens(Screens screen);
	//Screens
	StartScreen* mStartScreen;
	PlayScreen* mPlayScreen;
	CharacterCreatorScreen* mCharacterCreator;
	InventoryScreen* mInventoryScreen;
	TavernScreen* mTavern;
	BlacksmithScreen* mBlacksmith;
private:
	ScreenManager();
	~ScreenManager();

	
	Screens mCurrentScreen;

	static ScreenManager* sInstance;

	InputManager* mInput;


};