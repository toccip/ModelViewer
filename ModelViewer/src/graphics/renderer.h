#pragma once
#include <deque>
#include "entity.h"
#include "shader.h"
#include "camera.h"

#define WIDTH 1920
#define HEIGHT 1080
#define FOV 90.0f
#define NEAR_PLANE 0.1f
#define FAR_PLANE 10000.0f

namespace quetzal {

	class Renderer {
	private:
		std::deque<const Entity*> renderQueue;
		const Light* light;
		const Camera* camera;
	public:
		Renderer(Shader* shader);
		void prepare();
		void submit(const Light* light);
		void submit(const Camera* camera);
		void submit(const Entity* entity);
		void flush();
	};
}