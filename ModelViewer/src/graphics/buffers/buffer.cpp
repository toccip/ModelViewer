#include "buffer.h"

namespace quetzal {
	Buffer::Buffer(const std::vector<vec2>& a_data) {
		componentSize = 2;
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glBufferData(GL_ARRAY_BUFFER, a_data.size() * sizeof(vec2), &a_data[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	Buffer::Buffer(const std::vector<vec3>& a_data) {
		componentSize = 3;
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glBufferData(GL_ARRAY_BUFFER, a_data.size() * sizeof(vec3), &a_data[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	Buffer::Buffer(const std::vector<vec4>& a_data) {
		componentSize = 4;
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glBufferData(GL_ARRAY_BUFFER, a_data.size() * sizeof(vec4), &a_data[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	Buffer::~Buffer() {
		glDeleteBuffers(1, &bufferID);
	}

	void Buffer::bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	}

	void Buffer::unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}