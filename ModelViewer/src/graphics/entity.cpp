#include "entity.h"

namespace quetzal {

	Entity::Entity(const Model* a_model, const Texture* a_texture, const Shader* a_shader, 
		const vec3& a_position, const vec3& a_rotation, const vec3& a_scale)
		: model(a_model), texture(a_texture), shader(a_shader), position(a_position), rotation(a_rotation), scale(a_scale){
		transformationMatrix = mat4::createTransformMatrix(position, rotation, scale);
		shineDamper = 1.0f;
		reflectivity = 0.0f;
	}

	void Entity::bind() const {
		shader->enable();
		model->bind();
		texture->bind();
	}
	void Entity::unbind() const {
		texture->unbind();
		model->unbind();
		shader->disable();
	}

	void Entity::setPosition(const vec3& a_position) {
		position = a_position;
		transformationMatrix = mat4::createTransformMatrix(position, rotation, scale);
	}
	void Entity::changePosition(const vec3& a_position) {
		position += a_position;
		transformationMatrix = mat4::createTransformMatrix(position, rotation, scale);
	}
	void Entity::setRotation(const vec3& a_rotation) {
		rotation = a_rotation;
		transformationMatrix = mat4::createTransformMatrix(position, rotation, scale);
	}
	void Entity::changeRotation(const vec3& a_rotation) {
		rotation += a_rotation;
		if (rotation.x >= 360.0f) {
			rotation.x -= 360.0f;
		}
		else if (rotation.x <= -360.0f) {
			rotation.x += 360.0f;
		}

		if (rotation.y >= 360.0f) {
			rotation.y -= 360.0f;
		}
		else if (rotation.y <= -360.0f) {
			rotation.y += 360.0f;
		}

		if (rotation.z >= 360.0f) {
			rotation.z -= 360.0f;
		}
		else if (rotation.z <= -360.0f) {
			rotation.z += 360.0f;
		}
		transformationMatrix = mat4::createTransformMatrix(position, rotation, scale);
	}
	void Entity::setScale(const vec3& a_scale) {
		scale = a_scale;
		transformationMatrix = mat4::createTransformMatrix(position, rotation, scale);
	}
	void Entity::changeScale(const vec3& a_scale) {
		scale += a_scale;
		transformationMatrix = mat4::createTransformMatrix(position, rotation, scale);
	}

}