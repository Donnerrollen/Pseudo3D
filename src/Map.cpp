#include "Map.h"

Map::Map(int width, int height) {
	gridHeight = height;
	gridWidth = width;
	std::vector<std::vector<int>> grid(width, std::vector<int>(height));

	for (int i = 0; i < width; i++) {
		for (int j; j < height; j++) {
			grid[i][j] = 0;
		}
	}
}

void Map::setPlayerPosition(float x, float y) {
	if (checkAccessToAddObj(float(x), float(y))) {
		std::unique_ptr<Player> player = std::make_unique<Player>(Player(100, x, y, 0.3, 0));
	}
	return;
}

void Map::addWall(int x, int y) {
	if (checkAccessToAddObj(float(x), float(y))) {
		grid[x][y] = 1;
	} 
	return;
}

void Map::deleteWall(int x, int y) {
	grid[x][y] = 0;
	return;
}

const Player& Map::getPlayer() const{
	return *player;
}

const std::vector<std::vector<int>>& Map::getGrid() const {
	return grid;
}

bool Map::checkAccessToAddObj(float x, float y) const {
	if (grid[x][y] == 1) {
		return false;
	}

	if (player != nullptr && std::floor(this->player->GetX()) == std::floor(x) && std::floor(this->player->GetY()) == std::floor(y)) {
		return false;
	}
	return true;
}

bool Map::isWall(int x, int y) {
	if (x >= gridWidth || y >= gridHeight || x < 0 || y < 0) {
		return true;
	} else
	if (grid[x][y] == 1) {
		return true;
	}
	return false;
}