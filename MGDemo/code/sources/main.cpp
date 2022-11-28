
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
	TestClass(int _a, int _b) { a = _a; b = _b; }
};

int main()
{
	/*MGEngine::Window myWindow("Ventanita", 800, 700, false);
	while (true) { }*/

	MemoryPool memorypool(50);
	TestClass * test = memorypool.allocate<TestClass>();
	TestClass * test2 = memorypool.allocate<TestClass>(2, 20);

	return 0;
}