#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "glew.h"

namespace SDLFramework {
	class Graphics {
	public:
		static const int SCREEN_WIDTH = 1024;
		static const int SCREEN_HEIGHT = 896;
		const char* WINDOW_TITLE = "Vanishing Vessels of Caspira";

		static Graphics* Instance();
		//handle releasing memory (unitializing memory)
		static void Release();
		static bool Initialized();

		SDL_Texture* LoadTexture(std::string path);

		void DrawTexture(SDL_Texture* texture, SDL_Rect* srcRect = nullptr, SDL_Rect* dst_Rect = nullptr,
			float angle = 0.0f, SDL_RendererFlip = SDL_FLIP_NONE);

		SDL_Texture* CreateTextTexture(TTF_Font*, std::string text, SDL_Color color);
		void DrawCustomCursor(SDL_Texture* cursorTexture, int mouseX, int mouseY, int cursorWidth, int cursorHeight);
		SDL_Renderer* GetRenderer() const;

		//Clean up that happens to the area in memory that draws the next frame
		void ClearBackBuffer();
		void Render();

		Graphics();
		~Graphics();

		bool Init();



	private:
		//This is going to hold the ONE instance of our Graphics class
		static Graphics* sInstance;
		static bool sInitialized;
		SDL_Window* mWindow = nullptr;
		SDL_Renderer* mRenderer = nullptr;

		SDL_GLContext glContext;
	};
}