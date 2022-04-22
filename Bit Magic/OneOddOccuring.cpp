/*
    i/p : arr[] = {4,3,4,4,4,5,5}
    o/p : 3
*/

//method 1 
//TC - O(n^2)
//SC - O(1)

#include<iostream>
using namespace std;

int main()
{
    int arr[] = {3,3,4,4,4,5,4};
    
    for(int i =0; i<7; i++)
    {
        int count = 0;
        for(int j=0; j<7;j++)
        {
            if(arr[j]==arr[i])
                count++;
        }

        if((count%2) != 0)
            cout<< arr[i] <<endl;
    }
}

// Method 2 - It also works in any case odd occurence is any other odd no.
//TC -O(n)
//SC -O(1)

/*

#include<iostream>
using namespace std;
int main()
{
    int arr[] = {4,3,4,4,4,5,5};
     int ans = 0;
    for(int i =0; i<7; i++)
    {
       ans = ans ^ arr[i];
    }
    cout << ans <<endl;
}

*/