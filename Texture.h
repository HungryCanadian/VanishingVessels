#pragma once
#include "GameEntity.h"
#include "AssetManager.h"
#include <SDL_ttf.h>

namespace SDLFramework {
    class Texture : public GameEntity {
    public:
        // Constructor for loading an image as a texture
        Texture(std::string filename, bool managed = true);

        // Constructor for creating a texture from a piece of an image (clipping)
        Texture(std::string filename, int x, int y, int width, int height, bool managed = true);

        // Constructor for creating a texture from text
        Texture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed = true);

        // Destructor
        ~Texture();

        // Set the new text and update the texture
        void SetText(const std::string& newText, std::string fontPath, int size, SDL_Color color, bool managed);
        void Visible(bool visible) { mVisible = visible; }
        bool Visible() const { return mVisible; }
        // Getter for SDL_Texture
        SDL_Texture* GetSDLTexture();

        // Setters for width and height
        void SetWidth(int width);
        void SetHeight(int height);

        // Method to return scaled dimensions
        Vector2 ScaledDimensions();

        // Render the texture to the screen
        virtual void Render() override;

    protected:
        SDL_Texture* mTexture;      // SDL texture to render
        Graphics* mGraphics;        // Graphics instance for drawing
        TTF_Font* mFont;            // Font for rendering text
        SDL_Color mTextColor;       // Text color
        std::string mText;          // Current text for the texture
        bool mClipped;              // Whether the texture is clipped
        SDL_Rect mSourceRect;       // Source rectangle for clipping (if used)
        SDL_Rect mDestinationRect;  // Destination rectangle for rendering
        int mWidth;                 // Width of the texture (in pixels)
        int mHeight;                // Height of the texture (in pixels)
        bool mVisible = true;       // Setting visibility of textures, default is True
    };
}
