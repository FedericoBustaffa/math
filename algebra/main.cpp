#include <iostream>

#include "mat.h"

int **rc_product(int **a, int **b, int n, int m, int p)
{
	int **c = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		c[i] = (int *)malloc(p * sizeof(int));
		for (int j = 0; j < p; j++)
			c[i][j] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < p; j++)
		{
			for (int k = 0; k < m; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return c;
}

int **init_matrix(int n, int m)
{
	int **M = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		M[i] = (int *)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++)
			M[i][j] = rand() % 10;
	}

	return M;
}

void show_matrix(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void free_matrix(int **a, int n)
{
	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
}

int main()
{
	mat<int, 1000, 1000> a;
	mat<int, 1000, 1000> b;
	mat<int, 1000, 1000> c;

	return 0;
}
