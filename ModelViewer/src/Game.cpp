#include "Game.h"

using namespace quetzal;


Game::Game()
{
	running = false;
	window = new Window("Model Viewer", WIDTH, HEIGHT);
	if (!window->init()) {
		return;
	}

	shader = new Shader("src/shaders/vertexShader.txt", "src/shaders/fragmentShader.txt");
	renderer = new Renderer(shader);

	camera = new Camera(vec3(0.0f, 5.0f, 12.0f), vec3(0.0f, 0.0f, 0.0f));
	light = new Light(vec3(0.0f, 1000.0f, 0.0f), vec3(1.0f, 1.0f, 1.0f));
	running = true;

	purple_texture = new Texture("src/assets/purple_square.bmp");
	player_model = new Model;
	player_model->loadModel("src/assets/dragon.obj");
	player_entity = new Entity(player_model, purple_texture, shader, vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec3(1.0f, 1.0f, 1.0f));
	player_entity->setShineDamper(10.0f);
	player_entity->setReflectivity(1.0f);
	time = std::chrono::high_resolution_clock::now();
}


Game::~Game()
{
	delete window;
	delete renderer;
	delete shader;
	delete light;
	delete player_entity;
	delete player_model;
	delete purple_texture;
	delete camera;
}

void Game::update() {
	auto new_time = std::chrono::high_resolution_clock::now();
	//stuff here
	float rot_amount = std::chrono::duration_cast<std::chrono::milliseconds>(new_time - time).count() / 1000.0;
	rot_amount *= deg_per_second;
	vec3 rot_vec(0.0f, rot_amount, 0.0f);
	player_entity->changeRotation(rot_vec);
	time = new_time;
	renderer->prepare();
	//add objects here
	renderer->submit(light);
	renderer->submit(camera);
	renderer->submit(player_entity);
	renderer->flush();

	window->update();
	if (window->should_close() || window->isKeyPressed(GLFW_KEY_ESCAPE)) {
		running = false;
	}

}


bool Game::is_running() const {
	return running;
}
