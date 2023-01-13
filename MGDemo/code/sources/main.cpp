
#include <Window.hpp>
#include <iostream>
#include <scene.h>

using namespace MGEngine;

int main()
{
	// Create window
	Window window("MGDemo", 1280, 720);
	window.enable_vsync();

	// Create scene
	scene first_scene(window);
	first_scene.load_default_scene();

	// Engine main loop
	first_scene.run();

	return 0;
}