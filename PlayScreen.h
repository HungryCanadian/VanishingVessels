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
	
	Texture* mTest;
	Texture* mTextArea;
	Texture* mTopBar;
	Texture* mBottomBar;
	Texture* mPaperOverlay;
	TextInput* mName;

	Texture* mSymbol;

	Texture* mTextLine1;
	Texture* mTextLine2;
	Texture* mTextLine3;
	Texture* mTextLine4;
	Texture* mTextLine5;
	Texture* mTextLine6;
	Texture* mTextLine7;
	Texture* mTextLine8;
	Texture* mTextLine9;
	Texture* mTextLine10;
	Texture* mTextLine11;

	Texture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

	SDL_Renderer* mRenderer = nullptr;

	Level* mLevel;

};