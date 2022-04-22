/**
 * 
 * Hash Search Algorithm - Best Time Complexity Ω(1)
 * In this algorithm, we use the method of division and reservation remainder to
 * construct the hash function, and use the method of chain address to solve the
 * conflict, that is, we link a chain list after the data, and store all the
 * records whose keywords are synonyms in the same linear chain list.
 */
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAX 6      ///< Determines how much data
#define HASHMAX 5  ///< Determines the length of the hash table

int data[MAX] = {1, 10, 15, 5, 8, 7};  //!< test data

typedef struct list {
    int key;            //!< key value for node
    struct list* next;  //!< pointer to next link in the chain
} node,                 /**< define node as one item list */
    *link;              ///< pointer to nodes

node hashtab[HASHMAX];  ///< array of nodes

// int counter = 1;

/**
 * Mode of hash detection :
 * Division method
 * [in] key to hash
 * hash value for `key`
 */
int h(int key) { return key % HASHMAX; }

/**
 * The same after the remainder will be added after the same hash header
 * To avoid conflict, zipper method is used
 * Insert elements into the linked list in the header
 * [in] key key to add to list
 * dynamic memory allocated to `n` never gets freed.
 * fix memory leak
 */
void create_list(int key) {  // Construct hash table
    link p, n;
    int index;
    n = (link)malloc(sizeof(node));
    n->key = key;
    n->next = NULL;
    index = h(key);
    p = hashtab[index].next;
    if (p != NULL) {
        n->next = p;
        hashtab[index].next = n;
    } else {
        hashtab[index].next = n;
    }
}

/**
 * Input the key to be searched, and get the hash header position through the H
 * (int key) function, then one-dimensional linear search. If found @return
 * element depth and number of searches If not found @return -1
 */
int hash_search(int key, int* counter) {  // Hash lookup function
    link pointer;
    int index;

    *counter = 0;
    index = h(key);
    pointer = hashtab[index].next;

    cout << "data[" << index << "]:";

    while (pointer != NULL) {
        counter[0]++;
        cout << "data[" << pointer->key << "]:";
        if (pointer->key == key)
            return 1;
        else
            pointer = pointer->next;
    }

    return 0;
}

/** main function */
int main() {
    link p;
    int key, index, i, counter;  // Key is the value to be found
    index = 0;

    // You can write the input mode here
    while (index < MAX) {  // Construct hash table
        create_list(data[index]);
        index++;
    }

    for (i = 0; i < HASHMAX; i++) {  // Output hash table
        cout << "hashtab [" << i << "]\n";

        p = hashtab[i].next;

        while (p != NULL) {
            cout << "please int key:";
            if (p->key > 0)
                cout << "[" << p->key << "]";
            p = p->next;
        }
        cout << endl;
    }

    while (key != -1) {
        // You can write the input mode here
        // test key = 10
        key = 10;
        if (hash_search(key, &counter))
            cout << "search time = " << counter << endl;
        else
            cout << "no found!\n";
        key = -1;  // Exit test
        /* The test sample is returned as:
         * data[0]:data[5]:data[15]:data[10]:search time = 3 The search is
         * successful. There are 10 in this set of data */
    }

    return 0;
}
