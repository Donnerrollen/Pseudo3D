#pragma once 
#include "IInputHandler.h"

class SFMLKeyboard : public IInputHandler {
private:
	InputState state;
public:
	const InputState& getInputState() const override;
	void setInputState();
};