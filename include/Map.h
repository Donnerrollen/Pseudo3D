#pragma once

#include <memory>
#include "Player.h"
#include <vector>


class Map {
private:
	std::vector<std::vector<int>> grid;
	int gridWidth;
	int gridHeight;
	//std::vector<std::unique_ptr<Enemy>> enemies;
	std::unique_ptr<Player> player;

	bool checkAccessToAddObj(float x, float y) const;
public:
	Map();
	Map(int width, int height);
	bool isWall(int x, int y);
	void setPlayerPosition(float x, float y, float angle);
	void MakeFence();
	void addWall(int x, int y);
	void deleteWall(int x, int y);
	const int getWidth();
	const int getHeight();
//	void addEnemy(float x, float y);
	Player& getPlayer() const ;
	const std::vector<std::vector<int>>& getGrid() const;
//	std::vector<std::unique_ptr<Enemy>>& getEnemies() const;
//	void removeEnemy(Enemy* enemy);

};