
#include <input_system.h>

namespace MGEngine
{
	input_system::input_system(scene * given_scene)
	{
		i_task.set_scene(given_scene);
	}
}