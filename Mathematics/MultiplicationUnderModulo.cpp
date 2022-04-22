//https://practice.geeksforgeeks.org/problems/multiplication-under-modulo/1/?track=DSASP-Mathematics&batchId=154

//TC - O(1)
//SC - O(1)

#include<iostream>
#include<math.h>
using namespace std;

class Solution{
    public:
        int multiplicationUnderModulo(long long a,long long b)
    {
        long long int M = pow(10,9)+7;
        return ((a%M) * (b%M))%M;
    }
};