#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }

    int j, k = 0, number = 1;

    while (number <= n * m)
    {
        k++;
        for (j = k - 1; j <= m - k; j++)
        {
            matrix[k - 1][j] = number++;
        }
        if (number - 1 >= n * m)
            break;
        for (j = k; j < n - k + 1; j++)
        {
            matrix[j][m - k] = number++;
        }
        if (number - 1 >= n * m)
            break;
        for (j = m - k - 1; j >= k - 1; j--)
        {
            matrix[n - k][j] = number++;
        }
        if (number - 1 >= n * m)
            break;
        for (j = n - k - 1; j >= k; j--)
        {
            matrix[j][k - 1] = number++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}