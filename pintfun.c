#include "main.h"
/**
 * pintfun - main entry
 * @headEntry: variable for head
 * @count: counter
 * Return: void
*/
void pintfun(stack_t **headEntry, unsigned int count)
{
	if (*headEntry == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(extent.fileList);
		free(extent.contentList);
		free_stack(*headEntry);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*headEntry)->n);
}
