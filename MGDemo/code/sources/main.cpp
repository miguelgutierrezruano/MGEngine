
#include <Window.hpp>
#include <iostream>
#include <scene.h>
#include <MovementListener.h>

using namespace MGEngine;

int main()
{
	// Create window
	Window window("MGDemo", 1280, 720);
	window.enable_vsync();

	// Create scene
	scene first_scene(window);
	first_scene.load_default_scene();

	// Add for entities in scene their listener
	std::string moveleft = "MoveLeft";
	first_scene.add_input_event_mapping(Keyboard::KEY_A, moveleft);

	std::string moveRight = "MoveRight";
	first_scene.add_input_event_mapping(Keyboard::KEY_D, moveRight);

	std::shared_ptr < MovementListener > movListener = std::make_shared<MovementListener>();

	std::string firstName = "First";

	auto targetEntity = first_scene.get_entity(firstName);
	movListener.get()->set_owner(targetEntity);

	first_scene.get_entity(firstName)->add_listener("MoveLeft", movListener);
	first_scene.get_entity(firstName)->add_listener("MoveRight", movListener);

	// Engine main loop
	first_scene.run();

	return 0;
}