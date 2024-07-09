#include<iostream>
#include<cstring>
using namespace std;

template <typename T>
class Matrix {
private:
    T** matrix;
    int rows, columns;

public:
    // Constructor

    Matrix() {
        rows = 0;
        columns = 0;
        matrix = nullptr;
    }

    Matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        matrix = new T * [rows];
        for (int i = 0; i < rows; i++) {}
        matrix[i] = new T[columns];
    }
}

// Copy constructor
Matrix(Matrix const& obj) {
    rows = obj.rows;
    columns = obj.columns;
    matrix = new T * [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new T[columns];
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = obj.matrix[i][j];
        }
    }
}

// Insert function
void insertElement(T const& element, int rowNo, int colNo) {
    if (rowNo >= 0 && colNo >= 0) {

        matrix[rowNo][colNo] = element;
    }
}

// Overloaded + operator
Matrix<T> operator+(Matrix const& obj) {
    if (rows != obj.rows || columns != obj.columns) {
        cout << "Matrices are not of the same sizes." << endl;
        return Matrix<T>();
    }

    Matrix<T> result(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
        }
    }

    return result;
}

// Print function
void print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Transpose function
void transpose() {

    int** temp = new int* [columns];
    for (int i = 0; i < columns; i++) {
        temp[i] = new int[rows];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            temp[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }


    delete[] matrix;
    matrix = temp;
    int swap = rows;
    rows = columns;
    columns = swap;
}

// Destructor
~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}
};

template <>
class Matrix <char*> {
private:
    char*** data;
    int numRows, numCols;

public:
    Matrix(int r, int c) : numRows(r), numCols(c) {
        data = new T * *[numRows];
        for (int i = 0; i < numRows; ++i) {
            data[i] = new T * [numCols];
            for (int j = 0; j < numCols; ++j) {
                data[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix& obj) : numRows(obj.numRows), numCols(obj.numCols) {
        data = new T * *[numRows];
        for (int i = 0; i < numRows; ++i) {
            data[i] = new T * [numCols];
            for (int j = 0; j < numCols; ++j) {
                if (obj.data[i][j] != 0) {
                    data[i][j] = new T[strlen(obj.data[i][j]) + 1];
                    strcpy(data[i][j], obj.data[i][j]);
                }
                else {
                    data[i][j] = 0;
                }
            }
        }
    }

    void insertElement(const T* element, int rowNo, int colNo) {
        if (rowNo >= 0 && rowNo < numRows && colNo >= 0 && colNo < numCols) {
            if (element != 0) {
                data[rowNo][colNo] = new T[strlen(element) + 1];
                strcpy(data[rowNo][colNo], element);
            }
            else {
                data[rowNo][colNo] = 0;
            }
        }
        else {
            cout << "Invalid position for element insertion." << endl;
        }
    }

    Matrix<T> operator+(const Matrix& obj) {
        if (numRows != obj.numRows || numCols != obj.numCols) {
            cout << "Matrix dimensions mismatch for addition." << endl;
            return Matrix<T>(0, 0);
        }

        Matrix<T> result(numRows, numCols);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (data[i][j] != 0 && obj.data[i][j] != 0) {
                    int len1 = strlen(data[i][j]);
                    int len2 = strlen(obj.data[i][j]);
                    result.data[i][j] = new T[len1 + len2 + 1];
                    strcpy(result.data[i][j], data[i][j]);
                    strcat(result.data[i][j], obj.data[i][j]);
                }
                else {
                    result.data[i][j] = 0;
                }
            }
        }
        return result;
    }

    void print() {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (data[i][j] != 0) {
                    cout << data[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }

    void transpose() {
        Matrix<T> transposed(numCols, numRows);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (data[i][j] != 0) {
                    transposed.insertElement(data[i][j], j, i);
                }
            }
        }
        *this = transposed;
    }

    Matrix<T>& operator=(const Matrix& obj) {
        if (this == &obj) {
            return *this;
        }

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                delete[] data[i][j];
                if (obj.data[i][j] != 0) {
                    data[i][j] = new T[strlen(obj.data[i][j]) + 1];
                    strcpy(data[i][j], obj.data[i][j]);
                }
                else {
                    data[i][j] = 0;
                }
            }
        }
        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                delete[] data[i][j];
            }
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    Matrix<int> m1(2, 3);
    m1.insertElement(1, 0, 0);
    m1.insertElement(1, 0, 1);
    m1.insertElement(1, 0, 2);
    m1.insertElement(0, 1, 0);
    m1.insertElement(0, 1, 1);
    m1.insertElement(0, 1, 2);
    m1.transpose();
    Matrix<int> m2(2, 3);
    m2.insertElement(-1, 0, 0);
    m2.insertElement(-1, 0, 1);
    m2.insertElement(-1, 0, 2);
    m2.insertElement(10, 1, 0);
    m2.insertElement(5, 1, 1);
    m2.insertElement(1, 1, 2);
    m2.transpose();
    Matrix<int> m3(m2);
    Matrix<int> m4(m1 + m3);
    m4.transpose();
    m4.print();

    Matrix<char*> matrixA(2, 2);
    matrixA.insertElement((char*)"Computer", 0, 0);
    matrixA.insertElement((char*)"Electrical", 0, 1);
    matrixA.insertElement((char*)"Business", 1, 0);
    matrixA.insertElement((char*)"Civil", 1, 1);

    Matrix<char*> matrixB(2, 2);
    matrixB.insertElement((char*)"Science", 0, 0);
    matrixB.insertElement((char*)"Engineering", 0, 1);
    matrixB.insertElement((char*)"Administration", 1, 0);
    matrixB.insertElement((char*)"Engineering", 1, 1);

    Matrix<char*> matrixC = matrixA + matrixB;
    matrixC.print();

    return 0;
}