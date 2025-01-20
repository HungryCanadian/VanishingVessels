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
	std::vector<GLTexture*> mTextLines;
	Player* mPlayer;
	GLTexture* mSymbol;
	GLTexture* mLabel;

	GLTexture* mTest;
	GLTexture* mTextArea;
	GLTexture* mTopBar;
	GLTexture* mBottomBar;
	GLTexture* mPaperOverlay;
	GLTexture* mTextLine1;
	GLTexture* mTextLine2;
	GLTexture* mTextLine3;
	GLTexture* mPrice1;
	GLTexture* mPrice2;
	GLTexture* mPrice3;
	GLTexture* mPrice4;
	GLTexture* mBroke;

	float mBrokeTimer;
	float mBrokeDelay;

	GLTexture* mCursorTexture;
	int mCursorWidth, mCursorHeight;

};