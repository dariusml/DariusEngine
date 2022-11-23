#include <Window.h>
#include <MemoryAllocator.h>

int main()
{
	std::string nombre("ventana");
	//Darius::Window ventana(nombre, 1024, 768, false);
	//while(true){}

	MemoryAllocator characters(8);
	int* cosa = characters.allocate<int>();
	return 0;
}