
#include <Window.hpp>
#include <scene.h>
#include <BallController.h>
#include <PaddleController.h>
#include <MovementListener.h>
#include <BallListener.h>
#include <filesystem>

using namespace MGEngine;

void add_pong_logic(scene & pong_scene)
{
	// Add for entities in scene their listener
	std::string moveUp = "MoveUp";
	pong_scene.add_input_event_mapping(Keyboard::KEY_W, moveUp);

	std::string moveDown = "MoveDown";
	pong_scene.add_input_event_mapping(Keyboard::KEY_S, moveDown);

	std::shared_ptr < MovementListener > movListener = std::make_shared<MovementListener>();

	std::string firstName = "PlayerPaddle";

	auto targetEntity = pong_scene.get_entity(firstName);
	movListener.get()->set_owner(targetEntity);

	pong_scene.get_entity(firstName)->add_listener("MoveUp", movListener);
	pong_scene.get_entity(firstName)->add_listener("MoveDown", movListener);

	std::string ballName = "Ball";
	std::string paddleName = "Paddle";

	// Add controller for ball
	std::shared_ptr < BallController > ballController = std::make_shared<BallController>(
		pong_scene.get_entity(firstName),
		pong_scene.get_entity(paddleName));

	pong_scene.get_entity(ballName)->add_controller(ballController);

	// Add controller for enemy paddle
	std::shared_ptr < PaddleController > paddleController = std::make_shared<PaddleController>(pong_scene.get_entity(ballName));

	pong_scene.get_entity(paddleName)->add_controller(paddleController);

	// Add event to move ball
	std::string moveBall = "MoveBall";
	pong_scene.add_input_event_mapping(Keyboard::KEY_SPACE, moveBall);

	std::shared_ptr < BallListener > ballListener = std::make_shared<BallListener>();
	ballListener.get()->set_ball_controller(ballController.get());

	pong_scene.get_entity(ballName)->add_listener("MoveBall", ballListener);
}

int main()
{
	// Create window
	Window window("MGDemo", 1280, 720);
	window.enable_vsync();

	// Create scene
	scene pong_scene(window);

	pong_scene.load_scene("..\\binaries\\pong_scene.xml");

	add_pong_logic(pong_scene);

	// Engine main loop
	pong_scene.run();

	return 0;
}