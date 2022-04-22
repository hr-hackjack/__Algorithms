// Count no. of set bits in a given no.

// Solution 1 - Naive method (using right shift operator)
//TC  - Theta(total bits in n)


#include<iostream>
using namespace std;
int countSetBits(int n)
{
    int count = 0;
    while(n)
    {
        if(n & 1)				//if(n % 2!= 0)
        {
           count++; 
        }
        n = n>>1;				//n=n/2
    }
    return count;
}
int main()
{
    int x = 10;
    int ans = countSetBits(x);
    cout << "No. of set bits "<< ans <<endl;
    return 0;
}

//Solution 2 - Brian Kerningam’s algorithm
//TC – Theta(set bit counts)

/*
#include<iostream>
using namespace std;
int countSetBits(int n)
{
    int count = 0;
    while(n)
    {
        n = n & (n-1);		main logic. one by one turns off the last set bit from right to left
        count++;
    }
    return count;
}
int main()
{
    int x = 40;
    int ans = countSetBits(x);
    cout << "No. of set bits "<< ans <<endl;
    return 0;
}

*/
