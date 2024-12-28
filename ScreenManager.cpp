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
		mPreviousScreen = mCurrentScreen;  // Save the current screen before changing
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

	mCurrentScreen = Start;
	mPreviousScreen = Start;
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

}

void ScreenManager::Update() {

	switch (mCurrentScreen) {
	case ScreenManager::Start:
		mStartScreen->Update();

		if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) {
			//we want to switch from start screen to the play screen
			//Find a way to determine which choice the player is choosing to determine if 'hiscore is selected' (startscreen variable = mSelectedMode; write a getter to grab the selected mode)
			mCurrentScreen = Play;
		}
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
	case ScreenManager::Back:
		// Switch to the previous screen
		if (mPreviousScreen != Screens::Back) {  // Make sure we're not stuck in an invalid state
			SetScreens(mPreviousScreen);  // Switch to the previous screen
			// Now that we've set the screen, call the update method of that screen
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
			default:
				std::cerr << "Unknown Screen Found! Please supply a valid Screen!\n";
				break;
			}
			mPreviousScreen = Screens::Back;  // Prevent cycling back to the same screen
		}
		break;
	default:
		std::cerr << "Unknown Screen Found! please supply a valid Screen!\n";
		break;
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
	case ScreenManager::Back:
		// Switch to the previous screen
		if (mPreviousScreen != Screens::Back) {  // Make sure we're not stuck in an invalid state
			SetScreens(mPreviousScreen);  // Switch to the previous screen
			// Now that we've set the screen, call the update method of that screen
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
			default:
				std::cerr << "Unknown Screen Found! Please supply a valid Screen!\n";
				break;
			}
			mPreviousScreen = Screens::Back;  // Prevent cycling back to the same screen
		}
		break;
	}
}