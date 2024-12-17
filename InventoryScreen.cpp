#include "InventoryScreen.h"
#include "GameManager.h"


std::vector<Inventory> PlayerInventory = {
	{ "backpack", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "gold pouch", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "mess kit", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "tinderbox", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "torch", Effect(0,0,0), 10, 1, false, ItemType::Item },
	{ "rations", Effect(2,0,0), 5, 1, true, ItemType::Consumable },
	{ "waterskin", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "rope", Effect(0,0,0), 1, 2, false, ItemType::Item },
	{ "healing potion", Effect(5,0,0), 5, 5, true, ItemType::Consumable },
};

std::vector<Inventory> BlacksmithShop = {
	{ "sword", Effect(0,3,0), 1, 15, false, ItemType::Weapon, false },
	{ "shield", Effect(0,0,0,1), 1, 25, false, ItemType::Gear, false },
	{ "crossbow", Effect(0,2,0), 1, 20, false, ItemType::Weapon, false },
	{ "armor", Effect(0,0,0,2), 1, 100, false, ItemType::Gear, false },
};

static vector<Inventory> MerchantShop = {
	{ "healing potion", Effect(5,0,0), 5, 5, true, ItemType::Consumable },
	{ "rations", Effect(2,0,0), 30, 1, true, ItemType::Consumable },
	{ "mess kit", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "tinderbox", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "torch", Effect(0,0,0), 10, 1, false, ItemType::Item },
	{ "waterskin", Effect(0,0,0), 1, 1, false, ItemType::Item },
	{ "rope", Effect(0,0,0), 1, 2, false, ItemType::Item }

};

InventoryScreen::InventoryScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInputManager = InputManager::Instance();
	mInventory = Inventory::Instance();



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

	mTextLine1 = new Texture("What would you like to do?", "ToThePoint.ttf", 42, {0,0,0});
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.67f);
	mTextLine2 = new Texture("The islands, known for their lush forests and masterful shipbuilders,", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine2->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mTextLine3 = new Texture("thrived on exports of fine lumber and swift sailing ships.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.28f);
	mTextLine4 = new Texture("Yet, a dark cloud loomed over the vibrant trade routes;", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine4->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);
	mTextLine5 = new Texture("vessels laden with precious cargo had begun to vanish without a trace.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine5->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.34f);
	mTextLine6 = new Texture("The people of Caspira grew anxious.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine6->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.385f);
	mTextLine7 = new Texture("Whispers of curses and sea spirits filled the air,", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine7->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.43f);
	mTextLine8 = new Texture("as merchants and sailors traded tales of the lost ships.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine8->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.46f);
	mTextLine9 = new Texture("One night, as the village gathered by the flickering lanterns,", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine9->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.49f);
	


	mCursorTexture = new Texture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor



	SetupButtons();
	DisplayInventoryItem(PlayerInventory);

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
	Button* NewButton = new Button(Graphics::SCREEN_WIDTH * 0.30f, Graphics::SCREEN_HEIGHT * 0.91f, 190, 42, "New Character", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* QuitButton = new Button(Graphics::SCREEN_WIDTH * 0.60f, Graphics::SCREEN_HEIGHT * 0.91f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");
	Button* UseButton = new Button(Graphics::SCREEN_WIDTH * 0.60f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Use an Item", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* EquipButton = new Button(Graphics::SCREEN_WIDTH * 0.30f, Graphics::SCREEN_HEIGHT * 0.75f, 190, 42, "Equip/Unequip Item", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	


	// Add buttons to the mButtons list
	mButtons.push_back(*NewButton);
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

	// Loop through the inventory and add a texture for each item
	for (int i = 0; i < inventory.size(); ++i) {
		Inventory& selectedItem = inventory[i];

		std::string itemName = selectedItem.GetItemName();
		int itemQuantity = selectedItem.GetItemQuantity();

		std::string displayString = itemName + " x" + std::to_string(itemQuantity);

		// Create a new texture for the inventory item name
		Texture* textLine = new Texture(displayString, "ToThePoint.ttf", 42, { 0, 0, 0 });

		// Adjust Y-position dynamically (previous Y-positioning logic)
		float itemPosY = Graphics::SCREEN_HEIGHT * (0.22f + i * 0.05f);
		textLine->Position(Graphics::SCREEN_WIDTH * 0.27f, itemPosY);

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
			std::string buttonLabel = itemName + " x" + std::to_string(itemQuantity);

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

void InventoryScreen::Update() {
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
				if (btn.label == "New Character") {
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::NewCharacter);

				}
				else if (btn.label == "Quit") {
					GameManager::Instance()->QuitGame();
				}
				else if (btn.label == "Use an Item") {
					for (int i = 0; i < mTextLines.size(); i++) {
						mTextLines[i]->Visible(false);  // Hide each texture
					}
					DisplayConsumableItems(PlayerInventory);
					if (btn.label == "Use an Item") {
						btn.Visible(false);
					}
				}
				else if (btn.label == "Equip/Unequip Item") {
					std::cout << "Toggle Equip Item Clicked.";
				}
			}
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