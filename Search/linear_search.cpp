#include <iostream>   /// for IO operations
#include <cassert>    /// for assert
using namespace std;

int LinearSearch(int *array, int size, int key) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (array[i] == key) {
            return i;
        }
    }

    /* We reach here only in case element is not present in array, return an invalid entry in that case*/
    return -1;
}

static void tests() {
    int size = 4;
    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    assert(LinearSearch(array, size, 0) == 0);
    assert(LinearSearch(array, size, 1) == 1);
    assert(LinearSearch(array, size, 2) == 2);

    size = 6;
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    assert(LinearSearch(array, size, 3) == 3);
    assert(LinearSearch(array, size, 1) == 1);
    assert(LinearSearch(array, size, 5) == 5);

    cout << "All tests have successfully passed!\n";
    delete[] array; // free memory up
}

int main() {
    int mode = 0;

    cout << "Choose mode\n";
    cout << "Self-test mode (1), interactive mode (2): ";

    cin >> mode;

    if (mode == 2) {
        int size = 0;
        cout << "\nEnter the size of the array: ";
        cin >> size;

        while ((size <= 1) || (size >= 30)) {
            cout << "Size cannot be less than zero. Please choose another value: ";
            cin >> size;
        }

        int *array = new int[size];
        int key = 0;

        // Input for the array elements
        cout << "Enter the array of " << size << " numbers: ";
        for (int i = 0; i < size; i++) {
            cin >> array[i];
        }

        cout << "\nEnter the number to be searched: ";
        cin >> key;

        int index = LinearSearch(array, size, key);
        if (index != -1)
        {
            cout << "Number found at index: " << index << "\n";
        } 
        else
        {
            cout << "Array element not found";
        }
        delete[] array;
    }
    else {
        tests();  // run self-test implementations
    }
    return 0;
}
