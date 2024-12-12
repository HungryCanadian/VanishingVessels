#pragma once
#include "Texture.h"

namespace SDLFramework {

    class Button {
    public:
        Button(float x, float y, float w, float h, const std::string& label, const std::string& fontPath, int fontSize, SDL_Color bgColor, const std::string& buttonTexture = "Button.png");
        ~Button();

        void checkHover(int mouseX, int mouseY);
        void render();
        void Visible(bool visibility);  // Method to set the visibility of the button
        bool Visible() const;  // Method to get the visibility status of the button

        bool isHovered;
        std::string label;
    private:
        float x, y, width, height;
        
        SDL_Color mBgColor;
        std::string mFontPath;
        int mFontSize;

        bool mVisible;
        

        Texture* mBackgroundTexture;  // Custom background texture for the button
        Texture* mTextTexture;        // Text on the button
    };
}