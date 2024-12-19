#pragma once
#include "InventoryScreen.h"

using namespace SDLFramework;


class BlacksmithScreen : public GameEntity {
public:
	BlacksmithScreen();
	~BlacksmithScreen();

	void RunBlacksmith(Player* player);
	void SetupButtons();

	void DefaultScreen();

	void Update() override;
	void Render() override;

private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInputManager;
	Inventory* mInventory;
	std::vector<Button> mButtons;
	std::vector<Texture*> mTextLines;
	Player* mPlayer;
	Texture* mSymbol;

	Texture* mTest;
	Texture* mTextArea;
	Texture* mTopBar;
	Texture* mBottomBar;
	Texture* mPaperOverlay;
	Texture* mTextLine1;
	Texture* mTextLine2;
	Texture* mTextLine3;
	Texture* mPrice1;
	Texture* mPrice2;
	Texture* mPrice3;
	Texture* mPrice4;
	Texture* mBroke;

	float mBrokeTimer;
	float mBrokeDelay;

	Texture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};