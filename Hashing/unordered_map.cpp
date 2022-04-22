//unordered_map is also built using hashing
//it is used to store key value pair
//elements in map are random in order

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<int,int> m;

    //method 1 to insert in map
    m.insert({10,263});
    //method 2 to insert in map
    m[20] = 400;
    m.insert({5,24});

    for(auto i : m)
    {
        cout << i.first << " "<<i.second <<endl;
    }

    //trying to insert key value pair with an already inserted key
    m.insert({20,50});

    
    cout<<"-----------------------------------------------------";
    cout<<endl;
    cout <<"Duplicate key is ignored : ";
    for(auto i : m)
    {
        cout << i.first << " "<<i.second <<endl;
    }

    
    cout<<"----------------------------------------------------";
    cout<<endl;
    //difference between insert and [] methods for inserting in map

    unordered_map<int,int> n;
    n.insert({10,200});
    cout << n.size() <<endl;

    //if you try to access an element using map_name[key] which is not present
    //in the map, then this will insert the element with that key
    //and value will be default value for that data type
    //in this example value will be 0.
    cout << "Value at key 20 is : " << n[20] <<endl;
    cout << n.size() <<endl;

    //[] can also be used for updating value. It is a member access operator
    n[10] = 300;
    //at() also does the work of accessing or updation
    //but if that key is not present in the map, then it does 
    //not insert that key in the map unlike the [] operator
    //trying to access a key using at() when it is not present in map
    //will throw an "out of range" error
    n.at(10) = 400;

    cout<<"----------------------------------------------------"<<endl;
    cout<<"Traversing using begin() and end() : "<<endl;
    for(auto i = m.begin(); i != m.end(); i++)
    {
        cout << (*i).first <<" " <<(*i).second <<endl;
    }
    cout<<endl;
    cout<<"----------------------------------------------------"<<endl;
    //clear() removes all element of set
    cout << "Size of t before clear : " <<m.size() <<endl;
    m.clear();
    cout <<"Size of t after clear : "<<m.size() ;

    cout<<endl;
    cout<<"----------------------------------------------------"<<endl;
    
    //find() : works on key not on the value
    unordered_map<int,string> o;
    o.insert({5,"gfg"});
    o.insert({2,"ide"});
    o.insert({1,"practice"});

    if(o.find(5) == o.end())
        cout <<"Not found" <<endl;

    else
        cout <<"Found" <<endl;

    //count() tells about the occurence of element in map
    //but in map it will be either 1(when element is present) or 0(when it is absent)
    //hence count can be used as find function
    //only difference is find returns iterator and count returns 1 or 0



}