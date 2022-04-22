//https://practice.geeksforgeeks.org/problems/factorial5739/1#

//TC - O(n)

// { Driver Code Starts
//Initial Template for C

#include<iostream> 

long long int factorial(int N){
       
       long long int fact = 1;
       for(int i = N; i>=1; i--)
       {
           fact = fact*i;
       }
       return fact;
}

