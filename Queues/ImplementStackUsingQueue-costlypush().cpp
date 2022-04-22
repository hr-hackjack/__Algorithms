//https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1
//Implement stack using two queues

//Method 1 
//push operation is costly

#include<bits/stdc++.h>
using namespace std;

class stack
{
    public : 

    queue<int> q1, q2;

    int top()
    {
        return q1.front();
    }

    int size()
    {
        return q1.size();
    }

    int pop()
    {
        if(q1.empty())
        return -1;
    
        else
        {
            int ans = q1.front();
            q1.pop();
            return ans;
        }
    }

    //main challenge arise for push operation
    //because in stack we push from top (lets say front)
    //but in queue we push from rear

    void push(int x)
    {
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
};