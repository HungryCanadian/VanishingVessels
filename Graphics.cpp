#include "SDLGraphics.h"
#include "GLGraphics.h"


namespace SDLFramework {
	//this is how we initialize static members in a class
	//specifically ones that we do not want to be constants!!
	Graphics* Graphics::sInstance = nullptr;
	bool Graphics::sInitialized = false;

	//this is where we make this class a singleton
	Graphics* Graphics::Instance() {
		//we are checking if sInstance already has an instance of Graphics stored in it.
		if (sInstance == nullptr) {
			//if not, create a new instance of graphics
			sInstance = new GLGraphics();
		}
		//returns our graphics instance after making sure there is one.
		return sInstance;
	}

	void Graphics::Release() {
		delete sInstance;
		sInstance = nullptr;
		sInitialized = false;
	}

	bool Graphics::Initialized() {
		return sInitialized;
	}

	SDL_Texture* Graphics::LoadTexture(std::string path) {
		SDL_Texture* tex = nullptr;

		SDL_Surface* surface = GetSurfaceTexture(path);

		if (surface == nullptr) {
			//This means we have failed to fin the image
			std::cerr << "Unable to load " << path << ". IMG Error: " << IMG_GetError() << "\n";
			return nullptr;
		}

		//We can assume that we were able to create a surface of our Image
		//We want to convert from a SDL_Surface to a SDL_Texture

		tex = SDL_CreateTextureFromSurface(mRenderer, surface);
		SDL_FreeSurface(surface);

		if (tex == nullptr) {
			std::cerr << "Unable to create a texture from Surface IMG ERROR: " << IMG_GetError() << "\n";
			return nullptr;
		}

		return tex;
	}

	void Graphics::DrawCustomCursor(SDL_Texture* cursorTexture, int mouseX, int mouseY, int cursorWidth, int cursorHeight) {
		// Set the rectangle for the custom cursor at the current mouse position
		SDL_Rect cursorRect = { mouseX, mouseY, cursorWidth, cursorHeight };

		// Draw the cursor
		SDL_RenderCopy(mRenderer, cursorTexture, nullptr, &cursorRect);
	}

	void Graphics::DrawTexture(SDL_Texture* texture, SDL_Rect* srcrect, SDL_Rect* dstrect, float angle, SDL_RendererFlip flip) {
		//SDL_RenderCopyEx(mRenderer, texture, srcrect, dstrect, angle, nullptr, flip);
	}

	SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color) {
		SDL_Surface* surface = GetSurfaceText(font, text.c_str(), color);

		if (surface == nullptr) {
			std::cerr << "CreateTextTexture:: SDL_CreateTextureFromSurface ERROR:  " << SDL_GetError() << "\n";
			return nullptr;
		}

		SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);
		if (tex == nullptr) {
			std::cerr << "CreateTextTexture:: SDL_CreateTextureFromSurface ERROR:  " << SDL_GetError() << "\n";
			return nullptr;
		}

		SDL_FreeSurface(surface);
		return tex;
	}


	Graphics::Graphics() : mRenderer(nullptr) {
		sInitialized = Init();
	}

	Graphics::~Graphics() {
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
	}

	bool Graphics::Init() {

		if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
			std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
			return false;
		}

		mWindow = SDL_CreateWindow(
			WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
		);

		if (mWindow == nullptr) {
			std::cerr << "Failed to create a window! SDL_Error: " << SDL_GetError() << "\n;";
			return false;
		}

		mRenderer = SDL_CreateRenderer(
			mWindow,
			-1,
			SDL_RENDERER_ACCELERATED
		);

		if (mRenderer == nullptr) {
			std::cerr << "Failed to create a renderer! SDL_Error: " << SDL_GetError() << "\n;";
			return false;
		}

		if (TTF_Init() == -1) {
			std::cerr << "Unable to initialize SDL_TTF! TTF Error: " << TTF_GetError() << "\n";
			return false;
		}

		return true;
	}

	SDL_Renderer* Graphics::GetRenderer() const {
		return mRenderer;  // return the SDL_Renderer instance
	}

	SDL_Surface* Graphics::GetSurfaceTexture(std::string filepath) {
		SDL_Surface* surface = IMG_Load(filepath.c_str());

		if (surface == nullptr) {
			std::cerr << "Unable to load " << filepath << ". Surface Error: " << IMG_GetError() << std::endl;
			return nullptr;
		}

		return surface;
	}

	SDL_Surface* Graphics::GetSurfaceText(TTF_Font* font, std::string text, SDL_Color color) {
		SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);

		if (surface == nullptr) {
			std::cerr << "CreateSurfaceText: TTF_RenderText_Blended Error: " << TTF_GetError() << std::endl;
			return nullptr;
		}

		return surface;
	}
}