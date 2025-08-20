#include <RayCasting.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif
const int count_rays = 320;
const float step = 0.1f;

RayCasting::RayCasting(float field) {
	FieldOfView = field;
	return;
}

float castRay(float start_x, float start_y, float dx, float dy, const std::vector<std::unique_ptr<Wall>>& walls) {
	bool collision = false;
	while (!collision) {
		start_x += dx;
		start_y += dy;
		for ()
	}
}

std::vector<float> RayCasting::castsRays(const Map& map) {
	const Player player = map.getPlayer();
	const auto& walls = map.getWalls();
	float dx = 0;
	float dy = 0;
	float player_x = player.GetX();
	float player_y = player.GetY();
	float ray_length = 0;
	std::vector<float> rays_length_arr;

	float start_angle = player.GetAngle() + (FieldOfView / 2) * M_PI / 180.0f;
	float unit_angle_rad = (FieldOfView * M_PI) / (180.0f * count_rays);
	for (int i = 0; i < count_rays; i++) {
		float current_angle = start_angle - (unit_angle_rad * i);
		dx = step * cos(current_angle);
		dy = step * sin(current_angle);
		ray_length = castRay(player_x, player_y, dx, dy, walls);
		rays_length_arr.push_back(ray_length);
	}
	return rays_length_arr;
}