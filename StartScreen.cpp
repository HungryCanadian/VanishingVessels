#include "StartScreen.h"
#include "GameManager.h"
#include "SDLTexture.h"

StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();
	mAudioManager = AudioManager::Instance();

	// Screen Animation Variables
	// Top Bar
	mTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 40.0f);

	// Background Entities TODO: Uncomment the Audiomanager down a line.
	// mAudioManager->PlayMusic("5. Dread March .mp3", -1);

	// Top Bar Entities
	mTopBar->Parent(this);

	mPlayModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.75f);
	mButtonTexture = new SDLTexture("PanelDarkButtonHolder.png");
	mButtonTexture->Parent(mPlayModes);
	mButtonTexture->Scale(Vector2(0.2f, 0.2f));
	mButtonTexture->Position(Vec2_Zero);

	mBackground = new SDLTexture("startBackground.png");
	mBackground->Position(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));

	mCursorTexture = new SDLTexture("Mouse.png");  // Adjust the path to your custom cursor image
	SDL_QueryTexture(mCursorTexture->GetSDLTexture(), nullptr, nullptr, &mCursorWidth, &mCursorHeight);  // Get the cursor's width and height
	SDL_ShowCursor(SDL_DISABLE);  // Hide the default SDL cursor
	

	// Logo SDLTexture
	mLogoSpace = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.25f);
	mLogoSpace->Parent(this);

	mTitleHeadboard = new SDLTexture("HeaderBackgroundDark.png");
	mTitleHeadboard->Parent(this);
	mTitleHeadboard->Position(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.10f));
	mTitleHeadboard->Scale(Vector2(0.4f, 0.2f));
	mTitleBackground = new SDLTexture("PanelDarkSquare.png");
	mTitleBackground->Parent(this);
	mTitleBackground->Position(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.25f));
	mTitleBackground->Scale(Vector2(0.3f, 0.2f));
	mPaperOverlay = new SDLTexture("LargePaperOverlay.png");
	mPaperOverlay->Parent(this);
	mPaperOverlay->Position(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.25f));
	mPaperOverlay->Scale(Vector2(0.29f, 0.19f));
	mCaspiraLogo = new SDLTexture("World of Caspira", "ToThePoint.ttf", 162, { 53,33,0 });
	mCaspiraLogo->Scale(Vector2(0.45f, 0.5f));
	mCaspiraLogo->Parent(this);
	mCaspiraLogo->Position(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.10f));
	mVanishVessels = new SDLTexture("Vanishing Vessels", "ToThePoint.ttf", 142, { 0,0,0 });
	mVanishVessels->Scale(Vector2(0.5f, 0.5f));
	mVanishVessels->Parent(this);
	mVanishVessels->Position(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.22f));
	mOfCaspira = new SDLTexture("Of Caspira", "ToThePoint.ttf", 142, { 0,0,0 });
	mOfCaspira->Scale(Vector2(0.5f, 0.5f));
	mOfCaspira->Parent(this);
	mOfCaspira->Position(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.27f));


	// Play Bar Entities
	mPlayModes->Parent(this);

	// Bottom Bar Entities
	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	mBottomBar->Parent(this);

	// Initialize buttons
	ResetAnimation();
	SetupButtons();
}

void StartScreen::ResetAnimation() {

}


void StartScreen::SetupButtons() {
	Button* playButton = new Button(Graphics::SCREEN_WIDTH * 0.40f, Graphics::SCREEN_HEIGHT * 0.70f, 200, 50, "Play", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttongreen.png");
	Button* exitButton = new Button(Graphics::SCREEN_WIDTH * 0.40f, Graphics::SCREEN_HEIGHT * 0.75f, 200, 50, "Exit", "ToThePoint.ttf", 32, { 255, 255, 255, 255 }, "buttonred.png");

	// Add buttons to the mButtons list
	mButtons.push_back(*playButton);
	mButtons.push_back(*exitButton);
}

void StartScreen::Update() {
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
				mAudioManager->PlaySFX("buttonClick.wav", 0, -1, 50);
				if (btn.label == "Play") {
					/*mAudioManager->PlaySFX("buttonClick.wav", 0, -1, 50);*/
					ScreenManager::Instance()->SetScreens(ScreenManager::Screens::Play);

				}
				else if (btn.label == "Exit") {
					GameManager::Instance()->QuitGame();
				}
			}
		}
	}
}


void StartScreen::Render() {
	mBackground->Render();
	mTitleBackground->Render();

	mPaperOverlay->Render();
	mTitleHeadboard->Render();
	mCaspiraLogo->Render();
	mVanishVessels->Render();
	mOfCaspira->Render();

	mButtonTexture->Render();
	for (auto& btn : mButtons) {
		btn.render();
	}

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Graphics::Instance()->DrawCustomCursor(mCursorTexture->GetSDLTexture(), mouseX, mouseY, mCursorWidth, mCursorHeight);

}

StartScreen::~StartScreen() {
	//Background Entities
	delete mButtonTexture;
	mButtonTexture = nullptr;

	delete mBackground;
	mBackground = nullptr;

	delete mTitleHeadboard;
	mTitleHeadboard = nullptr;

	delete mTitleBackground;
	mTitleBackground = nullptr;

	delete mPaperOverlay;
	mPaperOverlay = nullptr;

	delete mCaspiraLogo;
	mCaspiraLogo = nullptr;

	delete mVanishVessels;
	mVanishVessels = nullptr;

	delete mOfCaspira;
	mOfCaspira = nullptr;
	

	//This is our TopBar Entities
	delete mTopBar;
	mTopBar = nullptr;

	//Play Bar Entities
	delete mPlayModes;
	mPlayModes = nullptr;


	//Bottom Bar Entities
	delete mBottomBar;
	mBottomBar = nullptr;


	//Logo Entities

	delete mLogoSpace;
	mLogoSpace = nullptr;



	mTimer = nullptr;
	mInputManager = nullptr;
	mAudioManager = nullptr;
}


