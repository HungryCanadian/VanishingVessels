#include "Town.h"
#include "GameManager.h"


TownScreen::TownScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInputManager = InputManager::Instance();
	mPlayer = Player::Instance();

	mTest = new SDLTexture("startBackground.png");
	mTest->Parent(this);
	mTest->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mTopBar = new SDLTexture("TopCornerBar.png");
	mTopBar->Parent(this);
	mTopBar->Position(Graphics::SCREEN_WIDTH * 0.285f, Graphics::SCREEN_HEIGHT * 0.065);
	mTopBar->Scale(Vector2(0.5f, 0.5f));

	mBottomBar = new SDLTexture("BottomBar.png");
	mBottomBar->Parent(this);
	mBottomBar->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.94f);
	mBottomBar->Scale(Vector2(0.4f, 0.3f));

	mTextArea = new SDLTexture("PanelDarkSquare.png");
	mTextArea->Parent(this);
	mTextArea->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	mTextArea->Scale(Vector2(0.5f, 0.5f));

	mPaperOverlay = new SDLTexture("LargePaperOverlay.png");
	mPaperOverlay->Parent(this);
	mPaperOverlay->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	mPaperOverlay->Scale(Vector2(0.5f, 0.5f));


	mSymbol = new SDLTexture(mPlayer->GetClass() + ".png");
	mSymbol->Parent(this);
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));

	mLabel = new SDLTexture("Town Center", "ToThePoint.ttf", 80, { 53,33,0 });
	mLabel->Parent(this);
	mLabel->Position(Graphics::SCREEN_WIDTH * 0.38f, Graphics::SCREEN_HEIGHT * 0.06f);
	mLabel->Visible(true);

	mTextLine1 = new SDLTexture("You wake up in your cozy bed at the tavern,", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.22f);
	mTextLine1->Visible(false);
	mTextLine2 = new SDLTexture("the smell of breakfast wafting through the air.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine2->Visible(false);
	mTextLine3 = new SDLTexture("You can hear the chatter of patrons and the clinking of mugs,", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine3->Visible(false);
	mTextLine4 = new SDLTexture("but your head is pounding. As you sit up, a wave of nausea hits you,", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine4->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine4->Visible(false);
	mTextLine5 = new SDLTexture("and you remember last night's revelry.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine5->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine5->Visible(false);
	mTextLine6 = new SDLTexture("You feel dehydrated and your mouth is dry; you crave water.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine6->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mTextLine6->Visible(false);
	mTextLine7 = new SDLTexture("A faint light coming through the window only intensifies your headache.", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine7->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.40f);
	mTextLine7->Visible(false);
	mTextLine8 = new SDLTexture("You get up slowly and gather your things.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine8->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.43f);
	mTextLine8->Visible(false);
	mTextLine9 = new SDLTexture("You meander your way out of the room and down the stairs to the tavern", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine9->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.46f);
	mTextLine9->Visible(false);


	mTextLine15 = new SDLTexture("The Town Center of Caspira pulses with life and activity, serving as the", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine15->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.22f);
	mTextLine15->Visible(true);
	mTextLine16 = new SDLTexture(" heart of the community. Cobblestone streets radiate from a central square,", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine16->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine16->Visible(true);
	mTextLine17 = new SDLTexture("where a grand fountain bubbles cheerfully, its water shimmering in the sunlight.", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine17->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine17->Visible(true);
	mTextLine18 = new SDLTexture("Surrounding the square, charming buildings with colorful facades house an array", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine18->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine18->Visible(true);
	mTextLine19 = new SDLTexture("of shops and stalls, each overflowing with goods that reflect the town's vibrant", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine19->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine19->Visible(true);
	mTextLine20 = new SDLTexture("culture. Merchants hawk their wares, from fresh produce and fragrant spices to", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine20->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mTextLine20->Visible(true);
	mTextLine21 = new SDLTexture("handmade crafts and shimmering trinkets, creating a lively atmosphere filled with", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine21->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.40f);
	mTextLine21->Visible(true);
	mTextLine22 = new SDLTexture("laughter and friendly banter. At the center of it all, townsfolk gather to share", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine22->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.43f);
	mTextLine22->Visible(true);
	mTextLine23 = new SDLTexture("news and stories, their voices blending into a harmonious chorus. Children dart", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine23->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.46f);
	mTextLine23->Visible(true);
	mTextLine24 = new SDLTexture("between stalls, their laughter mingling with the enticing aromaswafting from", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine24->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.49f);
	mTextLine24->Visible(true);
	mTextLine25 = new SDLTexture("nearby food vendors who serve steaming bowls of hearty stew and freshly baked", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine25->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.52f);
	mTextLine25->Visible(true);
	mTextLine26 = new SDLTexture("pastries. The Town Center is not just a marketplace but a gathering place, ", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine26->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mTextLine26->Visible(true);
	mTextLine27 = new SDLTexture("where community events and celebrations are held, bringing everyone together", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine27->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.58f);
	mTextLine27->Visible(true);
	mTextLine28 = new SDLTexture("in joyous unity.With its vibrant energy and rich tapestry of life, the Town Center", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine28->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.61f);
	mTextLine28->Visible(true);
	mTextLine29 = new SDLTexture("holds the spirit of Caspira, a place where connections areforged and memories are made.", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine29->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.64f);
	mTextLine29->Visible(true);
	mTextLine30 = new SDLTexture("Where would you like to go? East, West, or North?", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine30->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.44f);
	mTextLine30->Visible(false);
	mTextLine31 = new SDLTexture("East takes you Towards the Dock outskirts and the Docks.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine31->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.47f);
	mTextLine31->Visible(false);
	mTextLine32 = new SDLTexture("West takes you to the monster laden Graveyard.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine32->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.50f);
	mTextLine32->Visible(false);
	mTextLine33 = new SDLTexture("North takes you Towards the Lumbermill and the Heartwood Grove.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine33->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.53f);
	mTextLine33->Visible(false);



	mCursorTexture = new SDLTexture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor

	SetupButtons();

}

TownScreen::~TownScreen() {
	mTimer = nullptr;
	mAudio = nullptr;
	mPlayer = nullptr;


	delete mTest;
	mTest = nullptr;
	delete mTopBar;
	mTopBar = nullptr;
	delete mBottomBar;
	mBottomBar = nullptr;
	delete mTextArea;
	mTextArea = nullptr;
	delete mPaperOverlay;
	mPaperOverlay = nullptr;
	delete mLabel;
	mLabel = nullptr;

	delete mTextLine1;
	mTextLine1 = nullptr;
	delete mTextLine2;
	mTextLine2 = nullptr;
	delete mTextLine3;
	mTextLine3 = nullptr;
	delete mTextLine4;
	mTextLine4 = nullptr;
	delete mTextLine5;
	mTextLine5 = nullptr;
	delete mTextLine6;
	mTextLine6 = nullptr;
	delete mTextLine7;
	mTextLine7 = nullptr;
	delete mTextLine8;
	mTextLine8 = nullptr;
	delete mTextLine9;
	mTextLine9 = nullptr;

	delete mTextLine15;
	mTextLine15 = nullptr;
	delete mTextLine16;
	mTextLine16 = nullptr;
	delete mTextLine17;
	mTextLine17 = nullptr;
	delete mTextLine18;
	mTextLine18 = nullptr;
	delete mTextLine19;
	mTextLine19 = nullptr;
	delete mTextLine20;
	mTextLine20 = nullptr;
	delete mTextLine21;
	mTextLine21 = nullptr;
	delete mTextLine22;
	mTextLine22 = nullptr;
	delete mTextLine23;
	mTextLine23 = nullptr;
	delete mTextLine24;
	mTextLine24 = nullptr;
	delete mTextLine25;
	mTextLine25 = nullptr;
	delete mTextLine26;
	mTextLine26 = nullptr;
	delete mTextLine27;
	mTextLine27 = nullptr;
	delete mTextLine28;
	mTextLine28 = nullptr;
	delete mTextLine29;
	mTextLine29 = nullptr;
	delete mTextLine30;
	mTextLine30 = nullptr;
	delete mTextLine31;
	mTextLine31 = nullptr;
	delete mTextLine32;
	mTextLine32 = nullptr;
	delete mTextLine33;
	mTextLine33 = nullptr;

	delete mSymbol;
	mSymbol = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}

void TownScreen::Leave() {
	mTextLine1->Visible(false);
	mTextLine2->Visible(false);
	mTextLine3->Visible(false);
	mTextLine4->Visible(false);
	mTextLine5->Visible(false);
	mTextLine6->Visible(false);
	mTextLine7->Visible(false);
	mTextLine8->Visible(false);
	mTextLine9->Visible(false);
	mTextLine14->Visible(false);

	mTextLine15->Visible(true);
	mTextLine16->Visible(true);
	mTextLine17->Visible(true);
	mTextLine18->Visible(true);
	mTextLine19->Visible(true);
	mTextLine20->Visible(true);
	mTextLine21->Visible(true);
	mTextLine22->Visible(true);
	mTextLine23->Visible(true);
	mTextLine24->Visible(true);
	mTextLine25->Visible(true);
	mTextLine26->Visible(true);
	mTextLine27->Visible(true);
	mTextLine28->Visible(true);
	mTextLine29->Visible(true);
	mTextLine30->Visible(false);
	mTextLine31->Visible(false);
	mTextLine32->Visible(false);
	mTextLine33->Visible(false);

	mButtons[2].Visible(false);
	mButtons[3].Visible(true);
	mButtons[4].Visible(false);
	mButtons[5].Visible(true);
	mButtons[6].Visible(false);
	mButtons[7].Visible(false);
	mButtons[8].Visible(false);
	mButtons[9].Visible(false);
	mButtons[10].Visible(false);
}

void TownScreen::Description() {
	mTextLine1->Visible(false);
	mTextLine2->Visible(false);
	mTextLine3->Visible(false);
	mTextLine4->Visible(false);
	mTextLine5->Visible(false);
	mTextLine6->Visible(false);
	mTextLine7->Visible(false);
	mTextLine8->Visible(false);
	mTextLine9->Visible(false);

	mTextLine15->Visible(true);
	mTextLine16->Visible(true);
	mTextLine17->Visible(true);
	mTextLine18->Visible(true);
	mTextLine19->Visible(true);
	mTextLine20->Visible(true);
	mTextLine21->Visible(true);
	mTextLine22->Visible(true);
	mTextLine23->Visible(true);
	mTextLine24->Visible(true);
	mTextLine25->Visible(true);
	mTextLine26->Visible(true);
	mTextLine27->Visible(true);
	mTextLine28->Visible(true);
	mTextLine29->Visible(true);
	mTextLine30->Visible(false);
	mTextLine31->Visible(false);
	mTextLine32->Visible(false);
	mTextLine33->Visible(false);
	
	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(false);
	mButtons[3].Visible(true);
	mButtons[4].Visible(true);
	mButtons[5].Visible(true);
	mButtons[6].Visible(false);
	mButtons[7].Visible(false);
	mButtons[8].Visible(false);
	mButtons[9].Visible(false);
	mButtons[10].Visible(true);
	
}

void TownScreen::DefaultText() {
	mTextLine1->Visible(false);
	mTextLine2->Visible(false);
	mTextLine3->Visible(false);
	mTextLine4->Visible(false);
	mTextLine5->Visible(false);
	mTextLine6->Visible(false);
	mTextLine7->Visible(false);
	mTextLine8->Visible(false);
	mTextLine9->Visible(false);
	mTextLine15->Visible(true);
	mTextLine16->Visible(true);
	mTextLine17->Visible(true);
	mTextLine18->Visible(true);
	mTextLine19->Visible(true);
	mTextLine20->Visible(true);
	mTextLine21->Visible(true);
	mTextLine22->Visible(true);
	mTextLine23->Visible(true);
	mTextLine24->Visible(true);
	mTextLine25->Visible(true);
	mTextLine26->Visible(true);
	mTextLine27->Visible(true);
	mTextLine28->Visible(true);
	mTextLine29->Visible(true);
	mTextLine30->Visible(false);
	mTextLine31->Visible(false);
	mTextLine32->Visible(false);
	mTextLine33->Visible(false);


	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(true);
	mButtons[3].Visible(false);
	mButtons[4].Visible(true);
	mButtons[5].Visible(false);
	mButtons[6].Visible(true);
	mButtons[7].Visible(false);
	mButtons[8].Visible(false);
	mButtons[9].Visible(false);
	mButtons[10].Visible(false);
}

void TownScreen::LeaveTown() {
	mTextLine1->Visible(false);
	mTextLine2->Visible(false);
	mTextLine3->Visible(false);
	mTextLine4->Visible(false);
	mTextLine5->Visible(false);
	mTextLine6->Visible(false);
	mTextLine7->Visible(false);
	mTextLine8->Visible(false);
	mTextLine9->Visible(false);

	mTextLine15->Visible(false);
	mTextLine16->Visible(false);
	mTextLine17->Visible(false);
	mTextLine18->Visible(false);
	mTextLine19->Visible(false);
	mTextLine20->Visible(false);
	mTextLine21->Visible(false);
	mTextLine22->Visible(false);
	mTextLine23->Visible(false);
	mTextLine24->Visible(false);
	mTextLine25->Visible(false);
	mTextLine26->Visible(false);
	mTextLine27->Visible(false);
	mTextLine28->Visible(false);
	mTextLine29->Visible(false);
	mTextLine30->Visible(true);
	mTextLine31->Visible(true);
	mTextLine32->Visible(true);
	mTextLine33->Visible(true);

	mButtons[2].Visible(false);
	mButtons[3].Visible(false);
	mButtons[4].Visible(false);
	mButtons[5].Visible(false);
	mButtons[6].Visible(true);
	mButtons[7].Visible(true);
	mButtons[8].Visible(true);
	mButtons[9].Visible(true);
	mButtons[10].Visible(false);
}

void TownScreen::SetupButtons() {
	Button* BackButton = new Button(Graphics::SCREEN_WIDTH * 0.27f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* QuitButton = new Button(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* InvestigateButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Investigate", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* MerchantButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Merchant", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* InventoryButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Inventory", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* BlacksmithButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Blacksmith", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* LeaveButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Leave", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* EastButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "East", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* WestButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "West", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* NorthButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "North", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* TavernButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Tavern", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");



	// Add buttons to the mButtons list
	mButtons.push_back(*BackButton);
	mButtons.push_back(*QuitButton);
	mButtons.push_back(*InvestigateButton);
	mButtons.push_back(*BlacksmithButton);
	mButtons.push_back(*InventoryButton);
	mButtons.push_back(*MerchantButton);
	mButtons.push_back(*LeaveButton);
	mButtons.push_back(*EastButton);
	mButtons.push_back(*WestButton);
	mButtons.push_back(*NorthButton);
	mButtons.push_back(*TavernButton);


	mButtons[5].Visible(false);
	mButtons[3].Visible(false);
	mButtons[7].Visible(false);
	mButtons[8].Visible(false);
	mButtons[9].Visible(false);
	mButtons[10].Visible(false);

}


void TownScreen::Update() {
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	// Check button hover state
	for (auto& btn : mButtons) {
		btn.checkHover(mouseX, mouseY);
	}
	mSymbol = new SDLTexture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));
	mSymbol->Update();


	// Handle mouse clicks on buttons
	if (mInputManager->MouseButtonPressed(InputManager::LEFT)) {
		for (auto& btn : mButtons) {
			if (btn.isHovered) {
				mAudio->PlaySFX("buttonClick.wav", 0, -1, 50);
				if (btn.label == "Back") {
					DefaultText();
				}
				else if (btn.label == "Quit") {
					GameManager::Instance()->QuitGame();

				}
				else if (btn.label == "Investigate") {
					Description();
				}
				else if (btn.label == "Inventory") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Inventory);
				}
				else if (btn.label == "Merchant") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Merchant);
				}
				else if (btn.label == "Blacksmith") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Blacksmith);
				}
				else if (btn.label == "Leave") {
					LeaveTown();
				}
				else if (btn.label == "East") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::East);
				}
				else if (btn.label == "West") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::West);
				}
				else if (btn.label == "North") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::North);
				}
				else if (btn.label == "Tavern") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Tavern);
				}
			}
		}
	}
}



void TownScreen::Render() {
	if (mTest->Visible()) mTest->Render();
	if (mTextArea->Visible()) mTextArea->Render();
	if (mPaperOverlay->Visible()) mPaperOverlay->Render();
	if (mTopBar->Visible()) mTopBar->Render();
	if (mSymbol->Visible()) mSymbol->Render();
	if (mBottomBar->Visible()) mBottomBar->Render();
	if (mLabel->Visible()) mLabel->Render();

	//First block of text 'waking up'
	if (mTextLine1->Visible()) mTextLine1->Render();
	if (mTextLine2->Visible()) mTextLine2->Render();
	if (mTextLine3->Visible()) mTextLine3->Render();
	if (mTextLine4->Visible()) mTextLine4->Render();
	if (mTextLine5->Visible()) mTextLine5->Render();
	if (mTextLine6->Visible()) mTextLine6->Render();
	if (mTextLine7->Visible()) mTextLine7->Render();
	if (mTextLine8->Visible()) mTextLine8->Render();
	if (mTextLine9->Visible()) mTextLine9->Render();

	//Regular Investigation
	if (mTextLine15->Visible()) mTextLine15->Render();
	if (mTextLine16->Visible()) mTextLine16->Render();
	if (mTextLine17->Visible()) mTextLine17->Render();
	if (mTextLine18->Visible()) mTextLine18->Render();
	if (mTextLine19->Visible()) mTextLine19->Render();
	if (mTextLine20->Visible()) mTextLine20->Render();
	if (mTextLine21->Visible()) mTextLine21->Render();
	if (mTextLine22->Visible()) mTextLine22->Render();
	if (mTextLine23->Visible()) mTextLine23->Render();
	if (mTextLine24->Visible()) mTextLine24->Render();
	if (mTextLine25->Visible()) mTextLine25->Render();
	if (mTextLine26->Visible()) mTextLine26->Render();
	if (mTextLine27->Visible()) mTextLine27->Render();
	if (mTextLine28->Visible()) mTextLine28->Render();
	if (mTextLine29->Visible()) mTextLine29->Render();
	if (mTextLine30->Visible()) mTextLine30->Render();
	if (mTextLine31->Visible()) mTextLine31->Render();
	if (mTextLine32->Visible()) mTextLine32->Render();
	if (mTextLine33->Visible()) mTextLine33->Render();



	for (auto& btn : mButtons) {
		if (btn.Visible()) {
			btn.render();
		}
	}

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}