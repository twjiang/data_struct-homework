#include <iostream>
#include <string>
#include "sequenceList.h"
#define max 100

using namespace std;

int main()
{
	sequenceList<string> projectName;
	string name;
	sequenceList<double> projectInterest;
	double interest;
	int position;
	char choice;
	
	cout << endl;
	cout << "---------------------天文银行利率表管理系统---------------------" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << endl;
	cout << "                  添加项目-------------------1" << endl;
	cout << endl;
	cout << "                  删除项目-------------------2" << endl;
	cout << endl;
	cout << "                  查找项目-------------------3" << endl;
	cout << endl;
	cout << "                  查看全部项目---------------4" << endl;
	cout << endl;
	cout << "                  退出系统-------------------0" << endl;
	cout << endl;
	
	cout << "请输入你要进行的操作的编号：";
	cin >> choice;
	while(choice != '0')
	{
		switch(choice)
		{
			case '1':
				cout << "请输入要添加的项目名称和利率：";
				cin >> name;
				projectName.addData(name);
				cin >> interest;
				projectInterest.addData(interest);
				break;
			case '2':
				cout << "请输入要删除的项目名称：";
				cin >> name;
				position = projectName.find(name);
				projectName.deleteData(position);
				projectInterest.deleteData(position);
				break;
			case '3':
				cout << "请输入要查找的项目名称：";
				cin >> name;
				cout << "该项目的利率为：";
				cout << projectInterest.getData(projectName.find(name)) << endl;
				break;
			case '4':
				for(int i = 1; i <= projectName.getLast(); i++)
				{
					cout << i << ". ";
					cout << projectName.getData(i) << " ";
					cout << projectInterest.getData(i);
					cout << endl;
				}
				break;	
		}
		cout << "请输入你要进行的操作的编号：";
		cin >> choice;
	}
	
	return 0;
}