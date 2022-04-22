//https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial5134/1

//TC - O(log n)  - coz 5 se multiply ho raha hai i har iteration me
//SC - O(1)

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    int trailingZeroes(int N)
    {
        // Write Your Code here
        int res = 0;
        for(int i = 5; i<= N; i=i*5)
        {
            res = res + N/i;
        }
        return res;
    }
};
