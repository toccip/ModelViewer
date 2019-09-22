#pragma once
#include "GL/glew.h"
#include "../utils/fileutils.h"

namespace quetzal {
	class Texture {
	private:
		unsigned int textureID;
	public:
		Texture(const char* filename);
		~Texture();
		void bind() const;
		void unbind() const;
	};
}