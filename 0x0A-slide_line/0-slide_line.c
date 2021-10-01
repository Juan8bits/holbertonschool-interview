#include "slide_line.h"

/**
* left - Reproduce 2048 game on one line, no memory allocation
* @line: Array of ints containing size elements
* @size: number of elements to slide
*/

void left(int *line, size_t size)
{
	size_t i, j = 0;

	for (i = 0; i < size; i++)
	{
		while (line[j] == 0 && j < size)
			j++;
		if (j >= size)
			break;
		line[i] = line[j];
		if (i != j && j < size)
			line[j] = 0;
		j++;
	}
}

/**
* right - Reproduce 2048 game on one line, no memory allocation
* @line: Array of ints containing size elements
* @size: number of elements to slide
*/

void right(int *line, size_t size)
{
	int i, j = 0;

	for (i = j = size - 1; i >= 0; i--)
	{
		while (line[j] == 0)
			j--;
		if (j < 0)
			break;
		line[i] = line[j];
		if (i != j)
			line[j] = 0;
		j--;
	}
}

/**
* merge - Reproduce 2048 game on one line, no memory allocation
* @line: Array of ints containing size elements
* @size: number of elements to slide
* @direction: direction
*/

void merge(int *line, size_t size, int direction)
{
	size_t i = size;

	if (direction == SLIDE_LEFT)
	{
		for (i = 1; i < size; i++)
		{
			if (line[i - 1] == line[i] && line[i] != 0)
				line[i - 1] = line[i - 1] * 2, line[i] = 0;
		}
	}
	if (direction == SLIDE_RIGHT)
	{
		for (i = size - 2; (int)i >= 0; i--)
		{
			if (line[i + 1] == line[i] && line[i] != 0)
				line[i + 1] = line[i + 1] * 2, line[i] = 0;
		}
	}
}

/**
* slide_line - Reproduce 2048 game on one line, no memory allocation
* @line: Array of ints containing size elements
* @size: number of elements to slide
* @direction: direction to slide (left or right, otherwise fail)
* Return: 1 upon success, 0 on failure
*/

int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
		left(line, size), merge(line, size, direction), left(line, size);
	else if (direction == SLIDE_RIGHT)
		right(line, size), merge(line, size, direction), right(line, size);
	else
		return (0);
	return (1);
}
