#include <stdio.h>
#include <fstream>
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ostream;
class Matrix{
    public:
        Matrix(int);
        Matrix();
        ~Matrix();
        int getLength();
        float* getData();
        void readMatrix(string fileName);

        Matrix operator+(Matrix &input);
        Matrix operator+(float); // Allows A + 2.2
        friend Matrix operator+(float, const Matrix& A);    // Allows 2.2 + A
        friend ostream& operator<<(ostream& os, const Matrix& A); // Allows cout << A

        void print();

    private:
        float *data;
        int length;
};

