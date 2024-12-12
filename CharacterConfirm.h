#pragma once
#include "Level.h"
#include "Button.h"
#include "Player.h"

using namespace SDLFramework;

class CharacterConfirmation : public GameEntity {
public:
	CharacterConfirmation();
	~CharacterConfirmation();

	void SetupButtons();

	void Update() override;
	void Render() override;

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
	Texture* mConfirmText;
	Texture* mStr;
	Texture* mDex;
	Texture* mCon;
	Texture* mInt;
	Texture* mWis;
	Texture* mCha;
	Texture* mHP;

	Texture* mSymbol;

	std::string mRace;

	Texture* mCursorTexture;
	int mCursorWidth, mCursorHeight;
	SDL_Renderer* mRenderer;

	Level* mLevel;

};
