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
T **multi(T lambda, T **M, int rows, int columns)
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
double det(double **M, int N)
{
	double determinant;
	int sub_j, minor_sign;
	double **subM;
	switch (N)
	{
	case 1:
		return M[0][0];
	case 2:
		return M[0][0] * M[1][1] - M[0][1] * M[1][0];
	default:
		if (N < 1)
			return 0; // error
		subM = new double *[N - 1];
		determinant = 0;
		minor_sign = 1;
		for (int i = 0; i < N; i++) // Разложение по первому столбцу
		{
			sub_j = 0;
			for (int j = 0; j < N; j++)
				if (i != j)					  // исключить i строку
					subM[sub_j++] = M[j] + 1; // здесь + 1 исключает первый столбец

			determinant = determinant + minor_sign * M[i][0] * det(subM, N - 1);
			minor_sign = -minor_sign;
		};
		delete[] subM;
		return determinant;
	};
};

T **inv(double **matr, int n)
{
	double **obr_matr = new double *[n];
	if (det(matr, n))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int m = n - 1;
				int **temp_matr = new int *[m];
				for (int k = 0; k < m; k++)
					temp_matr[k] = new int[m];
				Get_matr(matr, n, temp_matr, i, j);
				obr_matr[i][j] = pow(-1.0, i + j + 2) * det(temp_matr, m) / det;
			}
		}
	}
	else
		std::cout << "матрица вырожденная" << std::endl;
	return obr_matr;

}
void Get_matr(double **matr, int n, int **temp_matr, int indRow, int indCol)
{

	int ki = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != indRow)
		{
			for (int j = 0, kj = 0; j < n; j++)
			{
				if (j != indCol)
				{
					temp_matr[ki][kj] = matr[i][j];
					kj++;
				}
			}
			ki++;
		}
	}
}
double **linspace(double first, double last, int n);
