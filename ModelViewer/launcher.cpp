#include "src/Game.h"


typedef std::chrono::high_resolution_clock Clock;


int main(void) {
	using namespace quetzal;
	
	Game my_game;

	while (my_game.is_running()) {
		my_game.update();
	}

	return EXIT_SUCCESS;
}