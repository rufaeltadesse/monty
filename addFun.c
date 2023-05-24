#include "monty.h"
/**
 * addfun - main entry
 * @headEntry: is a variable
 * @count: counter
 * Return: void
*/
void addfun(stack_t **headEntry, unsigned int count)
{
	stack_t *first;
	int length = 0, varA;

	first = *headEntry;
	while (first)
	{
		first = first->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(extent.fileList);
		free(extent.contentList);
		free_stack(*headEntry);
		exit(EXIT_FAILURE);
	}
	first = *headEntry;
	varA = first->n + first->next->n;
	first->next->n = varA;
	*headEntry = first->next;
	free(first);
}
