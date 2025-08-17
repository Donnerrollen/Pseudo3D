#pragma once
#include <vector>
#include <memory>
#include "Wall.h"
#include "Player.h"
class Map {
private:
	std::vector<std::unique_ptr<Wall>> walls;
	//std::vector<std::unique_ptr<Enemy>> enemies;
	std::unique_ptr<Player> player;
public:
	void setPlayerPosition(float x, float y);
	void addWall(int x, int y);
	void addEnemy(float x, float y);
	const Player& getPlayer() const;
	std::vector<std::unique_ptr<Wall>>& getWalls() const;
	//std::vector<std::unique_ptr<Enemy>>& getEnemies() const;
	//void removeEnemy(Enemy* enemy);

};