#include "Player.h"
#include <iostream>
#define M_PI 3.14159265358979323846f

Player::Player(int new_hp, float new_x, float new_y, float new_speed, float new_angle) : Entity(new_hp, new_x, new_y, new_speed, new_angle) {}

void Player::update(const ICollision& collisionsystem, const Map& map) {
	InputState comands;
	(*inputHandler).setInputState();

	comands = (*inputHandler).getInputState();

	if (comands.getMove() != 0) {
		float dist = collisionsystem.DistToCollision(map, (comands.getMove() == 1) ? true : false) - 0.05;
		dist = std::min(dist, speed);
		if (dist >= 0.05) {
			float dx, dy;
			dx = ((comands.getMove() == 1) ? 1 : -1) * cos(angle * M_PI / 180.0f) * dist;
			dy = ((comands.getMove() == 1) ? 1 : -1) * sin(angle * M_PI / 180.0f) * dist;
			move(dx, -dy);
		}
	}
	if (comands.getTurn() != 0) {
		Turn(speedTurn * ((comands.getTurn() == 1) ? -1 : 1));
	}
}

void Player::setInputHanler(std::unique_ptr<IInputHandler> new_inputHandler) const {
	inputHandler = std::move(new_inputHandler);
	return;
}