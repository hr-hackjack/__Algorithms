/**[Wiggle Sort Algorithm]
 * (https://leetcode.com/problems/wiggle-sort-ii/) Implementation
 *
 * Wiggle Sort sorts the array into a wave like array.
 * An array ‘arr[0..n-1]’ is sorted in wave form,
 * if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..
 *
 * arr = [1,1,5,6,1,4], after wiggle sort arr will become equal to [1,1,6,1,5,4]
 * arr = [2,8,9,1,7], after wiggle sort arr will become equal to [8,2,9,1,7]
 */

#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>  /// for io operations
#include <vector>
using namespace std;

namespace sorting {

namespace wiggle_sort {

/**
 *
 * Function used for sorting the elements in wave form.
 * Checking whether the even indexed elements are greater than
 * their adjacent odd elements.
 * Traversing all even indexed elements of the input arr.
 * If current element is smaller than the previous odd element, swap them.
 * If current element is smaller than the next odd element, swap them.
 *
 * arr input array (unsorted elements)
 *
 */
template <typename T>  // this allows to have vectors of ints, double, float,
                       // etc
                       vector<T> wiggleSort(const vector<T> &arr) {
    uint32_t size = arr.size();

    vector<T> out(
        arr);  // create a copy of input vector. this way, the original input
               // vector does not get modified. a sorted array is is returned.

    for (int i = 0; i < size; i += 2) {
        if (i > 0 && out[i - 1] > out[i]) {
            swap(out[i], out[i - 1]);  // swapping the two values
        }

        if (i < size - 1 && out[i] < out[i + 1]) {
            swap(out[i], out[i + 1]);  // swapping the two values
        }
    }

    return out;  // returns the sorted vector
}
}  
}  

template <typename T>
static void displayElements(const vector<T> &arr) {
    uint32_t size = arr.size();

    cout << "Sorted elements are as follows: ";

    cout << "[";

    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

static void test() {
    srand(time(nullptr));  // initialize random number generator

    vector<float> data1(100);
    for (auto &d : data1) {  // generate random numbers between -5.0 and 4.99
        d = float(rand() % 1000 - 500) / 100.f;
    }

    vector<float> sorted = sorting::wiggle_sort::wiggleSort<float>(data1);

    displayElements(sorted);

    for (uint32_t j = 0; j < data1.size(); j += 2) {
        assert(data1[j] <= data1[j + 1] &&
               data1[j + 1] >= data1[j + 2]);  // check the validation condition
    }

    cout << "Test 1 passed\n";
}

/** Driver Code */
int main() {
    test();
    return 0;
}
