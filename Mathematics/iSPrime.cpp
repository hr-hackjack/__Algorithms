//https://practice.geeksforgeeks.org/problems/prime-number2314/1#

//brute force approach : gives TLE
//TC - O(n)

#include<iostream>
using namespace std;

class Solution{
public:
    int isPrime(int N){
        
        if(N == 1)
            return 0;
            
        if(N == 2)
            return 1;
            
        for(int i = 2; i<N; i++)
        {
            if(N%i == 0)
                return 0;
        }
        return 1;
    }
};

//Optimised approach
//TC - O(n^1/2)

/*

class Solution{
public:
    int isPrime(int N){
        
        if(N == 1)
            return 0;
        
        if(N==2 || N==3)
            return 1;
            
        if(N%2 == 0 || N%3 == 0)
            return 0;
        for(int i = 5; i<=sqrt(N); i=i+6)
        {
            if(N%i == 0 || N%(i+2)==0)
                return 0;
        }
        return 1;
    }
};


*/

