#include "Wall.h"

Wall::Wall(int new_x, int new_y) {
	x = new_x;
	y = new_y;
}

int Wall::GetX() const {
	return x;
}

int Wall::GetY() const {
	return y;
}