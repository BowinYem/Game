#pragma once

class InputComponent
{
public:
	~InputComponent();
	
	virtual void Update() = 0;
};