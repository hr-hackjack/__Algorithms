/*
Left Shift Operator

If we assume that leading y bits are 0 then result of 
(x<<y) is equivalent to x*2^y
*/


/*
Right Shift Operator

If we assume that leading y bits are 0 then result of 
(x>>y) is equivalent to floor(x/(2^y))
*/


#include<iostream>
using namespace std;
int main()
{
    int x = 4;
    cout << (x<<1) <<endl;
    cout << (x<<2) <<'\n'<<endl;
    
    int y = 4;
    int z = (x<<y);
    cout << z<<"\n\n"<<endl;
    

    int a = 32;
    cout << (a>>1) <<endl;
    cout << (a>>2) <<'\n'<<endl;
    
    int b = 4;
    int c = (a>>b);
    cout << c;
    

    return 0;
}
