#include "renderer.h"

namespace quetzal {

	Renderer::Renderer(Shader* shader) {
		
		mat4 projectionMatrix = mat4::createProjectionMatrix(FOV, (float)WIDTH / (float)HEIGHT, NEAR_PLANE, FAR_PLANE);
		shader->enable();
		shader->loadMatrix("projectionMatrix", projectionMatrix);
		shader->disable();
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);

	}

	void Renderer::prepare() {
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.25f, 0.5f, 0.75f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::submit(const Light* a_light) {
		light = a_light;
	}
	void Renderer::submit(const Camera* a_camera) {
		camera = a_camera;
	}

	void Renderer::submit(const Entity* entity) {
		renderQueue.push_back(entity);
	}

	void Renderer::flush() {

		while (!renderQueue.empty()) {
			const Entity* entity = renderQueue.front();
			entity->bind();
			entity->getShader()->loadLight(*light);
			mat4 viewMatrix = mat4::createViewMatrix(camera->getPosition(), camera->getRotation());
			entity->getShader()->loadMatrix("viewMatrix", viewMatrix);
			entity->getShader()->loadMatrix("transformationMatrix", entity->getTransformationMatrix());
			entity->getShader()->loadFloat("shineDamper", entity->getShineDamper());
			entity->getShader()->loadFloat("reflectivity", entity->getReflectivity());
			glDrawElements(GL_TRIANGLES, entity->getModel()->getIBO()->getCount(), GL_UNSIGNED_INT, nullptr);
			entity->unbind();
			renderQueue.pop_front();
		}

	}
}