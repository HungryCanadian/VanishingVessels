#pragma once
#include <map>
#include <iostream>
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
#include "NorthRoad.h"
#include "Lumberyard.h"
#include "Heartwood.h"
#include "CombatScreen.h"

class ScreenManager {
public:
	static ScreenManager* Instance();
	static void Release();

	enum Screens { Start, Play, NewCharacter, Inventory, Blacksmith,
					Tavern, Merchant, Back, Town, East, Outskirts, Docks, 
					West, Grave, Ancestors, North, Lumber, Grove, Combat,
					EndCombat};

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
	NorthRoad* mNorth;
	Lumberyard* mLumber;
	HeartwoodGrove* mGrove;
	CombatScreen* mCombat;

private:
	ScreenManager();
	~ScreenManager();
	
	Screens mCurrentScreen;
	Screens mPreviousScreen;
	Screens mBeforeCombatScreen;

	static ScreenManager* sInstance;

	InputManager* mInput;


};