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
	std::vector<SDLTexture*> mTextLines;
	Player* mPlayer;
	SDLTexture* mSymbol;
	SDLTexture* mLabel;

	SDLTexture* mTest;
	SDLTexture* mTextArea;
	SDLTexture* mTopBar;
	SDLTexture* mBottomBar;
	SDLTexture* mPaperOverlay;
	SDLTexture* mTextLine1;
	SDLTexture* mTextLine2;
	SDLTexture* mTextLine3;
	SDLTexture* mPrice1;
	SDLTexture* mPrice2;
	SDLTexture* mPrice3;
	SDLTexture* mPrice4;
	SDLTexture* mPrice5;
	SDLTexture* mPrice6;
	SDLTexture* mPrice7;
	SDLTexture* mBroke;
	SDLTexture* mSold;
	SDLTexture* mSoldOut;

	float mBrokeTimer;
	float mBrokeDelay;

	SDLTexture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};