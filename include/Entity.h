#pragma once
#include <cmath>
class Entity
{
protected:
	int hp;
	mutable float x, y;
	mutable  float angle;
	float speed;
	float speedTurn;

	float CalculateDX();
	float CalculateDY();
	void setSpeed(float new_speed);
	void setHP(int new_hp);
	void move(float dx, float dy);
	void fire();
	void Turn(float dangle);

public:
	Entity(int new_hp, float new_x, float new_y, float new_speed, float new_angle);
	Entity(int new_hp, float new_x, float new_y, float new_speed, float new_speedTurn, float new_angle);
	float GetX() const;
	float GetY() const;
	float GetAngle() const;
	int GetHP() const;
	void takeDamage(int damage);
};

