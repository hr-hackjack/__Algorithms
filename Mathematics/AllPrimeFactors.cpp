//https://practice.geeksforgeeks.org/problems/prime-factors5052/1

//TC - O(root n)
//SC - O(n) -  coz we used a set

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	
	vector<int>AllPrimeFactors(int N) {
	    
	    set<int> s;
	    
	    while(N%2==0)
	   {
	       s.insert(2);
	       N = N/2;
	   }
	   
	   while(N%3==0)
	   {
	       s.insert(3);
	       N = N/3;
	   }
	   
	  
	    for(int i = 5; i<= sqrt(N); i=i+6)
	    {
	        while(N%i == 0)
	        {
	            
	               s.insert(i);
	               N/=i;
	        }
	        
	        while(N%(i+2)==0)
	        {
	            s.insert(i+2);
	            N/=(i+2);	        }
	    }
	    
	    if(N>3)
	        s.insert(N);
	    
	    vector<int> ans;
	    for(auto i : s)
	    {
	        ans.push_back(i);
	    }
	    
	    return ans;
	}
};
