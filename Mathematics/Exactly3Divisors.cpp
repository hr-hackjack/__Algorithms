//https://practice.geeksforgeeks.org/problems/exactly-3-divisors/1/?track=DSASP-Mathematics&batchId=154

//TC - O(sqrt(n)* sqrt(n))
//SC - O(1)

#include<iostream>
using namespace std;

class Solution{
    public:
    
    bool isPrime(int N)
    {
        if(N==1)
        return false;
        if(N==2 || N==3)
        return true;
        if(N%2==0 || N%3==0)
        return false;
        for(int i=5; i*i<=N;i=i+6)
            if(N%i==0 || N%(i+2)==0)
                return false;
        return true;
        
    }
    
    int exactly3Divisors(int N)
    {
        //Your code here
        int count=0;
        for(int i=2; i*i<=N;i++)
        {
            if(isPrime(i))
            {
                if(i*i<=N)
                count++;
            }
        }
        return count;
    }
};