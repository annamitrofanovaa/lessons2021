#include <iostream>
#include "matrix.h"

double **linspace(double first, double last, int n)
{
	if (n < 2)
		throw "linspace arguments error (n<2)";

	double step = (last - first) / (n - 1);

	double **M = createMatrix<double>(1, n);
	for (int i = 0; i < n; ++i)
		M[0][i] = first + i * step;
	return M;
}
