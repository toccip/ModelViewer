#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

namespace quetzal {

		//vec2
#pragma pack(push, 1)
		struct vec2 {
			float x; 
			float y;

			inline vec2() {
				x = 0.0f; y = 0.0f;
			}
			inline vec2(float a_x, float a_y) {
				x = a_x; y = a_y;
			}

			inline friend std::ostream& operator<<(std::ostream& stream, const vec2& vector) {
				return stream << "(" << vector.x << ", " << vector.y << ")";
			}

			inline friend bool operator==(const vec2& left, const vec2& right) {
				return ((left.x == right.x) && (left.y == right.y));
			}

			inline friend vec2 operator+(const vec2& left, const vec2& right) {
				return vec2(left.x + right.x, left.y + right.y);
			}
			inline friend void operator+=(vec2& left, const vec2& right) {
				left.x += right.x;
				left.y += right.y;
			}

			inline friend vec2 operator-(const vec2& left, const vec2& right) {
				return vec2(left.x - right.x, left.y - right.y);
			}
			inline friend void operator-=(vec2& left, const vec2& right) {
				left.x -= right.x;
				left.y -= right.y;
			}

			inline friend vec2 operator*(const vec2& left, const vec2& right) {
				return vec2(left.x * right.x, left.y * right.y);
			}
			inline friend void operator*=(vec2& left, const vec2& right) {
				left.x *= right.x;
				left.y *= right.y;
			}

			inline friend vec2 operator/(const vec2& left, const vec2& right) {
				return vec2(left.x / right.x, left.y / right.y);
			}
			inline friend void operator/=(vec2& left, const vec2& right) {
				left.x /= right.x;
				left.y /= right.y;
			}

		};
#pragma pack(pop)
		/////////////////////////////////////////////////////////////////////
		//vec3
#pragma pack(push, 1)
		struct vec3 {
			float x, y, z;

			inline vec3() {
				x = 0.0f; y = 0.0f; z = 0.0f;
			}
			inline vec3(float a_x, float a_y, float a_z) {
				x = a_x; y = a_y; z = a_z;
			}

			inline friend std::ostream& operator<<(std::ostream& stream, const vec3& vector) {
				return stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			}

			inline friend bool operator==(const vec3& left, const vec3& right) {
				return ((left.x == right.x) && (left.y == right.y) && (left.z == right.z));
			}

			inline friend vec3 operator+(const vec3& left, const vec3& right) {
				return vec3(left.x + right.x, left.y + right.y, left.z + right.z);
			}
			inline friend void operator+=(vec3& left, const vec3& right) {
				left.x += right.x;
				left.y += right.y;
				left.z += right.z;
			}

			inline friend vec3 operator-(const vec3& left, const vec3& right) {
				return vec3(left.x - right.x, left.y - right.y, left.z - right.z);
			}
			inline friend void operator-=(vec3& left, const vec3& right) {
				left.x -= right.x;
				left.y -= right.y;
				left.z -= right.z;
			}

			inline friend vec3 operator*(const vec3& left, const vec3& right) {
				return vec3(left.x * right.x, left.y * right.y, left.z * right.z);
			}
			inline friend void operator*=(vec3& left, const vec3& right) {
				left.x *= right.x;
				left.y *= right.y;
				left.z *= right.z;
			}

			inline friend vec3 operator/(const vec3& left, const vec3& right) {
				return vec3(left.x / right.x, left.y / right.y, left.z / right.z);
			}
			inline friend void operator/=(vec3& left, const vec3& right) {
				left.x /= right.x;
				left.y /= right.y;
				left.z /= right.z;
			}

		};
#pragma pack(pop)
		/////////////////////////////////////////////////////////////////////
		//vec4
#pragma pack(push, 1)
		struct vec4 {
			float x, y, z, w;

			inline vec4() {
				x = 0.0f; y = 0.0f; z = 0.0f; w = 0.0f;
			}
			inline vec4(float a_x, float a_y, float a_z, float a_w) {
				x = a_x; y = a_y; z = a_z; w = a_w;
			}

			inline friend std::ostream& operator<<(std::ostream& stream, const vec4& vector) {
				return stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
			}

			inline friend vec4 operator+(const vec4& left, const vec4& right) {
				return vec4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
			}
			inline friend void operator+=(vec4& left, const vec4& right) {
				left.x += right.x;
				left.y += right.y;
				left.z += right.z;
				left.w += right.w;
			}

			inline friend vec4 operator-(const vec4& left, const vec4& right) {
				return vec4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
			}
			inline friend void operator-=(vec4& left, const vec4& right) {
				left.x -= right.x;
				left.y -= right.y;
				left.z -= right.z;
				left.w -= right.w;
			}

			inline friend vec4 operator*(const vec4& left, const vec4& right) {
				return vec4(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w);
			}
			inline friend void operator*=(vec4& left, const vec4& right) {
				left.x *= right.x;
				left.y *= right.y;
				left.z *= right.z;
				left.w *= right.w;
			}

			inline friend vec4 operator/(const vec4& left, const vec4& right) {
				return vec4(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w);
			}
			inline friend void operator/=(vec4& left, const vec4& right) {
				left.x /= right.x;
				left.y /= right.y;
				left.z /= right.z;
				left.w /= right.w;
			}

		};
#pragma pack(pop)
		/////////////////////////////////////////////////////////////////////
		//matrix stuff
		struct mat4 {
			union {
				float elems[4 * 4];
				vec4 columns[4];
			};

			inline mat4() {
				for (int i = 0; i < 4 * 4; i++) {
					elems[i] = 0.0f;
				}
			}
			inline mat4(float d) {
				for (int i = 0; i < 4 * 4; i++) {
					elems[i] = 0.0f;
				}
				elems[0 + 0 * 4] = d;
				elems[1 + 1 * 4] = d;
				elems[2 + 2 * 4] = d;
				elems[3 + 3 * 4] = d;
			}


			inline friend mat4 operator*(const mat4& left, const mat4& right) {
				mat4 result;
				for (int col = 0; col < 4; col++) {
					for (int row = 0; row < 4; row++) {
						float sum = 0.0f;
						for (int e = 0; e < 4; e++) {
							sum += left.elems[row + e * 4] * right.elems[e + col * 4];
						}
						result.elems[row + col * 4] = sum;
					}
				}
				return result;
			}
			inline friend void operator*=(mat4& left, const mat4& right) {
				left = left * right;
			}


			inline static mat4 createTranslationMatrix(const vec3& translation) {
				mat4 result(1.0f);
				result.elems[0 + 3 * 4] = translation.x;
				result.elems[1 + 3 * 4] = translation.y;
				result.elems[2 + 3 * 4] = translation.z;

				return result;
			}

			inline static mat4 createRotationMatrix(float angle, vec3 axis) {
				mat4 result(1.0f);

				float rads = toRadians(angle);
				float c = (float)cos(rads);
				float c1 = 1.0f - c;
				float s = (float)sin(rads);
				float x = axis.x;
				float y = axis.y;
				float z = axis.z;

				result.elems[0 + 0 * 4] = x * x * c1 + c;
				result.elems[1 + 0 * 4] = x * y * c1 + z * s;
				result.elems[2 + 0 * 4] = x * z * c1 - y * s;
				result.elems[0 + 1 * 4] = x * y * c1 - z * s;
				result.elems[1 + 1 * 4] = y * y * c1 + c;
				result.elems[2 + 1 * 4] = y * z * c1 + x * s;
				result.elems[0 + 2 * 4] = x * z * c1 + y * s;
				result.elems[1 + 2 * 4] = y * z * c1 - x * s;
				result.elems[2 + 2 * 4] = z * z * c1 + c;

				return result;
			}

			inline static mat4 createScaleMatrix(const vec3& scale) {
				mat4 result(1.0f);
				result.elems[0 + 0 * 4] = scale.x;
				result.elems[1 + 1 * 4] = scale.y;
				result.elems[2 + 2 * 4] = scale.z;

				return result;
			}

			inline static mat4 createTransformMatrix(vec3 translation, vec3 rotation, vec3 scale) {
				mat4 result(1.0f);
				mat4 operand;

				//translate
				operand = createTranslationMatrix(translation);
				result *= operand;

				//rotate
				operand = createRotationMatrix(rotation.x, vec3(1.0f, 0.0f, 0.0f));
				result *= operand;

				operand = createRotationMatrix(rotation.y, vec3(0.0f, 1.0f, 0.0f));
				result *= operand;

				operand = createRotationMatrix(rotation.z, vec3(0.0f, 0.0f, 1.0f));
				result *= operand;

				//scale
				operand = createScaleMatrix(scale);
				result *= operand;

				return result;

			}

			inline static mat4 createProjectionMatrix(float fov, float ar, float near1, float far1) {
				mat4 result;

				float q = 1.0f / tan(toRadians(0.5f * fov));

				result.elems[0 + 0 * 4] = q / ar;
				result.elems[1 + 1 * 4] = q;
				result.elems[2 + 2 * 4] = (far1 + near1) / (near1 - far1);
				result.elems[3 + 2 * 4] = -1.0f;
				result.elems[2 + 3 * 4] = (2.0f * far1 * near1) / (near1 - far1);

				return result;
			}

			inline static mat4 createViewMatrix(vec3 position, vec3 rotation) {
				mat4 result(1.0f);
				mat4 operand;
				//rotate
				operand = createRotationMatrix(rotation.x, vec3(1, 0, 0));
				result *= operand;

				operand = createRotationMatrix(rotation.y, vec3(0, 1, 0));
				result *= operand;

				operand = createRotationMatrix(rotation.z, vec3(0, 0, 1));
				result *= operand;

				//translate
				operand = createTranslationMatrix(position * vec3(-1.0f, -1.0f, -1.0f));
				result *= operand;

				return result;
			}

			inline static float toRadians(float degrees) {
				return degrees * (float)(M_PI / 180.0f);
			}

		};

		///////////////////

		/*
		mat4x4 mat4x4::orthographic(float left, float right, float bot, float top, float near, float far) {
		mat4x4 result(1.0f);
		result.elems[0 + 0 * 4] = 2.0f / (right - left);
		result.elems[1 + 1 * 4] = 2.0f / (top - bot);
		result.elems[2 + 2 * 4] = 2.0f / (near - far);

		result.elems[0 + 3 * 4] = (right + left) / (left - right);
		result.elems[1 + 3 * 4] = (top + bot) / (bot - top);
		result.elems[2 + 3 * 4] = (far + near) / (near - far);

		return result;
		}
		

		

		*/

}
