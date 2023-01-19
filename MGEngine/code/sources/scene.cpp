
#include <scene.h>
#include <tinyxml2.h>

using namespace tinyxml2;

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

	void scene::load_scene(const char * xml_path)
	{
		XMLDocument doc;
		doc.LoadFile(xml_path);

		// Get scene element
		XMLElement * rootElement = doc.RootElement();
		
		XMLElement* entity_elem = rootElement->FirstChildElement("entity");

		while(entity_elem)
		{
			// Make entity
			std::string entity_name = entity_elem->Attribute("id");
			auto new_entity = make_shared< entity >(entity_name, this);

			// Apply transform
			XMLElement * entity_transform = entity_elem->FirstChildElement("transform");

			// Apply transform
			XMLElement* position = entity_transform->FirstChildElement("position_x");
			XMLElement* rotation = entity_transform->FirstChildElement("rotation_x");
			XMLElement* scale = entity_transform->FirstChildElement("scale_x");
			vec3 t_position(0, 0, 0);
			vec3 t_rotation(0, 0, 0);
			vec3 t_scale(0, 0, 0);

			for (int i = 0; i < 3; ++i)
			{
				t_position[i] = stof(position->GetText());
				t_rotation[i] = stof(rotation->GetText());
				t_scale[i] = stof(scale->GetText());

				position = position->NextSiblingElement();
				rotation = rotation->NextSiblingElement();
				scale = scale->NextSiblingElement();
			}

			new_entity.get()->get_transform()->set_position(t_position);
			new_entity.get()->get_transform()->set_rotation(t_rotation);
			new_entity.get()->get_transform()->set_scale(t_scale);

			// Apply render component
			XMLElement* entity_render = entity_elem->FirstChildElement("render_component");

			if (stoi(entity_render->GetText()) != 0)
			{
				auto render_comp = render_sys->create_component(entity_name);
				new_entity.get()->add_component("RenderComp", render_comp);
			}

			// Save entity
			entities[entity_name] = new_entity;

			entity_elem = entity_elem->NextSiblingElement();
		}
	}

	void scene::add_input_event_mapping(Keyboard::Key_Code key, const std::string& _event_id)
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
