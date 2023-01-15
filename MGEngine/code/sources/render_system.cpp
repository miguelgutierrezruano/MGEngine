
#include <render_system.h>
#include <scene.h>
#include <Render_Node.hpp>
#include <Model.hpp>
#include <Light.hpp>
#include <Cube.hpp>
#include <string>

using namespace std;

namespace MGEngine
{
	render_system::render_system(scene* given_scene)
	{
		r_task.set_scene(given_scene);

		// TODO: Convert camera and light into components
		shared_ptr< Camera > camera(new Camera(40.f, 1.f, 50.f, 1.f));
		shared_ptr< Light  > light(new Light);

		r_task.get_renderer()->add("camera", camera);
		r_task.get_renderer()->add("light", light);

		r_task.get_renderer()->get("camera")->translate(Vector3(0.f, 0.f, 10.f));
		r_task.get_renderer()->get("light")->translate(Vector3(10.f, 10.f, 10.f));
	}

	// TODO: Give xml node to create component OR Variadic arguments
	std::shared_ptr<component> render_system::create_component()
	{
		// Give entity name
		std::string name = "AAA";

		auto r_comp = std::make_shared< mesh_component >(name, new Cube); // TODO: Add other meshes
		r_task.add_component(r_comp);
		return r_comp;
	}
}

