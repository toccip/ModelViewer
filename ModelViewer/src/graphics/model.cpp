#include "model.h"

namespace quetzal {
	Model::Model() {
		vao = new VertexArray();
		ibo = new IndexBuffer();
	}
	
	Model::~Model() {
		delete vao;
		delete ibo;
	}

	bool Model::loadModel(const char * filename) {

		std::vector<vec3> vertices;
		std::vector<vec2> uvs;
		std::vector<vec3> normals;
		std::vector<unsigned int> indices;
		if (!read_obj(filename, vertices, uvs, normals, indices)) {
			return false;
		}

		vao->addBuffer(new Buffer(vertices), 0);
		vao->addBuffer(new Buffer(uvs), 1);
		vao->addBuffer(new Buffer(normals), 2);

		ibo->load(indices);
		return true;
	}
}