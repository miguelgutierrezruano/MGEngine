
#include <window.h>
#include <iostream>
#include "scene.h"
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

int main()
{
	scene first_scene;

	first_scene.load_default_scene();

	Window window("MGDemo", 800, 600, false);

	first_scene.run();

	return 0;
}