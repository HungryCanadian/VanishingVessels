#include "Texture.h"
#include "AssetManager.h"
#include "Graphics.h"
#include <SDL_ttf.h>
#include <iostream>

namespace SDLFramework {
	Texture::Texture(std::string filename, bool managed) {
		mGraphics = Graphics::Instance();
		mTexture = AssetManager::Instance()->getTexture(filename, managed);

		SDL_QueryTexture(mTexture, nullptr, nullptr, &mWidth, &mHeight);

		mClipped = false;
		mDestinationRect.w = mWidth;
		mDestinationRect.h = mHeight;
	}

	Texture::Texture(std::string filename, int x, int y, int width, int height, bool managed) {
		mGraphics = Graphics::Instance();
		mTexture = AssetManager::Instance()->getTexture(filename, managed);

		mWidth = width;
		mHeight = height;

		mClipped = true;

		mDestinationRect.w = mWidth;
		mDestinationRect.h = mHeight;

		mSourceRect.x = x;
		mSourceRect.y = y;
		mSourceRect.w = width;
		mSourceRect.h = height;
	}

    Texture::Texture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed) {
        mGraphics = Graphics::Instance();
        mText = text;  // Store the initial text

        // Load the texture based on the initial text
        mTexture = AssetManager::Instance()->getText(mText, fontPath, size, color, managed);

        mClipped = false;
        SDL_QueryTexture(mTexture, nullptr, nullptr, &mWidth, &mHeight);
        mDestinationRect.w = mWidth;
        mDestinationRect.h = mHeight;
    }

	Texture::~Texture() {
		AssetManager::Instance()->DestroyTexture(mTexture);
		mTexture = nullptr;
		mGraphics = nullptr;
	}



    
    void Texture::SetText(const std::string& newText, std::string fontPath, int size, SDL_Color color, bool managed) {
        if (mText != newText) {
            mText = newText;  // Update the stored text

            // Recreate the texture with the new text
            mTexture = AssetManager::Instance()->getText(mText, fontPath, size, color, managed);

            // Update the width and height based on new text
            SDL_QueryTexture(mTexture, nullptr, nullptr, &mWidth, &mHeight);
            mDestinationRect.w = mWidth;
            mDestinationRect.h = mHeight;
        }
    }


    // Render the texture to the screen
    void Texture::Render() {
        if (mVisible) {
            if (mTexture != nullptr) {
                // Set the position and scale for rendering
                Vector2 pos = getPosition(World);
                Vector2 scale = getScale(World);

                mDestinationRect.x = (int)(pos.x - mWidth * scale.x * 0.5f);
                mDestinationRect.y = (int)(pos.y - mHeight * scale.y * 0.5f);
                mDestinationRect.w = (int)(mWidth * scale.x);
                mDestinationRect.h = (int)(mHeight * scale.y);

                // Render the texture
                mGraphics->DrawTexture(mTexture, mClipped ? &mSourceRect : nullptr, &mDestinationRect, getRotation(World));
            }
        }
    }

    // Get the SDL_Texture pointer for the texture
    SDL_Texture* Texture::GetSDLTexture() {
        return mTexture;
    }

    // Setters for width and height
    void Texture::SetWidth(int width) {
        mWidth = width;
        mDestinationRect.w = mWidth;
    }

    void Texture::SetHeight(int height) {
        mHeight = height;
        mDestinationRect.h = mHeight;
    }

    // Return scaled dimensions based on the current scale
    Vector2 Texture::ScaledDimensions() {
        Vector2 scaledDimensions = getScale();
        scaledDimensions.x *= mWidth;
        scaledDimensions.y *= mHeight;
        return scaledDimensions;
    }
}
