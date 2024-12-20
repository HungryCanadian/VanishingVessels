#include "CharacterCreator.h"
#include "GameManager.h"
#include "RaceData.h"


CharacterCreatorScreen::CharacterCreatorScreen() {
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

	mHumanText = new Texture("+2 Wisdom, +1 Constitution", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });  // Text, font, size, color
	mHumanText->Position(Graphics::SCREEN_WIDTH * 0.58f, Graphics::SCREEN_HEIGHT * 0.47f);
	mElfText = new Texture("+2 Dexterity", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });  // Text, font, size, color
	mElfText->Position(Graphics::SCREEN_WIDTH * 0.58f, Graphics::SCREEN_HEIGHT * 0.57f);
	mDwarfText = new Texture("+2 Constitution", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });  // Text, font, size, color
	mDwarfText->Position(Graphics::SCREEN_WIDTH * 0.58f, Graphics::SCREEN_HEIGHT * 0.62f);
	mHalflingText = new Texture("+2 Dexterity", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });  // Text, font, size, color
	mHalflingText->Position(Graphics::SCREEN_WIDTH * 0.58f, Graphics::SCREEN_HEIGHT * 0.52f);
	mGnomeText = new Texture("+2 Intelligence", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });  // Text, font, size, color
	mGnomeText->Position(Graphics::SCREEN_WIDTH * 0.58f, Graphics::SCREEN_HEIGHT * 0.67f);
	mTieflingText = new Texture("+2 Charisma, +1 Intellect", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });  // Text, font, size, color
	mTieflingText->Position(Graphics::SCREEN_WIDTH * 0.58f, Graphics::SCREEN_HEIGHT * 0.72f);
	
	mStr = new Texture("Strength: " + std::to_string(mPlayer->GetStrength()) + " ( +" + std::to_string(mPlayer->GetStrengthBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mStr->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.42f);
	mStr->Visible(false);

	mDex = new Texture("Dexterity: " + std::to_string(mPlayer->GetDexterity()) + " ( +" + std::to_string(mPlayer->GetDexterityBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mDex->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.45f);
	mDex->Visible(false);

	mCon = new Texture("Constitution: " + std::to_string(mPlayer->GetConstitution()) + " ( +" + std::to_string(mPlayer->GetConstitutionBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mCon->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.48f);
	mCon->Visible(false);

	mInt = new Texture("Intellect: " + std::to_string(mPlayer->GetIntelligence()) + " ( +" + std::to_string(mPlayer->GetIntelligenceBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mInt->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.51f);
	mInt->Visible(false);

	mWis = new Texture("Wisdom: " + std::to_string(mPlayer->GetWisdom()) + " ( +" + std::to_string(mPlayer->GetWisdomBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mWis->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.54f);
	mWis->Visible(false);

	mCha = new Texture("Charisma: " + std::to_string(mPlayer->GetCharisma()) + " ( +" + std::to_string(mPlayer->GetCharismaBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mCha->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.57f);
	mCha->Visible(false);

	mConfirmText = new Texture("", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });  // Text, font, size, color
	mConfirmText->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mHP = new Texture("Max Health: " + std::to_string(mPlayer->GetMaxHealth()), "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mHP->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.57f);
	mHP->Visible(false);

	SetupButtons();

}

CharacterCreatorScreen::~CharacterCreatorScreen() {
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
	delete mConfirmText;
	mConfirmText = nullptr;




	delete mSymbol;
	mSymbol = nullptr;

	delete mLevel;
	mLevel = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}
void CharacterCreatorScreen::NewCharacter() {
	mHumanText->Visible(true);
	mElfText->Visible(true);
	mDwarfText->Visible(true);
	mGnomeText->Visible(true);
	mHalflingText->Visible(true);
	mTieflingText->Visible(true);
	mConfirmText->Visible(false);
	mStr->Visible(false);
	mDex->Visible(false);
	mCon->Visible(false);
	mInt->Visible(false);
	mWis->Visible(false);
	mCha->Visible(false);
	mHP->Visible(false);

	mButtons[0].Visible(true);
	mButtons[2].Visible(true);
	mButtons[3].Visible(true);
	mButtons[4].Visible(true);
	mButtons[5].Visible(true);
	mButtons[6].Visible(true);
	mButtons[15].Visible(true);

	mButtons[7].Visible(false);
	mButtons[8].Visible(false);
	mButtons[9].Visible(false);
	mButtons[10].Visible(false);
	mButtons[11].Visible(false);
	mButtons[12].Visible(false);
	mButtons[13].Visible(false);
	mButtons[14].Visible(false);
}

void CharacterCreatorScreen::ClassSelection() {
	mHumanText->Visible(false);
	mElfText->Visible(false);
	mDwarfText->Visible(false);
	mGnomeText->Visible(false);
	mHalflingText->Visible(false);
	mTieflingText->Visible(false);
	mConfirmText->Visible(false);

	mButtons[0].Visible(false);
	mButtons[2].Visible(false);
	mButtons[3].Visible(false);
	mButtons[4].Visible(false);
	mButtons[5].Visible(false);
	mButtons[6].Visible(false);
	mButtons[15].Visible(false);

	mButtons[7].Visible(true);
	mButtons[8].Visible(true);
	mButtons[9].Visible(true);
	mButtons[10].Visible(true);
	mButtons[11].Visible(true);
	mButtons[12].Visible(true);
	mButtons[13].Visible(true);
	mButtons[14].Visible(true);

	mStr->Visible(false);
	mDex->Visible(false);
	mCon->Visible(false);
	mInt->Visible(false);
	mWis->Visible(false);
	mCha->Visible(false);
	mHP->Visible(false);
}

void CharacterCreatorScreen::CharacterConfirm() {
	mPlayer->GenerateRandomStats();
	mPlayer->CalculateBonuses();
	mStr = new Texture("Strength: " + std::to_string(mPlayer->GetStrength()) + " ( +" + std::to_string(mPlayer->GetStrengthBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mStr->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.42f);
	mStr->Visible(true);
	mDex = new Texture("Dexterity: " + std::to_string(mPlayer->GetDexterity()) + " ( +" + std::to_string(mPlayer->GetDexterityBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mDex->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.45f);
	mDex->Visible(true);
	mCon = new Texture("Constitution: " + std::to_string(mPlayer->GetConstitution()) + " ( +" + std::to_string(mPlayer->GetConstitutionBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mCon->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.48f);
	mCon->Visible(true);
	mInt = new Texture("Intellect: " + std::to_string(mPlayer->GetIntelligence()) + " ( +" + std::to_string(mPlayer->GetIntelligenceBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mInt->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.51f);
	mInt->Visible(true);
	mWis = new Texture("Wisdom: " + std::to_string(mPlayer->GetWisdom()) + " ( +" + std::to_string(mPlayer->GetWisdomBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mWis->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.54f);
	mWis->Visible(true);
	mCha = new Texture("Charisma: " + std::to_string(mPlayer->GetCharisma()) + " ( +" + std::to_string(mPlayer->GetCharismaBonus()) + ")", "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mCha->Position(Graphics::SCREEN_WIDTH * 0.32f, Graphics::SCREEN_HEIGHT * 0.57f);
	mCha->Visible(true);
	mHP = new Texture("Max Health: " + std::to_string(mPlayer->GetMaxHealth()), "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mHP->Position(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.42f);
	mHP->Visible(true);
	mConfirmText->Visible(true);

	mHumanText->Visible(false);
	mElfText->Visible(false);
	mDwarfText->Visible(false);
	mGnomeText->Visible(false);
	mHalflingText->Visible(false);
	mTieflingText->Visible(false);

	mButtons[0].Visible(false);
	mButtons[2].Visible(false);
	mButtons[3].Visible(false);
	mButtons[4].Visible(false);
	mButtons[5].Visible(false);
	mButtons[6].Visible(false);
	mButtons[7].Visible(false);
	mButtons[8].Visible(false);
	mButtons[9].Visible(false);
	mButtons[10].Visible(false);
	mButtons[11].Visible(false);
	mButtons[12].Visible(false);
	mButtons[13].Visible(false);
	mButtons[14].Visible(true);
	mButtons[15].Visible(true);

	std::string text = "You have chosen " + mPlayer->GetRace() + " " + mPlayer->GetClass() + "!";
	mConfirmText->SetText(text, "ToThePoint.ttf", 42, { 0, 0, 0, 255 }, false);
	mConfirmText->Update();
	mSymbol = new Texture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));
	mSymbol->Update();
	
}

void CharacterCreatorScreen::SetupButtons() {
	Button* humanButton = new Button(Graphics::SCREEN_WIDTH * 0.23f, Graphics::SCREEN_HEIGHT * 0.45f, 190, 42, "Human", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* quitButton = new Button(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* halflingButton = new Button(Graphics::SCREEN_WIDTH * 0.23f, Graphics::SCREEN_HEIGHT * 0.50f, 190, 42, "Halfling", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* elfButton = new Button(Graphics::SCREEN_WIDTH * 0.23f, Graphics::SCREEN_HEIGHT * 0.55f, 190, 42, "Elf", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* dwarfButton = new Button(Graphics::SCREEN_WIDTH * 0.23f, Graphics::SCREEN_HEIGHT * 0.60f, 190, 42, "Dwarf", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* gnomeButton = new Button(Graphics::SCREEN_WIDTH * 0.23f, Graphics::SCREEN_HEIGHT * 0.65f, 190, 42, "Gnome", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* tieflingButton = new Button(Graphics::SCREEN_WIDTH * 0.23f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Tiefling", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* FighterButton = new Button(Graphics::SCREEN_WIDTH * 0.23f, Graphics::SCREEN_HEIGHT * 0.15f, 200, 200, "Fighter", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "Fighter.png");
	Button* PaladinButton = new Button(Graphics::SCREEN_WIDTH * 0.53f, Graphics::SCREEN_HEIGHT * 0.15f, 200, 200, "Paladin", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "Paladin.png");
	Button* DruidButton = new Button(Graphics::SCREEN_WIDTH * 0.235f, Graphics::SCREEN_HEIGHT * 0.35f, 200, 200, "Druid", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "Druid.png");
	Button* WarlockButton = new Button(Graphics::SCREEN_WIDTH * 0.53f, Graphics::SCREEN_HEIGHT * 0.35f, 200, 200, "Warlock", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "Warlock.png");
	Button* WizardButton = new Button(Graphics::SCREEN_WIDTH * 0.23f, Graphics::SCREEN_HEIGHT * 0.55f, 200, 200, "Wizard", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "Wizard.png");
	Button* SorcerorButton = new Button(Graphics::SCREEN_WIDTH * 0.53f, Graphics::SCREEN_HEIGHT * 0.55f, 200, 200, "Sorceror", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "Sorceror.png");
	Button* RangerButton = new Button(Graphics::SCREEN_WIDTH * 0.375f, Graphics::SCREEN_HEIGHT * 0.65f, 200, 200, "Ranger", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "Ranger.png");
	Button* BackButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* ConfirmButton = new Button(Graphics::SCREEN_WIDTH * 0.45f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Confirm", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	// Add buttons to the mButtons list
	mButtons.push_back(*humanButton);
	mButtons.push_back(*quitButton);
	mButtons.push_back(*halflingButton);
	mButtons.push_back(*elfButton);
	mButtons.push_back(*dwarfButton);
	mButtons.push_back(*gnomeButton);
	mButtons.push_back(*tieflingButton);
	mButtons.push_back(*FighterButton);
	mButtons.push_back(*PaladinButton);
	mButtons.push_back(*DruidButton);
	mButtons.push_back(*WarlockButton);
	mButtons.push_back(*WizardButton);
	mButtons.push_back(*SorcerorButton);
	mButtons.push_back(*RangerButton);
	mButtons.push_back(*BackButton);
	mButtons.push_back(*ConfirmButton);

	mButtons[7].Visible(false);
	mButtons[8].Visible(false);
	mButtons[9].Visible(false);
	mButtons[10].Visible(false);
	mButtons[11].Visible(false);
	mButtons[12].Visible(false);
	mButtons[13].Visible(false);
	mButtons[14].Visible(false);

	
}


void CharacterCreatorScreen::Update() {
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
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Start);
				}
				if (btn.label == "Back") {
					NewCharacter();
				}
				else if (btn.label == "Quit") {
					GameManager::Instance()->QuitGame();

				}
				else if (btn.label == "Human") {
					mPlayer->SetRace("Human");
					ClassSelection();
				}
				else if (btn.label == "Elf") {
					mPlayer->SetRace("Elf");
					ClassSelection();
				}
				else if (btn.label == "Dwarf") {
					mPlayer->SetRace("Dwarf");
					ClassSelection();
				}
				else if (btn.label == "Halfling") {
					mPlayer->SetRace("Halfling");
					ClassSelection();
				}
				else if (btn.label == "Gnome") {
					mPlayer->SetRace("Gnome");
					ClassSelection();
				}
				else if (btn.label == "Tiefling") {
					mPlayer->SetRace("Tiefling");
					ClassSelection();
				}
				else if (btn.label == "Fighter") {
					mPlayer->SetClass("Fighter");
					mPlayer->SetHitDice(10);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					CharacterConfirm();
				}
				else if (btn.label == "Paladin") {
					mPlayer->SetClass("Paladin");
					mPlayer->SetHitDice(12);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					CharacterConfirm();
				}
				else if (btn.label == "Druid") {
					mPlayer->SetClass("Druid");
					mPlayer->SetHitDice(8);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					CharacterConfirm();
				}
				else if (btn.label == "Warlock") {
					mPlayer->SetClass("Warlock");
					mPlayer->SetHitDice(8);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					CharacterConfirm();
				}
				else if (btn.label == "Wizard") {
					mPlayer->SetClass("Wizard");
					mPlayer->SetHitDice(6);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					CharacterConfirm();
				}
				else if (btn.label == "Sorceror") {
					mPlayer->SetClass("Sorceror");
					mPlayer->SetHitDice(6);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					CharacterConfirm();
				}
				else if (btn.label == "Ranger") {
					mPlayer->SetClass("Ranger");
					mPlayer->SetHitDice(10);
					mPlayer->calculateHealth();
					mPlayer->FullHeal();
					CharacterConfirm();
					mHP->Update();
				}
				else if (btn.label == "Confirm") {
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Tavern);
				}
			}
		}
	}
	/*mHP = new Texture("Max Health: " + std::to_string(mPlayer->GetMaxHealth()), "ToThePoint.ttf", 42, { 0, 0, 0, 255 });
	mHP->Position(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.42f);
	if (mHP->Visible()) mHP->Update();*/
}




void CharacterCreatorScreen::Render() {
	if (mTest->Visible()) mTest->Render();
	if (mTextArea->Visible()) mTextArea->Render();
	if (mPaperOverlay->Visible()) mPaperOverlay->Render();
	if (mTopBar->Visible()) mTopBar->Render();
	if (mSymbol->Visible()) mSymbol->Render();
	if (mBottomBar->Visible()) mBottomBar->Render();
	if (mHumanText->Visible()) mHumanText->Render();
	if (mElfText->Visible()) mElfText->Render();
	if (mDwarfText->Visible()) mDwarfText->Render();
	if (mGnomeText->Visible()) mGnomeText->Render();
	if (mHalflingText->Visible()) mHalflingText->Render();
	if (mTieflingText->Visible()) mTieflingText->Render();
	if (mStr->Visible()) mStr->Render();
	if (mDex->Visible()) mDex->Render();
	if (mCon->Visible()) mCon->Render();
	if (mInt->Visible()) mInt->Render();
	if (mWis->Visible()) mWis->Render();
	if (mCha->Visible()) mCha->Render();
	if (mHP->Visible()) mHP->Render();
	if (mConfirmText->Visible()) mConfirmText->Render();


	for (auto& btn : mButtons) {
		if (btn.Visible()) {
			btn.render();
		}
	}

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}