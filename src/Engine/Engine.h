#pragma once
#include "../Rrenderer/Renderer.h"
#include "../Inpputs/Keyboard/Keyboard.h"
#include "../Inpputs/Mouse/MousePosition.h"
#include "../Inpputs/Mouse/MouseScroll.h"

class Engine
{
public:
	//Engine();
	//~Engine();
	
	bool initialize();
	void shutDown();

	void run();

private:
	Renderer mRenderer;
	Keyboard* keyboard;
	MousePosition* mousePosition;
	MouseScroll* mouseScroll;
	bool mRunning = false;
	double deltaTime = 0.0f;		// Time between current frame and last frame
	double lastFrameTime = 0.0f;  	// Time of last frame
	double lastSec = 0.0;
	float frameCount = 0;

	map<int, function<void(map<int, bool>*)>> keyActions;

	static void processInput();
	void update();
	void generateOutput();
};
