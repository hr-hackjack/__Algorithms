//https://practice.geeksforgeeks.org/problems/quadratic-equation-roots/1/?track=DSASP-Mathematics&batchId=154

//TC - O(1)
//SC - O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        
        vector<int> ans;
        int D = b*b - 4*a*c;
        if(D<0)
        {
            ans.push_back(-1);
            return ans;
        }
        else if(D==0)
        {
            double root = floor(-b / (2*a));
            ans.push_back(root);
            ans.push_back(root);
        }
        
        else
        {
            double root1 = floor((-b + sqrt(D))/(2*a));
            double root2 = floor((-b - sqrt(D))/(2*a));
            
            ans.push_back(max(root1,root2));
            ans.push_back(min(root1,root2));
        }
        
        
        return ans;
    }
};