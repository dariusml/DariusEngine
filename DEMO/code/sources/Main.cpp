#include <Window.h>
#include <MemoryAllocator.h>

class Cosa
{
private:
	int a, b;
public:
	Cosa() : a(2), b(4444) {}
};

int main()
{
	std::string nombre("ventana");
	//Darius::Window ventana(nombre, 1024, 768, false);
	//while(true){}

	MemoryAllocator characters(8);
	Cosa* cosa = characters.allocate<Cosa>();

	return 0;
}