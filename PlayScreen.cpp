#include "PlayScreen.h"
#include "GameManager.h"


PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInputManager = InputManager::Instance();


	
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

	mLabel = new Texture("Prologue", "ToThePoint.ttf", 80, { 53,33,0 });
	mLabel->Parent(this);
	mLabel->Position(Graphics::SCREEN_WIDTH * 0.38f, Graphics::SCREEN_HEIGHT * 0.06f);
	mLabel->Visible(true);

	mTextLine1 = new Texture("In the shimmering waters of the Caspiran archipelago,", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine1->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.22f);
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
	mTextLine10 = new Texture("an elderly sailor recounted a haunting legend,", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine10->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.52f);
	mTextLine11 = new Texture("a specter known as the Wraith of the Waves,", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine11->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mTextLine12 = new Texture("said to haunt the waters, claiming ships that dared to leave", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine12->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.58f);
	mTextLine13 = new Texture("with timber from the sacred Heartwood Grove.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine13->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.61f);
	mTextLine14 = new Texture("Amidst the crowd, a newcomer emerged. With eyes like stormy seas", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine14->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.64f);
	mTextLine15 = new Texture("and a unyielding spirit, they had journeyed to Caspira seeking adventure.", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine15->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.67f);
	mTextLine16 = new Texture("Hearing the villagers' plight, they felt a calling to uncover the truth", "ToThePoint.ttf", 38, { 0,0,0 });
	mTextLine16->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.70f);
	mTextLine17 = new Texture("about the disappearances. they gathered their courage,", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine17->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.73f);
	mTextLine18 = new Texture("determined to face whatever lay beneath the waves.", "ToThePoint.ttf", 42, { 0,0,0 });
	mTextLine18->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.76f);

	
	mCursorTexture = new Texture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor

	

	SetupButtons();

}

PlayScreen::~PlayScreen() {
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
	delete mTextLine17;
	mTextLine17 = nullptr;
	delete mTextLine18;
	mTextLine18 = nullptr;
	

	delete mLevel;
	mLevel = nullptr;

	delete mCursorTexture;
	mCursorTexture = nullptr;


}

void PlayScreen::SetupButtons() {
	Button* newButton = new Button(Graphics::SCREEN_WIDTH * 0.30f, Graphics::SCREEN_HEIGHT * 0.91f, 190, 42, "New Character", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* quitButton = new Button(Graphics::SCREEN_WIDTH * 0.60f, Graphics::SCREEN_HEIGHT * 0.91f, 190, 42, "Quit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");

	// Add buttons to the mButtons list
	mButtons.push_back(*newButton);
	mButtons.push_back(*quitButton);
}

void PlayScreen::Update() { 
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
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::NewCharacter);

				}
				else if (btn.label == "Quit") {
					GameManager::Instance()->QuitGame();
				}
			}
		}
	}
}
	

void PlayScreen::Render() { 
	mTest->Render();
	mTextArea->Render();
	mPaperOverlay->Render();
	mTopBar->Render();
	mBottomBar->Render();
	if (mLabel->Visible()) mLabel->Render();
	mTextLine1->Render();
	mTextLine2->Render();
	mTextLine3->Render();
	mTextLine4->Render();
	mTextLine5->Render();
	mTextLine6->Render();
	mTextLine7->Render();
	mTextLine8->Render();
	mTextLine9->Render();
	mTextLine10->Render();
	mTextLine11->Render();
	mTextLine12->Render();
	mTextLine13->Render();
	mTextLine14->Render();
	mTextLine15->Render();
	mTextLine16->Render();
	mTextLine17->Render();
	mTextLine18->Render();
	
	for (auto& btn : mButtons) {
		btn.render();
	}
	//mButtons[0].render(); //also works to render a button but only the '0' number assigned!

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);
}