#include "SFMLKeyboard.h"
#include "SFML\Window\Keyboard.hpp"

const InputState& SFMLKeyboard::getInputState() const {
	return state;
};

void SFMLKeyboard::setInputState() {
	state.isFiring = false;
	state.move = 0;
	state.turn = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		state.turn -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		state.move += 1;
	} 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		state.move -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		state.turn += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		state.isFiring = true;
	}
	return;
};