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
	mCurrentScreen = screen;
}

ScreenManager::ScreenManager() {
	mInput = InputManager::Instance();
	//Screens
	mStartScreen = new StartScreen();
	mPlayScreen = new PlayScreen();
	mCharacterCreator = new CharacterCreatorScreen();
	mClassSelection = new CharacterClassScreen();
	mCharacterConfirm = new CharacterConfirmation();
	mTavern = new TavernScreen();

	mCurrentScreen = Start;
}

ScreenManager::~ScreenManager() {
	mInput = nullptr;

	delete mStartScreen;
	mStartScreen = nullptr;

	delete mPlayScreen;
	mPlayScreen = nullptr;
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
	case ScreenManager::CharacterClass:
		mClassSelection->Update();
		break;
	case ScreenManager::CharacterConfirm:
		mCharacterConfirm->Update();
		break;
	case ScreenManager::Tavern:
		mTavern->Update();
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
	case ScreenManager::CharacterClass:
		mClassSelection->Render();
		break;
	case ScreenManager::CharacterConfirm:
		mCharacterConfirm->Render();
		break;
	case ScreenManager::Tavern:
		mTavern->Render();
		break;
	}
}