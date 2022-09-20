#include <iostream>
#include <thread>
#include <stdlib.h>
#include <time.h>
using namespace std;
void funct(int id, int value)
{
	int gen = rand() % 10000;
	while(gen != value)
	{
		gen = rand()% 10000;
	}
	cout << "Thread " << id << " completed.\n";
}
int main(int argc, char* argv[])
{
	thread arr[10];
	srand(time(0));
	int value = atoi(argv[1]);
	for(int i = 0; i < 10; i++)
	{
		arr[i] = thread(funct, i, value);
	}
	for(int i = 0; i < 10; i++)
        {
                arr[i].join();
        }
	cout << "All threads have finished finding numbers.\n";
	return 0;
}
