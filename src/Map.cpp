#include "Map.h"

void Map::setPlayerPosition(float x, float y) {
	if (checkAccessToAddObj(float(x), float(y))) {
		std::unique_ptr<Player> player = std::make_unique<Player>(Player(100, x, y, 0.3, 0));
	}
	return;
}

void Map::addWall(int x, int y) {
	if (checkAccessToAddObj(float(x), float(y))) {
		std::unique_ptr<Wall> new_wall = std::make_unique<Wall>(Wall(x, y));
		walls.push_back(std::move(new_wall));
	}
	return;
}

const Player& Map::getPlayer() const{
	return *player;
}

const std::vector<std::unique_ptr<Wall>>& Map::getWalls() const {
	return walls;
}

bool Map::checkAccessToAddObj(float x, float y) const {
	return true;
}