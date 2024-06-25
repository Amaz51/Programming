//#include<iostream>
//#include<cstring>
//using namespace std;
//
//template <typename T>
//class Matrix {
//private:
//    T** matrix;
//    int rows, columns;
//
//public:
//    Matrix() {
//        rows = 0;
//        columns = 0;
//        matrix = nullptr;
//    }
//    Matrix(int rows, int columns) {
//        this->rows = rows;
//        this->columns = columns;
//        matrix = new T * [rows];
//        for (int i = 0; i < rows; i++) {
//            matrix[i] = new T[columns];
//        }
//    }
//    Matrix(Matrix const& obj) {
//        rows = obj.rows;
//        columns = obj.columns;
//        matrix = new T * [rows];
//        for (int i = 0; i < rows; i++) {
//            matrix[i] = new T[columns];
//            for (int j = 0; j < columns; j++) {
//                matrix[i][j] = obj.matrix[i][j];
//            }
//        }
//    }
//    void insertElement(T const& element, int rowNo, int colNo) {
//        if (rowNo >= 0 && colNo >= 0) {
//
//            matrix[rowNo][colNo] = element;
//        }
//    }
//    Matrix<T> operator+(Matrix const& obj) {
//        if (rows != obj.rows || columns != obj.columns) {
//            cout << "Matrices are not of the same sizes." << endl;
//            return Matrix<T>();
//        }
//
//        Matrix<T> result(rows, columns);
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < columns; j++) {
//                result.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
//            }
//        }
//
//        return result;
//    }
//    void print() {
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < columns; j++) {
//                cout << matrix[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//    void transpose() {
//
//        int** temp = new int* [columns];
//        for (int i = 0; i < columns; i++) {
//            temp[i] = new int[rows];
//        }
//
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < columns; j++) {
//                temp[j][i] = matrix[i][j];
//            }
//        }
//        for (int i = 0; i < rows; i++) {
//            delete[] matrix[i];
//        }
//
//
//        delete[] matrix;
//        matrix = temp;
//        int swap = rows;
//        rows = columns;
//        columns = swap;
//    }
//      ~Matrix() {
//        for (int i = 0; i < rows; i++) {
//            delete[] matrix[i];
//        }
//        delete[] matrix;
//        matrix = nullptr;
//    }
//};
//
//
//int main() {
//    Matrix<int> m1(2, 3);
//    m1.insertElement(1, 0, 0);
//    m1.insertElement(1, 0, 1);
//    m1.insertElement(1, 0, 2);
//    m1.insertElement(0, 1, 0);
//    m1.insertElement(0, 1, 1);
//    m1.insertElement(0, 1, 2);
//    m1.transpose();
//    Matrix<int> m2(2, 3);
//    m2.insertElement(-1, 0, 0);
//    m2.insertElement(-1, 0, 1);
//    m2.insertElement(-1, 0, 2);
//    m2.insertElement(10, 1, 0);
//    m2.insertElement(5, 1, 1);
//    m2.insertElement(1, 1, 2);
//    m2.transpose();
//    Matrix<int> m3(m2);
//    Matrix<int> m4(m1 + m3);
//    m4.transpose();
//    m4.print();
//}