#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

void check(ifstream& fin) {
	char check;
	do {
		fin >> check;
		if (check == '/') {
			string end;
			getline(fin, end);
			fin >> check;
		}
	} while (!isdigit(check));
	fin.putback(check);
}

int** input_matrix(ifstream& fin, int& row, int& col) {
	int** array = new int* [row];
	for (int i = 0; i < row; i++) {
		//array[i] = new int[col];
		*(array + i) = new int[col];
	}
	for (int i = 0; i < row; i++) {
		int* arr = *(array + i);
		for (int j = 0; j < col; j++) {
			check(fin);
			fin >> *arr;
			arr++;
		}
	}return array;
}

void output_matrix(int** matrix, const int& row, const int& col) {
	for (int i = 0; i < row; i++) {
		int* arr = *(matrix + i);
		for (int j = 0; j < col; j++) {
			cout << *arr << "     ";
			arr++;
		}cout << endl;
	}
}

int** addmatrix(int** matrixa, int** matrixb, const int& row, const int& col) {
	int** matrix_sum = new int* [row];
	for (int i = 0; i < row; i++) {
		*(matrix_sum + i) = new int[col];
	}
	for (int i = 0; i < row; i++) {
		int* arr1 = *(matrixa + i);
		int* arr2 = *(matrixb + i);
		int* arr3 = *(matrix_sum + i);
		for (int j = 0; j < col; j++) {
			*arr3 = *arr1 + *arr2;
			arr1++;
			arr2++;
			arr3++;
		}
	}return matrix_sum;
}

int** transpose_matrix(int** matrix, const int& row, const int& col) {
	int** matrix_trans = new int* [col];
	for (int i = 0; i < col; i++) {
		*(matrix_trans + i) = new int[row];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			*(*(matrix_trans + j) + i) = *(*(matrix + i) + j);
		}
	}
	return matrix_trans;
}

bool is_symmetric(int** matrix, const int& row, const int& col) {
	bool a = 1;
	if (row == col) {
		int** transpose = transpose_matrix(matrix, row, col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (*(*(transpose + i) + j) != *(*(matrix + i) + j))
				{
					a = 0;
				}
			}
		}
		for (int i = 0; i < col; i++)delete[] transpose[i];
		delete[] transpose;
	}return a;
}


void interchange_rows(int** matrix, const int& rows, const int& cols) {
	int r1 = 1, r2 = 3;
	cout << "row 1 is : " << r1 << endl;
	cout << "row 2 is : " << r2 << endl;
	int* ptr1 = *(matrix + r1 - 1);
	int* ptr2 = *(matrix + r2 - 1);
	int* ptr = ptr1;
	ptr1 = ptr2;
	ptr2 = ptr;
	*(matrix + r1 - 1) = ptr1;
	*(matrix + r2 - 1) = ptr2;
}

void de_allocate(int** matrix, int row) {
	if (matrix != nullptr) {
		
			for (int i = 0; i < row; i++){
				delete[] matrix[i];
		}
		delete[] matrix;
		matrix = nullptr;
	}
}
int main() {
	int row1, row2, row3, col1, col2, col3;

	ifstream file{ "inputfile.txt" };
	
	check(file);
	file >> row1;
	check(file);
	file >> col1;
	int** matrix1 = input_matrix(file, row1, row2);
	cout << " matrix a is : " << endl;
	output_matrix(matrix1, row1, col1);

	check(file);
	file >> row2;
	check(file);
	file >> col2;
	int** matrix2 = input_matrix(file, row1, row2);
	cout << " matrix a is : " << endl;
	output_matrix(matrix1, row2, col2);

	check(file);
	file >> row3;
	check(file);
	file >> col3;
	int** matrix3 = input_matrix(file, row1, row2);
	cout << endl<<" matrix a is : " << endl;
	output_matrix(matrix1, row3, col3);

	int** add_matrix1 = nullptr;
	int** add_matrix2 = nullptr;
	cout << endl << "matrix  (a+b) = " << endl;
	if (row1 == row2 && col1 == col2) {
		add_matrix1 = addmatrix(matrix1, matrix2, row1, col1);
		output_matrix(add_matrix1, row1, col1);
	}
	else {
		cout << "addition is not possible because of change of order.";
	}

	if (row1 == row3 && col1 == col3) {
		add_matrix2 = addmatrix(matrix1, matrix3, row1, col1);
		output_matrix(add_matrix2, row1, col1);
	}
	else {
		cout << "addition is not possible because of change of order.";
	}


	cout << endl << "transpose of matrix a = " << endl;
	int** transpose_a = transpose_matrix(matrix1, row1, col1);
	output_matrix(transpose_a, col1, row1);

	cout << endl << "transpose of matrix c = " << endl;
	int** transpose_c = transpose_matrix(matrix3, row3, col3);
	output_matrix(transpose_c, col3, row3);

	if (is_symmetric(matrix1, row1, col1))
		cout << endl << "matrix a is symmetric" << endl;
	else  cout << endl << "matrix a is not symmetric" << endl;

	if (is_symmetric(matrix2, row2, col2))
	{
		cout << endl << "..matrix b is symmetric.." << endl;
	}
	
	else { 
		cout << endl << "..matrix b is not symmetric.." << endl;
	}

	cout << endl << "interchanged rows of matrix a are:" << endl;
	interchange_rows(matrix1, row1, col1);
	output_matrix(matrix1, row1, col1);

	de_allocate(matrix1, row1);
	de_allocate(matrix2, row2);
	de_allocate(matrix3, row3);
	de_allocate(add_matrix1, row1);
	de_allocate(add_matrix2, row1);
	de_allocate(transpose_a, col1);
	de_allocate(transpose_c, col3);
	file.close();
}