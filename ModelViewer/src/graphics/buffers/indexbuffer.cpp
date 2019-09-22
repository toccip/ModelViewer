#include "indexbuffer.h"

namespace quetzal {
	
	IndexBuffer::IndexBuffer() {
		glGenBuffers(1, &bufferID);
	}

	void IndexBuffer::load(const std::vector<unsigned int>& a_data){
		count = (unsigned int)a_data.size();
		bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), &a_data[0], GL_STATIC_DRAW);
		unbind();
	}
	IndexBuffer::~IndexBuffer() {
		glDeleteBuffers(1, &bufferID);
	}
	void IndexBuffer::bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	}

	void IndexBuffer::unbind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}