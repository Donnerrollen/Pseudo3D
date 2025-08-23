#pragma once
#include <Map.h>
#include <RayCasting.h>
#include "IRender.h"
#include "config.h"

class Game {
public:
	Map map;
	RayCasting raycaster;
	std::unique_ptr<ICollision> collisionSystem;
	std::unique_ptr<IRender> renderSystem;

	Game();
	~Game();
	Game(int w, int h);
	Game(int w, int h, float field);
	void update();
	void setCollisionSystem(std::unique_ptr<ICollision> new_collisionSystem);
	void setRenderSystem(std::unique_ptr<IRender> new_renderSystem);

};