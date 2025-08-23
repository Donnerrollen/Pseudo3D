#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include "Player.h"
#include <Map.h>
#include "Game.h"
#include <chrono>
#include "SFML/Window.hpp"
#include "SFMLKeyboard.h"
#include "DDACollision.h"
#include "SFMLRender.h"
#include "config.h"

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
	for (int i = 0; i < rayCount; i++) {
		std::cout << res[i] << "\n";
	}
	return;
}

void TestKeyboardSFML() {
	SFMLKeyboard hande;
	sf::Window window;
	window.create(sf::VideoMode({ screenWidth, screenHeight}), "My window");
	InputState res;

	while (window.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			break;
		}

		hande.setInputState();
		res = hande.getInputState();
		system("cls");
		std::cout << "Press escape to exit\n";
		std::cout << "move: " << res.getMove() << std::endl;
		std::cout << "turn: " << res.getTurn() << std::endl;
		std::cout << "firing: " << res.getFiring() << std::endl;
		std::cout << "_________" << std::endl;
	}
	return;
}

void TestMovePlayerInMap() {
	Game game;
	game.map.MakeFence();
	game.map.setPlayerPosition(4, 4, 0);
	game.map.getPlayer().setInputHandler(std::make_unique<SFMLKeyboard>());

	const auto& grid = game.map.getGrid();

	game.setCollisionSystem(std::make_unique<DDACollision>());

	sf::Window window;
	window.create(sf::VideoMode({ screenWidth, screenHeight }), "My window");
	
	while (window.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}

		game.update();
		system("cls");
		PrintGridMap(grid, game.map.getWidth(), game.map.getHeight(), game.map.getPlayer());
		std::cout << "_________\n";
		std::cout << "Press escape to exit\n";
		std::cout << "p_x: " << game.map.getPlayer().GetX() << std::endl;
		std::cout << "p_y: " << game.map.getPlayer().GetY() << std::endl;
		std::cout << "p_angle: " << game.map.getPlayer().GetAngle() << std::endl;
	}

	return;
}

void TestSFMLRenderCreateWindow() {
	std::string name = "TestSFMLRenderCreateWindow";
	Game game(10, 10);
	game.map.setPlayerPosition(4, 4, 0);

	game.setCollisionSystem(std::make_unique<DDACollision>());
	game.setRenderSystem(std::make_unique<SFMLRender>());
	game.map.MakeFence();

	game.map.getPlayer().setInputHandler(std::make_unique<SFMLKeyboard>());

	game.update();
}

int main() {
	//TestCreatePlayer();
	//TestCreateEntity();
	//TestTakeDamageEntity();
	//TestAddWallGrid();
	//TestRayCasts();
	//TestKeyboardSFML();
	//TestMovePlayerInMap();
	TestSFMLRenderCreateWindow();
	system("pause");
	return 0;
}