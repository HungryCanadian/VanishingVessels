#include "CharacterConfirm.h"
#include "GameManager.h"
#include "RaceData.h"


CharacterConfirmation::CharacterConfirmation() {
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

	mCursorTexture = new Texture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor

	//std::string text = "You have chosen " + mPlayer->GetRace() + " " + mPlayer->GetClass() + "!";
	mConfirmText = new Texture("temp", "ToThePoint.ttf", 42, {0, 0, 0, 255});  // Text, font, size, color
	mConfirmText->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);

	mPlayer->GenerateRandomStats();
	mPlayer->CalculateBonuses();
	
	mStr = new Texture("Strength: " + std::to_string(mPlayer->GetStrength()) + " ( +" + std::to_string(mPlayer->GetStrengthBonus()) + ")", "ToThePoint.ttf", 42, {0, 0, 0, 255});
	mStr->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.42f);
	mDex = new Texture("Dexterity: " + std::to_string(mPlayer->GetDexterity()) + " ( +" + std::to_string(mPlayer->GetDexterityBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mDex->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.45f);
	mCon = new Texture("Constitution: " + std::to_string(mPlayer->GetConstitution()) + " ( +" + std::to_string(mPlayer->GetConstitutionBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mCon->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.48f);
	mInt = new Texture("Intellect: " + std::to_string(mPlayer->GetIntelligence()) + " ( +" + std::to_string(mPlayer->GetIntelligenceBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mInt->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.51f);
	mWis = new Texture("Wisdom: " + std::to_string(mPlayer->GetWisdom()) + " ( +" + std::to_string(mPlayer->GetWisdomBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mWis->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.54f);
	mCha = new Texture("Charisma: " + std::to_string(mPlayer->GetCharisma()) + " ( +" + std::to_string(mPlayer->GetCharismaBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mCha->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.57f);

	mHP = new Texture("Max Health: " + std::to_string(mPlayer->GetMaxHealth()), "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mHP->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.57f);


	SetupButtons();

}

CharacterConfirmation::~CharacterConfirmation() {
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
	delete mConfirmText;
	mConfirmText = nullptr;


	delete mPlayer;
	mPlayer = nullptr;
	delete mStr;
	mStr = nullptr;
	delete mDex;
	mDex = nullptr;
	delete mCon;
	mCon = nullptr;
	delete mInt;
	mInt = nullptr;
	delete mWis;
	mWis = nullptr;
	delete mCha;
	mCha = nullptr;
	delete mHP;
	mHP = nullptr;




	delete mSymbol;
	mSymbol = nullptr;

	delete mLevel;
	mLevel = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}

void CharacterConfirmation::SetupButtons() {
	Button* backButton = new Button(Graphics::SCREEN_WIDTH * 0.58f, Graphics::SCREEN_HEIGHT * 0.77f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* quitButton = new Button(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* confirmButton = new Button(Graphics::SCREEN_WIDTH * 0.23f, Graphics::SCREEN_HEIGHT * 0.77f, 190, 42, "Confirm", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	
	// Add buttons to the mButtons list
	mButtons.push_back(*backButton);
	mButtons.push_back(*quitButton);
	mButtons.push_back(*confirmButton);


}


void CharacterConfirmation::Update() {
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	// Check button hover state
	for (auto& btn : mButtons) {
		btn.checkHover(mouseX, mouseY);
	}
	std::string text = "You have chosen " + mPlayer->GetRace() + " " + mPlayer->GetClass() + "!";
	mConfirmText->SetText(text, "ToThePoint.ttf", 42, { 0, 0, 0, 255 }, false);
	mConfirmText->Update();
	mSymbol = new Texture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));
	mSymbol->Update();
	mHP = new Texture("Max Health: " + std::to_string(mPlayer->GetMaxHealth()), "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mHP->Position(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.42f);
	mHP->Update();


	// Handle mouse clicks on buttons
	if (mInputManager->MouseButtonPressed(InputManager::LEFT)) {
		for (auto& btn : mButtons) {
			if (btn.isHovered) {
				if (btn.label == "Back") {
					std::cout << "Back Clicked\n";
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::NewCharacter);
				}
				else if (btn.label == "Quit") {
					std::cout << "Quit Clicked\n";
					GameManager::Instance()->QuitGame();

				}
				else if (btn.label == "Confirm") {
					std::cout << "Confirm Clicked\n";
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Tavern);

				}
			}
		}
	}
}



void CharacterConfirmation::Render() {
	mTest->Render();
	mTextArea->Render();
	mPaperOverlay->Render();
	mTopBar->Render();
	mSymbol->Render();
	mBottomBar->Render();
	mConfirmText->Render();
	mStr->Render();
	mDex->Render();
	mCon->Render();
	mInt->Render();
	mWis->Render();
	mCha->Render();
	mHP->Render();


	for (auto& btn : mButtons) {
		if (btn.Visible()) {
			btn.render();
		}
	}

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}