#include "TextInput.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

TextInput::TextInput(SDL_Renderer* renderer, TTF_Font* font, SDL_Color textColor, int x, int y)
    : mRenderer(renderer), mFont(font), mTextColor(textColor), inputText("") {
    // Initialize text rectangle at the specified position
    mTextRect.x = x;
    mTextRect.y = y;
    mTextRect.w = 0;
    mTextRect.h = 0;
    mTextTexture = nullptr;
    mFont = TTF_OpenFont("assets/fonts/ToThePoint.ttf", 42);
    if (mFont == nullptr) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
    SDL_StartTextInput();  // Start text input mode
}

TextInput::~TextInput() {
    if (mTextTexture) {
        SDL_DestroyTexture(mTextTexture);
    }
    SDL_StopTextInput();  // Stop text input mode
}

void TextInput::Update() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            // Handle quit event
            return;
        }
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_BACKSPACE && !inputText.empty()) {
                // Remove the last character if backspace is pressed
                inputText.pop_back();
            }
        }
        if (e.type == SDL_TEXTINPUT) {
            // Append the typed character to the input text
            inputText += e.text.text;
        }
    }

    // Create the text texture from the updated input string
    if (!inputText.empty()) {
        if (mTextTexture) {
            SDL_DestroyTexture(mTextTexture);  // Destroy previous texture
        }
        SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, inputText.c_str(), mTextColor);
        mTextTexture = SDL_CreateTextureFromSurface(mRenderer, textSurface);
        mTextRect.w = textSurface->w;
        mTextRect.h = textSurface->h;
        SDL_FreeSurface(textSurface);
    }
}

void TextInput::Render() {
    // Render the updated text texture on the screen
    if (mTextTexture) {
        SDL_RenderCopy(mRenderer, mTextTexture, nullptr, &mTextRect);
    }
}
