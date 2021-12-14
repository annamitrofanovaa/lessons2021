#pragma once

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
	do
	{
		std::cout << "rows = ";
		std::cin >> rows;
	} while (rows < 1);

	do
	{
		std::cout << "columns = ";
		std::cin >> columns;
	} while (columns < 1);
	T **M = createMatrix<T>(rows, columns);
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
		{
			std::cout << "matrix(" << i + 1 << "," << j + 1 << ") = ";
			std::cin >> M[i][j];
		}
	return M;
}

template <typename T>
T det(T **M, int rows, int columns)
{
	/*Вычисление определителя матрицы*/
}

double inv(double **A, int n); // Обратная к квадратной матрице A (n x n).
// Если обратная не существует, должно генерироваться исключение

double **linspace(double first, double last, int n);
