#include <Window.h>
#include <MemoryAllocator.h>
#include <iostream>

class Cosa
{
private:
	int a, b;
public:
	Cosa() : a(2), b(4444) {}
	Cosa(int a) : a(a), b(4444) {}
	Cosa(int a, int b) : a(a), b(b) {}
};

int main()
{
	std::string nombre("ventana");
	//Darius::Window ventana(nombre, 1024, 768, false);
	//while(true){}

	MemoryAllocator characters(32);
	Cosa* cosa  = characters.allocate<Cosa>();
	Cosa* cosa1 = characters.allocate<Cosa>(123);
	Cosa* cosa2 = characters.allocate<Cosa>(123,432);


	return 0;
}