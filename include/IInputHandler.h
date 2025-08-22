#pragma once 
#include "InputState.h"

class IInputHandler {
public: 
	virtual ~IInputHandler() = default;
	virtual const InputState& getInputState() const = 0;
};