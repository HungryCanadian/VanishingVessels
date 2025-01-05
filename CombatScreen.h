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
	Texture* mTextLine11;

	Texture* mSymbol;

	Texture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};

