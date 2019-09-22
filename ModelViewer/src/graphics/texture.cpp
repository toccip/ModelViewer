#include "texture.h"

namespace quetzal {
	Texture::Texture(const char* filename) {
		unsigned int imgWidth, imgHeight;
		unsigned char* imgData;
		if (!read_bmp(filename, imgData, imgWidth, imgHeight)) {
			return;
		}

		glGenTextures(1, &textureID);

		// "Bind" the newly created texture : all future texture functions will modify this texture
		bind();

		// Give the image to OpenGL
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, imgData);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		unbind();
		delete imgData;
	}

	Texture::~Texture() {
		glDeleteTextures(1, &textureID);
	}

	void Texture::bind() const{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureID);
	}

	void Texture::unbind() const {
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}