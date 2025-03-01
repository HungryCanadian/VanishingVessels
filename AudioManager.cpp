#include "AudioManager.h"

namespace SDLFramework {
	AudioManager* AudioManager::sInstance = nullptr;

	AudioManager* AudioManager::Instance() {
		if (sInstance == nullptr) {
			sInstance = new AudioManager();

		}
		return sInstance;
	}
	
	void AudioManager::Release() {
		delete sInstance;
		sInstance = nullptr;
	}

	void AudioManager::PlayMusic(std::string filename, int loops, int volume) {
		Mix_MasterVolume(volume);
		Mix_PlayMusic(mAssetManager->getMusic(filename), loops);
	}

	void AudioManager::PlayMusic(Mix_Music* music, int loops, int volume) {
		Mix_MasterVolume(volume);
		Mix_PlayMusic(music, loops);
	}

	void AudioManager::PauseMusic() {
		if (Mix_PlayingMusic() != 0) {
			Mix_PauseMusic();
		}
	}

	void AudioManager::ResumeMusic() {
		if (Mix_PausedMusic() != 0) {
			Mix_ResumeMusic();
		}
	}

	void AudioManager::PlaySFX(std::string filename, int loops, int channel, int volume) {
		Mix_PlayChannel(channel, mAssetManager->getSFX(filename), loops);
		Mix_Volume(channel, volume);
	}

	void AudioManager::PlaySFX(Mix_Chunk* sfx, int loops, int channel, int volume) {
		Mix_PlayChannel(channel, sfx, loops);
		Mix_Volume(channel, volume);
	}

	AudioManager::AudioManager() {
		mAssetManager = AssetManager::Instance();

		if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
			std::cerr << "Unable to Initialize SDL Audio! SDL Error: " << SDL_GetError() << "\n";
			return;
		}

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
			std::cerr << "Unable to Initialize audio! Mix Error: " << Mix_GetError() << "\n";
			return;
		}

	}

	AudioManager::~AudioManager() {
		mAssetManager = nullptr;
		Mix_CloseAudio();
		Mix_Quit();
	}

}