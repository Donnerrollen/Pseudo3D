#include <RayCasting.h>
#define M_PI 3.14159265358979323846f

const int count_rays = 320;

RayCasting::RayCasting() {
	FieldOfView = 120.0f;
}

RayCasting::RayCasting(float field) {
	FieldOfView = field;
	return;
}

float castRay(float start_x, float start_y, float dx, float dy, const std::vector<std::vector<int>>& grid) {
	bool collision = false;
	int stepY = 1;
	int stepX = -1;
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

std::vector<float> RayCasting::castsRays(const Map& map) {
	const Player player = map.getPlayer();
	const auto& grid = map.getGrid();
	float dx = 0;
	float dy = 0;
	float current_angle;
	float player_x = player.GetX();
	float player_y = player.GetY();
	float ray_length = 0;
	std::vector<float> rays_length_arr;

	float start_angle = (player.GetAngle() + FieldOfView / 2) * M_PI / 180.0f;
	float unit_angle_rad = (FieldOfView * M_PI) / (180.0f * count_rays);
	for (int i = 0; i < count_rays; i++) {
		current_angle = start_angle - (unit_angle_rad * i);
		dx = cos(current_angle);
		dy = sin(current_angle);
		ray_length = castRay(player_x, player_y, dx, dy, grid);
		rays_length_arr.push_back(ray_length);
	}
	return rays_length_arr;
}