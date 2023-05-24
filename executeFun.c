#include "monty.h"
/**
* execute - main entry
* @head: variable head
* @count: counter
* @fileList: file list
* @contentList: content list
* Return: no return
*/
int execute(char *contentList, stack_t **head, unsigned int count, FILE *fileList)
{
	instruction_t opstatus[] = {
				{"push", pushfun}, {"pall", pallfun}, {"pint", pintfun},
				{"pop", popfun},
				{"swap", swapfun},
				{"add", addfun},
				{"nop", nopfun},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *oper;

	oper = strtok(contentList, " \n\t");
	if (oper && oper[0] == '#')
		return (0);
	extent.argList = strtok(NULL, " \n\t");
	while (opstatus[i].opcode && oper)
	{
		if (strcmp(oper, opstatus[i].opcode) == 0)
		{	opstatus[i].f(head, count);
			return (0);
		}
		i++;
	}
	if (oper && opstatus[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unk %s\n", count, oper);
		fclose(fileList);
		free(contentList);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	return (1);
}

