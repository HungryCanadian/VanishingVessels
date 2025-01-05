#include "CombatScreen.h"
#include "GameManager.h"

Enemy enemies[] = {
		Enemy("Goblin", 2, 10, 3, 25),
		Enemy("Orc", 4, 15, 6, 50),
		Enemy("Troll", 3, 20, 25, 100),
		Enemy("Skeleton", 1, 5, 1, 50),
		Enemy("Werewolf", 4, 40, 100, 250)
};


CombatScreen::CombatScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInputManager = InputManager::Instance();
	mPlayer = Player::Instance();

	mCurrentEnemy = GetRandomEnemy();

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

	mLabel = new Texture("Combat", "ToThePoint.ttf", 80, { 53,33,0 });
	mLabel->Parent(this);
	mLabel->Position(Graphics::SCREEN_WIDTH * 0.38f, Graphics::SCREEN_HEIGHT * 0.06f);
	mLabel->Visible(true);

	mTextLine1 = new Texture("You were Ambushed! What would you like to do?", "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.22f);
	mTextLine1->Visible(true);
	mTextLine2 = new Texture("Current HP: " + std::to_string(mPlayer->GetHealth()), "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine2->Visible(true);
	mTextLine3 = new Texture("Enemy HP: " + std::to_string(mCurrentEnemy.GetHealth()), "ToThePoint.ttf", 36, {0,0,0});
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine3->Visible(true);
	mTextLine4 = new Texture("Victory!", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine4->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine4->Visible(false);
	mTextLine5 = new Texture("You gain: " + std::to_string(mCurrentEnemy.GetGold()) + " Gold and " + std::to_string(mCurrentEnemy.GetExp()) + " EXP!", "ToThePoint.ttf", 40, {0,0,0});
	mTextLine5->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine5->Visible(false);
	mTextLine6 = new Texture("Game Over!", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine6->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.37f);
	mTextLine6->Visible(false);
	mTextLine7 = new Texture("Try again and Good luck!", "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine7->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.40f);
	mTextLine7->Visible(false);
	mTextLine8 = new Texture("LEVEL UP!", "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine8->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.45f);
	mTextLine8->Visible(false);
	mTextLine9 = new Texture("You are now Level " + std::to_string(mPlayer->GetLevel()), "ToThePoint.ttf", 37, {0,0,0});
	mTextLine9->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.48f);
	mTextLine9->Visible(false);
	mTextLine10 = new Texture("You Hit them for " + mPlayer->Attack(), "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine10->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.49f);
	mTextLine10->Visible(false);
	mTextLine11 = new Texture("The Enemy takes " + mPlayer->Attack(), "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine11->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.52f);
	mTextLine11->Visible(false);


	mCursorTexture = new Texture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor

	SetupButtons();

}

CombatScreen::~CombatScreen() {
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

Enemy CombatScreen::GetRandomEnemy() {
	int index = rand() % (sizeof(enemies) / sizeof(enemies[0])); // Random index
	return enemies[index];
}


void CombatScreen::DefaultText() {
	mTextLine1->Visible(true);
	mTextLine2->Visible(true);
	mTextLine3->Visible(true);
	mTextLine4->Visible(false);
	mTextLine5->Visible(false);
	mTextLine6->Visible(false);
	mTextLine7->Visible(false);
	mTextLine8->Visible(false);
	mTextLine9->Visible(false);
	mTextLine10->Visible(false);
	mTextLine11->Visible(false);


	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(true);
	mButtons[3].Visible(true);
	mButtons[4].Visible(true);
	mButtons[5].Visible(false);
	mButtons[6].Visible(false);
	mButtons[7].Visible(false);
	mButtons[8].Visible(false);
	mButtons[9].Visible(false);
	mButtons[10].Visible(false);

}

void CombatScreen::Attack() {
	mTextLine1->Visible(false);
	mTextLine2->Visible(true);
	mTextLine3->Visible(true);
	mTextLine4->Visible(false);
	mTextLine5->Visible(false);
	mTextLine6->Visible(false);
	mTextLine7->Visible(false);
	mTextLine8->Visible(false);
	mTextLine9->Visible(false);
	mTextLine10->Visible(false);
	mTextLine11->Visible(false);

	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(false);
	mButtons[3].Visible(false);
	mButtons[4].Visible(false);
	mButtons[5].Visible(true);
	mButtons[6].Visible(true);
	mButtons[7].Visible(true);
	mButtons[8].Visible(true);
	mButtons[9].Visible(false);
	mButtons[10].Visible(false);
}

void CombatScreen::UseItem() {

}

void CombatScreen::Run() {
	DefaultText();
	mCurrentEnemy = GetRandomEnemy();
	ScreenManager::Instance()->SetScreens(ScreenManager::Screens::EndCombat);
}

void CombatScreen::Victory() {
	int level = mPlayer->GetLevel();
	mPlayer->AddGold(mCurrentEnemy.GetGold());
	mPlayer->AddEXP(mCurrentEnemy.GetExp());
	if (level != mPlayer->GetLevel()) {
		mTextLine8->Visible(true);
		mTextLine9->Visible(true);
	}
	else {
		mTextLine8->Visible(false);
		mTextLine9->Visible(false);
	}

	mTextLine1->Visible(false);
	mTextLine2->Visible(true);
	mTextLine3->Visible(true);
	mTextLine4->Visible(true);
	mTextLine5->Visible(true);
	mTextLine6->Visible(false);
	mTextLine7->Visible(false);
	mTextLine10->Visible(false);
	mTextLine11->Visible(false);

	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(false);
	mButtons[3].Visible(false);
	mButtons[4].Visible(false);
	mButtons[5].Visible(false);
	mButtons[6].Visible(false);
	mButtons[7].Visible(false);
	mButtons[8].Visible(false);
	mButtons[9].Visible(true);
	mButtons[10].Visible(false);
}

void CombatScreen::GameOver() {
	mTextLine1->Visible(false);
	mTextLine2->Visible(true);
	mTextLine3->Visible(true);
	mTextLine4->Visible(false);
	mTextLine5->Visible(false);
	mTextLine6->Visible(true);
	mTextLine7->Visible(true);
	mTextLine8->Visible(false);
	mTextLine9->Visible(false);
	mTextLine10->Visible(false);
	mTextLine11->Visible(false);

	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(false);
	mButtons[3].Visible(false);
	mButtons[4].Visible(false);
	mButtons[5].Visible(false);
	mButtons[6].Visible(false);
	mButtons[7].Visible(false);
	mButtons[8].Visible(false);
	mButtons[9].Visible(false);
	mButtons[10].Visible(true);
}

void CombatScreen::EnemyTurn() {
	if (mCurrentEnemy.IsAlive()) {
		int enemyDamage = mCurrentEnemy.Attack(); // Enemy attacks the player
		int damageReduction = mPlayer->GetDamageReduction();
		int takendamage = enemyDamage - damageReduction;
		if (takendamage <= 0) {
			takendamage = 0;
		}
		mPlayer->TakeDamage(takendamage); // Player takes damage

		// Update player's HP on the screen
		mTextLine2->SetText("Current HP: " + std::to_string(mPlayer->GetHealth()), "ToThePoint.ttf", 36, { 0,0,0 }, false);

		// Check if the player is still alive
		if (!mPlayer->IsAlive()) {
			GameOver(); // Handle game over
		}
	}
}


void CombatScreen::SetupButtons() {
	Button* BackButton = new Button(Graphics::SCREEN_WIDTH * 0.27f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* QuitButton = new Button(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.9325f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* AttackButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Attack", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* InventoryButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Use an Item", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* RunButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Run", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* LightAttackButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Light Attack", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* HeavyAttackButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Heavy Attack", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* SpecialAttackButton = new Button(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Special Attack", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* UltimateAttackButton = new Button(Graphics::SCREEN_WIDTH * 0.57f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Ultimate Attack", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* ContinueButton = new Button(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.55f, 190, 42, "Continue", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* GameOverButton = new Button(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.55f, 190, 42, "Game Over", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");



	// Add buttons to the mButtons list
	mButtons.push_back(*BackButton);
	mButtons.push_back(*QuitButton);
	mButtons.push_back(*AttackButton);
	mButtons.push_back(*InventoryButton);
	mButtons.push_back(*RunButton);
	mButtons.push_back(*LightAttackButton);
	mButtons.push_back(*HeavyAttackButton);
	mButtons.push_back(*SpecialAttackButton);
	mButtons.push_back(*UltimateAttackButton);
	mButtons.push_back(*ContinueButton);
	mButtons.push_back(*GameOverButton);

	mButtons[0].Visible(true);
	mButtons[1].Visible(true);
	mButtons[2].Visible(true);
	mButtons[3].Visible(true);
	mButtons[4].Visible(true);
	mButtons[5].Visible(false);
	mButtons[6].Visible(false);
	mButtons[7].Visible(false);
	mButtons[8].Visible(false);
	mButtons[9].Visible(false);
	mButtons[10].Visible(false);

}


void CombatScreen::Update() {
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	// Check button hover state
	for (auto& btn : mButtons) {
		btn.checkHover(mouseX, mouseY);
	}
	mSymbol = new Texture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));

	mTextLine2 = new Texture("Current HP: " + std::to_string(mPlayer->GetHealth()), "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.3f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine3 = new Texture("Enemy HP: " + std::to_string(mCurrentEnemy.GetHealth()), "ToThePoint.ttf", 36, { 0,0,0 });
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.25f);
	if (mTextLine5->Visible()) mTextLine5 = new Texture("You gain: " + std::to_string(mCurrentEnemy.GetGold()) + " Gold and " + std::to_string(mCurrentEnemy.GetExp()) + " EXP!", "ToThePoint.ttf", 40, { 0,0,0 });
	mTextLine5->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	if (mTextLine9->Visible()) mTextLine9 = new Texture("You are now Level " + std::to_string(mPlayer->GetLevel()), "ToThePoint.ttf", 37, { 0,0,0 });
	mTextLine9->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.48f);
	if (mTextLine10->Visible()) mTextLine10->Update();
	if (mTextLine11->Visible()) mTextLine11->Update();

	// Handle mouse clicks on buttons
	if (mInputManager->MouseButtonPressed(InputManager::LEFT)) {
		for (auto& btn : mButtons) {
			if (btn.isHovered) {
				if (btn.label == "Back") {
					DefaultText();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Back);
				}
				else if (btn.label == "Quit") {
					GameManager::Instance()->QuitGame();

				}
				else if (btn.label == "Attack") {
					Attack();
				}
				else if (btn.label == "Use an Item") {
					DefaultText();	
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Inventory);
				}
				else if (btn.label == "Run") {
					Run();
				}
				else if (btn.label == "Light Attack") {
					std::cout << "Light Attack Clicked\n";
					int damage = mPlayer->Attack(); // Player's attack method
					mCurrentEnemy.TakeDamage(damage); // Enemy takes damage

					// Update enemy HP on the screen
					/*mTextLine3->SetText("Enemy HP: " + std::to_string(mCurrentEnemy.GetHealth()), "ToThePoint.ttf", 36, { 0,0,0 }, false);*/
					mTextLine10->SetText("You Hit them for " + std::to_string(damage), "ToThePoint.ttf", 37, {0,0,0}, false);
					mTextLine10->Visible(true);
					

					// Check if the enemy is still alive
					if (!mCurrentEnemy.IsAlive()) {
						Victory(); // Handle victory
					}
					else {
						EnemyTurn(); // Proceed with the enemy's turn
					}
				}
				else if (btn.label == "Heavy Attack") {
					int damage = mPlayer->Attack() * 2; // Player's attack method
					mCurrentEnemy.TakeDamage(damage); // Enemy takes damage

					// Update enemy HP on the screen
					/*mTextLine3->SetText("Enemy HP: " + std::to_string(mCurrentEnemy.GetHealth()), "ToThePoint.ttf", 36, { 0,0,0 }, false);*/
					mTextLine10->SetText("You Hit them for " + std::to_string(damage), "ToThePoint.ttf", 37, { 0,0,0 }, false);
					mTextLine10->Visible(true);

					// Check if the enemy is still alive
					if (!mCurrentEnemy.IsAlive()) {
						Victory(); // Handle victory
					}
					else {
						EnemyTurn(); // Proceed with the enemy's turn
					}
				}
				else if (btn.label == "Special Attack") {
					SpecialMove();
					EnemyTurn();
				}
				else if (btn.label == "Ultimate Attack") {
					std::cout << "Ultimate Attack Clicked\n";
					EnemyTurn();
				}
				else if (btn.label == "Continue") {
					DefaultText();
					mCurrentEnemy = GetRandomEnemy();
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::EndCombat);
				}
				else if (btn.label == "Game Over") {
					exit(0);
				}
			}
		}
	}
}

void CombatScreen::SpecialMove() {
	if (mPlayer->GetClass() == "Fighter") {
		mTextLine10->SetText("You spin around, hitting everyone around you.", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine10->Visible(true);
		mTextLine11->SetText("The Enemy takes 10 Damage", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine11->Visible(true);
		mCurrentEnemy.TakeDamage(10);
		if (!mCurrentEnemy.IsAlive()) {
			Victory(); // Handle victory
		}
		else {
			EnemyTurn(); // Proceed with the enemy's turn
		}

	}
	else if (mPlayer->GetClass()  == "Paladin") {
		mTextLine10->SetText("You call upon your Diety and Smite them", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine10->Visible(true);
		mTextLine11->SetText("The Enemy takes 10 Damage", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine11->Visible(true);
		mCurrentEnemy.TakeDamage(10);
		if (!mCurrentEnemy.IsAlive()) {
			Victory(); // Handle victory
		}
		else {
			EnemyTurn(); // Proceed with the enemy's turn
		}
	}
	else if (mPlayer->GetClass() == "Druid") {
		mTextLine10->SetText("You cast Thorny Grasp, Tendrils burst from the ground and grab the Enemy", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine10->Visible(true);
		mTextLine11->SetText("The Enemy takes 15 Damage", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine11->Visible(true);
		mCurrentEnemy.TakeDamage(15);
		if (!mCurrentEnemy.IsAlive()) {
			Victory(); // Handle victory
		}
		else {
			EnemyTurn(); // Proceed with the enemy's turn
		}
	}
	else if (mPlayer->GetClass() == "Warlock") {
		mTextLine10->SetText("You Siphon life from the Enemy!", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine10->Visible(true);
		mTextLine11->SetText("The Enemy takes 10 Damage (you heal for 10 health)", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine11->Visible(true);
		mCurrentEnemy.TakeDamage(10);
		mPlayer->Heal(10);
		if (!mCurrentEnemy.IsAlive()) {
			Victory(); // Handle victory
		}
		else {
			EnemyTurn(); // Proceed with the enemy's turn
		}
	}
	else if (mPlayer->GetClass() == "Sorceror") {
		mTextLine10->SetText("You Unleash a powerful Arcane blast!", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine10->Visible(true);
		mTextLine11->SetText("The Enemy takes 15 Damage", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine11->Visible(true);
		mCurrentEnemy.TakeDamage(15);
		if (!mCurrentEnemy.IsAlive()) {
			Victory(); // Handle victory
		}
		else {
			EnemyTurn(); // Proceed with the enemy's turn
		}
	}
	else if (mPlayer->GetClass() == "Wizard") {
		mTextLine10->SetText("You cast Fireball!", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine10->Visible(true);
		mTextLine11->SetText("The Enemy takes 10 Damage", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine11->Visible(true);
		mCurrentEnemy.TakeDamage(10);
		if (!mCurrentEnemy.IsAlive()) {
			Victory(); // Handle victory
		}
		else {
			EnemyTurn(); // Proceed with the enemy's turn
		}
	}
	else if (mPlayer->GetClass() == "Ranger") {
		mTextLine10->SetText("You Fire a Precise shot at the Enemy!", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine10->Visible(true);
		mTextLine11->SetText("The Enemy takes 15 Damage", "ToThePoint.ttf", 37, { 0,0,0 }, false);
		mTextLine11->Visible(true);
		mCurrentEnemy.TakeDamage(15);
		if (!mCurrentEnemy.IsAlive()) {
			Victory(); // Handle victory
		}
		else {
			EnemyTurn(); // Proceed with the enemy's turn
		}
	}
	else {
	}
}



void CombatScreen::Render() {
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



	for (auto& btn : mButtons) {
		if (btn.Visible()) {
			btn.render();
		}
	}

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}