#pragma once
#include <string>
#include <cstdio>
#include <cerrno>
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../linearalgebra.h"
#include "light.h"

namespace quetzal {

	class Shader {

	private:
		GLuint shaderID;
		const char* vertPath;
		const char* fragPath;
		GLuint loadShader(const char* filename, GLenum type);
		GLint getUniformLocation(const GLchar* name) const;
	public:
		Shader(const char* a_vertPath, const char* a_fragPath);
		~Shader();
		void loadBool(const GLchar* name, int value) const;
		void loadFloat(const GLchar* name, GLfloat value) const;
		void loadVector3(const GLchar* name, vec3 vector) const;
		void loadMatrix(const GLchar* name, mat4 matrix) const;
		void loadLight(Light light) const;
		void enable() const;
		void disable() const;
	};

}