
#include <window.h>
#include <iostream>
#include "thread_pool.h"
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
		priority = DEFAULT_PRIORITY;

		consumable = false;
	}

	dummy_tasks(Priority given_priority, bool is_consumable)
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

	void run() override
	{
		for (size_t i = 0; i < 10; i++)
		{
			lots_of_multiplications();
		}
	}
};

void test3094(int n)
{

}

int main()
{
	auto myThread = std::thread(test3094, 4);
	myThread.join();

	/*thread_pool tp;

	dummy_tasks dummy_task;
	dummy_tasks high_dummy(task::HIGH_PRIORITY, false);

	tp.add_task(&dummy_task);
	tp.add_task(&high_dummy);

	task* topTask = tp.task_queue.top();

	tp.add_task(&dummy_task);
	tp.add_task(&dummy_task);

	while (not tp.task_queue.empty())
	{

	}*/

	std::cout << "All tasks finished!";

	return 0;
}