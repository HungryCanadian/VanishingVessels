#pragma once
#include "Graphics.h"
#include "AudioManager.h"
#include "PhysicsManager.h"
#include "ScreenManager.h"



namespace SDLFramework {
	//Singleton
	class GameManager {
	public:
		static GameManager* Instance();
		static void Release();

		GameManager();
		~GameManager();

		void Update();
		void LateUpdate();

		void Render();

		void Run();
		void QuitGame();


	private:
		const int FRAME_RATE = 60;
		//How we are creating this as a Singleton
		static GameManager* sInstance;
		//Loop Control
		bool mQuit;

		//Modules
		Graphics* mGraphics;
		Timer* mTimer;
		AssetManager* mAssetManager;
		InputManager* mInputManager;
		AudioManager* mAudioManager;
		PhysicsManager* mPhysicsManager;
		ScreenManager* mScreenManager;



		//Example Variables
		AnimatedTexture* mTex;
		Texture* mRedShip;
		
		Texture* mFontTex;
		Texture* mBackground2;

		PhysicsEntity* mPhysone;
		PhysicsEntity* mPhystwo;

		SDL_Event mEvents;

	};
}