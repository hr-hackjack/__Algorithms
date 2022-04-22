//TC is O(1) for all operation

#include<iostream>
using namespace std;

class Node
{
    public : 

    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    
};

class Stack
{
    public : 
        Node* head;
        int sz;
        
        Stack()
        {
            head = NULL;
            sz = 0;
        }

        //push
        void push(int data)
        {
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
            sz++;
        }
               
        //pop
        int pop()
        {
            if(head == NULL)
            {
                cout <<"Stack underflow "<<endl;
                return -1;
            }

            int res = head->data;
            Node* temp = head;
            head = head->next;
            delete(temp);
            sz--;
            return res;

        }


        //peak
        int peak(Node* &head, Node* &tail)
        {
            if(head==NULL)
                return -1;

            else
                return head->data;
        }

        int size()
        {
            return sz;   
        }

        //isEmpty
        bool empty(Node*head)
        {
            if(head ==NULL)
                return true;

            else
                return false;
        }

};