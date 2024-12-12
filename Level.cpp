#include "Level.h"
#include "InputManager.h"

void Level::StartStage() {
	mStageStarted = true;
}

Level::Level(int stage) {
	mTimer = Timer::Instance();
	
	mStage = stage;
	mStageStarted = false;

	mLabelTimer = 0.0f;

	mStageLabel = new Texture("STAGE", "ToThePoint.ttf", 32, { 75,75,200 });
	mStageLabel->Parent(this);
	mStageLabel->Position(Graphics::SCREEN_WIDTH * 0.35f, Graphics::SCREEN_HEIGHT * 0.5f);

	mStageNumber = new Scoreboard({ 75,75,200 });
	mStageNumber->Score(mStage);
	mStageNumber->Parent(this);
	mStageNumber->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mStageLabelOnScreen = 0.0f;
	mStageLabelOffScreen = 1.5f;

	mReadyLabel = new Texture("GET READY", "ToThePoint.ttf", 32, { 150,0,0 });
	mReadyLabel->Parent(this);
	mReadyLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	mReadyLabelOnScreen = mStageLabelOffScreen;
	mReadyLabelOffScreen = mReadyLabelOnScreen + 3.0f;

	mPlayerHit = false;
	mRespawnDelay = 3.0f;
	mRespawnLabelOnScreen = 2.0f;

	mGameOverLabel = new Texture("Game Over!", "ToThePoint.ttf", 32, { 150,0,0 });
	mGameOverLabel->Parent(this);
	mGameOverLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);
	
	mGameOverDelay = 6.0f;
	mGameOverTimer = 0.0f;
	mGameOverLabelOnScreen = 1.0f;

	mCurrentState = Running;

}

Level::~Level() {
	mTimer = nullptr;

	delete mStageLabel;
	mStageLabel = nullptr;
	delete mStageNumber;
	mStageNumber = nullptr;
	delete mReadyLabel;
	mReadyLabel = nullptr;

	delete mGameOverLabel;
	mGameOverLabel = nullptr;
}

Level::LevelStates Level::State() {
	return mCurrentState;
}

void Level::HandleStartLabels() {
	mLabelTimer += mTimer->DeltaTime();

	if (mLabelTimer >= mStageLabelOffScreen) {

		if (mStage > 1) {
			StartStage();
		}
		else {
			//GET READY label only shows on stage 1 - change this?
			if (mLabelTimer >= mReadyLabelOffScreen) {
				StartStage();

			}
		}
	}
}

void Level::HandleCollisions() {
	if (!mPlayerHit) {
		if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_X)) {
			
		}
	}
}

void Level::Update() {
	
}

void Level::Render() {
	
}


