
#include <window.h>
#include <iostream>
#include "incremental_memory_pool.h"
#include "chunked_memory_pool.h"
#include "object_pool.h"

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
	// Window test
	/*MGEngine::Window myWindow("Ventanita", 800, 700, false);
	while (true) { }*/

	

	return 0;
}