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
#include "Docks.h"
#include "WestRoad.h"
#include "Graveyard.h"
#include "Ancestors.h"

class ScreenManager {
public:
	static ScreenManager* Instance();
	static void Release();
	enum Screens { Start, Play, NewCharacter, Inventory, Blacksmith,
					Tavern, Merchant, Back, Town, East, Outskirts, Docks, West, Grave, Ancestors, North};

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
	DockScreen* mDocks;
	WestRoad* mWest;
	Graveyard* mGrave;
	HallOfAncestors* mAncestors;

private:
	ScreenManager();
	~ScreenManager();

	
	Screens mCurrentScreen;
	Screens mPreviousScreen;

	static ScreenManager* sInstance;

	InputManager* mInput;


};