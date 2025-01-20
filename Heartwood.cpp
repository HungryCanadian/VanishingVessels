#include "Heartwood.h"
#include "GameManager.h"


HeartwoodGrove::HeartwoodGrove() {
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

	mLabel = new SDLTexture("Heartwood Grove", "ToThePoint.ttf", 80, { 53,33,0 });
	mLabel->Parent(this);
	mLabel->Position(Graphics::SCREEN_WIDTH * 0.38f, Graphics::SCREEN_HEIGHT * 0.06f);
	mLabel->Visible(true);

	mTextLine1 = new SDLTexture("The Heartwood Grove is a place of serene beauty, where the ancient", "ToThePoint.ttf", 40, { 0,0,0 });
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.22f);
	mTextLine1->Visible(true);
	mTextLine2 = new SDLTexture("trees stand as silent sentinels over the vibrant undergrowth.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine2->Visible(true);
	mTextLine3 = new SDLTexture("The air is thick with the scent of moss and wildflowers, and the", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine3->Visible(true);
	mTextLine4 = new SDLTexture("sounds of birdsong and rustling leaves create a symphony of nature", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine4->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine4->Visible(true);
	mTextLine5 = new SDLTexture("that soothes the soul. Sunlight filters through the canopy, casting", "ToThePoint.ttf", 40, { 0,0,0 });
	mTextLine5->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine5->Visible(true);
	mTextLine6 = new SDLTexture("dappled shadows on the forest floor, where delicate ferns and", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine6->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mTextLine6->Visible(true);
	mTextLine7 = new SDLTexture("mushrooms thrive in the cool, damp earth.", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine7->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.40f);
	mTextLine7->Visible(true);
	mTextLine8 = new SDLTexture("As you wander deeper into the grove, the trees seem to whisper secrets", "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine8->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.43f);
	mTextLine8->Visible(true);
	mTextLine9 = new SDLTexture("to one another, their leaves rustling in the gentle breeze. The ancient oaks", "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine9->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.46f);
	mTextLine9->Visible(true);
	mTextLine10 = new SDLTexture("and towering pines create a cathedral-like canopy above.", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine10->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.49f);
	mTextLine10->Visible(true);


	mCursorTexture = new SDLTexture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor

	SetupButtons();

}

HeartwoodGrove::~HeartwoodGrove() {
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

	delete mSymbol;
	mSymbol = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}


void HeartwoodGrove::DefaultText() {
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


	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(true);
	mButtons[3].Visible(true);
	mButtons[4].Visible(true);
	mButtons[5].Visible(true);

}

void HeartwoodGrove::Barbossa() {

}

void HeartwoodGrove::SetupButtons() {
	Button* BackButton = new Button(Graphics::SCREEN_WIDTH * 0.27f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* QuitButton = new Button(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* InvestigateButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Investigate", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* InventoryButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Inventory", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* LumberButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Lumberyard", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* BossButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Barbossa", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");



	// Add buttons to the mButtons list
	mButtons.push_back(*BackButton);
	mButtons.push_back(*QuitButton);
	mButtons.push_back(*InvestigateButton);
	mButtons.push_back(*InventoryButton);
	mButtons.push_back(*LumberButton);
	mButtons.push_back(*BossButton);



}


void HeartwoodGrove::Update() {
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
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Boss);

				}
				else if (btn.label == "Inventory") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Inventory);
				}
				else if (btn.label == "Lumberyard") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Lumber);
				}
				else if (btn.label == "Barbossa") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Boss);
					
				}
			}
		}
	}
}



void HeartwoodGrove::Render() {
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



	for (auto& btn : mButtons) {
		if (btn.Visible()) {
			btn.render();
		}
	}

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}