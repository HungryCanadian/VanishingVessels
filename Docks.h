#pragma once
#include "Level.h"
#include "Button.h"
#include "Player.h"

using namespace SDLFramework;

class DockScreen : public GameEntity {
public:
	DockScreen();
	~DockScreen();

	void SetupButtons();
	void DefaultText();
	void Investigate();
	void Rest();

	void Update() override;
	void Render() override;

private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInputManager;
	std::vector<Button> mButtons;
	Player* mPlayer;
	bool mFirstVisit;

	Texture* mTest;
	Texture* mTextArea;
	Texture* mTopBar;
	Texture* mBottomBar;
	Texture* mPaperOverlay;
	Texture* mLabel;

	//Default text
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
	Texture* mTextLine12;
	Texture* mTextLine13;
	Texture* mTextLine14;
	Texture* mTextLine15;

	//Investigative Text
	Texture* mTextLine16;
	Texture* mTextLine17;
	Texture* mTextLine18;
	Texture* mTextLine19;
	Texture* mTextLine20;
	Texture* mTextLine21;
	Texture* mTextLine22;
	Texture* mTextLine23;

	//Rest
	Texture* mTextLine24;
	Texture* mTextLine25;

	Texture* mSymbol;

	Texture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};
