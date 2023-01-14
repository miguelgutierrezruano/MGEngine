
#include <render_system.h>
#include <scene.h>
#include <Render_Node.hpp>
#include <Model.hpp>
#include <Light.hpp>
#include <Cube.hpp>

using namespace glt;
using namespace std;

namespace MGEngine
{
	render_system::render_system(scene* given_scene)
	{
		r_task.set_scene(given_scene);

		shared_ptr< Model  > cube(new Model);
		shared_ptr< Camera > camera(new Camera(20.f, 1.f, 50.f, 1.f));
		shared_ptr< Light  > light(new Light);


		cube->add(shared_ptr< Drawable >(new Cube), Material::default_material());


		r_task.get_renderer()->add("cube", cube);
		r_task.get_renderer()->add("camera", camera);
		r_task.get_renderer()->add("light", light);

		r_task.get_renderer()->get("camera")->translate(Vector3(0.f, 0.f, 5.f));
		r_task.get_renderer()->get("light")->translate(Vector3(10.f, 10.f, 10.f));
	}

	std::shared_ptr<component> render_system::create_component()
	{
		auto r_comp = std::make_shared< mesh_component >();
		r_task.add_component(r_comp);
		return r_comp;
	}
}

