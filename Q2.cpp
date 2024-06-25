#include <iostream>
#include <cstring>
using namespace std;
//1st
template <typename T>
class Matrix {
private:
    T** matrix;
    int rows, columns;

public:
    Matrix() {
        rows = 0;
        columns = 0;
        matrix = nullptr;
    }
    Matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        matrix = new T * [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[columns];
        }
    }
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
    void insertElement(T const& element, int rowNo, int colNo) {
        if (rowNo >= 0 && colNo >= 0) {

            matrix[rowNo][colNo] = element;
        }
    }
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
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
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
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;
    }
};
//2nd
template <>
class Matrix<char*>
{
private:
    char*** matrix;
    int rows, columns;

public:
    Matrix(int r, int c) : rows(r), columns(c)
    {
        matrix = new char** [rows];
        for (int i = 0; i < rows; ++i)
        {
            matrix[i] = new char* [columns];
            for (int j = 0; j < columns; ++j)
            {
                matrix[i][j] = nullptr;
            }
        }
    }

    Matrix(const Matrix& obj) : rows(obj.rows), columns(obj.columns)
    {
        matrix = new char** [rows];
        for (int i = 0; i < rows; ++i)
        {
            matrix[i] = new char* [columns];
            for (int j = 0; j < columns; ++j)
            {
                if (obj.matrix[i][j] != nullptr)
                {
                    matrix[i][j] = new char[strlen(obj.matrix[i][j]) + 1];
                    strcpy(matrix[i][j], obj.matrix[i][j]);
                }
                else
                {
                    matrix[i][j] = nullptr;
                }
            }
        }
    }

    void insertElement(const char* element, int rowNo, int colNo)
    {
        if (rowNo >= 0 && rowNo < rows && colNo >= 0 && colNo < columns)
        {
            if (element != nullptr)
            {
                matrix[rowNo][colNo] = new char[strlen(element) + 1];
                strcpy(matrix[rowNo][colNo], element);
            }
            else
            {
                matrix[rowNo][colNo] = nullptr;
            }
        }
        else
        {
            cout << "Insertion cant be processed because of Invalid position . " << endl;
        }
    }

    Matrix<char*> operator+(const Matrix& obj)
    {
        if (rows != obj.rows || columns != obj.columns)
        {
            cout << "Invalid for addition." << endl;
            return Matrix<char*>(0, 0);
        }

        Matrix<char*> result(rows, columns);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (matrix[i][j] != nullptr && obj.matrix[i][j] != nullptr)
                {
                    int len1 = strlen(matrix[i][j]);
                    int len2 = strlen(obj.matrix[i][j]);
                    result.matrix[i][j] = new char[len1 + len2 + 1];
                    strcpy(result.matrix[i][j], matrix[i][j]);
                    strcat(result.matrix[i][j], obj.matrix[i][j]);
                }
                else if (matrix[i][j] != nullptr)
                {
                    result.matrix[i][j] = new char[strlen(matrix[i][j]) + 1];
                    strcpy(result.matrix[i][j], matrix[i][j]);
                }
                else if (obj.matrix[i][j] != nullptr)
                {
                    result.matrix[i][j] = new char[strlen(obj.matrix[i][j]) + 1];
                    strcpy(result.matrix[i][j], obj.matrix[i][j]);
                }
                else
                {
                    result.matrix[i][j] = nullptr;
                }
            }
        }
        return result;
    }

    void print()
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (matrix[i][j] != nullptr)
                {
                    cout << matrix[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }

    void transpose()
    {
        Matrix<char*> resultt(columns, rows);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (matrix[i][j] != nullptr)
                {
                    resultt.insertElement(matrix[i][j], j, i);
                }
            }
        }
        *this = resultt;
    }

    Matrix<char*>& operator=(const Matrix& obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                delete[] matrix[i][j];
                if (obj.matrix[i][j] != nullptr)
                {
                    matrix[i][j] = new char[strlen(obj.matrix[i][j]) + 1];
                    strcpy(matrix[i][j], obj.matrix[i][j]);
                }
                else
                {
                    matrix[i][j] = nullptr;
                }
            }
        }
        return *this;
    }

    bool operator==(const Matrix& obj)
    {
        if (rows != obj.rows || columns != obj.columns)
        {
            return false;
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (matrix[i][j] == nullptr && obj.matrix[i][j] != nullptr)
                {
                    return false;
                }
                else if (matrix[i][j] != nullptr && obj.matrix[i][j] == nullptr)
                {
                    return false;
                }
                else if (matrix[i][j] != nullptr && obj.matrix[i][j] != nullptr)
                {
                    if (strcmp(matrix[i][j], obj.matrix[i][j]) != 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                delete[] matrix[i][j];
            }
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

// main function
int main()
{
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
    cout << "\tThe 3D Character Array..\t\n";

    Matrix<char*> mA(2, 2);
    mA.insertElement((char*)"Computer", 0, 0);
    mA.insertElement((char*)"Electrical", 0, 1);
    mA.insertElement((char*)"Business", 1, 0);
    mA.insertElement((char*)"Civil", 1, 1);
    mA.print();

    Matrix<char*> mB(2, 2);
    mB.insertElement((char*)"Science", 0, 0);
    mB.insertElement((char*)"Engineering", 0, 1);
    mB.insertElement((char*)"Administration", 1, 0);
    mB.insertElement((char*)"Engineering", 1, 1);

    Matrix<char*> mC(1, 1);
    mC = mA + mB;
    Matrix<char*> mD = mA + mB;
    mC.transpose();
    mC.print();
    bool truth = mD == mC;
    cout << truth;

    cout << endl;
    system("pause");
    return 0;
}
