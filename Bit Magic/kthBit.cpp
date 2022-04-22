// Check if kth bit is set bit or not

// Solution 1 -  using left shift
#include<iostream>
using namespace std;
void kthBit(int x, int k)
{
    if((x & (1<<(k-1))) != 0)
        cout<<"Yes" << endl;
    else
        cout<<"No" << endl;
}
int main()
{
    int x = 1;
    int k = 2;
    kthBit(x,k);
    return 0;
}

//Solution 2 - Using right shift

/*
#include<iostream>
using namespace std;
void kthBit(int x, int k)
{
    if(((x>>(k-1)) & 1) == 1)
        cout<<"Yes" << endl;
    else
        cout<<"No" << endl;
}
int main()
{
    int x = 2;
    int k = 2;
    kthBit(x,k);
    return 0;
}

*/