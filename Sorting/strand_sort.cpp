/**
 * Strand Sort is a sorting algorithm that works in O(n) time if list is already sorted and works in \f$O(n^2)\f$ in worst case.
 * 
 * It is passed over the array to be sorted once and the ascending (sequential) numbers are taken.
 * After the first iteration, the sequential sub-array is put on the empty sorted array.
 * The main sequence is passed over again and a new sub-sequence is created in order.
 * Now that the sorted array is not empty, the newly extracted substring is merged with the sorted array.
 * Repeat types 3 and 4 until the sub-sequence and main sequence are empty.
 */
#include <iostream>
#include <list>
using namespace std;


namespace sorting {
    namespace strand {
        template <typename T>
        list<T> strand_sort(list<T> lst) {
            if (lst.size() < 2) { // Returns list if empty or contains only one element
                return lst; // Returns list
            }
            list<T> result; // Define new "result" named list instance.
            list<T> sorted; // Define new "sorted" named list instance.
            while(!lst.empty()) /* if lst is not empty */ {
                sorted.push_back(lst.front()); // Adds the first element of "lst" list to the bottom of the "sorted" list.
                lst.pop_front(); // Remove first element of "lst" list.
                for (auto it = lst.begin(); it != lst.end(); ) { // Return the loop as long as the current iterator is not equal to the last literator of the "lst" list.
                    if (sorted.back() <= *it) { // If the last reference of the "sorted" list is less than or equal to the current iterator reference.
                        sorted.push_back(*it); // Adds the iterator retrieved in the loop under the "sorted" list.
                        it = lst.erase(it); // Deletes the element with the current iterator and assigns the deleted element to the iterator.
                    } else {
                        it++; // Next iterator.
                    }
                }
                result.merge(sorted); // Merge "result" list with "sorted" list.
            }
            return result; // Returns sorted list
        }
    }  // namespace strand
}  // namespace sorting

static void test() {
    list<int> lst = { -333, 525, 1, 0, 94, 52, 33 };

    cout << "Before: ";
    for(auto item: lst) {
        cout << item << " ";
    }

    lst = sorting::strand::strand_sort(lst); // Sort list.

    cout << "\nAfter: ";
    for(auto item: lst) {
        cout << item << " ";
    }
}

int main() {
    test();
    return 0;
}
