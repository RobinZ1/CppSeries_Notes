#include <iostream>

#define LOG(x) std::cout<<x<<std::endl;

class Player {

public:
	int x, y;
	int speed;

public:
	void Move(Player& player, int xa, int ya)
	{
		player.x += xa * player.speed;
		player.y += ya * player.speed;
	}
};



int main()
{
	Player player;
	player.Move(player, 1, -1);
	std::cin.get();
}
