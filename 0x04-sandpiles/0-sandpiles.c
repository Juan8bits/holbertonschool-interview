#include "sandpiles.h"

/**
 * my_print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
void my_print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * sandpiles_sum - Sum two sandpiles.
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	unsigned int row, col;

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			grid1[row][col] = grid1[row][col] + grid2[row][col];
	while (!stable(grid1))
	{
		my_print_grid(grid1);
		expansion(grid1);
	}
}

/**
* stable - Determine if it is a stable sandpile or not.
* @grid: 3x3 grid
* Return: 1 on succes, 0 on failure.
*/
short int stable(int grid[3][3])
{
	unsigned int row, col;

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			if (grid[row][col] > 3)
				return (0);
	return (1);
}
/**
 * expansion - A function that extends around the sandpile a sum.
 * @grid: 3x3 grid
 */
void expansion(int grid[3][3])
{
	unsigned int row, col;

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
		{
			if (grid[row][col] > 3)
			{
				grid[row][col] -= 4;
				/*up*/
				if (row > 0)
					grid[row - 1][col] += 1;
				/*down*/
				if (row < 2 && (row + 1) < 3)
					grid[row + 1][col] += 1;
				/*left*/
				if (col > 0)
					grid[row][col - 1] += 1;
				/*right*/
				if (col < 2 && (col + 1) < 3)
					grid[row][col + 1] += 1;
			}
		}
}
