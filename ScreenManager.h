#pragma once
#include "StartScreen.h"
#include "PlayScreen.h"
#include "CharacterCreator.h"
#include "CharacterClassSelection.h"
#include "CharacterConfirm.h"
#include "Tavern.h"

class ScreenManager {
public:
	static ScreenManager* Instance();
	static void Release();
	enum Screens { Start, Play, NewCharacter, CharacterClass, CharacterConfirm,
					Tavern};

	void Update();
	void Render();
	void SetScreens(Screens screen);
	//Screens
	StartScreen* mStartScreen;
	PlayScreen* mPlayScreen;
	CharacterCreatorScreen* mCharacterCreator;
	CharacterClassScreen* mClassSelection;
	CharacterConfirmation* mCharacterConfirm;
	TavernScreen* mTavern;
private:
	ScreenManager();
	~ScreenManager();

	
	Screens mCurrentScreen;

	static ScreenManager* sInstance;

	InputManager* mInput;


};