#pragma once
#include <cmath>
class Entity
{
protected:
	int hp;
	float x, y;
	float speed;
	float angle;

	float CalculateDX();
	float CalculateDY();
	void setSpeed(float new_speed);
	void setHP(int new_hp);
	void move(float dx, float dy);
	void fire();
	void Turn(float dangle);

public:
	Entity(int new_hp, float new_x, float new_y, float new_speed, float new_angle);
	float GetX() const;
	float GetY() const;
	float GetAngle() const;
	void takeDamage(int damage);
};

