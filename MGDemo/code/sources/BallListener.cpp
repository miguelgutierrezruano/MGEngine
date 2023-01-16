
#include <BallListener.h>
#include <BallController.h>

void BallListener::handle(const event& _event, float delta_time)
{
	if (_event.id == "MoveBall")
	{
		ball_controller->set_moving_state();
	}
}
