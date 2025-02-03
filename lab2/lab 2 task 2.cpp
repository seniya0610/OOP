#include <iostream>
using namespace std;

int main() {
	int rows1, cols1;

	cout << "Enter matrix 1 rows: " << endl;
	cin >> rows1;
	cout << "Enter matrix 1 cols: " << endl;
	cin >> cols1;

	// First matrix
	int** matrix1 = new int*[rows1];
	for (int i = 0; i < rows1; i++) {
		matrix1[i] = new int[cols1];
	}

	cout << "Enter elements of matrix 1:" << endl;
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols1; j++) {
			cout << "Element[" << i << "][" << j << "]: ";
			cin >> matrix1[i][j];
		}
	}

	cout << "2D Array elements of matrix 1:" << endl;
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols1; j++) {
			cout << matrix1[i][j] << " ";
		}
		cout << endl;
	}

	int rows2, cols2;

	cout << "Enter matrix 2 rows: " << endl;
	cin >> rows2;
	cout << "Enter matrix 2 cols: " << endl;
	cin >> cols2;

	// Second matrix
	int** matrix2 = new int*[rows2];
	for (int i = 0; i < rows2; i++) {
		matrix2[i] = new int[cols2];
	}

	cout << "Enter elements of matrix 2:" << endl;
	for (int i = 0; i < rows2; i++) {
		for (int j = 0; j < cols2; j++) {
			cout << "Element[" << i << "][" << j << "]: ";
			cin >> matrix2[i][j];
		}
	}

	cout << "2D Array elements of matrix 2:" << endl;
	for (int i = 0; i < rows2; i++) {
		for (int j = 0; j < cols2; j++) {
			cout << matrix2[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

// addition subtraction

	if (rows1 == rows2 && cols1 == cols2) {
		int** matrix3 = new int*[rows1];
		int** matrix4 = new int*[rows1];
		for (int i = 0; i < rows1; i++) {
			matrix3[i] = new int[cols1];
			matrix4[i] = new int[cols1];
		}

		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < cols1; j++) {
				matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
				matrix4[i][j] = matrix1[i][j] - matrix2[i][j];
			}
		}

		cout << "Result of addition:" << endl;
		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < cols1; j++) {
				cout << matrix3[i][j] << " ";
			}
			cout << endl;
		}

		cout << "Result of subtraction:" << endl;
		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < cols1; j++) {
				cout << matrix4[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < rows1; i++) {
			delete[] matrix3[i];
			delete[] matrix4[i];
		}
		delete[] matrix3;
		delete[] matrix4;
	} else {
		cout << "Cannot be added or subtracted." << endl;
	}

    cout << endl;

//multiplication

	if (cols1 == rows2) {
		int** matrix5 = new int*[rows1];
		for (int i = 0; i < rows1; i++) {
			matrix5[i] = new int[cols2];
		}

		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < cols2; j++) {
				matrix5[i][j] = 0;
				for (int k = 0; k < cols1; k++) {
					matrix5[i][j] += matrix1[i][k] * matrix2[k][j];
				}
			}
		}

		cout << "Result of multiplication:" << endl;
		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < cols2; j++) {
				cout << matrix5[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < rows1; i++) {
			delete[] matrix5[i];
		}
		delete[] matrix5;
		
	} else {
		cout << "Cannot be multiplied." << endl;
	}

	for (int i = 0; i < rows1; i++) {
		delete[] matrix1[i];
	}
	delete[] matrix1;

	for (int i = 0; i < rows2; i++) {
		delete[] matrix2[i];
	}
	delete[] matrix2;

	return 0;
}