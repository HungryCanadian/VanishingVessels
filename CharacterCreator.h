#pragma once
#include "Level.h"
#include "Scoreboard.h"
#include "AnimatedTexture.h"
#include "Button.h"
#include "TextInput.h"
#include "Player.h"

using namespace SDLFramework;

class CharacterCreatorScreen : public GameEntity {
public:
	CharacterCreatorScreen();
	~CharacterCreatorScreen();

	void SetupButtons();

	void Update() override;
	void Render() override;
	void ClassSelection();
	void CharacterConfirm();
	void NewCharacter();

private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInputManager;
	std::vector<Button> mButtons;
	Player* mPlayer;

	Texture* mTest;
	Texture* mTextArea;
	Texture* mTopBar;
	Texture* mBottomBar;
	Texture* mPaperOverlay;
	std::string mInputText;
	Texture* mHumanText;
	Texture* mElfText;
	Texture* mDwarfText;
	Texture* mGnomeText;
	Texture* mHalflingText;
	Texture* mTieflingText;
	Texture* mStr;
	Texture* mDex;
	Texture* mCon;
	Texture* mInt;
	Texture* mWis;
	Texture* mCha;
	Texture* mHP;
	Texture* mConfirmText;

	Texture* mSymbol;
	Texture* mLabel;

	bool isChoosingRace;
	bool isChoosingClass;
	std::string mRace;

	Texture* mCursorTexture;
	int mCursorWidth, mCursorHeight;
	SDL_Renderer* mRenderer;

	Level* mLevel;

};
