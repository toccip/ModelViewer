#include "vertexarray.h"

namespace quetzal {

	VertexArray::VertexArray() {
		glGenVertexArrays(1, &vaoID);
	}

	VertexArray::~VertexArray() {
		for (int i = 0; i < buffers.size(); i++) {
			delete buffers[i];
		}
		std::vector<Buffer*>().swap(buffers);
		glDeleteVertexArrays(1, &vaoID);
	}

	void VertexArray::addBuffer(Buffer* a_buffer, GLuint a_index) {
		bind();
		a_buffer->bind();
		glEnableVertexAttribArray(a_index);
		glVertexAttribPointer(a_index, a_buffer->getComponentSize(), GL_FLOAT, GL_FALSE, 0, 0);
		glDisableVertexAttribArray(a_index);
		a_buffer->unbind();
		unbind();
		buffers.push_back(a_buffer);
	}

	void VertexArray::bind() const {
		glBindVertexArray(vaoID);
		for (int i = 0; i < buffers.size(); i++) {
			glEnableVertexAttribArray(i);
		}
	}
	void VertexArray::unbind() const {
		for (int i = 0; i < buffers.size(); i++) {
			glDisableVertexAttribArray(i);
		}
		glBindVertexArray(0);
	}
}