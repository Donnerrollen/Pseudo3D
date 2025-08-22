#include "DDACollision.h"
#include <iostream>
#include "Map.h"
#define M_PI 3.14159265358979323846f

float DDACollision::DistToCollision(const Map& map, bool straight) const{
	bool collision = false;
	int stepY = 1;
	int stepX = -1;

	float dx = cos(map.getPlayer().GetAngle() * M_PI / 180.0f);
	float dy = sin(map.getPlayer().GetAngle() * M_PI / 180.0f);

	if (straight == false) {
		dx *= -1;
		dy *= -1;
	}

	float start_x = map.getPlayer().GetX();
	float start_y = map.getPlayer().GetY();
	
	const auto& grid = map.getGrid();

	if (dx > 0) stepX = 1;
	if (dy > 0) stepY = -1;
	int MapX = std::floor(start_x);
	int MapY = std::floor(start_y);
	float sideDistX = 0;
	float sideDistY = 0;
	float deltaDistX = (dx == 0) ? 1e30 : std::abs(1 / dx);
	float deltaDistY = (dy == 0) ? 1e30 : std::abs(1 / dy);
	int step = 0;
	float hitY = 0;
	float hitX = 0;

	if (stepX < 0) {
		sideDistX = (start_x - MapX) * deltaDistX;
	}
	else {
		sideDistX = (MapX + 1 - start_x) * deltaDistX;
	}
	if (stepY < 0) {
		sideDistY = (start_y - MapY) * deltaDistY;
	}
	else {
		sideDistY = (MapY + 1 - start_y) * deltaDistY;
	}

	while (!collision) {
		if (sideDistX < sideDistY) {
			sideDistX += deltaDistX;
			MapX += stepX;
			step = 0; //—толкновение с вертикальной пр€мой
		}
		else {
			sideDistY += deltaDistY;
			MapY += stepY;
			step = 1; //—толкновение с горизонтальной пр€мой
		}

		if (MapX < 0 || MapX >= grid[0].size() || MapY < 0 || MapY >= grid.size()) {
			return 1000.0f;
		}

		if (grid[MapY][MapX] > 0) {
			collision = true;
			if (step == 0) {
				hitX = MapX + (stepX == -1 ? 1 : 0);
				hitY = start_y + (sideDistX - deltaDistX) * dy;
			}
			else {
				hitX = start_x + (sideDistY - deltaDistY) * dx;
				hitY = MapY + (stepY == -1 ? 1 : 0);
			}
		}
	}

	return std::sqrt((hitX - start_x) * (hitX - start_x) + (hitY - start_y) * (hitY - start_y));
}

/*
void DDACollision::FireCollision(const Map& map) {

}
*/