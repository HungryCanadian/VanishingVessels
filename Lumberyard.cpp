#include "Lumberyard.h"
#include "GameManager.h"


Lumberyard::Lumberyard() {
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

	mLabel = new Texture("Lumberyard", "ToThePoint.ttf", 80, { 53,33,0 });
	mLabel->Parent(this);
	mLabel->Position(Graphics::SCREEN_WIDTH * 0.38f, Graphics::SCREEN_HEIGHT * 0.06f);
	mLabel->Visible(true);

	mTextLine1 = new Texture("Here the sounds of axes and saws echo through the air. Stacks of timber", "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.22f);
	mTextLine1->Visible(true);
	mTextLine2 = new Texture("line the rugged path, their fresh scent mingling with the earthy aroma of", "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine2->Visible(true);
	mTextLine3 = new Texture("sawdust. Workers move with purpose among the trees, their muscles flexing", "ToThePoint.ttf", 35, { 0,0,0 });
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine3->Visible(true);
	mTextLine4 = new Texture("as they fell the mighty oaks and pines that have stood for centuries.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine4->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine4->Visible(true);
	mTextLine5 = new Texture("The air is filled with the sounds of labor and the crackling of fires,", "ToThePoint.ttf", 40, { 0,0,0 });
	mTextLine5->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine5->Visible(true);
	mTextLine6 = new Texture("as the lumberyard hums with the energy of progress and growth.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine6->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mTextLine6->Visible(true);
	mTextLine7 = new Texture("As you make your way through the lumberyard, the towering stacks", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine7->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.40f);
	mTextLine7->Visible(true);
	mTextLine8 = new Texture("of timber create a maze of shadows and light, where the sun filters", "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine8->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.43f);
	mTextLine8->Visible(true);
	mTextLine9 = new Texture("through the canopy above, casting a golden glow on the", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine9->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.46f);
	mTextLine9->Visible(true);
	mTextLine10 = new Texture("work of the lumberjacks.", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine10->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.49f);
	mTextLine10->Visible(true);

	mTextLine11 = new Texture("Lumberjack:", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine11->Position(Graphics::SCREEN_WIDTH * 0.3f, Graphics::SCREEN_HEIGHT * 0.24f);
	mTextLine11->Visible(false);
	mTextLine12 = new Texture("Hard work, but it pays the bills.", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine12->Position(Graphics::SCREEN_WIDTH * 0.45f, Graphics::SCREEN_HEIGHT * 0.27f);
	mTextLine12->Visible(false);
	mTextLine13 = new Texture("Foreman", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine13->Position(Graphics::SCREEN_WIDTH * 0.3f, Graphics::SCREEN_HEIGHT * 0.33f);
	mTextLine13->Visible(false);
	mTextLine14 = new Texture("Keep up the pace, we have a quota to meet!", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine14->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.36f);
	mTextLine14->Visible(false);
	mTextLine15 = new Texture("Woodcutter:", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine15->Position(Graphics::SCREEN_WIDTH * 0.3f, Graphics::SCREEN_HEIGHT * 0.42f);
	mTextLine15->Visible(false);
	mTextLine16 = new Texture("The forest provides, but we must respect it.", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine16->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.45f);
	mTextLine16->Visible(false);


	mCursorTexture = new Texture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor

	SetupButtons();

}

Lumberyard::~Lumberyard() {
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

	delete mSymbol;
	mSymbol = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}


void Lumberyard::DefaultText() {
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

	mTextLine11->Visible(false);
	mTextLine12->Visible(false);
	mTextLine13->Visible(false);
	mTextLine14->Visible(false);
	mTextLine15->Visible(false);
	mTextLine16->Visible(false);


	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(true);
	mButtons[3].Visible(true);
	mButtons[4].Visible(true);
	mButtons[5].Visible(true);

}

void Lumberyard::Investigate() {
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

	mTextLine11->Visible(true);
	mTextLine12->Visible(true);
	mTextLine13->Visible(true);
	mTextLine14->Visible(true);
	mTextLine15->Visible(true);
	mTextLine16->Visible(true);


	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(true);
	mButtons[3].Visible(true);
	mButtons[4].Visible(true);
	mButtons[5].Visible(true);
}

void Lumberyard::SetupButtons() {
	Button* BackButton = new Button(Graphics::SCREEN_WIDTH * 0.27f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* QuitButton = new Button(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* InvestigateButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Investigate", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* InventoryButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Inventory", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* GroveButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Heartwood Grove", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* NorthButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "North Road", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");



	// Add buttons to the mButtons list
	mButtons.push_back(*BackButton);
	mButtons.push_back(*QuitButton);
	mButtons.push_back(*InvestigateButton);
	mButtons.push_back(*InventoryButton);
	mButtons.push_back(*GroveButton);
	mButtons.push_back(*NorthButton);



}


void Lumberyard::Update() {
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
					DefaultText();
				}
				else if (btn.label == "Quit") {
					GameManager::Instance()->QuitGame();

				}
				else if (btn.label == "Investigate") {
					DefaultText();
					int randomChoice = std::rand() % 4;
					if (randomChoice == 0) {
						ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Combat);
					}
					else {
						Investigate();
					}
				}
				else if (btn.label == "Inventory") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Inventory);
				}
				else if (btn.label == "North Road") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::North);
				}
				else if (btn.label == "Heartwood Grove") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Grove);
				}
			}
		}
	}
}



void Lumberyard::Render() {
	if (mTest->Visible()) mTest->Render();
	if (mTextArea->Visible()) mTextArea->Render();
	if (mPaperOverlay->Visible()) mPaperOverlay->Render();
	if (mTopBar->Visible()) mTopBar->Render();
	if (mSymbol->Visible()) mSymbol->Render();
	if (mBottomBar->Visible()) mBottomBar->Render();
	if (mLabel->Visible()) mLabel->Render();


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
	if (mTextLine16->Visible()) mTextLine16->Render();



	for (auto& btn : mButtons) {
		if (btn.Visible()) {
			btn.render();
		}
	}

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}