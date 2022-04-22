/*
i/p : arr[] = {3,4,3,4,5,4,4,6,7,7}
o/p : 5 6
*/

//naive method
//TC - O(n^2)
//SC - O(1)

#include<iostream>
using namespace std;

int main()
{
    int arr[] = {3,4,3,4,5,4,4,6,7,7};
    
    for(int i =0; i<10; i++)
    {
        int count = 0;
        for(int j=0; j<10;j++)
        {
            if(arr[i]==arr[j])
                count++;
        }

        if((count%2) != 0)
            cout<< arr[i] <<" ";
    }
}

/*

Efficient method
TC - O(n)
SC - O(1)

// CPP code to find two odd occurring elements
// in an array where all other elements appear
// even number of times.

do dry run on this array = {3,4,3,4,8,4,4,3,7,7}

#include <bits/stdc++.h>
using namespace std;

void printOdds(int arr[], int n)
{
	// Find XOR of all numbers. All even appearing no. will cancel out themselves
	int res = 0;
	for (int i = 0; i < n; i++)
		res = res ^ arr[i];

	// Find a set bit in the XOR (We find
	// rightmost set bit here)
	int set_bit = res & (~(res - 1));

	// Traverse through all numbers and
	// divide them in two groups
	// (i) Having set bit set at same
	//	 position as the only set bit
	//	 in set_bit
	// (ii) Having 0 bit at same position
	//	 as the only set bit in set_bit
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		//group 1 which has last bit as set bit
		if (arr[i] & set_bit)
			x = x ^ arr[i];
		//group 2 which has last bit as zero
		else
			y = y ^ arr[i];
	}

	// XOR of two different sets are our
	// required numbers.
	cout << x << " " << y;
}

// Driver code
int main()
{
	int arr[] = { 2, 3, 3, 4, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printOdds(arr, n);
	return 0;
}




*/
