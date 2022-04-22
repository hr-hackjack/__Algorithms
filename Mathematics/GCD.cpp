//https://practice.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1?msclkid=ef696aa8aa9611ec847fc0e539e1b83c

//Brute force
//TC - O(min(a,b))
//gives tle

#include<iostream>
using namespace std;

class Solution
{
	public:
    int gcd(int A, int B) 
	{ 
	    // code here
	    int res = min(A,B);
	    
	    while(res > 0)
	    {
	        if(A%res == 0 && B%res==0)
	            break;
	            
	        res--;
	    }
	    
	    return res;
	      
	} 
};

//Eucledian algo - recursive
//TC - O(log(min(a,b)))

/*

if(B==0)
        return A;
    return gcd(B,A%B);
    
*/

/*

Eucledian algo - iterative

int gcd(int a, int b)
{
    if(a==0)
        return b;

    if(b==0)
        return a;

    while(a!=b)
    {
        if(a>b)
            a = a-b;

        else
            b = b-a;
    }
    return a;
}


*/

