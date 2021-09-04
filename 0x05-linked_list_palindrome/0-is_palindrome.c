#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Head of the list.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
	int buffer[10000];
	int j = 0, k = 0;
	listint_t *temp;

		if (head == NULL || *head == NULL || (*head)->next == NULL)
			return (1);

		temp = *head;

		while (temp != NULL)
		{
			buffer[j] = temp->n;
			temp = temp->next;
			j++;
		}

		while (k < (j / 2))
		{
			if (buffer[k] != buffer[j - k - 1])
				return (0);
			k++;
		}
		return (1);
}
