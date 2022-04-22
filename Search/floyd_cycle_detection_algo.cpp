#include <cassert>   /// for assert
#include <iostream>  /// for IO operations
#include <vector>    /// for vector
using namespace std;

namespace search {

namespace cycle_detection {

template <typename T>
int32_t duplicateNumber(const vector<T> &in_arr, const uint32_t &n) {
    if (n == 0 ||
        n == 1) {  // to find duplicate in an array its size should be atleast 2
        return -1;
    }
    uint32_t tortoise = in_arr[0];  // variable tortoise is used for the longer
                                    // jumps in the array
    uint32_t hare =
        in_arr[0];  // variable hare is used for shorter jumps in the array
    do {
        tortoise = in_arr[tortoise];
        hare = in_arr[in_arr[hare]];
    } while (tortoise != hare);
    tortoise = in_arr[0];
    while (tortoise != hare) {
        tortoise = in_arr[tortoise];
        hare = in_arr[hare];
    }
    return tortoise;
}
}  // namespace cycle_detection
}  // namespace search

static void test() {
    // 1st test
    // [3, 4, 8, 5, 9, 1, 2, 6, 7, 4] return 4
    vector<uint32_t> array1 = {3, 4, 8, 5, 9, 1, 2, 6, 7, 4};
    cout << "Test 1... ";
    assert(search::cycle_detection::duplicateNumber(array1, array1.size()) ==
           4);  // here the duplicate number is 4
    cout << "passed" << endl;

    // 2nd test
    // [1, 2, 3, 4, 2] return 2
    vector<uint32_t> array2 = {1, 2, 3, 4, 2};
    cout << "Test 2... ";
    assert(search::cycle_detection::duplicateNumber(array2, array2.size()) ==
           2);  // here the duplicate number is 2
    cout << "passed" << endl;

    // 3rd test
    // [] return -1
    vector<uint32_t> array3 = {};
    cout << "Test 3... ";
    assert(search::cycle_detection::duplicateNumber(array3, array3.size()) ==
           -1);  // since the input array is empty no duplicate number exists in
                 // this case
    cout << "passed" << endl;
}

int main() {
    test();  // run self-test implementations
    return 0;
}
