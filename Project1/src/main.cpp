
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

/**/
//tut27 destructor

#include <iostream>

class Entity
{
public:
	float X, Y;

	Entity()
	{}
	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}

	~Entity()
	{

	}

	void Print()
	{
		std::cout << X << ", " << Y < std::endl;
	}
};

int main()
{

}