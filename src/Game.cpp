#include <Game.h>

Game::Game() {
	map = Map(10, 10);
	raycaster = RayCasting(120);
}

Game::Game(int w, int h) {
	map = Map(w, h);
	raycaster = RayCasting(120);
}

Game::Game(int w, int h, float field) {
	map = Map(w, h);
	raycaster = RayCasting(field);
}