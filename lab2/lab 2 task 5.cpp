#include <iostream>
#include <cstring> // For strlen, strcmp, and strcat
using namespace std;

int main() {
    
    size_t length1, length2;

    // Input for the first string
    cout << "Enter the first string: ";
    string input1;
    getline(cin, input1);
    length1 = input1.length();
    char* str1 = new char[length1 + 1];
    strcpy(str1, input1.c_str());

    // Input for the second string
    cout << "Enter the second string: ";
    string input2;
    getline(cin, input2);
    length2 = input2.length();
    char* str2 = new char[length2 + 1];
    strcpy(str2, input2.c_str());

    // Display the strings
    cout << "\nFirst string: " << str1 << endl;
    cout << "Second string: " << str2 << endl;

    // Find and display lengths
    cout << "\nLength of the first string: " << length1 << endl;
    cout << "Length of the second string: " << length2 << endl;

    // Concatenate the strings
    char* concatenated = new char[length1 + length2 + 1];
    strcpy(concatenated, str1);
    strcat(concatenated, " ");
    strcat(concatenated, str2);
    cout << "\nConcatenated string: " << concatenated << endl;

    // Compare the strings
    int comparison = strcmp(str1, str2);
    if (comparison == 0) {
        cout << "\nThe strings are equal." << endl;
    } else if (comparison < 0) {
        cout << "\nThe first string is smaller than the second string." << endl;
    } else {
        cout << "\nThe first string is larger than the second string." << endl;
    }

    delete[] str1;
    delete[] str2;
    delete[] concatenated;

    return 0;
}