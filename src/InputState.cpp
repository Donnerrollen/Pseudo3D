#include "InputState.h"

InputState::InputState() {
	move = 0;
	turn = 0;
	isFiring = false;
}

InputState& InputState::operator=(const InputState& a) {
	this->move = a.move;
	this->turn = a.turn;
	this->isFiring = a.isFiring;
	return *this;
}

int InputState::getMove() const {
	return move;
}

int InputState::getTurn() const {
	return turn;
}

bool InputState::getFiring() const {
	return isFiring;
}