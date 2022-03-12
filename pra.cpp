#include<iostream>
#include <string>

using namespace std;
#define MAX 50

int input_scale() {
    int scale;
    cout << "Input your scale number: " << endl;
    cin >> scale;
    return scale;
}

class Matrix {
private:
    int column, row;
    int matrix[MAX][MAX];
public:
    Matrix() {

    }

    Matrix(int column, int row) {
        this->column = column;
        this->row = row;

    }

    Matrix(int matrix[][MAX]) {
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                this->matrix[i][j] = matrix[i][j];
            }
            cout << endl;
        }
    }

    void input_size() {
        cout << "Input the number of rows: " << endl;
        cin >> this->row;
        cout << "Input the number of columns: " << endl;
        cin >> this->column;
    }

//    void input_scale()
//    {
//        cout<<"Input your optional scale: "<<endl;
//        cin>>this->scale;
//    }
    void input_matrix() {
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                cout << "Matrix[" << i << "][" << j << "]:";
                cin >> this->matrix[i][j];
            }
        }
    }

    void print_matrix() {
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                cout << this->matrix[i][j] << "   ";
            }
            cout << endl;
        }
    }

    Matrix operator+(Matrix tmp1) {
        Matrix result;
        if (this->column != tmp1.row) {
            throw "No valid of size";
            //return result;
        }
        result.column = this->column;
        result.row = this->row;
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] + tmp1.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator&(Matrix tmp2) {
        Matrix result;
        if (this->column != tmp2.row) {
            throw "No valid of size";
            //return result;
        }
        result.column = tmp2.column;
        result.row = this->row;
        for (int i = 0; i < result.row; ++i) {
            for (int j = 0; j < result.column; ++j) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < this->column; ++k) {
                    result.matrix[i][j] += this->matrix[i][k] * tmp2.matrix[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator-(Matrix tmp3) {
        Matrix result;
        result.column = this->column;
        result.row = this->row;
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] - tmp3.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator-(int scale) {
        Matrix result;
        result.column = this->column;
        result.row = this->row;
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] - scale;
            }
        }
        return result;
    }

    Matrix operator+(int scale) {
        Matrix result;
        result.column = this->column;
        result.row = this->row;
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] + scale;
            }
        }
        return result;
    }

    Matrix operator*(int scale) {
        Matrix result;
        result.column = this->column;
        result.row = this->row;
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] * scale;
            }
        }
        return result;
    }

    Matrix operator*(Matrix tmp7) {
        Matrix result;
        result.column = tmp7.column;
        result.row = this->row;
        if (this->row != tmp7.row || this->column != tmp7.column) {
            throw "No valid of size";
        }
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < tmp7.column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] * tmp7.matrix[i][j];
            }
        }
        return result;
    }
};

int main() {
    Matrix a;
    Matrix b;
    a.input_size();
    cout << "Input matrix a: " << endl;
    a.input_matrix();
    a.print_matrix();
    b.input_size();
    cout << "Input matrix b: " << endl;
    b.input_matrix();
    b.print_matrix();
    fflush(stdin);
    int s = input_scale();
//    Cong 2 ma tran
    Matrix *d = new Matrix[10];
    try {
        *d = a + b;
        cout << "[1] Matrix a plus matrix b is: " << endl;
        d->print_matrix();
    } catch (const char *ex) {
        cout << "[1] Matrix a plus matrix b is: " << endl;
        cout << ex << endl;
    }
    //Cong 1 ma tran voi 1 scale
    Matrix *g1 = new Matrix[5];
    Matrix *g2 = new Matrix[5];
    *g1 = a + s;
    *g2 = b + s;
    cout << "[2.1] Matrix a plus a optional scale is " << endl;
    g1->print_matrix();
    cout << "[2.2] Matrix b plus a optional scale is " << endl;
    g2->print_matrix();
    //Tru 2 ma tran
    Matrix *e = new Matrix[5];
    try {
        *e = a - b;
        cout << "[3] Matrix a minus matrix b is: " << endl;
        e->print_matrix();
    } catch (const char *ex) {
        cout << "[3] Matrix a minus matrix b is: " << endl;
        cout << ex << endl;
    }
    //Tru 1 ma tran voi 1 scale
    Matrix *h1 = new Matrix[5];
    Matrix *h2 = new Matrix[5];
    *h1 = a - s;
    *h2 = b - s;
    cout << "[4.1] Matrix a minus a optional scale is " << endl;
    h1->print_matrix();
    cout << "[4.2] Matrix b minus a optimal scale is " << endl;
    h2->print_matrix();
    //Nhan 2 ma tran
    Matrix *c = new Matrix[5];
    try {
        *c = a & b;
        cout << "[5] Matrix a multiplies with matrix b is: " << endl;
        c->print_matrix();
    } catch (const char *ex) {
        cout << "[5] Matrix a multiplies with matrix b is: " << endl;
        cout << ex << endl;
    }
    //Nhan tuong ung phan tu 2 ma tran
    Matrix *h = new Matrix[5];
    try {
        *h = a * b;
        cout << "[6] Matrix a multiplies with matrix b with each components is " << endl;
        h->print_matrix();
    } catch (const char *ex) {
        cout << "[6] Matrix a multiplies with matrix b with each components is " << endl;
        cout << ex << endl;
    }
    //Nhan 1 ma tran voi 1 scale
    Matrix *f1 = new Matrix[5];
    Matrix *f2 = new Matrix[5];
    *f1 = a * s;
    *f2 = b * s;
    cout << "[7.1] Matrix a times a optional scale is: " << endl;
    f1->print_matrix();
    cout << "[7.2] Matrix b times a optional scale is: " << endl;
    f2->print_matrix();
    return 0;
}
