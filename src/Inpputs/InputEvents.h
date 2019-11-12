#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <constants.h>
#include <functional>
#include <iostream>
#include <map>
#include "../src/Camera/Camera.h"
using namespace std;

map<int, function<void(map<int, bool>*)>> setupKeyActions(Camera* camera, double *deltaTime) {
	return {
		{ GLFW_KEY_W, [=](map<int, bool>* keysState) -> void { camera->processKeyboard(CameraMovement::FORWARD, *deltaTime); } },
		{ GLFW_KEY_A, [=](map<int, bool>* keysState) -> void { camera->processKeyboard(CameraMovement::LEFT, *deltaTime); } },
		{ GLFW_KEY_S, [=](map<int, bool>* keysState) -> void { camera->processKeyboard(CameraMovement::BACKWARD, *deltaTime); } },
		{ GLFW_KEY_D, [=](map<int, bool>* keysState) -> void { camera->processKeyboard(CameraMovement::RIGHT, *deltaTime); } },
	};
};

map<int, function<void(double, double, bool)>> setupMouseDragActions(Camera* camera) {
	return {
		{ constants::DRAG, [=](double xpos, double ypos, bool mousePressed) -> void {
		    if (mousePressed) {
		        camera->processMouseMovement(xpos, ypos);
		        camera->mousePressed = true;
            } else {
		        camera->mousePressed = false;
		    }}
		},
	};
};

map<int, function<void(double)>> setupMouseScrollActions(Camera* camera) {
	return {
		{ constants::SCROLL, [=](double yoffset) -> void { camera->processMouseScroll(yoffset); } },
	};
};