/**
 * Given an array A[1,...,n] of n numbers and an index i, where 1 ≤ i ≤ n, find the i-th smallest element of A.
 * median_of_medians(A, i):
 *  #divide A into sublists of len 5
 *  sublists = [A[j:j+5] for j in range(0, len(A), 5)]
 *  medians = [sorted(sublist)[len(sublist)/2] for sublist in sublists]
 *  if len(medians) <= 5:
 *	pivot = sorted(medians)[len(medians)/2]
 *  else:
 *      #the pivot is the median of the medians
 *      pivot = median_of_medians(medians, len(medians)/2)
 *  #partitioning step
 *  low = [j for j in A if j < pivot]
 *  high = [j for j in A if j > pivot]
 *  k = len(low)
 *   if i < k:
 *      return median_of_medians(low,i)
 *   elif i > k:
 *      return median_of_medians(high,i-k-1)
 *  else: #pivot = k
 *       return pivot
 *
 * \note this algorithm implements median search for only arrays which have distinct elements
 *
 * Here are some example lists you can use to see how the algorithm works
 * A = [1,2,3,4,5,1000,8,9,99] (Contain Unique Elements)
 * B = [1,2,3,4,5,6] (Contains Unique Elements)
 * print median_of_medians(A, 0) #should be 1
 * print median_of_medians(A,7) #should be 99
 * print median_of_medians(B,4) #should be 5
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

namespace search {

namespace median_search {

int median_of_medians(const vector<int>& A,  const int& idx) {
	int pivot = 0;					// initialized with zero
	vector<int> a(A.begin(), A.end());
	vector<int> m;
	int r = a.size();
	for(int i = 0; i < r; i += 5){
		sort(a.begin() + i, a.begin() + min(r, i + 5));
		int mid = (i + min(r, i + 5)) / 2;
		m.push_back(a[mid]);
	}
	int sz = int(m.size());
	if(sz <= 5){
		sort(m.begin(), m.end());
		pivot = m[(sz- 1) / 2];
	}
	else{
		pivot = median_of_medians(m, idx);
	}
	vector<int> low;
	vector<int> high;
	for(int i = 0; i < r; i++){
		if(a[i] < pivot){
			low.push_back(a[i]);
		}
		else if(a[i] > pivot){
			high.push_back(a[i]);
		}
	}
	int k = int(low.size());
	if(idx < k){
		return median_of_medians(low, idx);
	}
	else if(idx > k){
		return median_of_medians(high, idx-k-1);
	}
	else{
		return pivot;
	}
}
}  // namespace median_search
}  // namespace search

/**
 * Function to test above algorithm
 */
void test(){
	vector<int> A{25,21,98,100,76,22,43,60,89,87};
	int i = 3;
	assert(A[6] == search::median_search::median_of_medians(A, i));		// A[6]  = 43, is the fourth smallest element.
	cout << "test case:1 passed\n";
	
	vector<int> B{1,2,3,4,5,6};
	int j = 4;
	assert(B[4] == search::median_search::median_of_medians(B, j));		// B[4] = 5, is the fifth smallest element.
	cout << "test case:2 passed\n";
	
	vector<int> C{1,2,3,4,5,1000,8,9,99};
	int k = 3;
	assert(C[3] == search::median_search::median_of_medians(C, k)); 	// C[3] = 4, is the fourth smallest element.
	cout << "test case:3 passed\n";
	cout << "--All tests passed--\n";
}

/**
 * Main function
 */
int main()
{
	test();
	int n = 0;
	cout << "Enter Size of Array: ";
	cin >> n;
	vector<int> a(n);
	cout << "Enter Array: ";
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << "Median: ";			// Median defination: https://en.wikipedia.org/wiki/Median
	int x = search::median_search::median_of_medians(a,  (n - 1) / 2);
	if(n % 2 == 0){
		int y = search::median_search::median_of_medians(a, n / 2);
		cout << (float(x) + float(y))/2.0;
	}
	else{
		cout << x;
	}
	cout << "\nTo find i-th smallest element ";
       	cout << "\nEnter i: ";
	int idx = 0;
	cin >> idx;
	idx--;
	cout << idx + 1<< "-th smallest element: " << search::median_search::median_of_medians(a, idx) << '\n';
	return 0;
}

