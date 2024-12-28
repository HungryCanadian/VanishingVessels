#include "Merchant.h"
#include "GameManager.h"


MerchantScreen::MerchantScreen() {
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

    mLabel = new Texture("Merchant Shop", "ToThePoint.ttf", 80, { 53,33,0 });
    mLabel->Parent(this);
    mLabel->Position(Graphics::SCREEN_WIDTH * 0.38f, Graphics::SCREEN_HEIGHT * 0.06f);
    mLabel->Visible(true);

	mTextLine1 = new Texture("What would you like to do?", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.67f);
	mTextLine2 = new Texture("Welcome to Caspira's End Trading Post!", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.47f);
	mTextLine3 = new Texture("We are the best and only source of General Goods in town!", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.50f);

	mPrice1 = new Texture("Gold: 5", "ToThePoint.ttf", 42, { 0,0,0 });
	mPrice1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.24f);
	mPrice1->Visible(false);
	mPrice2 = new Texture("Gold: 1", "ToThePoint.ttf", 42, { 0,0,0 });
	mPrice2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.29f);
	mPrice2->Visible(false);
	mPrice3 = new Texture("Gold: 1", "ToThePoint.ttf", 42, { 0,0,0 });
	mPrice3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mPrice3->Visible(false);
	mPrice4 = new Texture("Gold: 1", "ToThePoint.ttf", 42, { 0,0,0 });
	mPrice4->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.39f);
	mPrice4->Visible(false);
	mPrice5 = new Texture("Gold: 1", "ToThePoint.ttf", 42, { 0,0,0 });
	mPrice5->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.44f);
	mPrice5->Visible(false);
	mPrice6 = new Texture("Gold: 1", "ToThePoint.ttf", 42, { 0,0,0 });
	mPrice6->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.49f);
	mPrice6->Visible(false);
	mPrice7 = new Texture("Gold: 1", "ToThePoint.ttf", 42, { 0,0,0 });
	mPrice7->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.54f);
	mPrice7->Visible(false);

	mSymbol = new Texture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));
	mSymbol->Visible(true);

	mBroke = new Texture("You can't afford this", "ToThePoint.ttf", 42, { 0,0,0 });
	mBroke->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.55f);
	mBroke->Visible(false);

	mSold = new Texture("You Bought Something!", "ToThePoint.ttf", 42, { 0,0,0 });
	mSold->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.55f);
	mSold->Visible(false);

	mSoldOut = new Texture("There is no more of this Item!", "ToThePoint.ttf", 42, { 0,0,0 });
	mSoldOut->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.55f);
	mSoldOut->Visible(false);


	mCursorTexture = new Texture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor


	SetupButtons();

	mBrokeTimer = 0.0f;
	mBrokeDelay = 2.0f;


}

void MerchantScreen::RunMerchant(Player* player) {
	mSymbol = new Texture(mPlayer->GetClass() + ".png");
	mSymbol->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.11f);
	mSymbol->Scale(Vector2(0.1f, 0.1f));
	mSymbol->Update();
	InventoryScreen inv;
	const std::vector<Inventory> inventory = inv.GetMerchantInventory();
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
	mPrice5->Visible(true);
	mPrice6->Visible(true);
	mPrice7->Visible(true);
	mBroke->Visible(false);
	mSold->Visible(false);
	mSoldOut->Visible(false);

	// This will keep track of the position for consumable items
	int positionIndex = 0;

	// Loop through the inventory and create a button for each consumable item
	for (int i = 0; i < inventory.size(); ++i) {
		Inventory selectedItem = inventory[i];

		// Only create a button for consumable items
		if (selectedItem.GetType() == ItemType::Item || selectedItem.GetType() == ItemType::Consumable) {
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

void MerchantScreen::DefaultScreen() {
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
	mPrice5->Visible(false);
	mPrice6->Visible(false);
	mPrice7->Visible(false);
	mBroke->Visible(false);
	mSold->Visible(false);
	mSoldOut->Visible(false);


}


MerchantScreen::~MerchantScreen() {
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
	delete mPrice5;
	mPrice5 = nullptr;
	delete mPrice6;
	mPrice6 = nullptr;
	delete mPrice7;
	mPrice7 = nullptr;

	delete mBroke;
	mBroke = nullptr;
	delete mSold;
	mSold = nullptr;
	delete mSoldOut;
	mSoldOut = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}

void MerchantScreen::SetupButtons() {
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

void MerchantScreen::Update() {
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
                    DefaultScreen();
                }
                else if (btn.label == "Quit") {
                    GameManager::Instance()->QuitGame();
                }
                else if (btn.label == "Buy") {
                    RunMerchant(mPlayer);
                }
                else if (btn.label == "Browse") {
                    // Add logic for Browse if needed
                }
                else if (btn.label == "Leave") {
                    ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Town);
                }
                else if (btn.label == "Healing potion") {
                    std::cout << "Healing Potion Bought\n";
                    if (mPlayer->GetGold() >= 5) {
                        mPlayer->SubtractGold(5);

                        // Accessing player inventory
                        InventoryScreen inv;
                        std::vector<Inventory>& inventory = inv.GetPlayerInventory();

                        // Check if the Healing Potion already exists in the inventory
                        bool itemFound = false;
                        for (auto& item : inventory) {
                            if (item.GetItemName() == "Healing potion") {
                                // Item found, increment the quantity
                                item.SetItemQuantity(item.GetItemQuantity() + 1);
                                itemFound = true;
                                break;
                            }
                        }

                        // If the item is not found, add a new one
                        if (!itemFound) {
                            inventory.push_back(Inventory("Healing potion", Effect(5, 0, 0), 1, 5, true, ItemType::Consumable));
                        }

                        mSold->Position(Graphics::SCREEN_WIDTH * 0.65f, Graphics::SCREEN_HEIGHT * 0.24f);
                        std::cout << "mSold moved position, trying to make visible\n";
                        if (mBrokeTimer == 0.0f) {
                            mSold->Visible(true); // Show the texture when first clicked
                        }
                        mBrokeTimer += mTimer->DeltaTime();
                        if (mBrokeTimer <= mBrokeDelay) {
                            mSold->Visible(true);
                        }
                        if (mBrokeTimer >= mBrokeDelay) {
                            mSold->Visible(false);
                            mBrokeTimer = 0.0f;
                        }

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
                else if (btn.label == "Rations") {
                    if (mPlayer->GetGold() >= 1) {
                        mPlayer->SubtractGold(1);

                        // Accessing player inventory
                        InventoryScreen inv;
                        std::vector<Inventory>& inventory = inv.GetPlayerInventory();

                        // Check if the Rations already exists in the inventory
                        bool itemFound = false;
                        for (auto& item : inventory) {
                            if (item.GetItemName() == "Rations") {
                                // Item found, increment the quantity
                                item.SetItemQuantity(item.GetItemQuantity() + 1);
                                itemFound = true;
                                break;
                            }
                        }

                        // If the item is not found, add a new one
                        if (!itemFound) {
                            inventory.push_back(Inventory("Rations", Effect(2, 0, 0), 1, 1, true, ItemType::Consumable));
                        }
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
                else if (btn.label == "Mess kit") {
                    if (mPlayer->GetGold() >= 1) {
                        mPlayer->SubtractGold(1);

                        // Accessing player inventory
                        InventoryScreen inv;
                        std::vector<Inventory>& inventory = inv.GetPlayerInventory();

                        // Check if the Mess kit already exists in the inventory
                        bool itemFound = false;
                        for (auto& item : inventory) {
                            if (item.GetItemName() == "Mess kit") {
                                // Item found, increment the quantity
                                item.SetItemQuantity(item.GetItemQuantity() + 1);
                                itemFound = true;
                                break;
                            }
                        }

                        // If the item is not found, add a new one
                        if (!itemFound) {
                            inventory.push_back(Inventory("Mess kit", Effect(0, 0, 0), 1, 1, false, ItemType::Item));
                        }
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
                else if (btn.label == "Tinderbox") {
                    if (mPlayer->GetGold() >= 1) {
                        mPlayer->SubtractGold(1);

                        // Accessing player inventory
                        InventoryScreen inv;
                        std::vector<Inventory>& inventory = inv.GetPlayerInventory();

                        // Check if the Tinderbox already exists in the inventory
                        bool itemFound = false;
                        for (auto& item : inventory) {
                            if (item.GetItemName() == "Tinderbox") {
                                // Item found, increment the quantity
                                item.SetItemQuantity(item.GetItemQuantity() + 1);
                                itemFound = true;
                                break;
                            }
                        }

                        // If the item is not found, add a new one
                        if (!itemFound) {
                            inventory.push_back(Inventory("Tinderbox", Effect(0, 0, 0), 1, 1, false, ItemType::Item));
                        }
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
                else if (btn.label == "Torch") {
                    if (mPlayer->GetGold() >= 1) {
                        mPlayer->SubtractGold(1);

                        // Accessing player inventory
                        InventoryScreen inv;
                        std::vector<Inventory>& inventory = inv.GetPlayerInventory();

                        // Check if the Torch already exists in the inventory
                        bool itemFound = false;
                        for (auto& item : inventory) {
                            if (item.GetItemName() == "Torch") {
                                // Item found, increment the quantity
                                item.SetItemQuantity(item.GetItemQuantity() + 1);
                                itemFound = true;
                                break;
                            }
                        }

                        // If the item is not found, add a new one
                        if (!itemFound) {
                            inventory.push_back(Inventory("Torch", Effect(0, 0, 0), 1, 1, false, ItemType::Item));
                        }
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
                else if (btn.label == "Waterskin") {
                    if (mPlayer->GetGold() >= 1) {
                        mPlayer->SubtractGold(1);

                        // Accessing player inventory
                        InventoryScreen inv;
                        std::vector<Inventory>& inventory = inv.GetPlayerInventory();

                        // Check if the Waterskin already exists in the inventory
                        bool itemFound = false;
                        for (auto& item : inventory) {
                            if (item.GetItemName() == "Waterskin") {
                                // Item found, increment the quantity
                                item.SetItemQuantity(item.GetItemQuantity() + 1);
                                itemFound = true;
                                break;
                            }
                        }

                        // If the item is not found, add a new one
                        if (!itemFound) {
                            inventory.push_back(Inventory("Waterskin", Effect(0, 0, 0), 1, 1, false, ItemType::Item));
                        }
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
    if (mBrokeTimer > 0.0f && mBrokeTimer < mBrokeDelay) {
        mBrokeTimer += mTimer->DeltaTime(); // Increment timer on every frame
        if (mBrokeTimer >= mBrokeDelay) {
            mBroke->Visible(false);
        }
    }
}


void MerchantScreen::Render() {
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
	if (mPrice5->Visible()) mPrice5->Render();
	if (mPrice6->Visible()) mPrice6->Render();
	if (mPrice7->Visible()) mPrice7->Render();
	if (mBroke->Visible()) mBroke->Render();
	if (mSold->Visible()) mSold->Render();
	if (mSoldOut->Visible()) mSoldOut->Render();
    

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