#include "main.h"
/**
 * popfun - main entry
 * @headEntry: is a variable head
 * @count: counter
 * Return: void
*/
void popfun(stack_t **headEntry, unsigned int count)
{
	stack_t *head;

	if (*headEntry == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(extent.fileList);
		free(extent.contentList);
		free_stack(*headEntry);
		exit(EXIT_FAILURE);
	}
	head = *headEntry;
	*headEntry = head->next;
	free(head);
}
