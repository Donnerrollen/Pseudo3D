#pragma once 
#include "IInputHandler.h"
#include "InputState.h"

class SFMLKeyboard : public IInputHandler {
private:
	InputState state;
public:
	const InputState& getInputState() const;
	void setInputState();
};