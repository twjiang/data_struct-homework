void toFloat(float array[], string mystring)
{
    string tempstring;
    int lg = 0;                //保存整数部分的位数
    int k;
    string::iterator itr = mystring.begin();
    int j = 0;
    while(itr != mystring.end())
    {

        if(*itr >= '0' && *itr <= '9')
        {
            while(*itr >= '0' && *itr <= '9')
            {
                tempstring.append(1, *itr);
                lg++;
                itr++;
            }
            if(*itr == '.')
            {
                tempstring.append(1, *itr);
                itr++;
                while(*itr >= '0' && *itr <= '9')
                {
                    tempstring.append(1, *itr);
                    itr++;
                }
            }
        }
        if(lg != 0)
        {
            j++;
            itr--;
            for(k = 0; k < tempstring.length(); )
            {
                if(tempstring[k] != '.')
                {
                    array[j] += (tempstring[k] -48) * pow(10, lg - 1);
                    k++;
                    lg--;
                }
                else
                {
                    k++;
                }    
            }
            lg = 0;
        } 
        tempstring.clear();
        itr++;  
    }
}