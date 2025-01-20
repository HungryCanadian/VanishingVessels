#pragma once
#include "GLTexture.h"

namespace SDLFramework {

    class Button {
    public:
        Button(float x, float y, float w, float h, const std::string& label, const std::string& fontPath, int fontSize, SDL_Color bgColor, const std::string& buttonTexture = "Button.png");
        ~Button();

        void checkHover(int mouseX, int mouseY);
        void checkClick(int mouseX, int mouseY, bool mousePressed);
        void ResetDoubleClick();
        void render();
        void Visible(bool visibility);  // Method to set the visibility of the button
        bool Visible() const;  // Method to get the visibility status of the button

        bool operator==(const Button& other) const {
            return label == other.label;  // Compare based on label (or whatever you like)
        }

        bool isHovered;
        bool isClicked;
        bool isDoubleClicked;

        Uint32 mClickStartTime;
        bool mClickTimerStarted;
        Uint32 mDoubleClickThreshold;

        std::string label;
    private:
        float x, y, width, height;
        
        SDL_Color mBgColor;
        std::string mFontPath;
        int mFontSize;

        bool mVisible;

        AudioManager* mAudio;

        

        GLTexture* mBackgroundTexture;  // Custom background texture for the button
        GLTexture* mTextTexture;        // Text on the button
    };
}