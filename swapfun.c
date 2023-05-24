#include "main.h"
/**
 * swapfun - main entry
 * @headEntry: is a function
 * @count: count
 * Return: void
*/
void swapfun(stack_t **headEntry, unsigned int count)
{
	stack_t *first;
	int length = 0;
	int varA;

	first = *headEntry;
	while (first)
	{
		first = first->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(extent.fileList);
		free(extent.contentList);
		free_stack(*headEntry);
		exit(EXIT_FAILURE);
	}
	first = *headEntry;
	varA = first->n;
	first->n = first->next->n;
	first->next->n = varA;
}
