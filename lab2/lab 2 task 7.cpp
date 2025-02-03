#include <iostream>
#include <string>
using namespace std;

void swapIntegers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int *arr, int size)
{
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end)
    {
        swapIntegers(start, end);
        start++;
        end--;
    }
}

int main()
{
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "enter element " << i + 1 << ": " ;
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverseArray(arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

  return 0;
}
