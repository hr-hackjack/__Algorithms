//https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

//This brute force approach does not work for large no. like 100 becoz its factorial
//will have 158 digits which is out of range of long long int

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> factorial(int N){
        
        long long int fact = 1;
        vector<int> ans;
        int digit;
        for(int i = N; i>=1; i--)
        {
            fact = fact*i;
        }
        
        while(fact)
        {
            digit = N%10;
            ans.push_back(digit);
            N = N/10;
        }
        
        
        return ans;
    }
};