/*
i/p : "abc"
o/p : "", "a","b","c","ab","bc","ca","abc"

Decimal counter goes from 0 to 2^n-1

Counter(Decimal)        counter(binary)         subset
-------------------------------------------------------
    0                       000                   ""
    1                       001                   "a"
    2                       010                   "b"
    3                       011                   "ab"
    4                       100                   "c"
    5                       101                   "ac"
    6                       110                   "bc"
    7                       111                   "abc"

TC - Theta(2^n * (n))

*/

#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

void powerSet(string &str)
{
    int n = str.length();
    int powSize = pow(2,n);

    for(int counter =0; counter<powSize; counter++)
    {
        for(int j =0; j<n; j++)
        {
            if((counter & (1<<j)) != 0)
                cout << str[j];
        }
        cout <<" ";
    }
}

int main()
{
   string str; 
   cout <<"Enter a string"<<endl;
   cin>>str;

   powerSet(str);

}

