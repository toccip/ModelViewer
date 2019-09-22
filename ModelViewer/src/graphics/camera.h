#pragma once
#include "../linearalgebra.h"

namespace quetzal {

	class Camera {

	private:
		vec3 position;
		vec3 rotation;
	public:
		Camera() {
			position = vec3(0.0f, 0.0f, 0.0f);
			rotation = vec3(0.0f, 0.0f, 0.0f);
		}
		Camera(vec3 a_position, vec3 a_rotation) {
			position = a_position;
			rotation = a_rotation;
		}
		inline vec3 getPosition() const { return position; }
		inline vec3 getRotation() const { return rotation; }
		inline void setPosition(vec3 newPos) { position = newPos; }
		inline void setRotation(vec3 newRot) { rotation = newRot; }
		inline void changePosition(vec3 changePos) { position += changePos; }
		inline void changeRotation(vec3 changeRot) { rotation += changeRot; }
	};

}