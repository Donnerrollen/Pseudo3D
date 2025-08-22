#pragma once 
#include "InputState.h"

class IInputHandler {
public: 
	virtual ~IInputHandler() = default;
	virtual void setInputState() = 0;
	virtual const InputState& getInputState() const = 0;
};