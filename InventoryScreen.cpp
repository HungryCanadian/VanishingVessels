#include "InventoryScreen.h"
#include "GameManager.h"


std::vector<Inventory> PlayerInventory = {
	{ "Backpack", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "Gold pouch", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "Mess kit", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "Tinderbox", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "Torch", Effect(0,0,0), 10, 1, false, ItemType::Item },
	{ "Rations", Effect(2,0,0), 5, 1, true, ItemType::Consumable },
	{ "Waterskin", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "Rope", Effect(0,0,0), 1, 2, false, ItemType::Item },
	{ "Healing potion", Effect(5,0,0), 5, 5, true, ItemType::Consumable },
};

std::vector<Inventory> BlacksmithShop = {
	{ "Sword", Effect(0,3,0), 1, 15, false, ItemType::Weapon, false },
	{ "Shield", Effect(0,0,0,1), 1, 25, false, ItemType::Gear, false },
	{ "Crossbow", Effect(0,2,0), 1, 20, false, ItemType::Weapon, false },
	{ "Armor", Effect(0,0,0,2), 1, 100, false, ItemType::Gear, false },
};

static vector<Inventory> MerchantShop = {
	{ "Healing potion", Effect(5,0,0), 5, 5, true, ItemType::Consumable },
	{ "Rations", Effect(2,0,0), 30, 1, true, ItemType::Consumable },
	{ "Mess kit", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "Tinderbox", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "Torch", Effect(0,0,0), 10, 1, false, ItemType::Item },
	{ "Waterskin", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "Rope", Effect(0,0,0), 1, 2, false, ItemType::Item }

};

std::vector<Inventory>& InventoryScreen::GetBlacksmithInventory() {
	return BlacksmithShop;
}
std::vector<Inventory>& InventoryScreen::GetMerchantInventory() {
	return MerchantShop;
}
std::vector<Inventory>& InventoryScreen::GetPlayerInventory() {
	return PlayerInventory;
}

InventoryScreen::InventoryScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInputManager = InputManager::Instance();
	mInventory = Inventory::Instance();
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

	mLabel = new SDLTexture("Inventory", "ToThePoint.ttf", 80, { 53,33,0 });
	mLabel->Parent(this);
	mLabel->Position(Graphics::SCREEN_WIDTH * 0.38f, Graphics::SCREEN_HEIGHT * 0.06f);
	mLabel->Visible(true);

	mTextLine1 = new SDLTexture("What would you like to do?", "ToThePoint.ttf", 42, {0,0,0});
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.67f);
	mTextLine2 = new SDLTexture("You don't have anymore!", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine3 = new SDLTexture("thrived on exports of fine lumber and swift sailing ships.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine4 = new SDLTexture("Yet, a dark cloud loomed over the vibrant trade routes;", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine4->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine5 = new SDLTexture("vessels laden with precious cargo had begun to vanish without a trace.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine5->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine6 = new SDLTexture("The people of Caspira grew anxious.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine6->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.385f);
	mTextLine7 = new SDLTexture("Whispers of curses and sea spirits filled the air,", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine7->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.43f);
	mTextLine8 = new SDLTexture("as merchants and sailors traded tales of the lost ships.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine8->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.46f);
	mTextLine9 = new SDLTexture("One night, as the village gathered by the flickering lanterns,", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine9->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.49f);
	


	mCursorTexture = new SDLTexture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor



	SetupButtons();
	DisplayInventoryItem(PlayerInventory);

	mFlashTimer = 0.0f;
	mFlashDelay = 0.57f;

}

InventoryScreen::~InventoryScreen() {
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



	delete mLevel;
	mLevel = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}

void InventoryScreen::SetupButtons() {
	Button* BackButton = new Button(Graphics::SCREEN_WIDTH * 0.30f, Graphics::SCREEN_HEIGHT * 0.91f, 190, 42, "Back", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* QuitButton = new Button(Graphics::SCREEN_WIDTH * 0.60f, Graphics::SCREEN_HEIGHT * 0.91f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* UseButton = new Button(Graphics::SCREEN_WIDTH * 0.60f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Use an Item", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* EquipButton = new Button(Graphics::SCREEN_WIDTH * 0.30f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Equip/Unequip Item", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	


	// Add buttons to the mButtons list
	mButtons.push_back(*BackButton);
	mButtons.push_back(*QuitButton);
	mButtons.push_back(*UseButton);
	mButtons.push_back(*EquipButton);
}

void InventoryScreen::DisplayInventoryItem(std::vector<Inventory> inventory) {
	// Clear old textures and buttons
	for (auto textLine : mTextLines) {
		delete textLine;
	}
	mTextLines.clear();
	for (int i = 3; i < mButtons.size(); i++) {
		mButtons[i].Visible(false);
	}
	for (auto& btn : mButtons) {
		if (btn.label == "Equip/Unequip Item") {
			btn.Visible(true);
		}
		if (btn.label == "Use an Item") {
			btn.Visible(true);
		}
	}

	// Loop through the inventory and add a texture for each item
	for (int i = 0; i < inventory.size(); ++i) {
		Inventory& selectedItem = inventory[i];

		std::string itemName = selectedItem.GetItemName();
		int itemQuantity = selectedItem.GetItemQuantity();

		std::string displayString = itemName + " x" + std::to_string(itemQuantity);

		// Create a new texture for the inventory item name
		SDLTexture* textLine = new SDLTexture(displayString, "ToThePoint.ttf", 42, { 0, 0, 0 });

		// Adjust Y-position dynamically (previous Y-positioning logic)
		float itemPosY = Graphics::SCREEN_HEIGHT * (0.22f + i * 0.03f);
		textLine->Position(Graphics::SCREEN_WIDTH * 0.28f, itemPosY);

		mTextLines.push_back(textLine);
		mTextLines[i]->Visible(true);

	}
}

void InventoryScreen::DisplayConsumableItems(std::vector<Inventory> inventory) {
	// Clear old textures and buttons
	for (auto textLine : mTextLines) {
		delete textLine;
	}
	mTextLines.clear();

	for (int i = 3; i < mButtons.size(); i++) {
		mButtons[i].Visible(false);
	}
	for (auto& btn : mButtons) {
		if (btn.label == "Equip/Unequip Item") {
			btn.Visible(true);
		}
	}

	// This will keep track of the position for consumable items
	int positionIndex = 0;

	// Loop through the inventory and create a button for each consumable item
	for (int i = 0; i < inventory.size(); ++i) {
		Inventory& selectedItem = inventory[i];

		// Only create a button for consumable items
		if (selectedItem.IsUsable()) {
			std::string itemName = selectedItem.GetItemName();
			int itemQuantity = selectedItem.GetItemQuantity();

			// Combine item name and quantity for the button label
			std::string buttonLabel = itemName;

			// Dynamically create a button for each consumable item
			// We increment positionIndex only for consumable items to adjust the Y position
			float itemPosY = Graphics::SCREEN_HEIGHT * (0.22f + positionIndex * 0.05f);

			Button *itemButton = new Button(
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

			for (auto& btn : mButtons) {
				if (btn.label == "Use an Item") {
					btn.Visible(false);
				}
			}
		}
	}
}

void InventoryScreen::DisplayEquippableItems(std::vector<Inventory> inventory) {
	// Clear old textures and buttons
	for (auto textLine : mTextLines) {
		delete textLine;
	}
	mTextLines.clear();
	for (int i = 3; i < mButtons.size(); i++) {
		mButtons[i].Visible(false);
	}
	for (auto& btn : mButtons) {
		if (btn.label == "Use an Item") {
			btn.Visible(true);
		}
	}

	// This will keep track of the position for consumable items
	int positionIndex = 0;

	// Loop through the inventory and create a button for each consumable item
	for (int i = 0; i < inventory.size(); ++i) {
		Inventory& selectedItem = inventory[i];

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

			for (auto& btn : mButtons) {
				if (btn.label == "Equip/Unequip Item") {
					btn.Visible(false);
				}
			}
		}
	}
}

void InventoryScreen::Update() {
	mSymbol = new SDLTexture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));
	mSymbol->Update();
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	// Check button hover state
	for (auto& btn : mButtons) {
		btn.checkHover(mouseX, mouseY);
	}

	for (int i = 0; i < mTextLines.size(); i++) {
		if (mTextLines[i]->Visible()) mTextLines[i]->Render();
	}

	// Handle mouse clicks on buttons
	if (mInputManager->MouseButtonPressed(InputManager::LEFT)) {
		for (auto& btn : mButtons) {
			if (btn.isHovered) {
				mAudio->PlaySFX("buttonClick.wav", 0, -1, 50);
				if (btn.label == "Back") {
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Back);

				}
				else if (btn.label == "Quit") {
					GameManager::Instance()->QuitGame();
				}
				else if (btn.label == "Use an Item") {
					DisplayConsumableItems(PlayerInventory);
				}
				else if (btn.label == "Equip/Unequip Item") {
					DisplayEquippableItems(PlayerInventory);
				}
				else if (btn.label == "Sword") {
					for (auto& item : BlacksmithShop) {
						if (item.mName == "Sword") {
							if (item.mEquipped) {
								item.mEquipped = false;
								int damage = item.mEffect.damage;
								mPlayer->Attack(-damage);
							}
							else {
								item.mEquipped = true;
								int damage = item.mEffect.damage;
								mPlayer->Attack(damage);
							}
							break;
						}
					}					
					DisplayInventoryItem(PlayerInventory);
				}
				else if (btn.label == "Crossbow") {
					for (auto& item : BlacksmithShop) {
						if (item.mName == "Crossbow") {
							if (item.mEquipped) {
								item.mEquipped = false;
								int damage = item.mEffect.damage;
								mPlayer->Attack(-damage);
							}
							else {
								item.mEquipped = true;
								int damage = item.mEffect.damage;
								mPlayer->Attack(damage);
							}
							break;
						}
					}
					DisplayInventoryItem(PlayerInventory);
				}
				else if (btn.label == "Armor") {
					for (auto& item : BlacksmithShop) {
						if (item.mName == "Armor") {
							if (item.mEquipped) {
								item.mEquipped = false;
								int damageReduction = item.mEffect.damageReduction;
								mPlayer->RemoveDamageReduction(damageReduction);
							}
							else {
								item.mEquipped = true;
								int damageReduction = item.mEffect.damageReduction;
								mPlayer->AddDamageReduction(damageReduction);
							}
							break;
						}
					}
					DisplayInventoryItem(PlayerInventory);
				}
				else if (btn.label == "Shield") {
					for (auto& item : BlacksmithShop) {
						if (item.mName == "Shield") {
							// Check if the shield is already equipped
							if (item.mEquipped) {
								// If equipped, unequip it
								item.mEquipped = false;
								int damageReduction = item.mEffect.damageReduction;
								mPlayer->RemoveDamageReduction(damageReduction);
							}
							else {
								// If not equipped, equip it
								item.mEquipped = true;
								int damageReduction = item.mEffect.damageReduction;
								mPlayer->AddDamageReduction(damageReduction);
							}
							break; 
						}
					}
					DisplayInventoryItem(PlayerInventory);
				}
				else if (btn.label == "Rations") {
					std::cout << "Rations Consumed\n";
					// Accessing player inventory
					InventoryScreen inv;
					std::vector<Inventory>& inventory = inv.GetPlayerInventory();
					for (auto& item : inventory) {
						if (item.GetItemName() == "Rations") {
							// Item found, increment the quantity
							if (item.GetItemQuantity() == 0) {
								std::cout << "You have no more!\n";
								mTextLine2->Visible(true);
								mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.22f);
							}
							else {
								item.SetItemQuantity(item.GetItemQuantity() - 1);
								mPlayer->Heal(3);
							}
							break;
						}
					}
					DisplayInventoryItem(PlayerInventory);
				}
				else if (btn.label == "Healing potion") {
					// Accessing player inventory
					InventoryScreen inv;
					std::vector<Inventory>& inventory = inv.GetPlayerInventory();
					for (auto& item : inventory) {
						if (item.GetItemName() == "Healing potion") {
							// Item found, increment the quantity
							if (item.GetItemQuantity() == 0) {
								std::cout << "You have no more!\n";
								mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.27f);
								if (mFlashTimer == 0.0f) {
									mTextLine2->Visible(true); // Show the texture when first clicked
								}
								mFlashTimer += mTimer->DeltaTime();
								if (mFlashTimer <= mFlashDelay) {
									mTextLine2->Visible(true);
								}
								if (mFlashTimer >= mFlashDelay) {
									mTextLine2->Visible(false);
									mFlashTimer = 0.0f;
								}
								
							}
							else {
								item.SetItemQuantity(item.GetItemQuantity() - 1);
								mPlayer->Heal(5);
							}
							break;
						}
					}
					DisplayInventoryItem(PlayerInventory);
				}
			}
		}
	}
	if (mFlashTimer > 0.0f && mFlashTimer < mFlashDelay) {
		mFlashTimer += mTimer->DeltaTime(); // Increment timer on every frame
		if (mFlashTimer >= mFlashDelay) {
			mTextLine2->Visible(false);
		}
	}
}


void InventoryScreen::Render() {
	mTest->Render();
	mTextArea->Render();
	mPaperOverlay->Render();
	mTopBar->Render();
	mBottomBar->Render();
	mTextLine1->Render();
	mSymbol->Render();
	mLabel->Render();
	

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