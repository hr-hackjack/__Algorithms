//https://practice.geeksforgeeks.org/problems/gp-term/1/?track=DSASP-Mathematics&batchId=154

//TC - O(1)
//SC - O(1)

#include<iostream>
#include<math.h>
using namespace std;

class Solution{
    public:
        //Complete this function
    double termOfGP(int A,int B,int N)
    {
        double R = (double)B/A;
        double ans = pow(R,N-1);
        
        return floor(A*ans);
    }
};