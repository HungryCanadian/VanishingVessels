#pragma once
#include "Scoreboard.h"

using namespace SDLFramework;

class Level : public GameEntity {
public:
	enum LevelStates { Running, Finished, GameOver };

	Level(int stage);
	~Level();

	LevelStates State();

	void Update();
	void Render();

	

private:
	Timer* mTimer;


	int mStage;
	bool mStageStarted;

	SDLTexture* mReadyLabel;
	float mReadyLabelOnScreen;
	float mReadyLabelOffScreen;

	SDLTexture* mStageLabel;
	Scoreboard* mStageNumber;
	float mStageLabelOnScreen;
	float mStageLabelOffScreen;

	float mLabelTimer;

	bool mPlayerHit;
	float mRespawnDelay;
	float mRespawnTimer;
	float mRespawnLabelOnScreen;

	SDLTexture* mGameOverLabel;
	float mGameOverDelay;
	float mGameOverTimer;
	float mGameOverLabelOnScreen;

	LevelStates mCurrentState;

	void HandleStartLabels();
	void HandleCollisions();
	void HandlePlayerDeath();

	void StartStage();

	
};
