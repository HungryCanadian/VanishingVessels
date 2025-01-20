#pragma once
#include "Level.h"
#include "Button.h"
#include "Player.h"

using namespace SDLFramework;

class HallOfAncestors : public GameEntity {
public:
	HallOfAncestors();
	~HallOfAncestors();

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

	GLTexture* mTest;
	GLTexture* mTextArea;
	GLTexture* mTopBar;
	GLTexture* mBottomBar;
	GLTexture* mPaperOverlay;
	GLTexture* mLabel;

	GLTexture* mTextLine1;
	GLTexture* mTextLine2;
	GLTexture* mTextLine3;
	GLTexture* mTextLine4;
	GLTexture* mTextLine5;
	GLTexture* mTextLine6;
	GLTexture* mTextLine7;
	GLTexture* mTextLine8;
	GLTexture* mTextLine9;
	GLTexture* mTextLine10;

	GLTexture* mTextLine11;
	GLTexture* mTextLine12;
	GLTexture* mTextLine13;

	GLTexture* mSymbol;

	GLTexture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};
