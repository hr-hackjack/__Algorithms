//https://practice.geeksforgeeks.org/problems/queue-reversal/1

//Approach 1 - Did by myself
//Copy all elements of queue in stack, coz stack has a property to reverse anything put inside it
//Then again copy that into the queue.
//TC - O(n)
//SC - O(n)

#include<bits/stdc++.h>
using namespace std;

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    stack<int> s;
    while(!q.empty())
    {
        int num = q.front();
        s.push(num);
        q.pop();
    }
    
    //queue<int> ans;
    while(!s.empty())
    {
        int num = s.top();
        q.push(num);
        s.pop();
    }
    
    return q;
}

//Approach 2 - Using recursion
//TC - O(n)
//SC - O(n)

/*

queue<int> rev(queue<int> q)
{
    //base case
    if(q.empty())
       return q;
       
    int num = q.front();
    q.pop();
    
    //i made mistake here. i was simply writing rev(q).
    q = rev(q);
    q.push(num);
    return q;
    
}

*/