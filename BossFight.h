#pragma once
#include <cstdlib>
#include "Level.h"
#include "Button.h"
#include "Player.h"
#include "Enemy.h"

using namespace SDLFramework;

class BossScreen : public GameEntity {
public:
	BossScreen();
	~BossScreen();

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
	GLTexture* mTextLine14;
	GLTexture* mTextLine15;
	GLTexture* mTextLine16;
	GLTexture* mTextLine17;
	GLTexture* mTextLine18;
	GLTexture* mTextLine19;
	GLTexture* mTextLine20;

	GLTexture* mSymbol;

	GLTexture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};
