#include<iostream>
using namespace std;

class Matrix {
private:
    int row;
    int col;
    int** arr;
public:
    Matrix(int row, int col) {
        this->row = row;
        this->col = col;
        arr = new int* [row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[col];
        }
    }
    void setArr() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << "Enter element " << i << "," << j << ": ";
                cin >> arr[i][j];
            }
        }
    }
    void printArr() {
        cout << "Matrix: " << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool operator > (Matrix m) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                sum1 += arr[i][j];
                sum2 += m.arr[i][j];
            }
        }
        if (sum1 > sum2) {
            return true;
        }
        else {
            return false;
        }
    }
    Matrix operator * (Matrix m) {
        Matrix new_mat(row, m.col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < m.col; j++) {
                new_mat.arr[i][j] = 0;
                for (int k = 0; k < m.row; k++) {
                    new_mat.arr[i][j] += arr[i][k] * m.arr[k][j];
                }
            }
        }
        return new_mat;
    }
    Matrix operator + (Matrix m) {
        Matrix new_mat(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                new_mat.arr[i][j] = arr[i][j] + m.arr[i][j];
            }
        }
        return new_mat;
    }
};

int main() {
    int row, col;
    cout << "Enter number of rows and columns for first matrix: ";
    cin >> row >> col;

    Matrix m1(row, col);
    m1.setArr();
    m1.printArr();

    cout << endl;

    cout << "Enter number of rows and columns for second matrix: ";
    cin >> row >> col;

    Matrix m2(row, col);
    m2.setArr();
    m2.printArr();

    cout << endl;

    if (m1 > m2) {
        cout << "Sum of elements in first matrix is greater than second matrix" << endl;
    }
    else {
        cout << "Sum of elements in second matrix is greater than first matrix" << endl;
    }

    Matrix m3 = m1 * m2;
    cout << "Multiplication of two matrices: " << endl;
    m3.printArr();

    Matrix m4 = m1 + m2;
    cout << "Addition of two matrices: " << endl;
    m4.printArr();

    return 0;
}