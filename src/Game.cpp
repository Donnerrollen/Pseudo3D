#include <Game.h>

Game::Game() {
	map = Map(10, 10);
	raycaster = RayCasting(120);
}

Game::~Game() = default;

Game::Game(int w, int h) {
	map = Map(w, h);
	raycaster = RayCasting(120);
}

Game::Game(int w, int h, float field) {
	map = Map(w, h);
	raycaster = RayCasting(field);
}

void Game::setCollisionSystem(std::unique_ptr<ICollision> new_collisionSystem) {
	collisionSystem = std::move(new_collisionSystem);
}

void Game::update() {
	map.getPlayer().update(*collisionSystem, map);
}