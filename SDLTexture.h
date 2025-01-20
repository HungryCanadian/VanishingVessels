#pragma once
#include "Texture.h"

namespace SDLFramework {
	class SDLTexture : public Texture {
    public:
        SDLTexture(std::string filename, bool managed = true);

        // Constructor for creating a texture from a piece of an image (clipping)
        SDLTexture(std::string filename, int x, int y, int width, int height, bool managed = true);

        // Constructor for creating a texture from text
        SDLTexture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed = true);

        ~SDLTexture();

        void Render() override;
    private:
	};
}