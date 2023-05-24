#include "main.h"
/**
* free_stack - main entry
* @headEntry: is a variable
* Return: void
*/
void free_stack(stack_t *headEntry)
{
	stack_t *varA;

	varA = headEntry;
	while (headEntry)
	{
		varA = headEntry->next;
		free(headEntry);
		headEntry = varA;
	}
}
/**
 * addnode - main entry
 * @headEntry: variable for head
 * @n: new value
 * Return: void
*/
void addnode(stack_t **headEntry, int n)
{
	stack_t *firstNode, *varA;

	varA = *headEntry;
	firstNode = malloc(sizeof(stack_t));
	if (firstNode == NULL)
	{ printf("Error\n");
		exit(0); }
	if (varA)
		varA->prev = firstNode;
	firstNode->n = n;
	firstNode->next = *headEntry;
	firstNode->prev = NULL;
	*headEntry = firstNode;
}

/**
 * addqueue - main entry
 * @n: new value
 * @headEntry: is variable
 * Return: no return
*/
void addqueue(stack_t **headEntry, int n)
{
	stack_t *firstNode, *varA;

	varA = *headEntry;
	firstNode = malloc(sizeof(stack_t));
	if (firstNode == NULL)
	{
		printf("Error\n");
	}
	firstNode->n = n;
	firstNode->next = NULL;
	if (varA)
	{
		while (varA->next)
			varA = varA->next;
	}
	if (!varA)
	{
		*headEntry = firstNode;
		firstNode->prev = NULL;
	}
	else
	{
		varA->next = firstNode;
		firstNode->prev = varA;
	}
}


/**
 * pushfun - main entry
 * @headEntry: variable for head
 * @count: counter
 * Return: void
*/
void pushfun(stack_t **headEntry, unsigned int count)
{
	int n; 
	int j = 0;
	int flagCount = 0;

	if (extent.argList)
	{
		if (extent.argList[0] == '-')
			j++;
		for (; extent.argList[j] != '\0'; j++)
		{
			if (extent.argList[j] > 57 || extent.argList[j] < 48)
				flagCount = 1; }
		if (flagCount == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(extent.fileList);
			free(extent.contentList);
			free_stack(*headEntry);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(extent.fileList);
		free(extent.contentList);
		free_stack(*headEntry);
		exit(EXIT_FAILURE); }
	n = atoi(extent.argList);
	if (extent.lastInFirstIn == 0)
		addnode(headEntry, n);
	else
		addqueue(headEntry, n);
}
