//Implement stack using vector coz we want stack to be dynamic

#include<iostream>
#include<vector>
using namespace std;

class stack
{
    public : 

    vector<int> v;

    void push(int data)     // TC - O(1)
    {
        v.push_back(data);
    }

    int pop()     // TC - O(1)
    {
        //vector has two functions. front() gives first item of vector
        //back() gives last item of vector
        if(v.empty())
        {
            cout <<"Stack underflow"<<endl;
            return -1;
        }
            
        int res = v.back();
        v.pop_back();
        return res;
        
    }

    int peek()     // TC - O(1)
    {
        if(v.empty())
        {
            cout <<"Stack underflow"<<endl;
            return -1;
        }
        return v.back();
    }

    bool isEmpty()     // TC - O(1)
    {
        return v.empty();
    }

    int sizeOfStack()     // TC - O(1)
    {
        return v.size();
    }

};

int main()
{
    stack st;

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

    if(st.isEmpty())
        cout <<"Stack is empty"<<endl;

    st.pop();

    cout << "Size of stack is : " <<st.sizeOfStack() <<endl;

}