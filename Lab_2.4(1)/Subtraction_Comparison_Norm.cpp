#include "Matrix.h"

void operator -(Matrix& A, Matrix& B) {    //віднімання матриць і отримання нової
	Matrix C(A.size);
	if (A.size == B.size) {
		for (int i = 0; i < A.size; i++) {
			for (int j = 0; j < B.size; j++)
				C[i][j] = A[i][j] - B[i][j];
		}
		std::cout << "\n\nMatrix C:";
		std::cout << C;
	}
	else
		std::cout << "\n\nMatrices are not equal in size";
}

double Matrix::Calculation_Norm_Matrices() {   //обчислення норми матриці (корінь із суми квадратів елементів)
	int norma_matrix{ 0 };
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			norma_matrix += (int)pow((*this)[i][j], 2);
	}

	return sqrt(norma_matrix);
}

bool operator < (Matrix& A, Matrix& B) {     //перевантаження операції "менше"  (1 спосіб)
	bool b(A.size < B.size);
	return b;
}
bool operator > (Matrix& A, Matrix& B) {     //перевантаження операції "більше"  (1 спосіб)
	bool b(A.size > B.size);
	return b;
}

bool operator <= (Matrix& A, Matrix& B) {    //перевантаження операції "менше рівне"  (2 спосіб)
	int summa_A{}, summa_B{};
	bool b{};
	for (int i = 0; i < A.size; i++)
		for (int j = 0; j < B.size; j++) {
			summa_A += A[i][j];
			summa_B += B[i][j];
		}
	b = (summa_A <= summa_B);
	return b;
}

bool operator >= (Matrix& A, Matrix& B) {    //перевантаження операції "більше рівне"  (2 спосіб)
	int summa_A{}, summa_B{};
	bool b{};
	for (int i = 0; i < A.size; i++)
		for (int j = 0; j < B.size; j++) {
			summa_A += A[i][j];
			summa_B += B[i][j];
		}
	b = (summa_A >= summa_B);
	return b;
}

bool operator == (Matrix& A, Matrix& B) {    //перевантаження операції "рівне"  (3 спосіб)
	bool b = (A[0][0] == B[0][0]);
	return b;
}
bool operator != (Matrix& A, Matrix& B) {    //перевантаження операції "не рівне"  (3 спосіб)
	bool b = (A[0][0] != B[0][0]);
	return b;
}