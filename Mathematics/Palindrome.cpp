//https://practice.geeksforgeeks.org/problems/palindrome0746/1?msclkid=1f791816a98711ecb4b0e5be563b7624#

//TC - O(digits)

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    int num  = n;
		    int ans = 0;
		    int digit=0;
		    
		    while(num)
		    {
		       digit = num%10;
		       ans  = ans*10 + digit;
		       num = num/10;
		    }
		    
		    
		    
		    if(ans == n)
		        return "Yes";
		        
		    else
		        return "No";
		        
		}
};
