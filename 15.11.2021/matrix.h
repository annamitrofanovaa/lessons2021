#pragma once
#include <cmath>

template <typename T>
T **createMatrix(int rows, int columns)
{
	if (rows < 1)
		throw "Number of rows must be positive";
	if (columns < 1)
		throw "Number of columns must be positive";

	T **M = new T *[rows];
	for (int i = 0; i < rows; ++i)
		M[i] = new T[columns];
	return M;
}

template <typename T>
void deleteMatrix(T **M, int rows)
{
	for (int i = 0; i < rows; ++i)
		delete[] M[i];
	delete[] M;
}

template <typename T>
void print(T **M, int rows, int columns, const char pre[])
{
	std::cout << pre;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			std::cout << M[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

template <typename T>
T **zeros(int rows, int columns)
{
	T **M = createMatrix<T>(rows, columns);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			M[i][j] = 0;
	return M;
}

template <typename T>
T **ones(int rows, int columns)
{
	T **M = createMatrix<T>(rows, columns);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			M[i][j] = 1;
	return M;
}

template <typename T>
T **eye(int n)
{
	T **M = createMatrix<T>(n, n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			M[i][j] = 0;
		M[i][i] = 1;
	}
	return M;
}

template <typename T>
T **transpose(T **M, int rows, int columns)
{
	T **R = createMatrix<T>(columns, rows);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			R[j][i] = M[i][j];
	return R;
}

template <typename T>
T **mult(T lambda, T **M, int rows, int columns)
{
	double **R = createMatrix<T>(rows, columns);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			R[i][j] = lambda * M[i][j];
	return R;
}

template <typename T>
T **plus(T **A, T **B, int rows, int columns)
{
	T **R = createMatrix<T>(rows, columns);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			R[i][j] = A[i][j] + B[i][j];
	return R;
}

template <typename T>
T **minus(T **A, T **B, int rows, int columns)
{
	T **R = createMatrix<T>(rows, columns);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			R[i][j] = A[i][j] - B[i][j];
	return R;
}

template <typename T>
T **mult(T **A, T **B, int rowsA, int columnsA, int columnsB)
{
	T **C = createMatrix<T>(rowsA, columnsB);
	for (int i = 0; i < rowsA; ++i)
		for (int j = 0; j < columnsB; ++j)
		{
			C[i][j] = 0;
			for (int s = 0; s < columnsA; ++s)
				C[i][j] += A[i][s] * B[s][j];
		}
	return C;
}

template <typename T>
T **inputMatrix(int &rows, int &columns)
{
	/*do
	{
		std::cout << "rows = ";
		std::cin >> rows;
	} while (rows < 1);

	do
	{
		std::cout << "columns = ";
		std::cin >> columns;
	} while (columns < 1); */

	T **M = createMatrix<T>(rows, columns);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
		{
			std::cout << "matrix(" << i + 1 << "," << j + 1 << ") = ";
			std::cin >> M[i][j];
		}
	return M;
}

//квадратная матрица
double findDet(double **a, int size)
{
	if (size == 1)
	{
		return a[0][0];
	}
	else if (size == 2)
	{
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}
	else
	{
		double det = 0;
		for (int k = 0; k < size; k++)
		{
			double **m = new double *[size - 1];
			for (int i = 0; i < size - 1; i++)
			{
				m[i] = new double[size - 1];
			}
			for (int i = 1; i < size; i++)
			{
				int t = 0;
				for (int j = 0; j < size; j++)
				{
					if (j == k)
					{
						continue;
					}
					m[i - 1][t] = a[i][j];
					t++;
				}
			}
			det += pow(-1, k + 2) * a[0][k] * findDet(m, size - 1);
			deleteMatrix(m, size - 1);
		}
		return det;
	}
}

double **matrixMinor(double **matrix, int n, int a, int b)
{
	double **A = createMatrix<double>(n - 1, n - 1);
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			A[i][j] = matrix[i][j];
		}
		for (int j = b + 1; j < n; ++j)
		{
			A[i][j - 1] = matrix[i][j];
		}
	}
	for (int i = a + 1; i < n; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			A[i - 1][j] = matrix[i][j];
		}
		for (int j = b + 1; j < n; ++j)
		{
			A[i - 1][j - 1] = matrix[i][j];
		}
	}
	return A;
}

double** inv(double **A, int size)
{
	double det = findDet(A, size);
	if (det == 0)
	{
		throw "Determinant of input matrix is equal to 0";
	}
	double **result = createMatrix<double>(size, size);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			double **T = matrixMinor(A, size, j, i);
			result[i][j] = double(findDet(T, size - 1)) / det;
			if ((i + j) % 2)
				result[i][j] *= -1;

			if (result[i][j] == 0)
			{
				result[i][j] = 0;
			}
			deleteMatrix(T, size - 1);
		}
	}
	return result;
}

double **linspace(double first, double last, int n);
