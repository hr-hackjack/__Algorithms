/*
Given an array of n number that has values in range [1...n+1]. Every no. appears
exactly once. Hence one number is missing. Find that missing no.

i/p: arr[] = {1,4,3}
o/p: 2

Approach - do xor of all the no. from 1 to n+1 and then xor of result with the array
you will get the answer. Every no. will appear twice except the missing no. It will appear only once

*/

#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,4,5};
    int res = 0;
    for(int i = 1; i<=5;i++)
    {
        res = res^i;
    }
    for(int i = 0; i<4; i++)
    {
        res = res^arr[i];
    }
    cout <<"Missing no. is : "<<res<<endl;
}