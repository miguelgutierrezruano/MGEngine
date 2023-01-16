
#include <Window.hpp>
#include <scene.h>
#include <BallController.h>
#include <PaddleController.h>
#include <MovementListener.h>

using namespace MGEngine;

int main()
{
	// Create window
	Window window("MGDemo", 1280, 720);
	window.enable_vsync();

	// Create scene
	scene first_scene(window);
	first_scene.load_pong_scene();

	// Add for entities in scene their listener
	std::string moveleft = "MoveLeft";
	first_scene.add_input_event_mapping(Keyboard::KEY_A, moveleft);

	std::string moveRight = "MoveRight";
	first_scene.add_input_event_mapping(Keyboard::KEY_D, moveRight);

	std::shared_ptr < MovementListener > movListener = std::make_shared<MovementListener>();

	std::string firstName = "PlayerPaddle";

	auto targetEntity = first_scene.get_entity(firstName);
	movListener.get()->set_owner(targetEntity);

	first_scene.get_entity(firstName)->add_listener("MoveLeft", movListener);
	first_scene.get_entity(firstName)->add_listener("MoveRight", movListener);

	std::string ballName   = "Ball";
	std::string paddleName = "Paddle";

	// Add controller for ball
	std::shared_ptr < BallController > ballController = std::make_shared<BallController>(
														first_scene.get_entity(firstName),
														first_scene.get_entity(paddleName));

	first_scene.get_entity(ballName)->add_controller(ballController);

	// Add controller for enemy paddle
	std::shared_ptr < PaddleController > paddleController = std::make_shared<PaddleController>(first_scene.get_entity(ballName));

	first_scene.get_entity(paddleName)->add_controller(paddleController);

	// Engine main loop
	first_scene.run();

	return 0;
}