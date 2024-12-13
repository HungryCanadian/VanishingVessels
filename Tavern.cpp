#include "Tavern.h"
#include "GameManager.h"
#include "RaceData.h"


TavernScreen::TavernScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInputManager = InputManager::Instance();
	mPlayer = Player::Instance();

	mTest = new Texture("startBackground.png");
	mTest->Parent(this);
	mTest->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mTopBar = new Texture("TopCornerBar.png");
	mTopBar->Parent(this);
	mTopBar->Position(Graphics::SCREEN_WIDTH * 0.285f, Graphics::SCREEN_HEIGHT * 0.065);
	mTopBar->Scale(Vector2(0.5f, 0.5f));

	mBottomBar = new Texture("BottomBar.png");
	mBottomBar->Parent(this);
	mBottomBar->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.94f);
	mBottomBar->Scale(Vector2(0.4f, 0.3f));

	mTextArea = new Texture("PanelDarkSquare.png");
	mTextArea->Parent(this);
	mTextArea->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	mTextArea->Scale(Vector2(0.5f, 0.5f));

	mPaperOverlay = new Texture("LargePaperOverlay.png");
	mPaperOverlay->Parent(this);
	mPaperOverlay->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	mPaperOverlay->Scale(Vector2(0.5f, 0.5f));


	mSymbol = new Texture(mPlayer->GetClass() + ".png");
	mSymbol->Parent(this);
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));

	mTextLine1 = new Texture("You wake up in your cozy bed at the tavern,", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.22f);
	mTextLine2 = new Texture("the smell of breakfast wafting through the air.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine3 = new Texture("You can hear the chatter of patrons and the clinking of mugs,", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine4 = new Texture("but your head is pounding. As you sit up, a wave of nausea hits you,", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine4->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine5 = new Texture("and you remember last night's revelry.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine5->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine6 = new Texture("You feel dehydrated and your mouth is dry; you crave water.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine6->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mTextLine7 = new Texture("A faint light coming through the window only intensifies your headache.", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine7->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.40f);
	mTextLine8 = new Texture("You get up slowly and gather your things.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine8->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.43f);
	mTextLine9 = new Texture("You meander your way out of the room and down the stairs to the tavern", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine9->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.46f);

	mTextLine10 = new Texture("Barbossa: You alright there? you seem a little dazed and confused.", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine10->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine10->Visible(false);
	mTextLine11 = new Texture("Barbossa: Well, I would have a hangover too if I drank several bottles of rum.", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine11->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine11->Visible(false);
	mTextLine12 = new Texture("Barbossa: I do have some Errands to run, but breakfast is on the house!", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine12->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine12->Visible(false);
	mTextLine13 = new Texture("Barbossa: If you need anything, Varun can help you!", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine13->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mTextLine13->Visible(false);

	mTextLine14 = new Texture("Varun: Would you like to rest for the night?", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine14->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine14->Visible(false);
	mTextLine15 = new Texture("Leoric: How are you here?", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine15->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine15->Visible(false);

	mFirstVisit = true;

	mCursorTexture = new Texture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor

	SetupButtons();

}

TavernScreen::~TavernScreen() {
	mTimer = nullptr;
	mAudio = nullptr;


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



	delete mPlayer;
	mPlayer = nullptr;


	delete mSymbol;
	mSymbol = nullptr;

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
	}
	else {
		mTextLine10->Visible(false);
		mTextLine11->Visible(false);
		mTextLine12->Visible(false);
		mTextLine13->Visible(false);
		mTextLine15->Visible(true);
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
}

void TavernScreen::SetupButtons() {
	Button* backButton = new Button(Graphics::SCREEN_WIDTH * 0.27f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* quitButton = new Button(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* investigateButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Investigate", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* restButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Rest", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* leaveButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Leave", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* restConfirmButton = new Button(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.50f, 190, 42, "Confirm", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");

	// Add buttons to the mButtons list
	mButtons.push_back(*backButton);
	mButtons.push_back(*quitButton);
	mButtons.push_back(*investigateButton);
	mButtons.push_back(*restButton);
	mButtons.push_back(*restConfirmButton);
	mButtons.push_back(*leaveButton);

	mButtons[4].Visible(false);


}


void TavernScreen::Update() {
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	// Check button hover state
	for (auto& btn : mButtons) {
		btn.checkHover(mouseX, mouseY);
	}
	mSymbol = new Texture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));
	mSymbol->Update();


	// Handle mouse clicks on buttons
	if (mInputManager->MouseButtonPressed(InputManager::LEFT)) {
		for (auto& btn : mButtons) {
			if (btn.isHovered) {
				if (btn.label == "Back") {
					TavernScreen::DefaultText();
				}
				else if (btn.label == "Quit") {
					GameManager::Instance()->QuitGame();

				}
				else if (btn.label == "Investigate") {
					TavernScreen::Description();
				}
				else if (btn.label == "Rest") {
					TavernScreen::Rest();
				}
				else if (btn.label == "Confirm") {
					mPlayer->FullHeal();
					std::cout << "Player Healed\n";
					TavernScreen::DefaultText();
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



	for (auto& btn : mButtons) {
		if (btn.Visible()) {
			btn.render();
		}
	}

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}