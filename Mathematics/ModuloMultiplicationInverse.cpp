//https://practice.geeksforgeeks.org/problems/modular-multiplicative-inverse-1587115620/1/?track=DSASP-Mathematics&batchId=154

//TC - O(m)
//SC - O(1)

#include<iostream>
#include<math.h>
using namespace std;

class Solution{
    public:
    //Complete this function
    int modInverse(int a, int m)
    {
        int ans = -1;
        for(int i = 1; i<m; i++)
        {
            if((i*a)%m == 1)
                ans = i;
        }
        return ans;
    }
};