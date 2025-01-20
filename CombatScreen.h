#pragma once
#include <cstdlib>
#include "Level.h"
#include "Button.h"
#include "Player.h"
#include "Enemy.h"

using namespace SDLFramework;

class CombatScreen : public GameEntity {
public:
	CombatScreen();
	~CombatScreen();

	void SetupButtons();
	void DefaultText();
	void Attack();
	void UseItem();
	void Run();
	void Victory();
	void GameOver();
	void EnemyTurn();
	void SpecialMove();
	Enemy GetRandomEnemy();

	void Update() override;
	void Render() override;

private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInputManager;
	std::vector<Button> mButtons;
	Player* mPlayer;
	Enemy mCurrentEnemy;


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

	SDLTexture* mSymbol;

	SDLTexture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};

