#pragma once
#include <Map.h>
#include <RayCasting.h>
#include "config.h"

class Game {
public: 
	Game();
	~Game();
	Game(int w, int h);
	Game(int w, int h, float field);
	Map map;
	RayCasting raycaster;
	std::unique_ptr<ICollision> collisionSystem;
};