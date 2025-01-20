#pragma once
#include "Level.h"
#include "Button.h"
#include "Player.h"

using namespace SDLFramework;

class TownScreen : public GameEntity {
public:
	TownScreen();
	~TownScreen();

	void SetupButtons();
	void Description();
	void DefaultText();
	void Leave();
	void LeaveTown();

	void Update() override;
	void Render() override;

private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInputManager;
	std::vector<Button> mButtons;
	Player* mPlayer;
	bool mFirstVisit;

	SDLTexture* mTest;
	SDLTexture* mTextArea;
	SDLTexture* mTopBar;
	SDLTexture* mBottomBar;
	SDLTexture* mPaperOverlay;
	SDLTexture* mLabel;

	SDLTexture* mTextLine1;
	SDLTexture* mTextLine2;
	SDLTexture* mTextLine3;
	SDLTexture* mTextLine4;
	SDLTexture* mTextLine5;
	SDLTexture* mTextLine6;
	SDLTexture* mTextLine7;
	SDLTexture* mTextLine8;
	SDLTexture* mTextLine9;
	SDLTexture* mTextLine10;
	SDLTexture* mTextLine11;
	SDLTexture* mTextLine12;
	SDLTexture* mTextLine13;
	SDLTexture* mTextLine14;
	SDLTexture* mTextLine15;
	SDLTexture* mTextLine16;
	SDLTexture* mTextLine17;
	SDLTexture* mTextLine18;
	SDLTexture* mTextLine19;
	SDLTexture* mTextLine20;
	SDLTexture* mTextLine21;
	SDLTexture* mTextLine22;
	SDLTexture* mTextLine23;
	SDLTexture* mTextLine24;
	SDLTexture* mTextLine25;
	SDLTexture* mTextLine26;
	SDLTexture* mTextLine27;
	SDLTexture* mTextLine28;
	SDLTexture* mTextLine29;
	SDLTexture* mTextLine30;
	SDLTexture* mTextLine31;
	SDLTexture* mTextLine32;
	SDLTexture* mTextLine33;


	SDLTexture* mSymbol;

	SDLTexture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};
