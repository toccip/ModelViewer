#pragma once
#include "../linearalgebra.h"

namespace quetzal {

	class Light {

	private:
		vec3 position;
		vec3 color;
	public:
		Light() {
			position = vec3(0.0f, 0.0f, 0.0f);
			color = vec3(0.0f, 0.0f, 0.0f);
		}
		Light(vec3 a_position, vec3 a_color) {
			position = a_position;
			color = a_color;
		}
		inline vec3 getPosition() { return position; }
		inline vec3 getColor() { return color; }
		inline void setPosition(vec3 a_position) { position = a_position; }
		inline void setColor(vec3 a_color) { color = a_color; }
	};

}