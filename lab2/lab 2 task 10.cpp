#include <iostream>
using namespace std;

int main() {
	int rows, cols;

	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> cols;

	int** matrix = new int*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}

	cout << "Enter matrix elements:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "element[" << i + 1 << "][" << j + 1 << "]: " ;
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;

	int** transpose = new int*[cols];
	for (int i = 0; i < cols; i++) {
		transpose[i] = new int[rows];
	}

    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            *(*(transpose + i) + j) = *(*(matrix + j) + i);
            //*(matrix + i) moves the pointer to row i
            //*(matrix + i) + j moves the pointer to column j within row i.
            //*(*(matrix + i) + j) accesses the actual value at row i, column j.
        }
    }

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << transpose[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	for (int i = 0; i < cols; i++) {
		delete[] transpose[i];
	}
	delete[] transpose;

	return 0;
}
