//variation of stock span problem

#include<bits/stdc++.h>
using namespace std;

//Naive method
//TC - O(n^2)
/*
class Solution
{
    public:
    //Function to calculate the span of stocks price for all n days.
    vector <int> previousGreaterElement(int arr[], int n)
    {
       vector<int> ans;
       for(int i = 0; i< n; i++)
       {
           for(int j = i-1; j>=0; j++)
           {
                if(arr[j] > arr[i])
                {
                    ans.push_back(arr[j]);
                    break;
                }
                else
                {
                    ans.push_back(-1);
                    break;
                }
                    
           }
       }
       return ans;
       
    }
};
*/

//Efficient approach - TC - O(n)

class Solution
{
    public:
    //Function to calculate the span of stocks price for all n days.
    vector <int> previousGreaterElement(int arr[], int n)
    {
       // Create a stack and push index of first
       // element to it
       stack<int> s;
       s.push(arr[0]);
       vector<int> ans;
       // Previous greater value of first element is always -1
       ans.push_back(-1);
       
       // Traverse rest of the elements

       for(int i = 1; i<n;i++)
       {
            // Pop elements from stack while stack is not
            // empty and top of stack is smaller than
            // arr[i].
            // We always have elements in decreasing order in a
            // stack.
            while(!s.empty() && s.top() < arr[i])
                s.pop();
             
            // If stack becomes empty, then no element is greater
            // on left side. Else top of stack is previous
            // greater.
            int greater = s.empty() ? -1 : s.top();
            // Push this element to stack
            s.push(arr[i]);
            ans.push_back(greater);
       }
       
       return ans;
       
    }
};
   