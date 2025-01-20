#include "Tavern.h"
#include "GameManager.h"


TavernScreen::TavernScreen() {
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

	mLabel = new SDLTexture("Tavern", "ToThePoint.ttf", 80, { 53,33,0 });
	mLabel->Parent(this);
	mLabel->Position(Graphics::SCREEN_WIDTH * 0.38f, Graphics::SCREEN_HEIGHT * 0.06f);
	mLabel->Visible(true);

	mTextLine1 = new SDLTexture("You wake up in your cozy bed at the tavern,", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.22f);
	mTextLine2 = new SDLTexture("the smell of breakfast wafting through the air.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine3 = new SDLTexture("You can hear the chatter of patrons and the clinking of mugs,", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine4 = new SDLTexture("but your head is pounding. As you sit up, a wave of nausea hits you,", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine4->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine5 = new SDLTexture("and you remember last night's revelry.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine5->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine6 = new SDLTexture("You feel dehydrated and your mouth is dry; you crave water.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine6->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mTextLine7 = new SDLTexture("A faint light coming through the window only intensifies your headache.", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine7->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.40f);
	mTextLine8 = new SDLTexture("You get up slowly and gather your things.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine8->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.43f);
	mTextLine9 = new SDLTexture("You meander your way out of the room and down the stairs to the tavern", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine9->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.46f);

	mTextLine10 = new SDLTexture("Barbossa: You alright there? you seem a little dazed and confused.", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine10->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine10->Visible(false);
	mTextLine11 = new SDLTexture("Barbossa: Well, I would have a hangover too if I drank several bottles of rum.", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine11->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine11->Visible(false);
	mTextLine12 = new SDLTexture("Barbossa: I do have some Errands to run, but breakfast is on the house!", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine12->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine12->Visible(false);
	mTextLine13 = new SDLTexture("Barbossa: If you need anything, Varun can help you!", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine13->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mTextLine13->Visible(false);

	mTextLine14 = new SDLTexture("Varun: Would you like to rest for the night?", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine14->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine14->Visible(false);

	mTextLine15 = new SDLTexture("The old tavern, with its creaky wooden floorboards and dimly lit corners,", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine15->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.22f);
	mTextLine15->Visible(false);
	mTextLine16 = new SDLTexture("feels almost forgotten in the morning light. The air is thick", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine16->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine16->Visible(false);
	mTextLine17 = new SDLTexture("with the scent of stale ale and smoke, remnants of last night's", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine17->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine17->Visible(false);
	mTextLine18 = new SDLTexture("revelry still hanging heavy. A few weary patrons sit hunched", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine18->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine18->Visible(false);
	mTextLine19 = new SDLTexture("over at the bar, nursing mugs of water or weak coffee,", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine19->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine19->Visible(false);
	mTextLine20 = new SDLTexture("their eyes tired and unfocused. The once-lively space now ", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine20->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mTextLine20->Visible(false);
	mTextLine21 = new SDLTexture("holds only the soft clink of glass and the quiet hum of murmurs,", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine21->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.40f);
	mTextLine21->Visible(false);
	mTextLine22 = new SDLTexture("as sunlight filters lazily through dusty windows, casting long", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine22->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.43f);
	mTextLine22->Visible(false);
	mTextLine23 = new SDLTexture("shadows across the worn furniture. The rowdy energy ", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine23->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.46f);
	mTextLine23->Visible(false); 
	mTextLine24 = new SDLTexture("of the night has faded, leaving only the quiet hum of recovery.", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine24->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.49f);
	mTextLine24->Visible(false);

	mFirstVisit = true;

	mCursorTexture = new SDLTexture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor

	Mix_VolumeMusic(10);
	//mAudio->PlayMusic("TavernTheme.wav", -1);
	

	SetupButtons();

}

TavernScreen::~TavernScreen() {
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

	delete mSymbol;
	mSymbol = nullptr;
	delete mLabel;
	mLabel = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}

void TavernScreen::Description() {
	mButtons[4].Visible(false);
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
	if (mFirstVisit) {
		mTextLine10->Visible(true);
		mTextLine11->Visible(true);
		mTextLine12->Visible(true);
		mTextLine13->Visible(true);
		mFirstVisit = false;
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
	}
	else {
		mTextLine10->Visible(false);
		mTextLine11->Visible(false);
		mTextLine12->Visible(false);
		mTextLine13->Visible(false);
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
	}
}
void TavernScreen::Rest() {
	mTextLine1->Visible(false);
	mTextLine2->Visible(false);
	mTextLine3->Visible(false);
	mTextLine4->Visible(false);
	mTextLine5->Visible(false);
	mTextLine6->Visible(false);
	mTextLine7->Visible(false);
	mTextLine8->Visible(false);
	mTextLine9->Visible(false);

	mButtons[4].Visible(true);

	mTextLine10->Visible(false);
	mTextLine11->Visible(false);
	mTextLine12->Visible(false);
	mTextLine13->Visible(false);

	mTextLine14->Visible(true);
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

	
}

void TavernScreen::DefaultText() {
	mButtons[4].Visible(false);

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
}

void TavernScreen::SetupButtons() {
	Button* backButton = new Button(Graphics::SCREEN_WIDTH * 0.27f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* quitButton = new Button(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* investigateButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Investigate", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* restButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Rest", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* leaveButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Leave", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* restConfirmButton = new Button(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.50f, 190, 42, "Confirm", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* inventoryButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Inventory", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");



	// Add buttons to the mButtons list
	mButtons.push_back(*backButton);
	mButtons.push_back(*quitButton);
	mButtons.push_back(*investigateButton);
	mButtons.push_back(*restButton);
	mButtons.push_back(*restConfirmButton);
	mButtons.push_back(*leaveButton);
	mButtons.push_back(*inventoryButton);

	mButtons[4].Visible(false);


}


void TavernScreen::Update() {
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
				else if (btn.label == "Rest") {
					Rest();
				}
				else if (btn.label == "Confirm") {
					mPlayer->FullHeal();
					DefaultText();
				}
				else if (btn.label == "Inventory") {
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Inventory);
				}
				else if (btn.label == "Leave") {
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Town);
				}
			}
		}
	}
}



void TavernScreen::Render() {
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

	//First time Investigation
	if (mTextLine10->Visible()) mTextLine10->Render();
	if (mTextLine11->Visible()) mTextLine11->Render();
	if (mTextLine12->Visible()) mTextLine12->Render();
	if (mTextLine13->Visible()) mTextLine13->Render();

	//Varun's Rest Text
	if (mTextLine14->Visible()) mTextLine14->Render();

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



	for (auto& btn : mButtons) {
		if (btn.Visible()) {
			btn.render();
		}
	}

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}