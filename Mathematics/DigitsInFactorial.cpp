//https://practice.geeksforgeeks.org/problems/digits-in-factorial/1/?track=DSASP-Mathematics&batchId=154

//TC - O(n)
//SC - O(1)

#include<iostream>
#include<math.h>
using namespace std;

class Solution{
    public:
   
    
    int digitsInFactorial(int N)
    {
        double sum = 0;
        for(int i = 1; i <= N; i++)
            sum = sum + log10(i);
            
        return floor(sum) + 1;
    }
};