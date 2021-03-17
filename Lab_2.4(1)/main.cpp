#include <iostream>
#include "Matrix.h"

int main(void) {
	std::cout << "\n\n//////////////////////////////////////////////////////////////////// sposob 1";

	int size_A, size_B;
	std::cout << "\n\nMatrix A:";
	std::cout << "\nEnter the size of the matrix: "; std::cin >> size_A;
	std::cout << "\n\nMatrix B:";
	std::cout << "\nEnter the size of the matrix: "; std::cin >> size_B;

	Matrix A(size_A),
		   B(size_B);

	std::cout << "\n\nMatrix A:";
	std::cin >> A;
	std::cout << "\n\nMatrix B:";
	std::cin >> B;

	std::cout << "\n\nMatrix A:";
	std::cout << A;
	std::cout << "\n\nMatrix B:";
	std::cout << B;

	A - B;

	std::cout << "\n\nCalculation norm matrices A: ";
	std::cout << A.Calculation_Norm_Matrices();

	std::cout << "\n\nCalculation norm matrices B: ";
	std::cout << B.Calculation_Norm_Matrices();

	std::cout << "\n\ncomparison of matrices: ";

	std::cout << "\nWay 1 --- A < B: " << (A < B);
	std::cout << "\nWay 1 --- A > B: " << (A > B);
	std::cout << "\nWay 2 --- A <= B: " << (A <= B);
	std::cout << "\nWay 2 --- A >= B: " << (A >= B);
	std::cout << "\nWay 3 --- A == B: " << (A == B);
	std::cout << "\nWay 4 --- A != B: " << (A != B);

	return 0;
}