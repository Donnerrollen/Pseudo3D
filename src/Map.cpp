#include "Map.h"

Map::Map() {
	gridHeight = 10;
	gridWidth = 10;
	grid = std::vector<std::vector<int>>(10);

	for (int i = 0; i < 10; i++) {
		grid[i] = std::vector<int>(10);
	}
}

Map::Map(int width, int height) {
	gridHeight = height;
	gridWidth = width;
	grid = std::vector<std::vector<int>>(height);

	for (int i = 0; i < height; i++) {
		grid[i] = std::vector<int>(width);
	}
}

void Map::setPlayerPosition(float x, float y, float angle) {
	if (checkAccessToAddObj(float(x), float(y))) {
		player = std::make_unique<Player>(Player(100, x, y, 0.2, angle));
	}
	return;
}

void Map::MakeFence() {
	for (int i = 0; i < gridHeight; i++) {
		for (int j = 0; j < gridWidth; j++) {
			if (i == 0 || i == gridHeight - 1 || j == 0 || j == gridWidth - 1) {
				addWall(j, i);
			}
		}
	}
}

void Map::addWall(int x, int y) {
	if (checkAccessToAddObj(float(x), float(y))) {
		grid[y][x] = 1;
	} 
	return;
}

void Map::deleteWall(int x, int y) {
	grid[y][x] = 0;
	return;
}

const int Map::getWidth() {
	return gridWidth;
}

const int Map::getHeight() {
	return gridHeight;
}

Player& Map::getPlayer() const {
	return *player;
}

const std::vector<std::vector<int>>& Map::getGrid() const {
	return grid;
}

bool Map::checkAccessToAddObj(float x, float y) const {
	if (grid[y][x] == 1) {
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
	if (grid[y][x] == 1) {
		return true;
	}
	return false;
}