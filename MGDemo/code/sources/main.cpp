
#include <window.h>
#include <iostream>
#include "MemoryPool.h"
#include "ChunkedMemoryPool.h"
#include "ObjectPool.h"

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
	// Window test
	/*MGEngine::Window myWindow("Ventanita", 800, 700, false);
	while (true) { }*/

	// Incremental memory pool test
	/*MemoryPool memorypool(30);
	TestClass * test = memorypool.allocate<TestClass>();
	TestClass * test2 = memorypool.allocate<TestClass>(2, 20);

	TestClass * test3 = memorypool.allocate<TestClass>(2, 20);
	TestClass* test4 = memorypool.allocate<TestClass>(2, 20);
	TestClass* test5 = memorypool.allocate<TestClass>(2, 20);
	TestClass* test6 = memorypool.allocate<TestClass>(2, 20);
	TestClass* test7 = memorypool.allocate<TestClass>(2, 20);*/

	// Chunked memory pool test
	/*ChunkedMemoryPool<sizeof(TestClass)> memoryPool(50);
	TestClass* test = memoryPool.allocate<TestClass>();
	TestClass* test2 = memoryPool.allocate<TestClass>();

	memoryPool.free(test2);
	memoryPool.free(test);

	TestClass* test4 = memoryPool.allocate<TestClass>();*/

	// Object pool test
	ObjectPool<TestClass> objectPool(3);

	return 0;
}