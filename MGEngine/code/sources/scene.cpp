
#include <scene.h>

namespace MGEngine
{
	scene::scene(Window& given_window)
	{
		window = &given_window;

		// Create systems. TODO: Use memorypools
		input_sys = new input_system(this);
		render_sys = new render_system(this);

		update_t = new update_task(&ev_dispatcher);

		// Add default systems tasks
		s_kernel.add_task(input_sys->get_task());
		s_kernel.add_task(render_sys->get_task());
		s_kernel.add_task(update_t);

		window->enable_vsync();
		s_kernel.set_fps(144);
	}

	void scene::load_pong_scene()
	{
		// Create player entity
		std::string player_name = "PlayerPaddle";
		auto player_entity = make_shared< entity >(player_name, this);

		// Add render component
		auto render_comp = render_sys->create_component(player_name);
		player_entity.get()->add_component("RenderComp", render_comp);

		// Save entity
		entities[player_name] = player_entity;

		player_entity.get()->get_transform()->set_position(vec3(-30.f, 0, 0));
		player_entity.get()->get_transform()->set_rotation(vec3(0, 0, 0));
		player_entity.get()->get_transform()->set_scale(vec3(1, 7, 0.1f));

		// Create first entity
		std::string ball_name = "Ball";
		auto ball = make_shared< entity >(ball_name, this);

		// Add render component
		auto render_comp_ball = render_sys->create_component(ball_name);
		ball.get()->add_component("RenderComp", render_comp_ball);

		// Save entity
		entities[ball_name] = ball;

		ball.get()->get_transform()->set_scale(vec3(1.3f, 1.3f, 0.1f));

		// Create second paddle
		std::string paddle_name = "Paddle";
		auto paddle_entity = make_shared< entity >(paddle_name, this);

		// Add render component
		auto render_comp_paddle = render_sys->create_component(paddle_name);
		paddle_entity.get()->add_component("RenderComp", render_comp_paddle);

		// Save entity
		entities[paddle_name] = paddle_entity;

		paddle_entity.get()->get_transform()->set_position(vec3(30.f, 0, 0));
		paddle_entity.get()->get_transform()->set_rotation(vec3(0, 0, 0));
		paddle_entity.get()->get_transform()->set_scale(vec3(1, 7, 0.1f));
	}

	void scene::add_input_event_mapping(Keyboard::Key_Code key, std::string& _event_id)
	{
		input_sys->add_input_event_mapping(key, _event_id);
	}

	void scene::add_controller(std::shared_ptr<controller> given_controller)
	{
		update_t->add_controller(given_controller);
	}

	entity* MGEngine::scene::get_entity(std::string& _name)
	{
		auto map_it = entities.find(_name);

		if (map_it != entities.end())
			return map_it->second.get();
		else
			return nullptr;
	}
}
