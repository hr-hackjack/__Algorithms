#include<iostream>
using namespace std;

class stack
{
    public : 

    int *arr;
    int size;
    int top;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)     // TC - O(1)
    {
        if(size-top > 1)
        {
            top++;
            arr[top] = data;
        }

        //we are checking overflow condition because we have given c certain
        //size to our stack. It is not dynamic
        else
            cout <<"Stack overflow";
    }

    int pop()     // TC - O(1)
    {
        if(top >= 0)
        {
            int res = arr[top];
            top--;
            return res;
        }
        else
            return -1;
    }

    int peek()     // TC - O(1)
    {
        if(top >= 0)
            return arr[top];

        else
        {
            cout <<"Stack is empty " <<endl;
            return -1;
        }
      
    }

    bool empty()     // TC - O(1)
    {
        if(top == -1)
            return true;

        else
            return false;
    }

    int sizeOfStack()     // TC - O(1)
    {
        return (top+1);
    }

};

int main()
{
    stack st(5);

    st.push(43);
    st.push(44);
    st.push(22);

    cout << "Peak is : "<<st.peek() <<endl;

    st.pop();
    cout << "Peak is : "<<st.peek() <<endl;

    cout << "Size of stack is : " <<st.sizeOfStack() <<endl;

    st.pop();
    cout << "Peak is : "<<st.peek() <<endl;

    st.pop();
    cout << "Peak is : "<<st.peek() <<endl;

    if(st.empty())
        cout <<"Stack is empty"<<endl;

    st.pop();

    cout << "Size of stack is : " <<st.sizeOfStack() <<endl;

}