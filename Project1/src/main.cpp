#include <iostream>

struct Entity
{
	static int x, y;
	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

int Entity::x;
int Entity::y;

int main()
{
	Entity e;
	e.x = 2;
	e.y = 3;
	e.print();
	std::cin.get();
}