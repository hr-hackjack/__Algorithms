/*
Span means no. of consecutive days on the left side including the current day which have values lesser that or equal to the current day
In input, the price of certain stock is given for n consecutive days. In output you have to tell span

i/p : 13,15,12,14,16,8,6,4,10,30
o/p : 1, 2, 1, 2, 5, 1, 1, 1, 4, 10 

*/

//Naive approach
//TC - O(n^2)
//It leads to TLE

/*

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> ans;
       for(int i = 0; i<n; i++)
       {
           int span = 1;
           for(int j = i-1; j >=0 && price[j] <= price[i]; j--)
           {
               span++;
           }
           ans.push_back(span);
       }
       return ans;
    }
};


  */

 //Efficient solution - using stack
 //TC - O(n)
//At first it looks like we are using two loops so TC will be quadratic but in reality we are doing
//push operations n times and pop operation atmost n times. TC of push and pop in stack is of constant time.
//So it total TC is O(n)

 //SC - O(n)
 //If arr is sorted in increasing order then we have i elements in stack at any point of time - O(n) when we come out loop
 //If arr is sorted in decreasing order then we have 1 element in stack at any point of time - O(1) when we come out of loop
 //so we take worst case complexity which is O(n)

 /*
Lets see some observation on below example

index :     0       1       2       3       4       5       6       7       8

i/p :       60      10      20      40      35      30      50      70      65
o/p :       1       1       2       3       1       1       6       8       1

We can observe that if there is greater element on left side then,

    span = Index of current element - Index of closest greater element of left

If there is no greater element on left the,

    span = Index of current element - (-1)
         = Index of current element + 1

So, we can calculate o/p using above formula

o/p :     (0+1)   (1-0)   (2-0)   (3-0)   (4-3)    (5-4)    (6-0)   (7+1)    (8-7)
 */

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stocks price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Create a stack and push index of first
       // element to it
       stack<int> s;
       s.push(0);
       vector<int> ans;
       // Span value of first element is always 1
       ans.push_back(1);
       
       // Calculate span values for rest of the elements

       for(int i = 1; i<n;i++)
       {
            // Pop elements from stack while stack is not
            // empty and top of stack is smaller than
            // price[i]
            while(!s.empty() && price[s.top()] <= price[i])
                s.pop();
             
            // If stack becomes empty, then price[i] is
            // greater than all elements on left of it,
            // i.e., price[0], price[1], ..price[i-1].  Else
            // price[i] is greater than elements after
            // top of stack   
            int span = s.empty() ? i+1 : i -s.top();
            // Push this element to stack
            s.push(i);
            ans.push_back(span);
       }
       
       return ans;
       
    }
};
