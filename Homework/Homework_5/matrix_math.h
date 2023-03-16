//structs
struct matrix{
    int size;
    float *data;
};

//function headers
void addition(struct matrix A, struct matrix B);
void subtraction(struct matrix A, struct matrix B);
struct matrix* readMatrix(char* filename);
void deleteMatrix(struct matrix *A);

