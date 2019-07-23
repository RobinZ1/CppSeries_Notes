/*
{
	//1b, 2b, 4b, 4b, 8b
	//unsigned char, short, int, long, long long;

	//float-4b, double -8b
	float variable = 8.0f; //-2b -> 2b
	float B = 8.0;
	//the 8.0f means float, otherwise double
	//bool - 1b
	std::cout << variable << std::endl;
	std::cin.get();
}
*/

#include <iostream>
#include "Log.h"

int main()
{
	for (int i = 0; i < 5; i++)
	{
		if (i > 2)
			continue; //continue means to return to for statement, skipping two lines below
		//break end the loop immediately
		Log("Hello World!");
		std::cout << i << std::endl;
	} 
	 

	std::cin.get();//this keeps window open
}

   