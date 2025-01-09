#pragma once
#include "Level.h"
#include "Button.h"
#include "Player.h"

using namespace SDLFramework;

class HeartwoodGrove : public GameEntity {
public:
	HeartwoodGrove();
	~HeartwoodGrove();

	void SetupButtons();
	void DefaultText();
	void Barbossa();


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

	Texture* mSymbol;

	Texture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};
