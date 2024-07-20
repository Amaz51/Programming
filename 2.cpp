//#include<iostream>
//#include<fstream>
//using namespace std;
//int** ALLOCATEMEM(int row, int col) {
//	int** matrix = new int* [row];
//	for (int i = 0; i < row; i++) {
//		*(matrix + i) = new int[col];
//	}
//	return matrix;
//}
//int** INPUTMATRIX(ifstream& fin, int& rows, int& cols) {
//	fin >> rows >> cols;
//	int** matrix = ALLOCATEMEM(rows, cols);
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			fin >> *(*(matrix + i) + j);
//		}
//	}
//	return matrix;
//}
//void DISPLAYMATRIX(int** matrix, const int& rows, const int& cols) {
//
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			cout << *(*(matrix + i) + j) << " ";
//		}cout << endl;
//	}
//}
//int** ADD_MATRIX(int** a1, int** a2, const int& rows, const int& cols) {
//	int** summ = ALLOCATEMEM(rows, cols);
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			*(*(summ + i) + j) = *(*(a1 + i) + j) + *(*(a2 + i) + j);
//		}
//	}return summ;
//}
//int** TRANSPOSEMAT(int** matrix, const int& rows, const int& cols) {
//	//	int **t= new int*[rows];
//	//	for(int i=0; i<rows; i++){TRANSPOSEMAT]=new int [cols];
//	//	}
//	int TR[20][20];
//	for (int i = 0; i < cols; i++) {
//		for (int j = 0; j < rows; j++) {
//			TR[i][j] = matrix[j][i];
//			//	*(*(t+i)+j)=*(*(matrix +i)+j);
//		}
//	}
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			*(*(matrix + i) + j) = *(*(TR + i) + j);
//		}
//	}
//
//	return matrix;
//}
//bool SYMMETRIC(int** matrix, const int& rows, const int& cols) {
//	int SYM[20][20];
//	if (rows != cols) {
//		cout << "The matrix is not SYMMETRIC ";
//	}
//	else if (rows == cols) {
//		for (int i = 0; i < rows; i++) {
//			for (int j = 0; j < cols; j++) {
//				SYM[i][j] = matrix[j][i];
//			}
//		}
//	}
//	int count = 0;
//	int sum = rows * cols;
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			if (SYM[i][j] == matrix[i][j]) {
//				count++;
//			}
//		}
//	}if (count == sum) {
//		cout << "This matrix is SYMMETTRIC ";
//		return 1;
//	}
//	else {
//		cout << "NO, the Matrix is not SYMMETRIC ";
//		return 0;
//	}
//}
//void InteRChangeRows(int*& row1, int*& row2) {
//	int* temp = row1;
//	row1 = row2;
//	row2 = temp;
//}
//void InteRChangeRows(int** matrix, const int& rows, const int& cols) {
//	int row1 = 1;
//	int row2 = 3;
//	InteRChangeRows(*(matrix + row1 - 1), *(matrix + row2 - 1));
//}
//void DEALLOCATEMEM(int** matrix, const int rows) {
//	for (int i = 0; i < rows; i++)
//	{
//		delete[] matrix[i];
//		matrix[i] = 0;
//	}
//	delete[] matrix;
//	matrix = 0;
//}
//int main()
//
//{
//	ifstream fin;
//	fin.open("input.txt");
//
//	if (fin) {
//
//		int R1 = 0, C1 = 0, R2 = 0, C2 = 0, RC = 0, C3 = 0;
//
//		int** matrix = INPUTMATRIX(fin, R1, C1);
//		cout << "Matrix A is " << endl;
//		DISPLAYMATRIX(matrix, R1, C1);
//		int** mat = INPUTMATRIX(fin, R2, C2);
//		cout << "Matrix B is " << endl;
//		DISPLAYMATRIX(mat, R2, C2);
//		int** matc = INPUTMATRIX(fin, RC, C3);
//		cout << "Matrix C is " << endl;
//		DISPLAYMATRIX(matc, RC, C3);
//		cout << endl << endl;
//		int** ma = ALLOCATEMEM(R1, C1);
//		ma = ADD_MATRIX(matrix, mat, R1, C1);
//		cout << "Addition of Matrix A and B is " << endl;
//		DISPLAYMATRIX(ma, R1, C1);
//		cout << endl;
//		cout << "Addition of Matrix A and C is " << endl;
//		int** mac = ALLOCATEMEM(R2, C2);
//		mac = ADD_MATRIX(mat, mac, R2, C2);
//		if (R1 != RC) {
//			cout << "Sum isnt possible as order isnt same." << endl;
//		}
//		else {
//			cout << "Addition of Matrix A and C is : " << endl;
//			DISPLAYMATRIX(mac, R2, C2);
//		}cout << endl;
//		cout << "-------------------------------------------------------------------------------" << endl;
//		TRANSPOSEMAT(matrix, R1, C1);
//		cout << "Transpose of Matrix A is " << endl;
//		DISPLAYMATRIX(matrix, R1, C1);
//		TRANSPOSEMAT(matc, RC, C3);
//		cout << "Transpose of matrix C is " << endl;
//
//		DISPLAYMATRIX(matc, RC, C3);
//
//
//		cout << "-------------------------------------------------------------------------------" << endl;
//		cout << "====================Matrix A====================" << endl;
//		SYMMETRIC(matrix, R1, C1);
//		cout << endl;
//		cout << "====================Matrix B====================" << endl;
//		SYMMETRIC(mat, R2, C2);
//		cout << endl;
//
//		InteRChangeRows(matrix, R1, C1);
//		cout << endl;
//		cout << "====================Matrix A====================" << endl;
//		cout << "After inteRChanging rows " << endl;
//		DISPLAYMATRIX(matrix, R1, C1);
//		cout << endl;
//		cout << "-------------------------------------------------------------------------------" << endl;
//		DEALLOCATEMEM(matrix, R1);
//		DEALLOCATEMEM(mat, R2);
//		DEALLOCATEMEM(mac, RC);
//		DEALLOCATEMEM(ma, R1);
//
//	}
//	else {
//		cout << "Error in file opening.";
//	}
//
//}
