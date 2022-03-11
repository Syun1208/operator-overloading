#include<iostream>

using namespace std;
#define MAX 100

class Matrix {
private:
    int c, r;
    int mat[MAX][MAX];
public:
    Matrix() {

    }

    Matrix(int c, int r)
    {
        this->c = c;
        this->r = r;
    }

    ~Matrix() {}

    Matrix(int mat[][MAX]) {
        for (int i = 0; i < this->r; ++i) {
            for (int j = 0; j < this->c; ++j) {
                this->mat[i][j] = mat[i][j];
            }
            cout << endl;
        }
    }

    void input_size() {
        cout << "Input the number of row: " << endl;
        cin >> this->r;
        cout << "Input the number of column: " << endl;
        cin >> this->c;
    }

    void input_matrix() {
        for (int i = 0; i < this->r; ++i) {
            for (int j = 0; j < this->c; ++j) {
                cout<<"Matrix["<<i<<"]["<<j<<"]:";
                cin >> this->mat[i][j];
            }
        }
    }

    void print_matrix() {
        for (int i = 0; i < this->r; ++i) {
            for (int j = 0; j < this->c; ++j) {
                cout << this->mat[i][j] <<" ";
            }
            cout << endl;
        }
    }

    Matrix operator +(Matrix tmp1) {
        Matrix result1;
        for(int i = 0; i < this->r; ++i) {
            for(int j = 0; j < this->c; ++j) {
                result1.mat[i][j] = this->mat[i][j] + tmp1.mat[i][j];
            }
        }
        return result1;
    }

    Matrix operator *(Matrix tmp2) {
        Matrix result2;
        for (int i = 0; i < this->r; ++i) {
            for (int j = 0; j < this->c; ++j) {
                result2.mat[i][j] = 0.0;
                for (int k = 0; k < this->c; ++k) {
                    result2.mat[i][j] += this->mat[i][k] * tmp2.mat[k][j];
                }
            }
        }
        return result2;
    }

    Matrix operator -(Matrix tmp3) {
        Matrix result3;
        for (int i = 0; i < this->r; ++i) {
            for (int j = 0; j < this->c; ++j) {
                result3.mat[i][j] = this->mat[i][j] - tmp3.mat[i][j];
            }
        }
        return result3;
    }

    Matrix operator -(int scale) {
        Matrix result4;
        for (int i = 0; i < this->r; ++i) {
            for (int j = 0; j < this->c; ++j) {
                result4.mat[i][j] = this->mat[i][j] - scale;
            }
        }
        return result4;
    }

    Matrix operator +(int scale) {
        Matrix result5;
        for (int i = 0; i < this->r; ++i) {
            for (int j = 0; j < this->c; ++j) {
                result5.mat[i][j] = this->mat[i][j] + scale;
            }
        }
        return result5;
    }

    Matrix operator *(int scale) {
        Matrix result6;
        for (int i = 0; i < this->r; ++i) {
            for (int j = 0; j < this->c; ++j) {
                result6.mat[i][j] = this->mat[i][j] * scale;
            }
        }
        return result6;
    }
};

int main() {
    Matrix a, b;
    a.input_size();
    cout << "Input matrix a: " << endl;
    a.input_matrix();
    a.print_matrix();
    b.input_size();
    cout << "Input matrix b: " << endl;
    b.input_matrix();
    b.print_matrix();
    //Cong 2 ma tran
//    Matrix d;
//    d = a+b;
//    cout <<"Matrix a plus matrix b is: " << endl;
//    d.print_matrix();
    //Cong 1 ma tran voi 1 scale
//    Matrix g1, g2;
//    g1 = b+2;
//    g2 = a+2;
//    cout<<"Matrix a plus a optional scale is "<<endl;
//    g1.print_matrix();
//    g2.print_matrix();
    //Tru 2 ma tran
//    Matrix e;
//    e = a-b;
//    cout<<"Matrix a minus matrix b is: "<<endl;
//    e.print_matrix();
    //Tru 1 ma tran voi 1 scale
//    Matrix h1, h2;
//    h1 = b-2;
//    h2 = a-2;
//    cout<<"Matrix a minus a optional scale is "<<endl;
//    h1.print_matrix();
//    h2.print_matrix();
    //Nhan 2 ma tran
//    Matrix c;
//    c = a*b;
//    cout<<"Matrix a multiplies with matrix b is: "<<endl;
//    c.print_matrix();
    //Nhan 1 ma tran voi 1 scale
//    Matrix f1, f2;
//    f1= a*2;
//    f2= b*2;
//    cout<<"Matrix a or b times a optional scale is: ";
//    f1.print_matrix();

    return 0;
}