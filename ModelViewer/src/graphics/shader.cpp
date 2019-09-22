#include "shader.h"

namespace quetzal {

	Shader::Shader(const char* a_vertPath, const char* a_fragPath)
	: vertPath(a_vertPath), fragPath(a_fragPath){
		shaderID = glCreateProgram();
		std::cout << "loading vertex shader..." << std::endl;
		GLuint vertexID = loadShader(vertPath, GL_VERTEX_SHADER);
		std::cout << "loading fragment shader..." << std::endl;
		GLuint fragmentID = loadShader(fragPath, GL_FRAGMENT_SHADER);
		glAttachShader(shaderID, vertexID);
		glAttachShader(shaderID, fragmentID);

		glBindAttribLocation(shaderID, 0, "position");
		glBindAttribLocation(shaderID, 1, "uv");
		glBindAttribLocation(shaderID, 2, "normal");

		glLinkProgram(shaderID);
		glValidateProgram(shaderID);

		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);

	}

	Shader::~Shader() {
		glDeleteProgram(shaderID);
	}

	GLuint Shader::loadShader(const char* filename, GLenum type) {
		GLuint newShader = glCreateShader(type);

		std::FILE *fp = std::fopen(filename, "rb");
		std::string fileContents;
		if (fp)
		{
			std::fseek(fp, 0, SEEK_END);
			fileContents.resize(std::ftell(fp));
			std::rewind(fp);
			std::fread(&fileContents[0], 1, fileContents.size(), fp);
			std::fclose(fp);
		}
		const char* shaderSource = fileContents.c_str();
		
		glShaderSource(newShader, 1, &shaderSource, NULL);
		glCompileShader(newShader);

		GLint result;
		glGetShaderiv(newShader, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE) {
			GLint length;
			glGetShaderiv(newShader, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(newShader, length, &length, &error[0]);
			std::cout << "Shader type: "<< type << " failed to compile" << std::endl << &error[0] << std::endl;
			glDeleteShader(newShader);
			return 0;
		}

		return newShader;

	}

	GLint Shader::getUniformLocation(const GLchar* name) const{
		return glGetUniformLocation(shaderID, name);
	}

	void Shader::loadBool(const GLchar* name, int value) const{
		int load = 0;
		if (value) {
			load = 1;
		}
		glUniform1i(getUniformLocation(name), load);

	}

	void Shader::loadFloat(const GLchar* name, GLfloat value) const{
		glUniform1f(getUniformLocation(name), value);
		
	}
	void Shader::loadVector3(const GLchar* name, vec3 vector) const{
		glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
	}

	void Shader::loadMatrix(const GLchar* name, mat4 matrix) const{
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elems);
	}

	void Shader::loadLight(Light light) const{
		loadVector3("light_position", light.getPosition());
		loadVector3("light_color", light.getColor());
	}

	void Shader::enable() const {
		glUseProgram(shaderID);
	}
	void Shader::disable() const {
		glUseProgram(0);
	}

}