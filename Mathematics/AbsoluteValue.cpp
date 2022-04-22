//https://practice.geeksforgeeks.org/problems/absolute-value/1/?track=DSASP-Mathematics&batchId=154

//TC - O(1)

#include<iostream>
using namespace std;

class Solution{
    public:
        int absolute(int I) {
        
        if(I>=0)
            return I;
            
        else
        {
            return -I;
        }
    }

};