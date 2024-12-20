#pragma once
#include "InventoryScreen.h"

using namespace SDLFramework;


class MerchantScreen : public GameEntity {
public:
	MerchantScreen();
	~MerchantScreen();

	void RunMerchant(Player* player);
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
	Texture* mPrice5;
	Texture* mPrice6;
	Texture* mPrice7;
	Texture* mBroke;
	Texture* mSold;
	Texture* mSoldOut;

	float mBrokeTimer;
	float mBrokeDelay;

	Texture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};