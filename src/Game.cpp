#include <Game.h>
#include <iostream>

Game::Game() {
	map = Map(10, 10);
	raycaster = RayCasting(standartViewField);
}

Game::~Game() = default;

Game::Game(int w, int h) {
	map = Map(w, h);
	raycaster = RayCasting(standartViewField);
}

Game::Game(int w, int h, float field) {
	map = Map(w, h);
	raycaster = RayCasting(field);
}

void Game::setCollisionSystem(std::unique_ptr<ICollision> new_collisionSystem) {
	collisionSystem = std::move(new_collisionSystem);
}

void Game::setRenderSystem(std::unique_ptr<IRender> new_renderSystem) {
	renderSystem = std::move(new_renderSystem);
}

void Game::update() {
	while ((*renderSystem).windowIsOpen()) {
		map.getPlayer().update(*collisionSystem, map);
		(*renderSystem).processEvents();
		(*renderSystem).clean();
		(*renderSystem).render(map, raycaster.castsRays(map));
	}
	return;
}