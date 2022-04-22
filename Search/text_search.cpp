#include <cassert>
#include <cstdlib>
#include <iostream>
#ifdef _MSC_VER
#include <string>  // required for MS Visual C++
#else
#include <cstring>
#endif

string lower(string word) {
    int length = word.length();
    string lc = "";

    for (int i = 0; i < length; i++) {
        lc += tolower(word[i]);
    }

    return lc;
}

static void test() {
    assert(lower("abcd").compare("abcd") == 0);
    assert(lower("abc").compare("abcd") == -1);
    assert(lower("abcd").compare("abc") == 1);
}


int main() {
    test();  // run self-test implementations
    string paragraph;
    cout << "Please enter your paragraph: \n";
    getline(cin, paragraph);
    cout << "\nHello, your paragraph is:\n " << paragraph << "!\n";
    cout << "\nThe size of your paragraph = " << paragraph.size()
              << " characters. \n\n";

    if (paragraph.empty()) {
        cout << "\nThe paragraph is empty" << endl;
    } else {
        int ch = 0;
        while (true) {
            string word;
            cout << "Please enter the word you are searching for: ";
            getline(cin, word);
            cout << "Ignore case-sensitive? 1 = Yes, 0 = No" << endl;
            cin >> ch;
            if (ch == 1) {
                string lowerCase = lower(
                    paragraph);  // convert string paragraph to lowercase
                                 // and store it in string lowerCase
                string lowerCaseWord =
                    lower(word);  // convert string paragraph to lowercase
                                  // and store it in string lowerCase

                cout << "Hello, your word is " << word << "!\n";
                if (lowerCase.find(lowerCaseWord) == string::npos) {
                    cout << word << " does not exist in the sentence"
                              << endl;
                } else {
                    cout << "The word " << word
                              << " is now found at location "
                              << lowerCase.find(lowerCaseWord) << endl
                              << endl;
                }
            } else {
                cout << "Hello, your word is " << word << "!\n";
                if (paragraph.find(word) == string::npos) {
                    cout << word << " does not exist in the sentence"
                              << endl;
                } else {
                    cout << "The word " << word
                              << " is now found at location "
                              << paragraph.find(word) << endl
                              << endl;
                }
            }
            cout << "\nPress Ctrl + C to exit the program.\n\n";
            cin.get();
        }
    }
    return 0;
}
