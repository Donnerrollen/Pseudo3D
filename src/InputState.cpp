#include "InputState.h"

int InputState::getMove() const {
	return move;
}

int InputState::getTurn() const {
	return turn;
}

bool InputState::getFiring() const {
	return isFiring;
}