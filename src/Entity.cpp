#include "Entity.h"
#include "config.h"
#define M_PI 3.14159265358979323846

Entity::Entity(int new_hp, float new_x, float new_y, float new_speed, float new_angle) {
	hp = new_hp;
	x = new_x;
	y = new_y;
	speed = new_speed;
	speedTurn = standartPlayerTurnSpeed;
	angle = new_angle;
}

Entity::Entity(int new_hp, float new_x, float new_y, float new_speed, float new_speedTurn, float new_angle) {
	hp = new_hp;
	x = new_x;
	y = new_y;
	speed = new_speed;
	speedTurn = new_speedTurn;
	angle = new_angle;
}

float Entity::GetX() const {
	return x;
}

float Entity::GetY() const {
	return y;
}

float Entity::GetAngle() const {
	return angle;
}

int Entity::GetHP() const {
	return hp;
}

void Entity::setHP(int new_hp) {
	hp = new_hp;
}

void Entity::setSpeed(float new_speed) {
	speed = new_speed;
}

void Entity::takeDamage(int damage) {
	hp -= damage;
}

void Entity::Turn(float dangle) {
	angle += dangle;
	while (angle < 0) {
		angle += 360;
	}
	while (angle > 360) {
		angle -= 360;
	}
}

float Entity::CalculateDX() {
	return speed * cos(angle * M_PI / 180.0);
}

float Entity::CalculateDY() {
	return speed * sin(angle * M_PI / 180.0);
}

void Entity::move(float dx, float dy) {
	x += dx;
	y += dy;
	return;
}

//TODO
void Entity::fire() {
	return;
}