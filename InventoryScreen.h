#pragma once
#include "Level.h"
#include "Scoreboard.h"
#include "AnimatedTexture.h"
#include "Button.h"
#include "TextInput.h"
#include "Inventory.h"


using namespace SDLFramework;

class InventoryScreen : public GameEntity {
public:
	InventoryScreen();
	~InventoryScreen();

	void SetupButtons();
	void DisplayInventoryItem(std::vector<Inventory> inventory);
	void DisplayConsumableItems(std::vector<Inventory> inventory);

	void Update() override;
	void Render() override;

	bool GameOver();

private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInputManager;
	Inventory* mInventory;
	std::vector<Button> mButtons;
	std::vector<Texture*> mTextLines;

	Texture* mTest;
	Texture* mTextArea;
	Texture* mTopBar;
	Texture* mBottomBar;
	Texture* mPaperOverlay;
	TextInput* mName;

	Texture* mSymbol;

	Texture* mTextLine1;
	Texture* mTextLine2;
	Texture* mTextLine3;
	Texture* mTextLine4;
	Texture* mTextLine5;
	Texture* mTextLine6;
	Texture* mTextLine7;
	Texture* mTextLine8;
	Texture* mTextLine9;


	Texture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

	Level* mLevel;

};