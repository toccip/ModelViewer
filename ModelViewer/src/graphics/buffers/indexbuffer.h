#pragma once
#include <vector>
#include "GL/glew.h"
namespace quetzal {
	class IndexBuffer {
	private:
		unsigned int bufferID;
		unsigned int count;
	public:
		IndexBuffer();
		void load(const std::vector<unsigned int>& a_data);
		void bind() const;
		void unbind() const;
		~IndexBuffer();
		inline unsigned int getCount() const { return count; }
	};
}