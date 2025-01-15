#include "Button.h"
#include "Graphics.h"
#include "AssetManager.h"
#include <SDL_ttf.h>

namespace SDLFramework {

    Button::Button(float x, float y, float w, float h, const std::string& label, const std::string& fontPath, int fontSize, SDL_Color bgColor, const std::string& textureFile)
        : x(x), y(y), width(w), height(h), label(label), mBgColor(bgColor), mFontPath(fontPath), mFontSize(fontSize), isHovered(false), mVisible(true) {
        
        mAudio->AudioManager::Instance();

        // Create the background texture (using the provided textureFile)
        mBackgroundTexture = new Texture(textureFile, false);  // Create texture with the provided file path
        mBackgroundTexture->Position(x + width / 2, y + height / 2);  // Set the position of the background texture
        mBackgroundTexture->SetWidth(width);  // Set the width of the background texture
        mBackgroundTexture->SetHeight(height);  // Set the height of the background texture

        // Create the text texture (label)
        mTextTexture = new Texture(label, fontPath, fontSize, { 255, 255, 255, 255 }, false);  // White text
        mTextTexture->Parent(mBackgroundTexture);
        mTextTexture->Position(Vec2_Zero);  // Center text on button

        mClickStartTime = 0;
        mClickTimerStarted = false;
        mDoubleClickThreshold = 500;
        
    }

    Button::~Button() {
       /* delete mBackgroundTexture;
        mBackgroundTexture = nullptr;

        delete mTextTexture;
        mTextTexture = nullptr;*/
    }

    void Button::checkHover(int mouseX, int mouseY) {
        //Check if the button is visible
        if (!mVisible) {
            isHovered = false;
            return;
        }
        // Check if mouse is over the button (simple bounding box check)
        isHovered = (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
    }

    void Button::checkClick(int mouseX, int mouseY, bool mousePressed) {
        Mix_Chunk* buttonClickSound = Mix_LoadWAV("ButtonClick.wav");
        if (!isHovered) {
            // If button is not hovered, reset clicked states
            isClicked = false;
            isDoubleClicked = false;  // Also reset double-click state
            return;
        }

        // Handle first click (start timing) and subsequent clicks
        if (mousePressed) {
            // If no click has been detected yet, start the timer for the first click
            if (!mClickTimerStarted) {
                mClickStartTime = SDL_GetTicks();
                mClickTimerStarted = true;
                isClicked = false;  // Reset previous clicked state to avoid accidental click detection
                isDoubleClicked = false;  // Reset double-click state
            }
            else {
                // Check if the current time is within the double-click threshold
                Uint32 clickTime = SDL_GetTicks() - mClickStartTime;
                if (clickTime < mDoubleClickThreshold) {
                    isDoubleClicked = true;  // It's a double-click
                    isClicked = false;  // Ensure it's not marked as a single click
                }
                else {
                    isClicked = true;  // Single-click
                    isDoubleClicked = false;  // Reset double-click state
                }
            }
            Mix_VolumeChunk(buttonClickSound, 10);
            mAudio->PlaySFX(buttonClickSound, 0, -1, 50);
        }
        else {
            // Reset click timer when the mouse button is released
            if (mClickTimerStarted) {
                mClickTimerStarted = false;  // Stop the timer when the mouse is released
            }
        }
    }

    void Button::render() {
        if (isHovered) {
            // Add a hover effect (like changing the background color or texture)
            mBackgroundTexture->SetWidth(width * 1.05);  // Example: scale the button up when hovered
            mBackgroundTexture->SetHeight(height * 1.05);  // Example: scale the button up when hovered
        }
        else {
            // Render normal texture size
            mBackgroundTexture->SetWidth(width);
            mBackgroundTexture->SetHeight(height);
        }

        mBackgroundTexture->Render();
        mTextTexture->Render();  // Render text on top of the button
    }

    void Button::Visible(bool visibility) {
        mVisible = visibility;  // Set the button's visibility flag
    }

    // Return whether the button is visible
    bool Button::Visible() const {
        return mVisible;  // Return the visibility status
    }

    void Button::ResetDoubleClick() {
        isDoubleClicked = false;
    }
}