
#include <window.h>
#include <iostream>
#include "kernel.h"
#include "task.h"

using namespace MGEngine;

class test_class
{
private:
	int a;
	int b;

public:
	test_class() { a = 2; b = 200; }
	test_class(int _a, int _b) { a = _a; b = _b; }
};

class dummy_tasks : public task
{

public:

	dummy_tasks()
	{
		status = WAITING;
		priority = UPDATE_PRIORITY;

		consumable = false;
	}

	dummy_tasks(Priority given_priority, bool is_consumable = true)
	{
		status = WAITING;
		priority = given_priority;

		consumable = is_consumable;
	}

private:

	void lots_of_multiplications()
	{
		int x;

		for (int i = 0; i < 1000; i++)
		{
			x = 7 * i;
		}
	}

protected:

	void run(float delta_time) override
	{
		for (size_t i = 0; i < 10; i++)
		{
			lots_of_multiplications();
		}

		std::cout << "Task finished!" << std::endl;
	}
};

int main()
{
	dummy_tasks mydummy(task::UPDATE_PRIORITY, false);

	kernel my_kernel;
	my_kernel.set_fps(1);
	my_kernel.add_task(&mydummy);

	my_kernel.execute();

	return 0;
}