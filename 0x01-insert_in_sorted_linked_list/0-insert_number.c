#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Insert new node on a order single linked list.
 * @head: pointer to list to be added.
 * @number: New node value.
 * Return: Structure with a new node added. On failure NULL.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *copy_head;
	listint_t *new;

	if (!head || !*head)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	copy_head = *head;
	while (copy_head)
	{
/*Checking the first SLL element*/
		if (copy_head == *head && number <= copy_head->n)
		{
			new->next = copy_head;
			*head = new;
			break;
		}
/*Checking for SSL element different to the first and last*/
		else if (copy_head->next != NULL)
		{
			if (number <= (copy_head->next)->n)
			{
				new->next = copy_head->next;
				copy_head->next = new;
				break;
			}
		}
/*Checking for the last SSL element*/
		else if (copy_head->next == NULL)
		{
			copy_head->next = new;
			new->next = NULL;
			break;
		}
		copy_head = copy_head->next;
	}
	return (new);
}
