#pragma once 
class InputState {
public:
	int move; //1 - вперед, -1 - назад, 0 - на месте
	int turn; //1 - вправо, -1 - влево, 0 - нет поворота
	bool isFiring;

	int getMove() const;
	int getTurn() const;
	bool getFiring() const;
};