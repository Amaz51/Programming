#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
int** allocate_matrix(int row, int col) {
	int** matrix = new int* [row];
	for (int i = 0; i < row; i++) {
		*(matrix + i) = new int[col];
	}
	return matrix;
}
int** input(ifstream& inp, int& rows, int& cols) {
	inp >> rows >> cols;
	int** matrix = allocate_matrix(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			inp >> *(*(matrix + i) + j);
			inp >> matrix[i][j];
		}
	}
	return matrix;
}
void output(int** matrix, const int& ROWS, const int& COLS) {
	for (int i = 0; i < ROWS; i++) {
		int* ptr = *(matrix + i);
		for (int j = 0; j < COLS; j++) {
			cout << *ptr << "\t";
			ptr++;
		}
		cout << endl;
	}
}
int** addmat(int** a1, int** a2, const int& rows, const int& cols) {
	int** sum = allocate_matrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			*(*(sum + i) + j) = *(*(a1 + i) + j) + *(*(a2 + i) + j);
		}
	}return sum;
}
int** transpose_matrix(int** matrix, const int& row, const int& col) {
	int** trans = allocate_matrix(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			*(*(trans + j) + i) = *(*(matrix + i) + j);
		}
	}
	return trans;
}
bool is_symmetric(int** matrix, const int& row, const int& col) {
	bool a = 0;
	if (row == col) {
		int** trans = transpose_matrix(matrix, row, col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (*(*(trans + i) + j) == *(*(matrix + i) + j))
				{
					a = 1;
				}
			}
		}for (int i = 0; i < col; i++)delete[] trans[i];
		delete[] trans;
	}return a;
}
void InterchangeRows(int*& row1, int*& row2) {
	int* swap = row1;
	row1 = row2;
	row2 = swap;
}
void InterchangeRows(int** matrix, const int& rows, const int& cols) {
	int r1 = 1;
	int r2 = 3;
	InterchangeRows(*(matrix + r1 - 1), *(matrix + r2 - 1));
}
void de_allocate(int** matrix, int row) {
	if (matrix != nullptr) {
		for (int i = 0; i < row; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = nullptr;
	}
}

int main() {
	cout << "----------------------------MATRIXES----------------------------" << endl << endl;
	int ra = 0, cola = 0, rb = 0, colb = 0, rc = 0, colc = 0;
	ifstream fin;
	fin.open("input.txt");
	int** matrix = input(fin, ra, cola);
	cout << "The matrix A is " << endl;
	output(matrix, ra, cola);
	int** mat = input(fin, rb, colb);
	cout << "The matrix B is " << endl;
	output(mat, rb, colb);
	int** matc = input(fin, rc, colc);
	cout << "The matrix C is " << endl;
	output(matc, rc, colc);
	cout << "-------------------------------------------------------------------------------" << endl;
	int** ma = allocate_matrix(ra, cola);
	if (ra == rb && cola == colb) {

		ma = addmat(matrix, mat, ra, cola);
		cout << "The addition of matrix A and B is " << endl;
		output(ma, ra, cola);
		cout << endl;
	}
	else if (ra != rb || cola != colb) {
		cout << "Sum not Possible because of change of order" << endl;
	}
	int** mac = allocate_matrix(rb, colb);
	if (ra == rc && cola == colc) {

		cout << "The addition of matrix A and C is " << endl;

		mac = addmat(mat, mac, rb, colb);
		output(mac, rb, colb);
		cout << endl;
	}
	else if (ra != rc || cola != colc) {
		cout << "Sum not Possible because of change of order" << endl;
	}

	cout << "-------------------------------------------------------------------------------" << endl;



	cout << endl << "Transpose of matrix A : " << endl;
	int** trans_a = transpose_matrix(matrix, ra, cola);
	output(trans_a, cola, ra);

	cout << endl << "Transpose of matrix B : " << endl;
	int** trans_b = transpose_matrix(mat, rb, colb);
	output(trans_b, colb, rb);

	/*cout << endl << "Transpose of matrix C : " << endl;
	int** trans_c = transpose_matrix(matc, rc, colc);
	output(trans_c, colc, rc);*/


	if (is_symmetric(matrix, ra, cola)) {
		cout << endl << "Matrix A is Symmetric." << endl;
	}
	else  cout << endl << "Matrix A isn't Symmetric." << endl;

	if (is_symmetric(mat, rb, colb))
	{
		cout << endl << "Matrix B is Symmetric." << endl;
	}

	else {
		cout << endl << "Matrix b isn't Symmetric." << endl;
	}

	cout << endl << "interchanged rows of matrix a are:" << endl;
	InterchangeRows(matrix, ra, cola);
	cout << endl;
	cout << "====================Matrix A====================" << endl;
	cout << "After interchanging rows " << endl;
	output(matrix, ra, cola);
	cout << endl;
	de_allocate(matrix, ra);
	de_allocate(mat, rb);
	de_allocate(matc, rc);
	de_allocate(ma, ra);
	de_allocate(mac, ra);
	de_allocate(trans_a, cola);
	de_allocate(trans_b, colb);
	//de_allocate(trans_c, colc);
	fin.close();
}