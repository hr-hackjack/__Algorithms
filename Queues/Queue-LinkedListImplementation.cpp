/*
If I dont use two pointer then TC will be O(1) for enqueue but O(n) for dequeue
So use two pointer

All operations here have O(1) time complexity

*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public : 
    int data;
    Node *next;
    
    Node(int x)
    {
        this->data = x;
        next = NULL;
    }
};
class Queue {
public:
    
    Node *qfront;
    Node *rear;
    int size;
    
    Queue() {
        
        qfront = NULL;
        rear = NULL;
        size = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == NULL && rear == NULL)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        
        Node *temp = new Node(data);
        size++;
        if(qfront == NULL)
        {
            qfront = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    int dequeue() {
        
        if(qfront == NULL)
            return -1;
        
        Node *temp = qfront;
        qfront = qfront->next;

        //how do we know ki ab last element bcha hai
        //ans is if we deleted current front and moved front further
        //now if we find that front points to NULL
        //it means that we deleted the only remaining last element
        
        //corner case when we delete last item
        //at that time it has both front and rear pointer
        //so we have to change rear to NULL
        if(qfront == NULL)
            rear = NULL;
        
        int ans = temp->data;
        temp->next = NULL;
        delete(temp);
        size--;
        return ans;
        
    }

    int front() {
        
        if(qfront == NULL)
            return -1;
        
        else 
            return qfront->data;
    }

    int getSize()
    {
        return size;
    }

    int getFront()
    {
        return qfront->data;
    }

    int getRear()
    {
        return rear->data;
    }
};