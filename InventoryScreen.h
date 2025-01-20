#pragma once
#include "Level.h"
#include "Scoreboard.h"
#include "AnimatedTexture.h"
#include "Button.h"
#include "Inventory.h"


using namespace SDLFramework;

class InventoryScreen : public GameEntity {
public:
	InventoryScreen();
	~InventoryScreen();

	void SetupButtons();
	void DisplayInventoryItem(std::vector<Inventory> inventory);
	void DisplayConsumableItems(std::vector<Inventory> inventory);
	void DisplayEquippableItems(std::vector<Inventory> inventory);
	std::vector<Inventory>& GetMerchantInventory();
	std::vector<Inventory>& GetBlacksmithInventory();
	std::vector<Inventory>& GetPlayerInventory();

	void Update() override;
	void Render() override;

	float mFlashTimer;
	float mFlashDelay;

private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInputManager;
	Inventory* mInventory;
	std::vector<Button> mButtons;
	std::vector<SDLTexture*> mTextLines;
	Player* mPlayer;

	SDLTexture* mTest;
	SDLTexture* mTextArea;
	SDLTexture* mTopBar;
	SDLTexture* mBottomBar;
	SDLTexture* mPaperOverlay;

	SDLTexture* mSymbol;
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


	SDLTexture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

	Level* mLevel;

};