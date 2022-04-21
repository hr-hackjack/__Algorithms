//ceiling on left is the smallest greater element on the left side
//i/p : 2   8   30  15  25  12
//o/p : -1  -1  -1  30  30  15

//TC - O(n^2)
//SC - O(1)

#include<iostream>
#include<limits.h>
#include<set>

using namespace std;

void printCeiling(int arr[], int n)
{
    //for first element ceiling will be -1
    cout <<"-1";

    for(int i = 1; i<n; i++)
    {
        int diff = INT_MAX;
        for(int j = 0; j<i; j++)
        {
            if(arr[j] >= arr[i])
                diff = min(diff, arr[j]-arr[i]);
        }

        if(diff == INT_MAX)
            cout<<"-1";

        else
            cout<<arr[i]+diff;
    }
}

//Efficient approach
//TC - O(nlogn)
//SC - O(n)

void printCeiling_2(int arr[],int n)
{
   
    //create a bst
    set<int> s;
    for(int i = 0; i<n; i++)
    {
        auto it = s.lower_bound(arr[i]);
        if(it == s.end())
            cout << "-1 ";
        
        else
            cout << *it;

        //element add krte ja rhe hai set me 
        //so that next element ka comparison krne k liye set
        //me elements ho
        s.insert(arr[i]);
    }
}