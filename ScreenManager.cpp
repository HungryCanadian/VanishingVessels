#include "ScreenManager.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager* ScreenManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new ScreenManager();
	}

	return sInstance;
}

void ScreenManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

void ScreenManager::SetScreens(Screens screen) {
	
	if (screen != Screens::Back) {
		mBeforeCombatScreen = mPreviousScreen;
		mPreviousScreen = mCurrentScreen;
	}
	mCurrentScreen = screen;  // Set the new screen
}

ScreenManager::ScreenManager() {
	mInput = InputManager::Instance();

	//Screens
	mStartScreen = new StartScreen();
	mPlayScreen = new PlayScreen();
	mCharacterCreator = new CharacterCreatorScreen();
	mInventoryScreen = new InventoryScreen();
	mTavern = new TavernScreen();
	mBlacksmith = new BlacksmithScreen();
	mMerchant = new MerchantScreen();
	mTown = new TownScreen();
	mEast = new EastRoad();
	mOutskirts = new DockOutskirts();
	mDocks = new DockScreen();
	mWest = new WestRoad();
	mGrave = new Graveyard();
	mAncestors = new HallOfAncestors();
	mNorth = new NorthRoad();
	mLumber = new Lumberyard();
	mGrove = new HeartwoodGrove();
	mCombat = new CombatScreen();

	mCurrentScreen = Start;
	mPreviousScreen = Start;
	mBeforeCombatScreen = Start;
}

ScreenManager::~ScreenManager() {
	mInput = nullptr;

	delete mStartScreen;
	mStartScreen = nullptr;

	delete mPlayScreen;
	mPlayScreen = nullptr;

	delete mCharacterCreator;
	mCharacterCreator = nullptr;

	delete mInventoryScreen;
	mInventoryScreen = nullptr;

	delete mTavern;
	mTavern = nullptr;

	delete mBlacksmith;
	mBlacksmith = nullptr;

	delete mMerchant;
	mMerchant = nullptr;

	delete mTown;
	mTown = nullptr;

	delete mEast;
	mEast = nullptr;

	delete mOutskirts;
	mOutskirts = nullptr;

	delete mDocks;
	mDocks = nullptr;

	delete mWest;
	mWest = nullptr;

	delete mGrave;
	mGrave = nullptr;

	delete mAncestors;
	mAncestors = nullptr;

	delete mNorth;
	mNorth = nullptr;

	delete mLumber;
	mLumber = nullptr;

	delete mGrove;
	mGrove = nullptr;

	delete mCombat;
	mCombat = nullptr;
}

void ScreenManager::Update() {

	switch (mCurrentScreen) {
	case ScreenManager::Start:
		mStartScreen->Update();
		break;
	case ScreenManager::Play:
		mPlayScreen->Update();
		break;
	case ScreenManager::NewCharacter:
		mCharacterCreator->Update();
		break;
	case ScreenManager::Inventory:
		mInventoryScreen->Update();
		break;
	case ScreenManager::Tavern:
		mTavern->Update();
		break;
	case ScreenManager::Blacksmith:
		mBlacksmith->Update();
		break;
	case ScreenManager::Merchant:
		mMerchant->Update();
		break;
	case ScreenManager::Town:
		mTown->Update();
		break;
	case ScreenManager::East:
		mEast->Update();
		break;
	case ScreenManager::Outskirts:
		mOutskirts->Update();
		break;
	case ScreenManager::Docks:
		mDocks->Update();
		break;
	case ScreenManager::West:
		mWest->Update();
		break;
	case ScreenManager::Grave:
		mGrave->Update();
		break;
	case ScreenManager::Ancestors:
		mAncestors->Update();
		break;
	case ScreenManager::North:
		mNorth->Update();
		break;
	case ScreenManager::Lumber:
		mLumber->Update();
		break;
	case ScreenManager::Grove:
		mGrove->Update();
		break;
	case ScreenManager::Combat:
		mCombat->Update();
		break;
	case ScreenManager::Back:
		if (mPreviousScreen != Screens::Back) {
			SetScreens(mPreviousScreen);
			switch (mPreviousScreen) {
			case Screens::Start:
				mStartScreen->Update();
				break;
			case Screens::Play:
				mPlayScreen->Update();
				break;
			case Screens::NewCharacter:
				mCharacterCreator->Update();
				break;
			case Screens::Inventory:
				mInventoryScreen->Update();
				break;
			case Screens::Tavern:
				mTavern->Update();
				break;
			case Screens::Blacksmith:
				mBlacksmith->Update();
				break;
			case ScreenManager::Merchant:
				mMerchant->Update();
				break;
			case ScreenManager::Town:
				mTown->Update();
				break;
			case ScreenManager::East:
				mEast->Update();
				break;
			case ScreenManager::Outskirts:
				mOutskirts->Update();
				break;
			case ScreenManager::Docks:
				mDocks->Update();
				break;
			case ScreenManager::West:
				mWest->Update();
				break;
			case ScreenManager::Grave:
				mGrave->Update();
				break;
			case ScreenManager::Ancestors:
				mAncestors->Update();
				break;
			case ScreenManager::North:
				mNorth->Update();
				break;
			case ScreenManager::Lumber:
				mLumber->Update();
				break;
			case ScreenManager::Grove:
				mGrove->Update();
				break;
			case ScreenManager::Combat:
				mCombat->Update();
				break;
			default:
				std::cerr << "Unknown Screen Found! Please supply a valid Screen!\n";
				break;
			}
	case ScreenManager::EndCombat:
		if (mBeforeCombatScreen != Screens::Back) {
			SetScreens(mBeforeCombatScreen);
			switch (mBeforeCombatScreen) {
			case Screens::Start:
				mStartScreen->Update();
				break;
			case Screens::Play:
				mPlayScreen->Update();
				break;
			case Screens::NewCharacter:
				mCharacterCreator->Update();
				break;
			case Screens::Inventory:
				mInventoryScreen->Update();
				break;
			case Screens::Tavern:
				mTavern->Update();
				break;
			case Screens::Blacksmith:
				mBlacksmith->Update();
				break;
			case ScreenManager::Merchant:
				mMerchant->Update();
				break;
			case ScreenManager::Town:
				mTown->Update();
				break;
			case ScreenManager::East:
				mEast->Update();
				break;
			case ScreenManager::Outskirts:
				mOutskirts->Update();
				break;
			case ScreenManager::Docks:
				mDocks->Update();
				break;
			case ScreenManager::West:
				mWest->Update();
				break;
			case ScreenManager::Grave:
				mGrave->Update();
				break;
			case ScreenManager::Ancestors:
				mAncestors->Update();
				break;
			case ScreenManager::North:
				mNorth->Update();
				break;
			case ScreenManager::Lumber:
				mLumber->Update();
				break;
			case ScreenManager::Grove:
				mGrove->Update();
				break;
			case ScreenManager::Combat:
				mCombat->Update();
				break;
			default:
				std::cerr << "Unknown Screen Found! Please supply a valid Screen!\n";
				break;
			}
		}
		break;
	default:
		std::cerr << "Unknown Screen Found! please supply a valid Screen!\n";
		break;
		}
	}
}

void ScreenManager::Render() {
	switch (mCurrentScreen) {
	case ScreenManager::Start:
		mStartScreen->Render();
		break;
	case ScreenManager::Play:
		mPlayScreen->Render();
		break;
	case ScreenManager::NewCharacter:
		mCharacterCreator->Render();
		break;
	case ScreenManager::Inventory:
		mInventoryScreen->Render();
		break;
	case ScreenManager::Tavern:
		mTavern->Render();
		break;
	case ScreenManager::Blacksmith:
		mBlacksmith->Render();
		break;
	case ScreenManager::Merchant:
		mMerchant->Render();
		break;
	case ScreenManager::Town:
		mTown->Render();
		break;
	case ScreenManager::East:
		mEast->Render();
		break;
	case ScreenManager::Outskirts:
		mOutskirts->Render();
		break;
	case ScreenManager::Docks:
		mDocks->Render();
		break;
	case ScreenManager::West:
		mWest->Render();
		break;
	case ScreenManager::Grave:
		mGrave->Render();
		break;
	case ScreenManager::Ancestors:
		mAncestors->Render();
		break;
	case ScreenManager::North:
		mNorth->Render();
		break;
	case ScreenManager::Lumber:
		mLumber->Render();
		break;
	case ScreenManager::Grove:
		mGrove->Render();
		break;
	case ScreenManager::Combat:
		mCombat->Render();
		break;
	case ScreenManager::Back:
		if (mPreviousScreen != Screens::Back) {
			SetScreens(mPreviousScreen);
			switch (mPreviousScreen) {
			case Screens::Start:
				mStartScreen->Render();
				break;
			case Screens::Play:
				mPlayScreen->Render();
				break;
			case Screens::NewCharacter:
				mCharacterCreator->Render();
				break;
			case Screens::Inventory:
				mInventoryScreen->Render();
				break;
			case Screens::Tavern:
				mTavern->Render();
				break;
			case Screens::Blacksmith:
				mBlacksmith->Render();
				break;
			case ScreenManager::Merchant:
				mMerchant->Render();
				break;
			case ScreenManager::Town:
				mTown->Render();
				break;
			case ScreenManager::East:
				mEast->Render();
				break;
			case ScreenManager::Outskirts:
				mOutskirts->Render();
				break;
			case ScreenManager::Docks:
				mDocks->Render();
				break;
			case ScreenManager::West:
				mWest->Render();
				break;
			case ScreenManager::Grave:
				mGrave->Render();
				break;
			case ScreenManager::Ancestors:
				mAncestors->Render();
				break;
			case ScreenManager::North:
				mNorth->Render();
				break;
			case ScreenManager::Lumber:
				mLumber->Render();
				break;
			case ScreenManager::Grove:
				mGrove->Render();
				break;
			case ScreenManager::Combat:
				mCombat->Render();
				break;
			default:

				break;
			}
	case ScreenManager::EndCombat:
		if (mBeforeCombatScreen != Screens::Back) {
			SetScreens(mBeforeCombatScreen);
			switch (mBeforeCombatScreen) {
			case Screens::Start:
				mStartScreen->Render();
				break;
			case Screens::Play:
				mPlayScreen->Render();
				break;
			case Screens::NewCharacter:
				mCharacterCreator->Render();
				break;
			case Screens::Inventory:
				mInventoryScreen->Render();
				break;
			case Screens::Tavern:
				mTavern->Render();
				break;
			case Screens::Blacksmith:
				mBlacksmith->Render();
				break;
			case ScreenManager::Merchant:
				mMerchant->Render();
				break;
			case ScreenManager::Town:
				mTown->Render();
				break;
			case ScreenManager::East:
				mEast->Render();
				break;
			case ScreenManager::Outskirts:
				mOutskirts->Render();
				break;
			case ScreenManager::Docks:
				mDocks->Render();
				break;
			case ScreenManager::West:
				mWest->Render();
				break;
			case ScreenManager::Grave:
				mGrave->Render();
				break;
			case ScreenManager::Ancestors:
				mAncestors->Render();
				break;
			case ScreenManager::North:
				mNorth->Render();
				break;
			case ScreenManager::Lumber:
				mLumber->Render();
				break;
			case ScreenManager::Grove:
				mGrove->Render();
				break;
			case ScreenManager::Combat:
				mCombat->Render();
				break;
			default:

				break;
			}
		}
		mBeforeCombatScreen = mPreviousScreen;
		mPreviousScreen = Screens::Back;  // Prevent cycling back to the same screen

		break;
		}
	}
}