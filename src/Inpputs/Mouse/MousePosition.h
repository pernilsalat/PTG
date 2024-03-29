#pragma once
#include "../Base/KeyInput.h"


class MousePosition : public KeyInput {
public:
	using KeyInput::KeyInput;

	MousePosition(map<int, function<void(double, double, bool)>> keysToMonitor)
		: KeyInput(keysToMonitor, constants::inputTypes::InputType::MOUSE_DRAG) {};

	void setupKeyInputs(GLFWwindow* window) override {
		glfwSetCursorPosCallback(window, KeyInput::callbackMousePosition);
	}
};