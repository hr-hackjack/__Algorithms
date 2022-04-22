//unordered_set container is built using hashing
//used to store distinct keys
//elements in unordered_set are stored in random order

#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);

    cout <<"Printing set in any order"<<endl;
    for(auto i: s)
    {
        cout << i <<" ";
    }
    cout<<endl;
    cout<<"----------------------------------------------------"<<endl;
    
    //Another style of traversal
    //s.begin - points to first element
    //s.end - points to place after the last element

    cout<<"----------------------------------------------------"<<endl;
    cout<<"Traversing using begin() and end() : "<<endl;
    for(auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i <<" ";
    }
    cout<<endl;

    cout<<endl;
    //Inserting duplicate values in set is not allowed.
    s.insert(5);
    s.insert(10);
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Trying to insert duplicate element : "<<endl;
    for(auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i <<" ";
    }

    cout<<endl;
    cout<<"----------------------------------------------------"<<endl;
    //Finding element in set using find()
    //If the element is found, iterator points to that element
    //else it points to end() which is place after the last element of set

    auto it = s.find(10);
    if(it == s.end())
        cout<<"Not Found"<<endl;

    else
        cout<<"Found" <<endl;

    cout<<"----------------------------------------------------"<<endl;
    //clear() removes all element of set
    cout << "Size of s before clear : " <<s.size() <<endl;
    s.clear();
    cout <<"Size of s after clear : "<<s.size() ;

    //count() tells about the occurence of element in set
    //but in set it will be either 1(when element is present) or 0(when it is absent)
    //hence count can be used as find function
    //only difference is find returns iterator and count returns 1 or 0

    cout<<endl;   
    cout<<"----------------------------------------------------"<<endl;
    if(s.count(10))
        cout <<"Found";
    else
        cout <<"Not found";

    cout<<endl;   
    cout<<"----------------------------------------------------"<<endl;
    // erase is used to remove an element or group of element from set

    unordered_set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(2);
    s1.insert(4);

    cout<<"Printing before erase : "<<endl;
    for(auto i = s1.begin(); i != s1.end(); i++)
    {
        cout << *i <<" ";
    }
    cout<<endl;
    s1.erase(2);
    cout<<"Printing after erase : "<<endl;
    for(auto i = s1.begin(); i != s1.end(); i++)
    {
        cout << *i <<" ";
    }
    cout <<endl;
    //another way of erasing using iterator
    auto itr = s1.find(30);
    s1.erase(itr);
    for(auto i = s1.begin(); i != s1.end(); i++)
    {
        cout << *i <<" ";
    }

    s1.insert(36);
    s1.insert(45);
    s1.insert(56);

    cout<<endl;   
    cout<<"----------------------------------------------------"<<endl;
    
    //Erasing range of element that begins from iterator and end at end()
    cout <<"Erasing the range of elements :"<<endl;
    itr = s1.find(45);
    s1.erase(itr,s1.end());
    for(auto i = s1.begin(); i != s1.end(); i++)
    {
        cout << *i <<" ";
    }

    
}