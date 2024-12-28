#pragma once
#include "StartScreen.h"
#include "PlayScreen.h"
#include "CharacterCreator.h"
#include "InventoryScreen.h"
#include "Tavern.h"
#include "Blacksmith.h"
#include "Merchant.h"
#include "Town.h"
#include "EastRoad.h"
#include "DockOutskirts.h"

class ScreenManager {
public:
	static ScreenManager* Instance();
	static void Release();
	enum Screens { Start, Play, NewCharacter, Inventory, Blacksmith,
					Tavern, Merchant, Back, Town, East, Outskirts, Docks, West, North};

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
	MerchantScreen* mMerchant;
	TownScreen* mTown;
	EastRoad* mEast;
	DockOutskirts* mOutskirts;

private:
	ScreenManager();
	~ScreenManager();

	
	Screens mCurrentScreen;
	Screens mPreviousScreen;

	static ScreenManager* sInstance;

	InputManager* mInput;


};