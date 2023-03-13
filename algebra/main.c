#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	srand(time(NULL));
	int n = 1000; // rand() % 5 + 1;
	int m = 1000; // rand() % 5 + 1;
	int p = 1000; // rand() % 5 + 1;

	int **A = init_matrix(n, m);
	int **B = init_matrix(m, p);

	// show_matrix(A, n, m);
	// show_matrix(B, m, p);

	int **C = rc_product(A, B, n, m, p);
	// show_matrix(C, n, p);

	free_matrix(A, n);
	free_matrix(B, m);
	free_matrix(C, n);

	return 0;
}
