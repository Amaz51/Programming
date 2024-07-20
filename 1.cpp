//#include<iostream>
//#include<fstream>
//using namespace std;
//int** InputMatrix(ifstream& ffin, int& rows, int& cols) {
//    ffin >> rows >> cols; // Read the matrix size from file
//
//    // Create the matrix dynamically
//    int** matrixA = new int* [rows];
//    int** matrixB = new int* [rows];
//    int** matrixC = new int* [rows];
//    for (int i = 0; i < rows; i++) {
//        matrixA[i] = new int[cols];
//        matrixB[i] = new int[cols];
//        matrixC[i] = new int[cols];
//    }
//
//    // Read the matrix elements from file
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            ffin >> matrixA[i][j];
//        }
//    }
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            ffin >> matrixB[i][j];
//        }
//    }
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            ffin >> matrixC[i][j];
//        }
//    }
//    ffin.close();
//    return matrixA; // Return the created matrix
//}
//void OutputMatrix(int** matrix, const int& ROWS, const int& COLS) {
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLS; j++) {
//            cout << matrix[i][j]<< " ";
//        }cout << endl;
//    }
//}
//int main() {
//
//    ifstream file;
//    file.open("file.txt");
//    
//    int rows, cols;
//    
//    int** matrixA = InputMatrix(file, rows, cols);
//    int** matrixB = InputMatrix(file, rows, cols);
//
//    // Use the matrix here
//    OutputMatrix(matrixA, rows, cols);
//    OutputMatrix(matrixB, rows, cols);
//    // Free the memory allocated for the matrix
//    for (int i = 0; i < rows; i++) {
//        delete[] matrixA[i];
//    }
//    delete[] matrixA;
//
//    return 0;
//}
