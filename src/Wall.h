#pragma once
class Wall
{
private:
	int x, y;

public:
	Wall(int nex_x, int new_y);
	int GetX() const;
	int GetY() const;
};

