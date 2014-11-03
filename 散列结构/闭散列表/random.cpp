#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	int ran_num;
	ofstream fcout;
	fcout.open("key1.txt");
	/*for(int j = 0; j < 1000; j++)
	{
		for(int i = 0; i < 11; i++)
		{ 
			ran_num[i] ='0' + rand() % 10;
		}
		ran_num[11] = '\0';
		fcout << ran_num << " ";
	}*/

	for(int i = 0; i < 100000; i++)
	{ 
		ran_num = rand() % 100000;
		fcout << ran_num << " ";
	}
	
	return 0;
}