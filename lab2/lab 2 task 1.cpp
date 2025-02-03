#include <iostream>
using namespace std;

int main() {
	int size;
	int sum = 0;
	int max;

	cout << "Enter size of array: ";
	cin >> size;

	int *arr = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "Enter element " << i + 1 << ": ";
		cin >> arr[i];
	}

	cout << "Array elements: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	
	cout << endl;

	max = arr[0];

	for (int i = 0; i < size; i++) {
		sum += arr[i];
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	cout << "Sum: " << sum << endl;
	cout << "Avg: " << (float)sum / size << endl;
	cout << "Max: " << max << endl;

	delete[] arr;
	return 0;
}
