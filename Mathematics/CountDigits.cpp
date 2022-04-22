//TC - O(count)

#include <iostream>
#include<math.h>
using namespace std;

//Iterative solution
int count(int n)
{
    if(n == 0)
        return 1;
        
    int count = 0;
    int digit;
    while(n)
    {
        n = n/10;   
        count++;
    }
    return count;
}

//Recursive solution
int count2(int n)
{
    //base case
    if(n/10 == 0)
        return 1;

    return 1 + count2(n/10) ;

}

//Logarithmic solution
//TC - O(1)

int count3(int n)
{
    return floor(log10(n) + 1);
}

int main() {
	
	cout <<"Enter number "<<endl;
	int num;
	cin>>num;
	
	int ans = count3(num);
	cout <<"No. of digits is : "<<ans;
	
	return 0;
}