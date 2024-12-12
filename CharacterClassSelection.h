#pragma once
#include "Level.h"
#include "Scoreboard.h"
#include "AnimatedTexture.h"
#include "Button.h"
#include "TextInput.h"
#include "Player.h"

using namespace SDLFramework;

 class CharacterClassScreen : public GameEntity{
 public:
	 CharacterClassScreen();
	 ~CharacterClassScreen();

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
	 Texture* mHumanText;
	 Texture* mElfText;
	 Texture* mDwarfText;
	 Texture* mGnomeText;
	 Texture* mHalflingText;
	 Texture* mTieflingText;
	 Texture* mConfirmText;

	 Texture* mCursorTexture;
	 int mCursorWidth, mCursorHeight;
	 SDL_Renderer* mRenderer;

	 Level* mLevel;

 };
