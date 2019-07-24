
/*

struct Entity
{
	int x, y;
	static void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
};
//but this works
static void Print(Entity e)
{
	std::cout << e.x << ", " << e.y << std::endl;
}

int main()
{
	Entity e;
	e.x = 2;
	e.y = 3;
	Entity::Print();
	std::cin.get();
	//static method can not have access to non-static members, since it does not have a class instance, unless refer to line 11th, pass instance as parameter

	//every non-static members of class have instance of a class as its parambers.
}

*/
 
/*
//tut24 local static in cpp
//lifetime and scope


#include <iostream>

class Singleton
{
public:
	static Singleton& Get()
	{
		static Singleton instance; //has to be static, otherwise, instance get destroyed leaving the scope
		//unless, make method non-static as well.
		return instance;
	}

	void Hello()
	{
		std::cout << "Banzai!" << std::endl;
	}

};


int main()
{
	Singleton::Get().Hello();
	std::cin.get();
}

//To do:
//commit change and push it to github!
*/



//tut25
/*

#include <iostream>

class Log
{
public:
	enum Level
	{
		LevelError = 0, LevelWarning, LevelInfo
	};
private:
	Level m_LogLevel = LevelInfo;
public:
	void SetLevel(Level level)
	{
		m_LogLevel = level;
	}
	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[Error]: " << message << std::endl;
	}
	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[Warn]: " << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[Info]: " << message << std::endl;
	}

};

int main()
{
	Log log;
	log.SetLevel(Log::LevelError);
	log.Warn("Hello");
	log.Error("Hello");
	log.Info("Hello");
	std::cin.get();
}
*/

/*
//tut27 destructor

#include <iostream>

class Entity
{
public:
	float X, Y;

	Entity()
	{
		X = 0;
		Y = 0;
		std::cout << "Created Entity!" << std::endl;
	}
	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}

	~Entity()
	{
		std::cout << "Entity Destroyed!" << std::endl;
	}

	void Print()
	{
		std::cout<<X<<", " <<Y << std::endl;
	}
};

void Function()
{
	Entity e;
	e.Print();
}

int main()
{
	Function();
	std::cin.get();
}
*/


//tut29 Virtual Functions

/*
#include <iostream>
#include <string>

class Entity {
public:
	virtual std::string GetName()
	{
		return "Entity";
	}
};

class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name) {}

	std::string GetName() override { return m_Name; }//override must be paired with 'virtual' keyword
};

void PrintName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
}

int main()
{
	Entity* e = new Entity();
	PrintName(e);

	Player* p = new Player("Cherno");
	PrintName(p); //if basic method in basic class is non-virtual, then return "Entity" instead of "Cherno"

	std::cin.get();
}

*/

/*
//tut30 interfaec-which is a class in c++
//tut 31 visibility
#include <iostream>
#include <string>

class Entity
{
protected:
	int X, Y;
	void Print() {};
public:
	Entity()
	{
		X = 0;
		Print();
	}
};

class Player : public Entity
{
public:
	Player()
	{
		X = 2;
		Print();
	}
};

int main()
{
	Entity e;
	e.Print();//Print() and line below cause error: as Protected members and methods can only be accessed by sub class but not to be visited outside the class.
	e.X = 2;
	std::cin.get();
} 
 

 */


/*tut 32 arrays*/

/*
#include <iostream>


int main()
{
	
	int example[5];
	for (int i = 0; i < 5; i++)
		example[i] = 2;

	int* ptr = example;
	example[2] = 5;
	*(ptr + 2) = 6; // or  *(int*)((char*)ptr+8)=6
	std::cin.get();
	*/

	/*
	int example[5];//built on stack, cleared when leaving scope
	for (int i = 0; i < 5; i++)
	{
		example[i] = 2;
	}
	int* another = new int[5];//built on heap, cleared when program terminates or being destroyed
	for (int i = 0; i < 5; i++)
	{
		another[i] = 2;
	}
	delete[] another;
	//array built on stack vs array on heap:  * new[]
	//difference and purpose
	std::cin.get();

}
*/
/*
#include <iostream>
#include <array>

class Entity
{
public:
	static const int exampleSize = 5;
	int example[exampleSize];

	//or in c++ std;
	std::array<int, 5> another;
	Entity()
	{
		for (int i = 0; i < another.size(); i++)
			example[i] = 2;
	}
};

int main()
{}
*/



/*
//tut 33 strings
#include <iostream>
#include <string>

void Print(const std::string& string) //& pass bt reference, no copy, const means no change is a promise
{
	std::cout << string << std::endl;
}

int main()
{
	std::string name = std::string("Cherno")+" hello!"; //const char array, thus, can not add "Hello" with + after "Cherno
	//or you can do name += " hello";

	//notice, string is a class! to modify it
	
	bool contains = name.find("no") != std::string::npos;
	if(contains)
		Print(name);
	std::cin.get(); 
	
}
*/

/*
//tut34 
//char* name = "abv";
//name[2] = 'a' modification is not allowed by creating such pointer since by default it is const, change pointer to name[] will do the job

#include <iostream>
#include <string>
#include <stdlib.h>

int main()
{
	using namespace std::string_literals;
	std::u32string name0 = U"Cherno"s + U" hello"; //adding s!
	const char* name = "Cherno"; //or u8"Cherno" 
	const wchar_t* name2 = L"Cherno";
	const char16_t* name3 = u"Cherno"; //2 bytes on windows, 4 bytes on linux
	const char32_t* name4 = U"Cherno";


	const char* example = R"(Line1
Line2
Line3
Line4)";

	const char* ex = "Line1\n"
		"Line2\n"
		"Line3\n";


	std::cout << name0 << std::endl;
	std::cin.get();
}

*/

//tut35 const in c

/**/
#include <iostream>
#include <string>

class Entity
{
private:
	int* m_X, *m_Y;
	mutable int var; //must have mutable keyword to modify it within const method along with other const variables
public:
	const int* const GetX() const //meaning not modifying any
		//const class variables, 
	{ 
		var = 2; //but mutable variable can be modified
		return m_X; 
	}

	void SetX(int x)
	{
		*m_X = x;
	}
};

void Print(const Entity& e)
{
	m_X = x;
}

int main()
{
	//const int* b;//not modifying its content
	//int* const c; //not modifying pointer
	//int const * b;//same as the first one
}