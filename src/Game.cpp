#include <iostream>
#include <chrono>
#include <Game.h>
#define NANOSECONDS_IN_SECOND 1000000000.0f

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
	std::chrono::steady_clock::time_point current;
	std::chrono::steady_clock::time_point previous;
	std::chrono::nanoseconds elapsed;
	float dir;
	
	while ((*renderSystem).windowIsOpen()) {
		current = std::chrono::steady_clock::now();
		elapsed = current - previous;
		dir = std::chrono::duration<float>(elapsed).count();
		map.getPlayer().update(*collisionSystem, map, dir);
		previous = current;

		(*renderSystem).processEvents();
		(*renderSystem).clean();
		(*renderSystem).render(map, raycaster.castsRays(map));
	}
	return;
}