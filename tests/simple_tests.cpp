#include <iostream>
#include <memory>
#include <vector>
#include "Player.h"
#include <Map.h>

void TestPassed(std::string NameTest) {
	std::cout << "[PASSED] " << NameTest << std::endl;
	return;
}

void TestFailed(std::string NameTest) {
	std::cout << "[FAILED] " << NameTest << std::endl;
	return;
}

void TestCreateWall() {
	std::string name = "TestCreateWall";
	Wall wall(10, 11);
	if (wall.GetX() == 10 && wall.GetY() == 11) {
		TestPassed(name);
	}
	else {
		TestFailed(name);
	}
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

int main() {
	TestCreateWall();
	TestCreatePlayer();
	TestCreateEntity();
	TestTakeDamageEntity();
	std::cin.get();
}