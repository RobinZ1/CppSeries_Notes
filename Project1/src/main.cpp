
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





//tut35 const in c++
/*
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
*/


//tut36 the mutable keyword in cpp
/*
#include <iostream>
#include <string>

class Entity {
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
public:
	const std::string& GetName() const 
	{
		m_DebugCount++;
		return m_Name;
	}
};

int main()
{
	const Entity e;
	e.GetName(); 

	int x = 8;
	auto f = [=]() mutable //(=)means to pass it by value
	{
		x++;
		std::cout << "Hello "<<x<< std::endl;
	};

	f();
	
	std::cout << x<< std::endl; //still 8, not passing by reference but by value =
	std::cin.get();
}

*/

//tut 37 Member initializer lists in cpp

//tut38 ternary operators in cpp
/*
#include <iostream>
#include <string>

int main()
{
	static int s_Level = 11;
	static int s_Speed = 10;

	s_Speed = s_Level > 5 ? (s_Level > 10 ? 15 : 10) : 5;
	std::cout << s_Speed << std::endl;
	std::cin.get                                                                                                                                
}
*/


/*
//tut39 how to create instantiate objects 
 
#include <iostream>
#include <string>

class Entity {
private:
	std::string m_Name;
public:
	Entity() : m_Name("unknown") {}
	Entity(const std::string& name) : m_Name(name) {}
	void GetName()
	{
		std::cout << "banzai" << std::endl;
	}
};


int main()
{
	//1. stack-simple and auto memory-cleaning, for small size of tasks

	//2. heap-manually use delete, large object set and want to manually track lifetime, then use heap
	Entity* e;
	{
		Entity* entity = new Entity("Cherno");
		e = entity;
		std::cout << e->GetName() << std::endl;
	}
	
	//stack
	Entity* e;
	{
		Entity entity("Cherno");
		e = &entity;
		std::cout <<entity.GetName() << std::endl;
	}

	std::cin.get();
	delete e;
}
*/



//tut40 NEW keyboard in cpp ---delete & delete[]
//tut41 implicit conversion and the explicit keyword in cpp
/*
#include <iostream>
#include <string>

class Entity
{
public:
	std::string m_name;
	int m_age;
	Entity(const std::string& name): m_name(name), m_age(-1) {} //however, adding 'explicit' keyword in front disable the implicit declaration.
	explicit Entity(int a): m_name("unknown"), m_age(a) {}
};

void Print(const Entity& entity)
{
	//print stuff
}

int main()
{
	Entity a = 18;
	Entity b = "Cherno";
	Print(18);
	Print(std::string("Cherno"));//or implicitly, Entity("Cherno")
}
*/


/*
//TUT42 operators(, [], () ...) and operation overloadings
//operator are just functions


#include <iostream>
#include <string>

struct Vector2
{
	float x, y;
	Vector2(float x, float y)
		: x(x), y(y) {}

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x*other.x, y*other.y);
	}


	Vector2 operator+(const Vector2& other) const
	{
		return Add(other);
		//return (*this)+other;
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Multiply(other);
		//return Vector2(x*other.x, y*other.y);
	}

	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
		//return (*this) == other;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << ", " << other.y;
	return stream;
}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.5f, 1.1f);

	Vector2 result1 = position.Add(speed.Multiply(powerup));
	Vector2 result2 = position + speed*powerup;

	if (result1 == result2)
	{
		std::cout << "Banzai" << std::endl;
	}
	else
	{
		std::cout << "charge" << std::endl;
	}

	std::cout << result1 << "\n"<<std::endl;
	std::cout << result2 << "\n" << std::endl;
	std::cin.get();
}

*/


/*
//TUT43 'THIS' KEYWORD
#include <iostream>
#include <string>

void PrintEntity(Entity* e); //if changes to (Entity& e)

class Entity
{
	int x, y;
	Entity(int x, int y)
	{
		this->x = x;
		this->y = y;
		PrintEntity(this); //then changes to PrintEntity(*this)
	}

	int Getx() const
	{
		//const Entity* e = this; //meaning the content of this is not to be modified due to within const method
	}
};

void PrintEntity(Entity* e)
{
	//Print
}
*/


/*
//TUT44 Object lifetime in cpp
class scopeP
{
private:
	Entity* m_ptr;
public:
	scopeP(Entity* ptr)
		: m_ptr(ptr)
	{}

	~scopeP()
	{
		delete m_ptr;
	}
};

int main()
{
	//built on stack
	{
		Entity e;
	}
	//built on heap
	{
		Entity* e = new Entity();
		delete e;
	}

	//or unique_pointer prototype, built on heap
	{
		scopeP e = new Entity();
	}//and clear memory when leaving the scope
}

*/







/*

//TUT45 smart pointers in cpp
#include <iostream>
#include <string>

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl; 
	}
	~Entity() 
	{
		std::cout << "destroyed entity!" << std::endl;
	}
	void Print() {}
};


int main()
{
	/*
	{
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();//this is more efficient way than using 'new' method, the latter one allocate memory twice while the first one only did it once
		entity->Print();
	}
	*/
	/*
	//shared_ptr--reference count, only when count is 0 when leaving the second scope, the memory gets cleaned
	{
		std::shared_ptr<Entity> e0;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e0 = sharedEntity;
		}
	}
	

	//weak_ptr: no reference counting, great for not taking ownship entities.

	{
		std::weak_ptr<Entity> e0;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_sahred<Entity>();
			e0 = sharedEntity;
		}//when leaving this scope, weak_ptr will be pointing to invalid entity, so inquiry actions can be applied to weak_ptr to ask for status of shared_ptr within such group.  
	}

	std::cin.get();

}


*/



/*

//TUT46 Copying and copy constructors in cpp

#include <iostream>
#include <string>

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size+1];//actually, notice + 1 is to allocate space for null end, strcpy function includes the null termination character
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size + 1] = 0;
	}
	//*********
	//Important: technics to perform deep copy
	String(const String& other)
		:m_Size(other.m_Size)
	{
		std::cout << "copied string" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);//m_Size+1 to automatically place null terminator at the end of char array
		m_Buffer[m_Size + 1] = 0;//in case no null terminator
	}
	//that's it!

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;//a private variable
	return stream; 
}

//private: only members of parent class & friend class/external function can have access to
//protected: access is granted to class under inheritence.

void PrintString(const String& string) //without &, "copied string" will be displayed twice
{
	std::cout << string << std::endl;
}

int main()
{
	//following sallow copy make two string shared one common memory block
	String string = "Cherno";
	String second = string;
	//notice the m_Buffer is the same for these two string
	//so the program crash when m_Buffer gets cleaned twice
	second[2] = 'a';//refer to line 778, the operator[] is implemented

	PrintString(string);
	PrintString(second);

	std::cin.get();

}


*/



/*
//TUT47 arrow operation
#include <iostream>
#include <string>

struct Vector3
{//0, 4, 8 memory location offset
	float x, y, z;
};

int main()
{
 
	//what to do if I want to know the offset of class variables' memory address?

	int offset = (int)(&((Vector3*)0)->z); //8
	std::cout << offset << std::endl;
	std::cin.get(); 
}
*/



/*

//TUT48 Dynamic Arrays in Cpp
//vector---the dynamic array in cpp
//no set size,  
 
#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

int main()
{
	std::vector<Vertex> vertices; //vertex objects is optimal, not pointers
	vertices.push_back({1,2,3});
	vertices.push_back({ 4,5,6 });
	for (const Vertex& v : vertices)//& more efficient than making copy
	{
		std::cout << vertices[i] << std::endl;
	}
	vertices.erase(vertices.begin()+1);//iterator {4,5,6} is removed
	std::cin.get();
}
*/


/*
//TUT49 optimizing the usage of std--vector


#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{}

	Vertex(const Vertex& vertex)
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied" << std::endl;
	}
	
};


/*

int main()
{
	
	//before optimization, copied 6 times, initializing once per Vertex on main, and then copied it to the memory where vector is allocated,besides, the vertices vector be default can hold 2 vectors, when the third one is added, it must increase capacity to 3, debug to check it out 1+2+3 = 6
	std::vector<Vertex> vertices; //vertex objects is optimal, not pointers
	vertices.push_back(Vertex(1, 2, 3));
	vertices.push_back(Vertex(4, 5, 6));
	vertices.push_back(Vertex(7, 8, 9));
	std::cin.get();
	

	//after optimization, not a single copy! 0 copy
	std::vector<Vertex> vertices; 
	vertices.reserve(3);
	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);
	std::cin.get();
	
}

*/


/*
//TUT50 Using libraries in cpp
#include <iostream>
#include <GLFW/glfw3.h>

extern "C" int glfwInit();

int main()
{
	int a = glfwInit();
	std::cout << a << std::endl;
	std::cin.get();
}

*/


/*


//TUT 51 Using dynamic libraries in cpp
 
 #include <iostream>
 #include <GLFW/glfw3.h>

int main()
{
	int a = glfwInit();
	std::cout << a << std::endl;
	std::cin.get();
}


*/

/*

//TUT54 Templates in cpp
#include <iostream>
#include <string>

template<typename T, int N>
class Array
{
private:
	T m_Array[N];
public:
	int Getsize() const { return N; }
};


int main()
{
	Array<int, 50> array;
	std::cout<<array.Getsize<<std::endl;
	std::cin.get();
}

*/

/*

//TUT 55 STACK VS HEAP MEMORY

//same physical storage location---memory

#include <iostream>
#include <string>

struct Vector3
{
	float x, y, z;
	Vector3()
		: x(10), y(11), z(12) {}
};

int main()
{
	int value = 5;//stack
	int array[5];
	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	Vector3 vector;

	//heap
	int* hvalue = new int;
	*hvalue = 5;
	int* harray = new int[5];
	harray[0] = 0;
	harray[1] = 1;
	harray[2] = 2;
	Vector3 hvector = new Vector3();

	std::cin.get();
	//stack pointer--one operator per time

	//allocating memory on stack is easy and fast, just one CPU instruction, while doing that on heap is to re-haul the heap, expensive and slow
	//suggestion take away, always use stack unless dealing with large data set, then heap with appropriate set size is better used for storage data.

}
*/

/*
//TUT 56 Macros in CPP
#include <iostream>

/*
#include <string>

#if PR_DEBUG == 1
#define LOG(x) std::cout<<x<<std::endl;
#elif defined(PR_RELEASE)
#define LOG(x) 
#endif

int main()
{	
	LOG("Hello");
	std::cin.get();
}
*/
/*
#define MAIN int main() \
{\
	std::cin.get();\
}

MAIN

 */



//TUT57 the 'auto' keyword in CPP	

/*
using device_map = ....(long type name);
typedef ....(long type name) device_map;
or auto device_map = ...
*/


//TUT58 the static array in CPP
//check array document


/*
//TUT59 function pointers in CPP

#include <iostream>
#include <vector>


void Print(int a)
{
	std::cout << a << std::endl;
}

void ForEach(const std::vector<int>& vector, void(*func)(int))
{
	for (auto ele : vector)
		func(ele);
}

int main()
{
	std::vector<int> values = { 1,2,3,4 };
	ForEach(values, Print);

	//better way is to use lambda function
	//ForEach(values, [](int value){std::cout<<value<<std::endl;});
	//pass parameter from outside world into []
	
	std::cin.get();
}
*/



/*
//TUT60 Lambdas in cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> values = { 1,5,4,2,3 };
	auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; });
	std::cout << *it << std::endl;

	std::cin.get();
	//More info refer to cppreference.com 
}
*/