#include <iostream>
#include <string>
#include <cmath>

#include "stack.h"
#include "infixToPostfix.h"
#include "calPostfix.h"
#include "toFloat.h"

using namespace std;

string nagtive(string _string)
{
    string::iterator itr = _string.begin();
    if(*itr == '-')
    {
        itr = _string.insert(itr, '0');
    }
    while(itr != _string.end())
    {
        if(*itr == '(' && *(itr+1) == '-')
        {
            itr = _string.insert(itr+1, '0');
            itr = itr + 2;
        }
        else
        {
            itr++;
        }
    }
    return _string;
}

int main()
{
    string infix, postfix;         //中缀、后缀表达式 
    float value[100];              //承装表达式中的数据，为后面数据的提取做准备
    float result = 0;              //保存结果
    for(int i = 0 ; i < 100; i++)
    {
      value[i] = 0;
    }
    cout << "Infix: ";            //提示用户输入中缀表达式
    cin >> infix;
    infix = nagtive(infix);
    /*cout << endl;
    cout << "infix to postfix............" << endl;
    cout << endl;*/
    postfix = toPostfix( infix );
    /*string::iterator itr = postfix.begin();
    cout << "Postfix: ";
    cout << *itr++;
    while( itr != postfix.end() )
    {
        cout << *itr++;              //输出后缀表达式
    }
    cout << endl; */              
    toFloat(value, postfix);

    /*cout << endl;
    cout << "calculating postfix............" << endl;
    cout << endl;*/
    result = calpostfix(postfix, value);
    cout << endl;
    cout << "Result: " ;
    cout << result << endl;           //输出最终结果
    return 0;
}
