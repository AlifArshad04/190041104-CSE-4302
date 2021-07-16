#include <iostream>
#include <vector>
using namespace std;

// Create a class called “Matrix3D”. An object of the Matrix3D class stores a three dimensional matrix.
class Matrix3D
{
private:
    int row;
    int col;
    vector<vector<double>> val;

public:
    // Implement the following public member functions (task of the function is written after a hyphen):

    // Necessary constructor and destructor function.
    Matrix3D(int _r, int _c);
    Matrix3D(vector<vector<double>> _val) : row(3), col(3), val(_val) {}
    Matrix3D(){};
    ~Matrix3D(){};

    void display();

    // double det() :  Returns the determinant of the matrix.
    double det();

    // Matrix3D inverse(): returns the inverse matrix.
    Matrix3D inverse();

    // Overload binary operator + , - , *  according to the matrix operator.
    Matrix3D operator+(Matrix3D &_ro);

    Matrix3D operator-(Matrix3D &_ro);

    Matrix3D operator*(Matrix3D &_ro);
};

Matrix3D::Matrix3D(int _r, int _c) : row(_r), col(_c)
{
    cout << "Enter 3 by 3 matrix: ";
    for (int i = 0; i < row; ++i)
    {
        int a;
        vector<double> row;
        for (int j = 0; j < col; ++j)
        {
            // cout << "Enter for row " << i << " colunm " << j << ": ";
            cin >> a;
            row.push_back(a);
        }
        val.push_back(row);
    }
};

void Matrix3D::display()
{
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            cout << val[row][col] << "  ";
        }
        cout << '\n';
    }
}

double Matrix3D::det()
{
    double x = ((val[1][1] * val[2][2]) - (val[2][1] * val[1][2]));
    double y = ((val[1][0] * val[2][2]) - (val[2][0] * val[1][2]));
    double z = ((val[1][0] * val[2][1]) - (val[2][0] * val[1][1]));

    return ((val[0][0] * x) - (val[0][1] * y) + (val[0][2] * z));
}

Matrix3D Matrix3D::inverse()
{
    vector<vector<double>> temp(3, vector<double>(3, 0.0));
    double inv_det = 1 / det();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp[i][j] = (val[(j + 1) % 3][(i + 1) % 3] * val[(j + 2) % 3][(i + 2) % 3] - val[(j + 1) % 3][(i + 2) % 3] * val[(j + 2) % 3][(i + 1) % 3]) * inv_det;
        }
    }
    return Matrix3D(temp);
}

Matrix3D Matrix3D::operator+(Matrix3D &_ro)
{
    vector<vector<double>> temp(3, vector<double>(3, 0.0));
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            temp[row][col] = val[row][col] + _ro.val[row][col];
        }
    }

    return Matrix3D(temp);
}

Matrix3D Matrix3D::operator-(Matrix3D &_ro)
{
    vector<vector<double>> temp(3, vector<double>(3, 0.0));
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            temp[row][col] = val[row][col] - _ro.val[row][col];
        }
    }
    return Matrix3D(temp);
}

Matrix3D Matrix3D::operator*(Matrix3D &_ro)
{
    vector<vector<double>> temp(3, vector<double>(3, 0.0));
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            for (int k = 0; k < 3; k++)
            {
                temp[row][col] += val[row][k] * _ro.val[k][col];
            }
        }
    }
    return Matrix3D(temp);
}

int main()
{

    Matrix3D m1(3, 3);

    // m1.display();

    // cout << "det: " << m1.det() << '\n';

    Matrix3D m2 = m1.inverse();
    cout << "inversed: \n";
    m2.display();

    // Matrix3D m2(3, 3);

    // m1 = m1 + m2;
    // cout << "m1 + m2:\n";
    // m1.display();

    return 0;
}