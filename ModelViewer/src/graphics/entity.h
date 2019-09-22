#pragma once
#include "model.h"
#include "texture.h"
#include "shader.h"

namespace quetzal {
	class Entity {
	private:
		const Model* model;
		const Texture* texture;
		const Shader* shader;

		vec3 position, rotation, scale;
		mat4 transformationMatrix;
		float shineDamper;
		float reflectivity;
	public:
		Entity(const Model* a_model, const Texture* a_texture, const Shader* a_shader, 
			const vec3& a_position, const vec3& a_rotation, const vec3& a_scale);

		void bind() const;
		void unbind() const;

		inline const Shader* getShader() const { return shader; }
		inline const Model* getModel() const { return model; }
		inline const vec3& getPosition() const { return position; }
		inline const vec3& getRotation() const { return rotation; }
		inline const vec3& getScale() const { return scale; }
		inline const mat4& getTransformationMatrix() const { return transformationMatrix; }
		inline const float& getShineDamper() const { return shineDamper; }
		inline const float& getReflectivity() const { return reflectivity; }

		void setPosition(const vec3& a_position);
		void changePosition(const vec3& a_position);
		void setRotation(const vec3& a_rotation);
		void changeRotation(const vec3& a_rotation);
		void setScale(const vec3& a_scale);
		void changeScale(const vec3& a_scale);
		inline void setShineDamper(const float& a_shineDamper) { shineDamper = a_shineDamper; }
		inline void setReflectivity(const float& a_reflectivity) { reflectivity = a_reflectivity; }
	};
}