//#include <iostream>
//#include <ctime>
//using namespace std;
//
//int main()
//{
//	int count = 0;
//	//clock_t t1, t2;
//	//t1 = t2 = clock();
//	//cout << t1 << endl;
//	//// loop until t2 gets a different value
//	//while (t1 == t2){
//	//	count++;
//	//	t2 = clock();
//	//}
//
//	//cout << "count is" << count << endl;
//	//// print resolution of clock()
//	//cout << t1<<"   "<<t2<<endl;
//	//cout << CLOCKS_PER_SEC << endl;
//
//	//cout << ((double)(t2 - t1) / CLOCKS_PER_SEC )* 1000 << " ms.\n";
//
//	//---------------------------------------------------------------------------------------
//		std::clock_t start;
//
//		double duration;
//
//		start = std::clock();
//
//		long a=10, b=5;
//		while (a < 100)
//			a = a + b;
//
//		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC*1000;
//
//		std::cout << "printf: " << duration << '\n';
//	
//	system("pause");
//	return 0;
//}


//-------------------------------------------------------------------------------

//#include <iostream>
//#include <chrono>
//typedef std::chrono::high_resolution_clock Clock;
//
//int main()
//{
//	int count = 0;
//	auto t1 = Clock::now();
//	auto t2 = Clock::now();
//	while (t1 == t2){
//		t2 = Clock::now();
//		count++;
//	}
//
//	std::cout << count << std ::endl;
//	std::cout << "Delta t2-t1: "
//		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
//		<< " nanoseconds" << std::endl;
//	system("pause");
//	return 0;
//}
//------------------------------------------------------------------
#include <iostream>
#include <windows.h>                // for Windows APIs
using namespace std;

int main()
{
	LARGE_INTEGER frequency;        // ticks per second
	LARGE_INTEGER t1, t2;           // ticks
	double elapsedTime;
	long count = 1000000;
	// get ticks per second
	QueryPerformanceFrequency(&frequency);

	// start timer
	QueryPerformanceCounter(&t1);

	// do something

	while (count > 100)
		count--;

		// stop timer
		QueryPerformanceCounter(&t2);

	// compute and print the elapsed time in millisec
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
	cout << elapsedTime << " ms.\n";
	system("pause");
	return 0;
}




//1-Game runs at different speeds on different computers.
//2-CPU(can be needlessly) pegged at 100 % usage.
//3-"Game states" / menus are missing or mixed with game code.
//4-Main game loop is very long and hard to maintain.
//5-Code is difficult to extend / port to other platforms.




//Rule #1. Do not make update() or loop() kind of functions rely on how often it gets called.
//
//You can't really get your desired FPS. You could try to boost it by skipping some expensive operations or slow it down by calling sleep() kind of functions. However, even with those techniques, FPS will be almost always different from the exact FPS you want.
//
//The common way to deal with this problem is using elapsed time from previous update.For example,
//
//// Bad
//void enemy::update()
//{
//	position.x += 10; // this enemy moving speed is totally up to FPS and you can't control it.
//}
//
//// Good
//void enemy::update(elapsedTime)
//{
//	position.x += speedX * elapsedTime; // Now, you can control its speedX and it doesn't matter how often it gets called.
//}