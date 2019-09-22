#pragma once
#include "buffer.h"

namespace quetzal {
	class VertexArray {
	private:
		unsigned int vaoID;
		std::vector<Buffer*> buffers;
	public:
		VertexArray();
		~VertexArray();
		void addBuffer(Buffer* a_buffer, GLuint a_index);
		void bind() const;
		void unbind() const;

	};
}