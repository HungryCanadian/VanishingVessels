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

	SDLTexture* mTest;
	SDLTexture* mTextArea;
	SDLTexture* mTopBar;
	SDLTexture* mBottomBar;
	SDLTexture* mPaperOverlay;
	std::string mInputText;
	SDLTexture* mHumanText;
	SDLTexture* mElfText;
	SDLTexture* mDwarfText;
	SDLTexture* mGnomeText;
	SDLTexture* mHalflingText;
	SDLTexture* mTieflingText;
	SDLTexture* mStr;
	SDLTexture* mDex;
	SDLTexture* mCon;
	SDLTexture* mInt;
	SDLTexture* mWis;
	SDLTexture* mCha;
	SDLTexture* mHP;
	SDLTexture* mConfirmText;

	SDLTexture* mSymbol;
	SDLTexture* mLabel;

	bool isChoosingRace;
	bool isChoosingClass;
	std::string mRace;

	SDLTexture* mCursorTexture;
	int mCursorWidth, mCursorHeight;
	SDL_Renderer* mRenderer;

	Level* mLevel;

};
