#pragma once
#include "Graphics.h"

namespace SDLFramework {
	class SDLGraphics : public Graphics {
	public:
		static SDLGraphics* Instance();
		SDLGraphics();
		~SDLGraphics();

		void DrawTexture(SDL_Texture* texture, SDL_Rect* srcRect = nullptr, SDL_Rect* dst_Rect = nullptr,
			float angle = 0.0f, SDL_RendererFlip = SDL_FLIP_NONE) override;

		void Render() override;
		void ClearBackBuffer() override;

	private:

		virtual bool Init() override;

	};

}