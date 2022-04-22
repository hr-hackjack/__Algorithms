#include <algorithm>  /// for is_sorted, swap
#include <cassert>    /// for assert
#include <iostream>   /// for IO operations
#include <vector>     /// for vector
using namespace std;



namespace sorting {

namespace wave_sort {

template <typename T>
vector<T> waveSort(const vector<T> &in_arr, int64_t n) {
    vector<T> arr(in_arr);

    for (int64_t i = 0; i < n; i++) {
        arr[i] = in_arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int64_t i = 0; i < n - 1; i += 2) {  // swap all the adjacent elements
        swap(arr[i], arr[i + 1]);
    }
    return arr;
}
}  // namespace wave_sort
}  // namespace sorting

static void test() {
    // [10, 90, 49, 2, 1, 5, 23] return [2, 1, 10, 5, 49, 23, 90]
    vector<int64_t> array1 = {10, 90, 49, 2, 1, 5, 23};
    cout << "Test 1... ";
    vector<int64_t> arr1 = sorting::wave_sort::waveSort(array1, 7);
    const vector<int64_t> o1 = {2, 1, 10, 5, 49, 23, 90};
    assert(arr1 == o1);
    cout << "passed" << endl;

    // [1, 3, 4, 2, 7, 8] return [2, 1, 4, 3, 8, 7]
    vector<int64_t> array2 = {1, 3, 4, 2, 7, 8};
    cout << "Test 2... ";
    vector<int64_t> arr2 = sorting::wave_sort::waveSort(array2, 6);
    const vector<int64_t> o2 = {2, 1, 4, 3, 8, 7};
    assert(arr2 == o2);
    cout << "passed" << endl;

    // [3, 3, 3, 3] return [3, 3, 3, 3]
    vector<int64_t> array3 = {3, 3, 3, 3};
    cout << "Test 3... ";
    vector<int64_t> arr3 = sorting::wave_sort::waveSort(array3, 4);
    const vector<int64_t> o3 = {3, 3, 3, 3};
    assert(arr3 == o3);
    cout << "passed" << endl;

    // [9, 4, 6, 8, 14, 3] return [4, 3, 8, 6, 14, 9]
    vector<int64_t> array4 = {9, 4, 6, 8, 14, 3};
    cout << "Test 4... ";
    vector<int64_t> arr4 = sorting::wave_sort::waveSort(array4, 6);
    const vector<int64_t> o4 = {4, 3, 8, 6, 14, 9};
    assert(arr4 == o4);
    cout << "passed" << endl;
}

int main() {
    test();  // run self-test implementations
    return 0;
}
