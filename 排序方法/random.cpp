#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	int ran_num;
	ofstream fcout;
	fcout.open("random.txt");
	for(int i = 0; i < 1600000; i++)
	{ 
		ran_num = rand() % 2000000;
		fcout << ran_num << " ";
	}
	return 0;
}