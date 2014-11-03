float calpostfix(string _string, float array[])
{
  stack<float> _stack;
  float temp = 0;
  int k = 1;
  string::iterator itr = _string.begin();

  while(itr != _string.end())
  {   
      int findNum = 0;
      if(*itr >= '0' && *itr <= '9')
      {
          while((*itr >= '0' && *itr <= '9') || *itr == '.')
          {
              findNum = 1;
              itr++;
          }
          if(findNum)      //找到一个数据中的所有字符，然后将承载数据的数组压入栈中
          {
              _stack.push(array[k]);
              k++;
              //cout << "stack: ";
              //_stack.print();
          }
          itr--;
      }
      else if(*itr == '+')   //根据不同的符号，弹出栈顶的两个元素，进行相应的运算
      {
          temp = _stack.top();
          _stack.pop();
          //cout << "stack: ";
           //_stack.print();
          temp = temp + _stack.top();
          _stack.pop();
          //cout << "stack: ";
           //_stack.print();
          _stack.push(temp);
          //cout << "stack: ";
           //_stack.print();
      }
      else if(*itr == '-')
      {
          temp = _stack.top();
          _stack.pop();
          //cout << "stack: ";
           //_stack.print();
          temp = _stack.top() - temp;
          _stack.pop();
          //cout << "stack: ";
          // _stack.print();
          _stack.push(temp);
          //cout << "stack: ";
           //_stack.print();
      }
      else if(*itr == '*')
      {
          temp = _stack.top();
          _stack.pop();
          //cout << "stack: ";
           //_stack.print();
          temp = _stack.top() * temp;
          _stack.pop();
          //cout << "stack: ";
           //_stack.print();
          _stack.push(temp);
          //cout << "stack: ";
           //_stack.print();
      }
      else if(*itr == '/')
      {
          temp = _stack.top();
          _stack.pop();
          //cout << "stack: ";
           //_stack.print();
          temp = _stack.top() / temp;
          _stack.pop();
          //cout << "stack: ";
           //_stack.print();
          _stack.push(temp);
          //cout << "stack: ";
           //_stack.print();
      }
      itr++;
  }
  return _stack.top();
}