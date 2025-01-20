#pragma once
#include "Level.h"
#include "Scoreboard.h"
#include "AnimatedTexture.h"
#include "Button.h"
#include "TextInput.h"

using namespace SDLFramework;

class PlayScreen : public GameEntity {
public:
	PlayScreen();
	~PlayScreen();

	void SetupButtons();

	void Update() override;
	void Render() override;	

	bool GameOver();

private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInputManager;
	std::vector<Button> mButtons;
	
	SDLTexture* mTest;
	SDLTexture* mTextArea;
	SDLTexture* mTopBar;
	SDLTexture* mBottomBar;
	SDLTexture* mPaperOverlay;
	TextInput* mName;

	SDLTexture* mSymbol;
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

	SDLTexture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

	SDL_Renderer* mRenderer = nullptr;

	Level* mLevel;

};