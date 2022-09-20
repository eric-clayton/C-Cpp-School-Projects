#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	int count = 0;
	ifstream p ("pipe");
	if(!p.is_open())
	{
		p.open("pipe");
	}
	string line;
	while(getline(p, line))
	{
		count++;
	}
	cout << "Program failed on operation " << count << "\n";
}
