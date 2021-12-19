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

void **inv(double **A, int size)
{
	double det = findDet(A, size);
	if (det == 0)
	{
		throw "Determinant of input matrix is equal to 0";
	}

	double temp;
	double **E = new double *[size];
	for (int i = 0; i < size; i++)
	{
		E[i] = new double[size];
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			E[i][j] = 0;
			if (i == j)
			{
				E[i][j] = 1;
			}
		}

	for (int k = 0; k < size; k++)
	{
		temp = A[k][k];
		for (int j = 0; j < size; j++)
		{
			A[k][j] /= temp;
			E[k][j] /= temp;
		}

		for (int i = k + 1; i < size; i++)
		{
			temp = A[i][k];
			for (int j = 0; j < size; j++)
			{
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int k = size - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			temp = A[i][k];
			for (int j = 0; j < size; j++)
			{
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			A[i][j] = E[i][j];
		}
	}

	deleteMatrix(E, size);
}

double **linspace(double first, double last, int n);
