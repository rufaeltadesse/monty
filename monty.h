#ifndef CLASSPROTOTYPES
#define CLASSPROTOTYPES
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct extentS - main entry
 * @argList: value
 * @fileList: pointer file
 * @contentList: line
 * @lastInFirstIn: lst in first out
 */
typedef struct extentS
{
	char *argList;
	FILE *fileList;
	char *contentList;
	int lastInFirstIn;
}  extentT;
extern extentT extent;

void pushfun(stack_t **head, unsigned int number);
void pallfun(stack_t **head, unsigned int number);
void pintfun(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void popfun(stack_t **head, unsigned int counter);
void swapfun(stack_t **head, unsigned int counter);
void addfun(stack_t **head, unsigned int counter);
void nopfun(stack_t **head, unsigned int counter);
void readList(stack_t **head, unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
#endif
