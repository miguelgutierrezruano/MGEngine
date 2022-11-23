
#include <window.h>
#include <MemoryPool.h>
#include <iostream>

class TestClass
{
private:
	int a;
	int b;

public:
	TestClass() { a = 2; b = 200; }
};

int main()
{
	/*MGEngine::Window myWindow("Ventanita", 800, 700, false);
	while (true) { }*/

	MemoryPool memorypool(50);
	TestClass * test = memorypool.allocate<TestClass>();

	return 0;
}