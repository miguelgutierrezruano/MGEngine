#pragma once

namespace MGEngine
{
	class task
	{

	public:

		// Status of the task
		enum Status
		{
			WAITING,
			RUNNING,
			CANCELLED,
			FINISHED
		};

	private:

		Status status;

	public:

		task()
		{
			status = WAITING;
		}

		Status get_status() const { return status; }
	};

	//TODO: task_group
}
