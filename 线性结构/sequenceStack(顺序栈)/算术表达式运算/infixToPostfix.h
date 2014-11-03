int priority( char _char )        //优先级的定义
{
    if( _char == '+' || _char == '-' )
       return 1;
    if( _char == '*' || _char == '/' )
       return 2;

    return 0;
}

string toPostfix( string _string )      //中缀转后缀的实现
{
    stack<char> _stack; 
    string _temString;

    string::iterator itr = _string.begin();
    while( itr != _string.end() )
    {
       if((*itr >= '0' && *itr <= '9') || *itr == '.')   //将数字字符以及小数点直接输出
       {
           _temString.append( 1, *itr );
       }
       else if( *itr == '(' )                      //将其他运算符号压入栈中
       {
           _stack.push( '(' );
           //cout << "stack: ";
           //_stack.print();
       }
       else if( *itr == ')' )
       {
           while( _stack.top() != '(' )
           {
               _temString.append( 1, _stack.top() );
               _stack.pop();
               //cout << "stack: ";
              //_stack.print();
           }
           _stack.pop();
           //cout << "stack: ";
           //_stack.print();
       }
       else if( _stack.empty() )
       {
           _temString.append(1, ' ');
           _stack.push( *itr );
           //cout << "stack: ";
           //_stack.print();
       }
       else
       {
           if(  priority( *itr ) > priority( _stack.top() ) )
           {
               _temString.append(1, ' ');
               _stack.push( *itr );
               //cout << "stack: ";
               //_stack.print();
           }
           else
           {
               while( !_stack.empty() && priority( *itr ) <= priority( _stack.top() ) )
               {
                   _temString.append( 1, _stack.top() );
                   _stack.pop();
                   //cout << "stack: ";
                   //_stack.print();
               }
               _stack.push( *itr );
               //cout << "stack: ";
               //_stack.print();
           }
       }
       itr++;
    }
    while( !_stack.empty() )
	{
	    _temString.append( 1, _stack.top() );
	    _stack.pop();
		//cout << "stack: ";
		//_stack.print();
	}
    return _temString;
}