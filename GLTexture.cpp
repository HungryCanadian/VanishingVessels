#include "GLTexture.h"
#include "GLGraphics.h"

namespace SDLFramework {
	GLTexture::GLTexture(std::string filename, bool managed) : Texture(filename, managed) {
		SetSurfaceTexture(filename, managed);
	}

	GLTexture::GLTexture(std::string filename, int x, int y, int width, int height, bool managed) : Texture(filename,x,y,width,height,managed) { 
		SetSurfaceTexture(filename, managed);
	}

	GLTexture::GLTexture(std::string text,std::string fontPath, int size, SDL_Color color, bool managed) : Texture(text, fontPath, size, color, managed) {
		SetSurfaceTextTexture(text, fontPath, size, color, managed);
	}

	void GLTexture::Generate() {
		GLint mode;
		GLint nOfColors = mSurface->format->BytesPerPixel;

		if (nOfColors == 4) {
			if (mSurface->format->Rmask == 0x000000ff) {
				mode = GL_RGBA;
			}
			else {
				mode = GL_BGRA;
			}
		}
		else if (nOfColors == 3) {
			if (mSurface->format->Rmask == 0x000000ff) {
				mode = GL_RGB;
			}
			else {
				mode = GL_BGR;
			}
		}
		else {
			mode = GL_RGBA;
		}

		glGenTextures(1, &ID);
		glBindTexture(GL_TEXTURE_2D, ID);

		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mSurface->w, mSurface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, mSurface->pixels);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	GLTexture::~GLTexture() { }

	void GLTexture::SetSurfaceTexture(std::string filename, bool managed) {
		mSurface = AssetManager::Instance()->GetSurfaceTexture(filename, managed);

		if (mSurface != nullptr) {
			Generate();
		}
		else {
			std::cerr << "mSurface nullptr in SetSurfaceTexture!\n";
		}
	}

	void GLTexture::SetSurfaceTextTexture(std::string text, std::string filename, int size, SDL_Color color, bool managed) {
		mSurface = AssetManager::Instance()->GetSurfaceText(text, filename, size, color, managed);
		
		if (mSurface != nullptr) {
			Generate();
		}
		else {
			std::cerr << "mSurface nullptr in SetSurfaceTextTexture!\n";
		}
	}

	void GLTexture::Render() {
		Texture::Render();

		GLGraphics::Instance()->DrawTexture(this, mClipped ? &mSourceRect : nullptr, &mDestinationRect, getRotation(World), Flip);
	}
}