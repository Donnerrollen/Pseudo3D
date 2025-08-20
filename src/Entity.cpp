#include "Entity.h"
#define M_PI 3.14159265358979323846

Entity::Entity(int new_hp, float new_x, float new_y, float new_speed, float new_angle) {
	hp = new_hp;
	x = new_x;
	y = new_y;
	speed = new_speed;
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
}

float Entity::CalculateDX() {
	return speed * cos(angle * M_PI / 180.0);
}

float Entity::CalculateDY() {
	return speed * sin(angle * M_PI / 180.0);
}

//TODO
void Entity::move(float dx, float dy) {
	return;
}

void Entity::fire() {
	return;
}