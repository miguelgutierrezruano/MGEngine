
#include <Render_Node.hpp>
#include <Cube.hpp>
#include <Model.hpp>
#include <Light.hpp>
#include "render_system.h"
#include <iostream>

using namespace glt;
using namespace std;

namespace MGEngine
{
	render_system::render_system(Window& given_window)
	{
		r_task.set_window(given_window);

		renderer = new Render_Node;

		r_task.set_renderer(renderer);

		shared_ptr< Model  > cube(new Model);
		shared_ptr< Camera > camera(new Camera(20.f, 1.f, 50.f, 1.f));
		shared_ptr< Light  > light(new Light);

		// Es necesario a�adir las mallas a los modelos antes de a�adir los modelos a la escena:

		cube->add(shared_ptr< Drawable >(new Cube), Material::default_material());

		// Se a�aden los nodos a la escena:

		renderer->add("cube", cube);
		renderer->add("camera", camera);
		renderer->add("light", light);

		// Se configuran algunas propiedades de transformaci�n:

		renderer->get("camera")->translate(Vector3(0.f, 0.f, 5.f));
		renderer->get("light")->translate(Vector3(10.f, 10.f, 10.f));
	}

	render_system::render_task::render_task()
	{
		task_window = nullptr;
		renderer    = nullptr;

		status = WAITING;
		priority = RENDER_PRIORITY;

		consumable = false;
	}

	void render_system::render_task::run(float delta_time)
	{
		GLsizei width = GLsizei(task_window->get_width());
		GLsizei height = GLsizei(task_window->get_height());

		renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);

		task_window->clear();

		renderer->render();

		task_window->swap_buffers();

		std::cout << "Render completed!" << std::endl;
	}

}