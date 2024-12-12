#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class TextInput {
public:
    TextInput(SDL_Renderer* renderer, TTF_Font* font, SDL_Color textColor, int x, int y);
    ~TextInput();

    void Update();
    void Render();

private:
    SDL_Renderer* mRenderer;
    TTF_Font* mFont;
    SDL_Color mTextColor;
    SDL_Rect mTextRect;
    SDL_Texture* mTextTexture;
    std::string inputText;
};


