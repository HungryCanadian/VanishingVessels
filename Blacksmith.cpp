#include "Blacksmith.h"
#include "GameManager.h"


BlacksmithScreen::BlacksmithScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInputManager = InputManager::Instance();
	mInventory = Inventory::Instance();
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

	mLabel = new Texture("Blacksmith Shop", "ToThePoint.ttf", 80, { 53,33,0 });
	mLabel->Parent(this);
	mLabel->Position(Graphics::SCREEN_WIDTH * 0.38f, Graphics::SCREEN_HEIGHT * 0.06f);
	mLabel->Visible(true);

	mTextLine1 = new Texture("What would you like to do?", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.67f);
	mTextLine2 = new Texture("Welcome to Hooves and Steel!", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.47f);
	mTextLine3 = new Texture("We are the best and only source of blacksmithing in town!", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.50f);

	mPrice1 = new Texture("Gold: 15", "ToThePoint.ttf", 42, { 0,0,0 });
	mPrice1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.24f);
	mPrice1->Visible(false);
	mPrice2 = new Texture("Gold: 25", "ToThePoint.ttf", 42, { 0,0,0 });
	mPrice2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.29f);
	mPrice2->Visible(false);
	mPrice3 = new Texture("Gold: 20", "ToThePoint.ttf", 42, { 0,0,0 });
	mPrice3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mPrice3->Visible(false);
	mPrice4 = new Texture("Gold: 100", "ToThePoint.ttf", 42, { 0,0,0 });
	mPrice4->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.39f);
	mPrice4->Visible(false);

	mSymbol = new Texture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));
	mSymbol->Update();
	mSymbol->Visible(true);

	mBroke = new Texture("You can't afford this", "ToThePoint.ttf", 42, { 0,0,0 });
	mBroke->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mBroke->Visible(false);


	mCursorTexture = new Texture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor


	SetupButtons();

	mBrokeTimer = 0.0f;
	mBrokeDelay = 2.0f;


}

void BlacksmithScreen::RunBlacksmith(Player* player) {
	mSymbol = new Texture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));
	mSymbol->Update();
	InventoryScreen inv;
	const std::vector<Inventory> inventory = inv.GetBlacksmithInventory();
	// Clear old textures and buttons
	for (auto textLine : mTextLines) {
		delete textLine;
	}
	mTextLines.clear();
	for (int i = 3; i < mButtons.size(); i++) {
		mButtons[i].Visible(false);
	}
	for (auto& btn : mButtons) {
		if (btn.label == "Browse") {
			btn.Visible(true);
		}
		if (btn.label == "Buy") {
			btn.Visible(false);
		}
	}
	mTextLine1->Visible(false);
	mTextLine2->Visible(false);
	mTextLine3->Visible(false);
	mPrice1->Visible(true);
	mPrice2->Visible(true);
	mPrice3->Visible(true);
	mPrice4->Visible(true);
	mBroke->Visible(false);

	// This will keep track of the position for consumable items
	int positionIndex = 0;

	// Loop through the inventory and create a button for each consumable item
	for (int i = 0; i < inventory.size(); ++i) {
		Inventory selectedItem = inventory[i];

		// Only create a button for consumable items
		if (selectedItem.GetType() == ItemType::Gear || selectedItem.GetType() == ItemType::Weapon) {
			std::string itemName = selectedItem.GetItemName();
			int itemQuantity = selectedItem.GetItemQuantity();

			// Combine item name and quantity for the button label
			std::string buttonLabel = itemName;

			// Dynamically create a button for each consumable item
			// We increment positionIndex only for consumable items to adjust the Y position
			float itemPosY = Graphics::SCREEN_HEIGHT * (0.22f + positionIndex * 0.05f);

			Button* itemButton = new Button(
				Graphics::SCREEN_WIDTH * 0.25f,  // X position of the button
				itemPosY,                        // Y position of the button
				190,                             // Width of the button
				42,                              // Height of the button
				buttonLabel,                     // Button label
				"ToThePoint.ttf",                // Font path
				32,                              // Font size
				{ 255, 255, 255, 255 },          // Text color (white)
				"buttongreen.png"                 // Background texture for the button (you can change this if needed)
			);

			// Add the button to the mButtons list
			mButtons.push_back(*itemButton);  // Add pointer to vector (not dereferenced)

			// Increment the position index for the next consumable item
			positionIndex++;

		}
	}
	for (auto& btn : mButtons) {
		if (btn.isHovered) {
			
			
			//purchaseEquipItem(player, input);
		}
	}
}

void BlacksmithScreen::DefaultScreen() {
	mSymbol = new Texture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));
	mSymbol->Update();
	for (int i = 3; i < mButtons.size(); i++) {
		mButtons[i].Visible(false);
	}
	for (auto& btn : mButtons) {
		if (btn.label == "Browse") {
			btn.Visible(true);
		}
		if (btn.label == "Buy") {
			btn.Visible(true);
		}
		if (btn.label == "Leave") {
			btn.Visible(true);
		}
	}
	mTextLine1->Visible(true);
	mTextLine2->Visible(true);
	mTextLine3->Visible(true);
	mPrice1->Visible(false);
	mPrice2->Visible(false);
	mPrice3->Visible(false);
	mPrice4->Visible(false);
	mBroke->Visible(false);

}
	

BlacksmithScreen::~BlacksmithScreen() {
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

	delete mLabel;
	mLabel = nullptr;

	delete mTextLine1;
	mTextLine1 = nullptr;
	delete mTextLine2;
	mTextLine2 = nullptr;
	delete mTextLine3;
	mTextLine3 = nullptr;

	delete mPrice1;
	mPrice1 = nullptr;
	delete mPrice2;
	mPrice2 = nullptr;
	delete mPrice3;
	mPrice3 = nullptr;
	delete mPrice4;
	mPrice4 = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}

void BlacksmithScreen::SetupButtons() {
	Button* BackButton = new Button(Graphics::SCREEN_WIDTH * 0.30f, Graphics::SCREEN_HEIGHT * 0.91f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* QuitButton = new Button(Graphics::SCREEN_WIDTH * 0.60f, Graphics::SCREEN_HEIGHT * 0.91f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* BuyButton = new Button(Graphics::SCREEN_WIDTH * 0.30f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Buy", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* BrowseButton = new Button(Graphics::SCREEN_WIDTH * 0.60f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Browse", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* LeaveButton = new Button(Graphics::SCREEN_WIDTH * 0.60f, Graphics::SCREEN_HEIGHT * 0.70f, 190, 42, "Leave", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");



	// Add buttons to the mButtons list
	mButtons.push_back(*BackButton);
	mButtons.push_back(*QuitButton);
	mButtons.push_back(*BuyButton);
	mButtons.push_back(*BrowseButton);
	mButtons.push_back(*LeaveButton);
}

void BlacksmithScreen::Update() {
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	bool mousePressed = SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_LEFT);

	mSymbol = new Texture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));
	mSymbol->Visible(true);

	// Check button hover state
	for (auto& btn : mButtons) {
		btn.checkHover(mouseX, mouseY);
	}

	// Handle mouse clicks on buttons
	if (mInputManager->MouseButtonPressed(InputManager::LEFT)) {
		for (auto& btn : mButtons) {
			if (btn.isHovered) {
				if (btn.label == "Back") {
					std::cout << "Try to call the screen back to default state\n";
					DefaultScreen();
				}
				else if (btn.label == "Quit") {
					GameManager::Instance()->QuitGame();
				}
				else if (btn.label == "Buy") {
					RunBlacksmith(mPlayer);
				}
				else if (btn.label == "Browse") {
					// Add logic for Browse if needed
				}
				else if (btn.label == "Leave") {
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Town);
				}
				else if (btn.label == "Sword") {
					if (mPlayer->GetGold() >= 15) {
						mPlayer->SubtractGold(15);
						InventoryScreen inv;
						std::vector<Inventory>& inventory = inv.GetPlayerInventory();
						inventory.push_back(Inventory("Sword", Effect(0, 3, 0), 1, 15, false, ItemType::Weapon, false));
					}
					else {
						// When the player doesn't have enough gold, show the broke texture
						if (mBrokeTimer == 0.0f) {
							mBroke->Visible(true); // Show the texture when first clicked
						}
						mBrokeTimer += mTimer->DeltaTime();
						if (mBrokeTimer <= mBrokeDelay) {
							mBroke->Visible(true);
						}
						if (mBrokeTimer >= mBrokeDelay) {
							mBroke->Visible(false);
							mBrokeTimer = 0.0f;
						}
					}
				}
				else if (btn.label == "Shield") {
					if (mPlayer->GetGold() >= 25) {
						mPlayer->SubtractGold(25);
						InventoryScreen inv;
						std::vector<Inventory>& inventory = inv.GetPlayerInventory();
						inventory.push_back(Inventory("Shield", Effect(0, 0, 0, 1), 1, 25, false, ItemType::Gear, false));
					}
					else {
						// When the player doesn't have enough gold, show the broke texture
						if (mBrokeTimer == 0.0f) {
							mBroke->Visible(true); // Show the texture when first clicked
						}
						mBrokeTimer += mTimer->DeltaTime();
						if (mBrokeTimer <= mBrokeDelay) {
							mBroke->Visible(true);
						}
						if (mBrokeTimer >= mBrokeDelay) {
							mBroke->Visible(false);
							mBrokeTimer = 0.0f;
						}
					}
				}
				else if (btn.label == "Armor") {
					if (mPlayer->GetGold() >= 100) {
						mPlayer->SubtractGold(100);
						InventoryScreen inv;
						std::vector<Inventory>& inventory = inv.GetPlayerInventory();
						inventory.push_back(Inventory("Armor", Effect(0, 0, 0, 2), 1, 100, false, ItemType::Gear, false));
					}
					else {
						// When the player doesn't have enough gold, show the broke texture
						if (mBrokeTimer == 0.0f) {
							mBroke->Visible(true); // Show the texture when first clicked
						}
						mBrokeTimer += mTimer->DeltaTime();
						if (mBrokeTimer <= mBrokeDelay) {
							mBroke->Visible(true);
						}
						if (mBrokeTimer >= mBrokeDelay) {
							mBroke->Visible(false);
							mBrokeTimer = 0.0f; 
						}
					}
				}
				else if (btn.label == "Crossbow") {
					if (mPlayer->GetGold() >= 20) {
						mPlayer->SubtractGold(20);
						InventoryScreen inv;
						std::vector<Inventory>& inventory = inv.GetPlayerInventory();
						inventory.push_back(Inventory("Crossbow", Effect(0, 2, 0), 1, 20, false, ItemType::Weapon, false));
					}
					else {
						// When the player doesn't have enough gold, show the broke texture
						if (mBrokeTimer == 0.0f) {
							mBroke->Visible(true); // Show the texture when first clicked
						}
						mBrokeTimer += mTimer->DeltaTime();
						if (mBrokeTimer <= mBrokeDelay) {
							mBroke->Visible(true);
						}
						if (mBrokeTimer >= mBrokeDelay) {
							mBroke->Visible(false);
							mBrokeTimer = 0.0f;
						}
					}
				}
			}
		}
	}

	// Ensure the timer increments every frame
	if (mBrokeTimer > 0.0f && mBrokeTimer < mBrokeDelay) {
		mBrokeTimer += mTimer->DeltaTime(); // Increment timer on every frame
		if (mBrokeTimer >= mBrokeDelay) {
			mBroke->Visible(false);
		}
	}
}

void BlacksmithScreen::Render() {
	mTest->Render();
	mTextArea->Render();
	mPaperOverlay->Render();
	mTopBar->Render();
	mBottomBar->Render();
	if (mSymbol->Visible()) mSymbol->Render();
	if (mLabel->Visible()) mLabel->Render();
	if (mTextLine1->Visible()) mTextLine1->Render();
	if (mTextLine2->Visible()) mTextLine2->Render();
	if (mTextLine3->Visible()) mTextLine3->Render();
	if (mPrice1->Visible()) mPrice1->Render();
	if (mPrice2->Visible()) mPrice2->Render();
	if (mPrice3->Visible()) mPrice3->Render();
	if (mPrice4->Visible()) mPrice4->Render();
	if (mBroke->Visible()) mBroke->Render();

	for (int i = 0; i < mTextLines.size(); i++) {
		if (mTextLines[i]->Visible()) mTextLines[i]->Render();
	}

	for (auto& btn : mButtons) {
		if (btn.Visible() == true) btn.render();
	}


	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}