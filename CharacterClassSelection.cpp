#include "CharacterClassSelection.h"
#include "GameManager.h"
#include "RaceData.h"


CharacterClassScreen::CharacterClassScreen() {
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

	mCursorTexture = new Texture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor


	mPlayer->GenerateRandomStats();
	mPlayer->CalculateBonuses();
	SDL_StartTextInput();
	SetupButtons();

}

CharacterClassScreen::~CharacterClassScreen() {
	mTimer = nullptr;
	mAudio = nullptr;

	SDL_StopTextInput();


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

	delete mHumanText;
	mHumanText = nullptr;
	delete mElfText;
	mElfText = nullptr;
	delete mDwarfText;
	mDwarfText = nullptr;
	delete mGnomeText;
	mGnomeText = nullptr;
	delete mHalflingText;
	mHalflingText = nullptr;
	delete mTieflingText;
	mTieflingText = nullptr;

	delete mLevel;
	mLevel = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}

void CharacterClassScreen::SetupButtons() {
	Button* FighterButton = new Button(Graphics::SCREEN_WIDTH * 0.23f, Graphics::SCREEN_HEIGHT * 0.15f, 250, 250, "Fighter", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "Fighter.png");
	Button* quitButton = new Button(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* PaladinButton = new Button(Graphics::SCREEN_WIDTH * 0.53f, Graphics::SCREEN_HEIGHT * 0.15f, 250, 250, "Paladin", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "Paladin.png");
	Button* DruidButton = new Button(Graphics::SCREEN_WIDTH * 0.235f, Graphics::SCREEN_HEIGHT * 0.33f, 250, 250, "Druid", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "Druid.png");
	Button* WarlockButton = new Button(Graphics::SCREEN_WIDTH * 0.53f, Graphics::SCREEN_HEIGHT * 0.33f, 250, 250, "Warlock", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "Warlock.png");
	Button* WizardButton = new Button(Graphics::SCREEN_WIDTH * 0.23f, Graphics::SCREEN_HEIGHT * 0.65f, 190, 42, "Wizard", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* SorcerorButton = new Button(Graphics::SCREEN_WIDTH * 0.53f, Graphics::SCREEN_HEIGHT * 0.65f, 190, 42, "Sorceror", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* RangerButton = new Button(Graphics::SCREEN_WIDTH * 0.35f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Ranger", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* BackButton = new Button(Graphics::SCREEN_WIDTH * 0.35f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");

	// Add buttons to the mButtons list
	mButtons.push_back(*FighterButton);
	mButtons.push_back(*quitButton);
	mButtons.push_back(*PaladinButton);
	mButtons.push_back(*DruidButton);
	mButtons.push_back(*WarlockButton);
	mButtons.push_back(*WizardButton);
	mButtons.push_back(*SorcerorButton);
	mButtons.push_back(*RangerButton);
	mButtons.push_back(*BackButton);

}


void CharacterClassScreen::Update() {
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	// Check button hover state
	for (auto& btn : mButtons) {
		btn.checkHover(mouseX, mouseY);
	}


	// Handle mouse clicks on buttons
	if (mInputManager->MouseButtonPressed(InputManager::LEFT)) {
		for (auto& btn : mButtons) {
			if (btn.isHovered) {
				if (btn.label == "New Character") {
					std::cout << "New Character Clicked\n";
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Start);
				}
				else if (btn.label == "Quit") {
					std::cout << "Quit Clicked\n";
					GameManager::Instance()->QuitGame();

				}
				else if (btn.label == "Back") {
					std::cout << "Quit Clicked\n";
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::NewCharacter);

				}
				else if (btn.label == "Fighter") {
					mPlayer->SetClass("Fighter");
					mPlayer->SetHitDice(10);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::CharacterConfirm);
				}
				else if (btn.label == "Paladin") {
					mPlayer->SetClass("Paladin");
					mPlayer->SetHitDice(12);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::CharacterConfirm);
				}
				else if (btn.label == "Druid") {
					mPlayer->SetClass("Druid");
					mPlayer->SetHitDice(8);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::CharacterConfirm);
				}
				else if (btn.label == "Warlock") {
					mPlayer->SetClass("Warlock");
					mPlayer->SetHitDice(8);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::CharacterConfirm);
				}
				else if (btn.label == "Wizard") {
					mPlayer->SetClass("Wizard");
					mPlayer->SetHitDice(6);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::CharacterConfirm);
				}
				else if (btn.label == "Sorceror") {
					mPlayer->SetClass("Sorceror");
					mPlayer->SetHitDice(6);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::CharacterConfirm);
				}
				else if (btn.label == "Ranger") {
					mPlayer->SetClass("Ranger");
					mPlayer->SetHitDice(10);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::CharacterConfirm);
				}
			}
		}
	}
}



void CharacterClassScreen::Render() {
	mTest->Render();
	mTextArea->Render();
	mPaperOverlay->Render();
	mTopBar->Render();
	mBottomBar->Render();
	//mHumanText->Render();
	//mElfText->Render();
	//mDwarfText->Render();
	//mGnomeText->Render();
	//mHalflingText->Render();
	//mTieflingText->Render();

	for (auto& btn : mButtons) {
		if (btn.Visible()) {
			btn.render();
		}
	}

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}