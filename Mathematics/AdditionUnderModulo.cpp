//https://practice.geeksforgeeks.org/problems/addition-under-modulo/1/?track=DSASP-Mathematics&batchId=154

//TC - O(1)
//SC - O(1)

#include<iostream>
#include<math.h>
using namespace std;

class Solution{
    public:
        long long sumUnderModulo(long long a,long long b)
    {
        int M = pow(10,9)+7;
        return ((a)%M + (b)%M)%M;
    }
};