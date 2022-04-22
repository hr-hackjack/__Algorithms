//https://leetcode.com/problems/powx-n/

//TC - O(log n)
//S C- O(log n)

#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0)
            return 1;
        
        if(n<0){
            n = abs(n);
            x = 1/x;
        }
        
        double temp = myPow(x, n/2);
        temp = temp * temp;
        
        if(n%2 == 0)
            return temp;
        else
            return temp * x;
        
    }
};