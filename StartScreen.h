#pragma once
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Scoreboard.h"
#include "Button.h"


using namespace SDLFramework;

class StartScreen : public GameEntity {
public:
	StartScreen();
	~StartScreen();


	
	void ResetAnimation();
	void SetupButtons();

	void Update() override;
	void Render() override;

private:
	Timer* mTimer;
	InputManager* mInputManager;
	AudioManager* mAudioManager;


	SDLTexture* mBackground;
	SDLTexture* mTitleHeadboard;
	SDLTexture* mTitleBackground;
	SDLTexture* mPaperOverlay;
	SDLTexture* mCaspiraLogo;
	SDLTexture* mVanishVessels;
	SDLTexture* mOfCaspira;

	SDLTexture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

	SDLTexture* mButtonTexture;
	AudioManager* mMusic;

	//Top Bar Entities
	//Empty game Object/Entity
	GameEntity* mTopBar;


	//Logo Entities
	GameEntity* mLogoSpace;
	

	//Play Mode
	GameEntity* mPlayModes;


	//Bottom Bar
	GameEntity* mBottomBar;

	std::vector<Button> mButtons;

};