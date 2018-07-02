#include <ctime>
#include <random>
#include <iostream>
#include <chrono>
#include <thread>
struct SourceOfNumbers
{
	unsigned int seed;
	std::default_random_engine engine;
	std::uniform_int_distribution<int> distribution;	
	SourceOfNumbers(): seed(std::chrono::system_clock::now().time_since_epoch().count()),
			   engine(seed), distribution(1,10)
	{
	}
	
	int GetNumber()
	{
		return distribution(engine);
	}
};


class Model
{
};

class View
{
	public:
	void Display(int number)
	{
		
		std::cout << "\r"  << number << std::flush ;
	}	
};

struct Level
{

	std::chrono::duration<int,std::ratio<1,1> > waitSpan;
	Level(): waitSpan(1)
	{}	





};

//std::mutex

class GameController
{
	Level level;

	SourceOfNumbers source;
	View view;
	public:
	void Run()
	{

	int i=10;	
		while(i-- > 0)
		{
			view.Display(source.GetNumber());
			std::this_thread::sleep_for(level.waitSpan);
		}

	}
	
};





int main()
{
	GameController game;

	game.Run();	

	return 0;
}

