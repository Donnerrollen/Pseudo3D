#pragma once 
#include "InputState.h"

class IInputHandler {
public: 
	~IInputHandler() = default;
	virtual const InputState& getInputState() const;
};