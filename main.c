#include "monty.h"
/**
* main - main entry
* @argc: argument count
* @argv: vector
* Return: 0
*/
int main(int argc, char *argv[])
{
	extentT extent = {NULL, NULL, NULL, 0};
	ssize_t readList = 1;
	FILE *fileList;
	char *contentList;
	size_t sizeList = 0;
	unsigned int counter = 0;
	stack_t *stackList = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileList = fopen(argv[1], "r");
	extent.fileList = fileList;
	if (!fileList)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readList > 0)
	{
		contentList = NULL;
		readList = getline(&contentList, &sizeList, fileList);
		extent.contentList = contentList;
		counter++;
		if (readList > 0)
		{
			execute(contentList, &stackList, counter, fileList);
		}
		free(contentList);
	}
	free_stack(stackList);
	fclose(fileList);
return (0);
}
