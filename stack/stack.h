#ifndef STACK_H
#define STACK_H

/* a positive-integer value stack, with no size limit */
typedef struct stack
{
	unsigned int inNode;
	stack* next;
} stack;
void showStack(stack* head);
void stackMain();
void push(stack* head, unsigned int element);
int pop(stack* head); // Return -1 if stack is empty
void initStack(stack* head, unsigned int addValue);
void initStack(stack* head);
void cleanStack(stack* head);
#endif // STACK_H