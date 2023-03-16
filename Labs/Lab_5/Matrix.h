#include <stdio.h>
#include <fstream>
#include <iomanip>
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

class Matrix{
    public:
        Matrix(int);
        Matrix();
        ~Matrix();
        int getLength();
        float* getData();
        void readMatrix(string fileName);
        Matrix operator+(Matrix&);
        void print();
    private:
        float *data;
        int length;
};
