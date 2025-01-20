#include "Docks.h"
#include "GameManager.h"


DockScreen::DockScreen() {
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

	mLabel = new SDLTexture("Caspira Docks", "ToThePoint.ttf", 80, { 53,33,0 });
	mLabel->Parent(this);
	mLabel->Position(Graphics::SCREEN_WIDTH * 0.38f, Graphics::SCREEN_HEIGHT * 0.06f);
	mLabel->Visible(true);

	//default text
	mTextLine1 = new SDLTexture("From the heart of the rundown neighborhood, a marvelous stone gatehouse rises majestically,", "ToThePoint.ttf", 30, { 0,0,0 });
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.22f);
	mTextLine1->Visible(true);
	mTextLine2 = new SDLTexture("its formidable walls encircling the Official Caspiran Docks like a guardian of prosperity.", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine2->Visible(true);
	mTextLine3 = new SDLTexture("The entrance, adorned with intricate carvings of maritime symbols, stands as a striking", "ToThePoint.ttf", 32, { 0,0,0 });
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine3->Visible(true);
	mTextLine4 = new SDLTexture("contrast to the surrounding dilapidation, beckoning travelers and townsfolk alike", "ToThePoint.ttf", 34, { 0,0,0 });
	mTextLine4->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine4->Visible(true);
	mTextLine5 = new SDLTexture("to experience the allure within. As one passes through the arched gates, ", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine5->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine5->Visible(true);
	mTextLine6 = new SDLTexture("the atmosphere shifts dramatically, revealing a bustling hub of activity", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine6->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mTextLine6->Visible(true);
	mTextLine7 = new SDLTexture("that breathes life into the port city.", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine7->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.40f);
	mTextLine7->Visible(true);
	mTextLine8 = new SDLTexture("Inside the walls, the docks present an epitome of wealth and extravagance,", "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine8->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.43f);
	mTextLine8->Visible(true);
	mTextLine9 = new SDLTexture("with wide stone wharfs stretching out toward the shimmering waters. Several opulent", "ToThePoint.ttf", 30, { 0,0,0 });
	mTextLine9->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.46f);
	mTextLine9->Visible(true);
	mTextLine10 = new SDLTexture("ships are anchored in the harbor, their sails furled and decks alive with ", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine10->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.49f);
	mTextLine10->Visible(true);
	mTextLine11 = new SDLTexture("crew members unloading cargo of all kinds. The air is filled with the", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine11->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.52f);
	mTextLine11->Visible(true);
	mTextLine12 = new SDLTexture("sounds of shouts and laughter, mingling with the creaking of wood and the", "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine12->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mTextLine12->Visible(true);
	mTextLine13 = new SDLTexture("sloshing of waves against the hulls. Merchants barter energetically, their voices", "ToThePoint.ttf", 33, { 0,0,0 });
	mTextLine13->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.58f);
	mTextLine13->Visible(true);
	mTextLine14 = new SDLTexture("rising above the din as they display their wares, exotic spices, silks, and shimmering", "ToThePoint.ttf", 30, { 0,0,0 });
	mTextLine14->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.61f);
	mTextLine14->Visible(true);
	mTextLine15 = new SDLTexture("trinkets, all promising tales of distant lands and adventures untold.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine15->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.64f);
	mTextLine15->Visible(true);

	//Investigate Text
	mTextLine16 = new SDLTexture("As the sun bathes the docks in golden light, the delightful aroma of", "ToThePoint.ttf", 34, { 0,0,0 });
	mTextLine16->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.24f);
	mTextLine16->Visible(false);
	mTextLine17 = new SDLTexture("freshly cooked food wafts through the air, mingling with the rich scent", "ToThePoint.ttf", 34, { 0,0,0 });
	mTextLine17->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.27f);
	mTextLine17->Visible(false);
	mTextLine18 = new SDLTexture("of ale poured from tankards at nearby taverns. The laughter of patrons", "ToThePoint.ttf", 34, { 0,0,0 });
	mTextLine18->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.30f);
	mTextLine18->Visible(false);
	mTextLine19 = new SDLTexture("spills into the streets, creating a vibrant backdrop to the industriousness", "ToThePoint.ttf", 34, { 0,0,0 });
	mTextLine19->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.33f);
	mTextLine19->Visible(false);
	mTextLine20 = new SDLTexture("of the docks. Here, amidst the contrast of wealth and the bustling life", "ToThePoint.ttf", 34, { 0,0,0 });
	mTextLine20->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.36f);
	mTextLine20->Visible(false);
	mTextLine21 = new SDLTexture("of the port, one can feel the pulse ofthe city. A place where dreams of", "ToThePoint.ttf", 34, { 0,0,0 });
	mTextLine21->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.39f);
	mTextLine21->Visible(false);
	mTextLine22 = new SDLTexture("adventure and fortune intertwine, drawing in both the weary and.", "ToThePoint.ttf", 34, { 0,0,0 });
	mTextLine22->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.42f);
	mTextLine22->Visible(false);
	mTextLine23 = new SDLTexture("the hopeful to partake in its splendor.", "ToThePoint.ttf", 34, { 0,0,0 });
	mTextLine23->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.45f);
	mTextLine23->Visible(false);

	//Rest
	mTextLine24 = new SDLTexture("Welcome to the Weary Wanderer!", "ToThePoint.ttf", 52, { 0,0,0 });
	mTextLine24->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.32f);
	mTextLine24->Visible(false);
	mTextLine25 = new SDLTexture("Want to rest for the night?", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine25->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.36f);
	mTextLine25->Visible(false);

	mCursorTexture = new SDLTexture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor

	SetupButtons();

}

DockScreen::~DockScreen() {
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

	//Default Text
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
	delete mTextLine10;
	mTextLine10 = nullptr;
	delete mTextLine11;
	mTextLine11 = nullptr;
	delete mTextLine12;
	mTextLine12 = nullptr;
	delete mTextLine13;
	mTextLine13 = nullptr;
	delete mTextLine14;
	mTextLine14 = nullptr;
	delete mTextLine15;
	mTextLine15 = nullptr;

	//Investigate Text
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

	//Rest
	delete mTextLine24;
	mTextLine24 = nullptr;
	delete mTextLine25;
	mTextLine25 = nullptr;

	delete mSymbol;
	mSymbol = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}


void DockScreen::DefaultText() {
	mButtons[4].Visible(false);
	mButtons[6].Visible(false);
	mTextLine1->Visible(true);
	mTextLine2->Visible(true);
	mTextLine3->Visible(true);
	mTextLine4->Visible(true);
	mTextLine5->Visible(true);
	mTextLine6->Visible(true);
	mTextLine7->Visible(true);
	mTextLine8->Visible(true);
	mTextLine9->Visible(true);
	mTextLine10->Visible(true);
	mTextLine11->Visible(true);
	mTextLine12->Visible(true);
	mTextLine13->Visible(true);
	mTextLine14->Visible(true);
	mTextLine15->Visible(true);

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


	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(true);
	mButtons[3].Visible(true);
	mButtons[4].Visible(false);
	mButtons[5].Visible(true);

}

void DockScreen::Investigate() {
	mTextLine1->Visible(false);
	mTextLine2->Visible(false);
	mTextLine3->Visible(false);
	mTextLine4->Visible(false);
	mTextLine5->Visible(false);
	mTextLine6->Visible(false);
	mTextLine7->Visible(false);
	mTextLine8->Visible(false);
	mTextLine9->Visible(false);
	mTextLine10->Visible(false);
	mTextLine11->Visible(false);
	mTextLine12->Visible(false);
	mTextLine13->Visible(false);
	mTextLine14->Visible(false);
	mTextLine15->Visible(false);

	mTextLine16->Visible(true);
	mTextLine17->Visible(true);
	mTextLine18->Visible(true);
	mTextLine19->Visible(true);
	mTextLine20->Visible(true);
	mTextLine21->Visible(true);
	mTextLine22->Visible(true);
	mTextLine23->Visible(true);
	mTextLine24->Visible(false);
	mTextLine25->Visible(false);


	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(true);
	mButtons[3].Visible(true);
	mButtons[4].Visible(true);
	mButtons[5].Visible(false);
	mButtons[6].Visible(false);

}

void DockScreen::Rest() {
	mTextLine1->Visible(false);
	mTextLine2->Visible(false);
	mTextLine3->Visible(false);
	mTextLine4->Visible(false);
	mTextLine5->Visible(false);
	mTextLine6->Visible(false);
	mTextLine7->Visible(false);
	mTextLine8->Visible(false);
	mTextLine9->Visible(false);

	mButtons[4].Visible(false);
	mButtons[6].Visible(true);

	mTextLine10->Visible(false);
	mTextLine11->Visible(false);
	mTextLine12->Visible(false);
	mTextLine13->Visible(false);

	mTextLine14->Visible(false);
	mTextLine15->Visible(false);
	mTextLine16->Visible(false);
	mTextLine17->Visible(false);
	mTextLine18->Visible(false);
	mTextLine19->Visible(false);
	mTextLine20->Visible(false);
	mTextLine21->Visible(false);
	mTextLine22->Visible(false);
	mTextLine23->Visible(false);
	mTextLine24->Visible(true);
	mTextLine25->Visible(true);
}

void DockScreen::SetupButtons() {
	Button* BackButton = new Button(Graphics::SCREEN_WIDTH * 0.27f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* QuitButton = new Button(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* InvestigateButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Investigate", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* InventoryButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Inventory", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* RestButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Rest", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* OutskirtsButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Docks Outskirts", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* ConfirmButton = new Button(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.6f, 190, 42, "Confirm", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");



	// Add buttons to the mButtons list
	mButtons.push_back(*BackButton);
	mButtons.push_back(*QuitButton);
	mButtons.push_back(*InvestigateButton);
	mButtons.push_back(*InventoryButton);
	mButtons.push_back(*RestButton);
	mButtons.push_back(*OutskirtsButton);
	mButtons.push_back(*ConfirmButton);

	mButtons[4].Visible(false);
	mButtons[6].Visible(false);

}


void DockScreen::Update() {
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
					Investigate();
				}
				else if (btn.label == "Inventory") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Inventory);
				}
				else if (btn.label == "Docks Outskirts") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Outskirts);
				}
				else if (btn.label == "Rest") {
					Rest();
				}
				else if (btn.label == "Confirm") {
					mPlayer->FullHeal();
					DefaultText();
				}

			}
		}
	}
}



void DockScreen::Render() {
	if (mTest->Visible()) mTest->Render();
	if (mTextArea->Visible()) mTextArea->Render();
	if (mPaperOverlay->Visible()) mPaperOverlay->Render();
	if (mTopBar->Visible()) mTopBar->Render();
	if (mSymbol->Visible()) mSymbol->Render();
	if (mBottomBar->Visible()) mBottomBar->Render();
	if (mLabel->Visible()) mLabel->Render();

	//Default Text
	if (mTextLine1->Visible()) mTextLine1->Render();
	if (mTextLine2->Visible()) mTextLine2->Render();
	if (mTextLine3->Visible()) mTextLine3->Render();
	if (mTextLine4->Visible()) mTextLine4->Render();
	if (mTextLine5->Visible()) mTextLine5->Render();
	if (mTextLine6->Visible()) mTextLine6->Render();
	if (mTextLine7->Visible()) mTextLine7->Render();
	if (mTextLine8->Visible()) mTextLine8->Render();
	if (mTextLine9->Visible()) mTextLine9->Render();
	if (mTextLine10->Visible()) mTextLine10->Render();
	if (mTextLine11->Visible()) mTextLine11->Render();
	if (mTextLine12->Visible()) mTextLine12->Render();
	if (mTextLine13->Visible()) mTextLine13->Render();
	if (mTextLine14->Visible()) mTextLine14->Render();
	if (mTextLine15->Visible()) mTextLine15->Render();

	//Investigate Text
	if (mTextLine16->Visible()) mTextLine16->Render();
	if (mTextLine17->Visible()) mTextLine17->Render();
	if (mTextLine18->Visible()) mTextLine18->Render();
	if (mTextLine19->Visible()) mTextLine19->Render();
	if (mTextLine20->Visible()) mTextLine20->Render();
	if (mTextLine21->Visible()) mTextLine21->Render();
	if (mTextLine22->Visible()) mTextLine22->Render();
	if (mTextLine23->Visible()) mTextLine23->Render();

	//Rest
	if (mTextLine24->Visible()) mTextLine24->Render();
	if (mTextLine25->Visible()) mTextLine25->Render();

	for (auto& btn : mButtons) {
		if (btn.Visible()) {
			btn.render();
		}
	}

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}