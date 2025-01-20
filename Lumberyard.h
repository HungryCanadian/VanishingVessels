#pragma once
#include "Level.h"
#include "Button.h"
#include "Player.h"

using namespace SDLFramework;

class Lumberyard : public GameEntity {
public:
	Lumberyard();
	~Lumberyard();

	void SetupButtons();
	void DefaultText();
	void Investigate();


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

	SDLTexture* mSymbol;

	SDLTexture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};
