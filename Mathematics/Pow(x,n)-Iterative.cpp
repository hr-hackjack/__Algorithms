//TC - O(n)
//TLE dega

#include<iostream>
using namespace std;

int myPow(int x, int n)
{
    int res = 1;
    for(int i = 1; i<=n; i++)
    {
        res = res*x;
    }
    return res;
}