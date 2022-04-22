
//check if the no. n is power of 2 or not
// i/p : 4
// o/p : yes

//TC - theta(no. of bits)

//all these solution give runtime error for -2^31 -1. It gives integer overflow on leetcode
//you can use method 4 to tackle it because you cant change input type on leetcode
//or you can put a condition where you return false if no. is <=0


#include<iostream>
using namespace std;
int main()
{
    cout <<"Enter a number : "<<endl;
    int n;
    cin >> n;
    int count = 0;
    while(n!=0)
    {
        if(n&1)
            count++;
        
        n=n>>1;
    }
    if(count==1)
        cout << "Yes"<<endl;
    else
        cout << "No"<<endl;

}

/*

better solution - brian kerningam algoritm
TC - Theta(no. of set bits)

#include<iostream>
using namespace std;
int main()
{
    cout <<"Enter a number : "<<endl;
    int n;
    cin >> n;
    int count = 0;
    while(n)
    {
        n= n & (n-1);
        count++;
    }
    if(count==1)
        cout << "Yes"<<endl;
    else
        cout << "No"<<endl;

}

*/

// method 3 - most efficient
//TC - O(1)
/*
#include<iostream>
using namespace std;
int main()
{
    cout <<"Enter a number : "<<endl;
    int n;
    cin >> n;

    if(n==0)
        cout << "false";
    if((n & (n-1)) == 0)
        cout << "true";
    else 
        cout << "false";
}
*/

//method 4
/*

#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int ans = 0;
        for(int i =0; i<=30; i++)
        {
            ans = pow(2,i);
            if(ans == n)
                return true;
        }
        return false;
    }
};

*/