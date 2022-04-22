//https://practice.geeksforgeeks.org/problems/number-of-factors1435/1/

//count no. of divisor
//TC - O(root n)

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

class Solution{
public:
    int countFactors(int N){
        
        int count = 0;
        int i ;
        
        for(i = 1; i<=sqrt(N); i++)
        {
            if(N%i==0)
            {
                count++;
                if(i!=N/i)
                    count++;
            }
                
        }
        
        
        return count;
    }
};
