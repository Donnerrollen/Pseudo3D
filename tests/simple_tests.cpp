#include <iostream>
#include <memory>
#include <vector>
#include "Player.h"
#include <Map.h>
#include "Game.h"

void PrintGridMap(const std::vector<std::vector<int>> grid, int width, int height, const Player& player) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (std::floor(player.GetX()) == j && std::floor(player.GetY()) == i) {
				std::cout << "T" << " ";
			} else std::cout << grid[i][j] << " ";
		} 
		std::cout << "\n";
	}
}

void TestPassed(std::string NameTest) {
	std::cout << "[PASSED] " << NameTest << std::endl;
	return;
}

void TestFailed(std::string NameTest) {
	std::cout << "[FAILED] " << NameTest << std::endl;
	return;
}

void TestCreatePlayer() {
	std::string name = "TestCreatePlayer";
	Player player(100, 10, 9, 0.3, 0);
	if (player.GetX() == 10 && player.GetY() == 9 && player.GetAngle() == 0) {
		TestPassed(name);
	}
	else {
		TestFailed(name);
	}
	return;
}

void TestCreateEntity() {
	std::string name = "TestCreateEntity";
	Entity entity(100, 10, 9, 0.3, 0);
	if (entity.GetX() == 10 && entity.GetY() == 9 && entity.GetAngle() == 0) {
		TestPassed(name);
	}
	else {
		TestFailed(name);
	}
	return;
}

void TestTakeDamageEntity() {
	std::string name = "TestTakeDamageEntity";
	Entity entity(100, 10, 9, 0.3, 0);
	entity.takeDamage(10);
	if (entity.GetHP() == 90) {
		TestPassed(name);
	}
	else {
		TestFailed(name);
	}
}

void TestAddWallGrid() {
	std::string name = "TestAddWallGrid";
	Map map(5, 10);
	auto& grid = map.getGrid();
	map.addWall(4, 9);
	map.addWall(0, 0);
	map.addWall(1, 1);
	if (grid[9][4] == 1 && grid[0][0] == 1 && grid[1][1] == 1) {
		TestPassed(name);
	}
	else {
		TestFailed(name);
	}
}

void TestRayCasts() {
	std::vector<float> res;
	std::string name = "TestRayCasts";
	Game game(5, 10);
	game.map.setPlayerPosition(3.99, 8.99, 270);
	game.map.MakeFence();
	const auto& grid = game.map.getGrid();
	PrintGridMap(grid, game.map.getWidth(), game.map.getHeight(), game.map.getPlayer());
	res = game.raycaster.castsRays(game.map);
	for (int i = 0; i < 320; i++) {
		std::cout << res[i] << "\n";
	}
	return;
}

int main() {
	TestCreatePlayer();
	TestCreateEntity();
	TestTakeDamageEntity();
	TestAddWallGrid();
	TestRayCasts();
	std::cin.get();
}