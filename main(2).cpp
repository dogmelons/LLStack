#include "LLStack.h"
//#include "VTimer.h"
#include <iostream>
#include <list>

#include <limits>
int main(int argc, char *argv[])
{
	//VTimer tempTimer; // Sets up a VTimer object. Creates it's own reference point
	//double currentTime = 0.0; // Assign time values to some variable, can be a double, size_t, int, whatever.

	{
		int out;
		LLStack<int> stack;
		
		//tempTimer.setStartTick();

		for (unsigned int i = 0; i < 10000000; i++)
		{
			stack.push(3);
		}

		//currentTime = tempTimer.time_u();
		//std::cout << "time: " << currentTime << std::endl;

		//tempTimer.setStartTick();

		for (unsigned int i = 0; i < 10000000; i++)
		{
			stack.pop(out);
		}

		//currentTime = tempTimer.time_u();
		//std::cout << "time: " << currentTime << std::endl;



		//std::list<int> stack2;

		////tempTimer.setStartTick();

		//for (unsigned int i = 0; i < 10000000; i++)
		//{
		//	stack2.push_back(3);
		//}

		////currentTime = tempTimer.time_u();
		////std::cout << "time2: " << currentTime << std::endl;

		////tempTimer.setStartTick();

		//for (unsigned int i = 0; i < 10000000; i++)
		//{
		//	stack2.pop_back();
		//}

		//currentTime = tempTimer.time_u();
		//std::cout << "time2: " << currentTime << std::endl;

	}

	//system("PAUSE");
	return 0;
}
