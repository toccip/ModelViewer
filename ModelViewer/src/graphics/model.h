#pragma once
#include "buffers/vertexarray.h"
#include "buffers/indexbuffer.h"
#include "../utils/fileutils.h"

namespace quetzal {

	class Model {
	private:
		VertexArray * vao;
		IndexBuffer* ibo;
	public:
		Model();
		~Model();

		bool loadModel(const char * filename);

		inline VertexArray* getVAO() const { return vao; }
		inline IndexBuffer* getIBO() const { return ibo; }
		inline void bind() const { vao->bind(); ibo->bind(); }
		inline void unbind() const { ibo->unbind(); vao->unbind(); }
	};
}