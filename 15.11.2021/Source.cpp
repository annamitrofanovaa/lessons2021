#include <iostream>
#include "matrix.h"

int main()
{
	int size;
	do
	{
		std::cout << "Input size of square matrix: ";
		std::cin >> size;
	} while (size < 1);

	double **A = inputMatrix<double>(size, size);

	print(A, size, size, "A = \n");

	std::cout << "Determinant = " << findDet(A, size) << std::endl;

	try
	{
		double** B = inv(A, size);
		print(B, size, size, "Inverse matrix = \n");
		deleteMatrix(B, size);
	}
	catch (const char c[])
	{
		std::cout << "Error: " << c << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
	}

	deleteMatrix(A, size);

	/*try
	{
		double **B = inverseMatrix(A, n);
		printMatrix(B, n, n, "Inverse matrix = \n");
		deleteMatrix(B, n);
	}
	catch (const char c[])
	{
		std::cout << "Error: " << c << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
	}

	deleteMatrix(A, n);

	/*double ** Z, **O, **E, **v;
	try {
		/*v = linspace(1, 8, 8);
		double **t = ones<double>(8, 1);
		Z = mult(t, v, 8, 1, 8);
		O = transpose(Z, 8, 8);
		E = mult(Z, O, 8, 8, 8);
		print(E, 8, 8, "result:\n");

		deleteMatrix(v, 1);
		deleteMatrix(t, 8);
		deleteMatrix(Z, 8);
		deleteMatrix(O, 8);
		deleteMatrix(E, 8);
		/*Z = zeros(4, 5);
		O = ones(4, 5);
		E = eye(4);
		v = linspace(1, 10, 10);

		print(Z, 4, 5, "Z=\n");
		print(O, 4, 5, "O=\n");
		print(E, 4, 4, "E=\n");
		print(v, 1, 10, "v=\n");

		double **t = transpose(v, 1, 10);
		print(t, 10, 1, "t=\n");
		double **M = mult(t, v, 10, 1, 10);
		print(M, 10, 10, "t*v=\n");

		deleteMatrix(t, 10);
		deleteMatrix(M, 10);

		deleteMatrix(Z, 4);
		deleteMatrix(O, 4);
		deleteMatrix(E, 4);
		deleteMatrix(v, 1);
	}
	catch (const char *error) {
		std::cout << "Error: " << error << std::endl;
	}
	catch (...) {
		std::cout << "Unknown error." << std::endl;
	}

	try {
		int **A, **B;
		int rowsA, columnsA, rowsB, columnsB;
		A = inputMatrix<int>(rowsA, columnsA);
		print(A, rowsA, columnsA, "A = \n");
		B = inputMatrix<int>(rowsB, columnsB);
		print(B, rowsB, columnsB, "B = \n");
		int **C = mult(A, B, rowsA, columnsA, columnsB);
		print(C, rowsA, columnsB, "A * B = \n");

		deleteMatrix(A, rowsA);
		deleteMatrix(B, rowsB);
		deleteMatrix(C, rowsA);
	}
	catch (const char *error) {
		std::cout << "Error: " << error << std::endl;
	}
	catch (...) {
		std::cout << "Unknown error." << std::endl;
	}*/

	system("pause");
	return 0;
}