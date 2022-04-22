//https://practice.geeksforgeeks.org/problems/lcm-and-gcd4516/1?msclkid=9431d2cfabdc11ec9d8e5f1d4cfa136b

//TC - O(log(min(a,b)))
//eucledian algo

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    long long gcd(long long A, long long B)
    {
        if(B == 0)
            return A;
            
        return gcd(B,A%B);
    }
    
    long long lcm(long long A, long long B)
    {
        long long res = A*B;
        
        return (res/gcd(A,B));
        
    }
    
    vector<long long> lcmAndGcd(long long A , long long B) {
        
        vector<long long> ans;
        
        long long LCM = lcm(A,B);
        ans.push_back(LCM);
        
        long long GCD = gcd(A,B);
        ans.push_back(GCD);
        
        return ans;
    }
};
