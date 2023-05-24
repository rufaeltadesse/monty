#include "main.h"
/**
 * pallfun - main entry
 * @headEntry: head entry
 * @count: counter
 * Return: void
*/
void pallfun(stack_t **headEntry, unsigned int count)
{
	stack_t *head;
	(void)count;

	head = *headEntry;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
