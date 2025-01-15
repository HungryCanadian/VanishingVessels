#include "Graphics.h"


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
			sInstance = new Graphics();
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

		SDL_Surface* surface = IMG_Load(path.c_str());

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
		SDL_RenderCopyEx(mRenderer, texture, srcrect, dstrect, angle, nullptr, flip);
	}

	SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color) {
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);

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

	void Graphics::ClearBackBuffer() {
		SDL_RenderClear(mRenderer);
	}

	void Graphics::Render() {
		SDL_RenderPresent(mRenderer);

		glClearDepth(1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnableClientState(GL_COLOR_ARRAY);

		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);

		glVertex2f(0, 0);
		glVertex2f(0, 500);
		glVertex2f(500, 500);

		//glEnd();

		
		glBegin(GL_TRIANGLES);
		glColor3f(0.5f, 0.0f, 0.5f);

		glVertex2f(0, 0);
		glVertex2f(0, -500);
		glVertex2f(-500, -500);

		glBegin(GL_TRIANGLES);
		glColor3f(0.5f, 0.0f, 0.5f);

		glVertex2f(0, 0);
		glVertex2f(-500, 0);
		glVertex2f(-500, -500);

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.1f, 0.5f);

		glVertex2f(0, 0);
		glVertex2f(500, 0);
		glVertex2f(500, -500);

		glEnd();

		SDL_GL_SwapWindow(mWindow);

		
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
			SDL_WINDOW_OPENGL
		);

		if (mWindow == nullptr) {
			std::cerr << "Failed to create a window! SDL_Error: " << SDL_GetError() << "\n;";
			return false;
		}

		glContext = SDL_GL_CreateContext(mWindow);

		if (glContext == nullptr) {
			std::cerr << "SDL_GL_Context could not be created! " << SDL_GetError() << std::endl;
			return false;
		}

		GLenum error = glewInit();

		if (error != GLEW_OK) {
			std::cerr << "Could not initialize glew! " << glewGetErrorString(error) << std::endl;
		}

		/*mRenderer = SDL_CreateRenderer(
			mWindow,
			-1,
			SDL_RENDERER_ACCELERATED
		);

		if (mRenderer == nullptr) {
			std::cerr << "Failed to create a renderer! SDL_Error: " << SDL_GetError() << "\n;";
			return false;
		}*/

		if (TTF_Init() == -1) {
			std::cerr << "Unable to initialize SDL_TTF! TTF Error: " << TTF_GetError() << "\n";
			return false;
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

		return true;
	}

	SDL_Renderer* Graphics::GetRenderer() const {
		return mRenderer;  // return the SDL_Renderer instance
	}
}