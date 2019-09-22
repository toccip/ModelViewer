#pragma once
#include <vector>
#include <GL/glew.h>
#include "../../linearalgebra.h"
namespace quetzal {

	class Buffer {
	private:
		unsigned int bufferID;
		unsigned int componentSize;
	public:
		Buffer(const std::vector<vec2>& a_data);
		Buffer(const std::vector<vec3>& a_data);
		Buffer(const std::vector<vec4>& a_data);
		~Buffer();
		void bind() const;
		void unbind() const;

		inline unsigned int getComponentSize() const { return componentSize; }
	};

}