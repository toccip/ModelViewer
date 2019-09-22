#pragma once
#include "graphics/window.h"
#include "graphics/renderer.h"
#include "graphics/camera.h"

class Game
{
private:
	quetzal::Window* window;
	quetzal::Shader* shader;
	quetzal::Renderer* renderer;
	quetzal::Camera* camera;
	quetzal::Light* light;
	quetzal::Texture* purple_texture;
	quetzal::Model* player_model;
	quetzal::Entity* player_entity;

	std::chrono::high_resolution_clock::time_point time;

	bool running;
	int deg_per_second = 90;
public:
	Game();
	~Game();

	void update();

	bool is_running() const;
};

