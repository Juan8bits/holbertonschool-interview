#include "menger.h"

/**
* menger - draws a 2d menger sponge.
* @level: level of menger sponge to draw (do nothing < 0)
*/
void menger(int level)
{
	int side = pow(3, level), i, j, d;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	for (i = 0; i < side; i++)
	{
		for (j = 0; j < side; j++)
		{
			for (d = side; d; d /= 3)
			{
				if (((i % 3 == 1) && (j % 3 == 1)) || (i % (3 * level) / level == 1 && j % (3 * level) / level == 1))
					break;
			}
			if (d)
			{
				printf(" ");
			}
			else
				printf("#");
		}
		printf("\n");

	}
}
