#include "stack.h"
#include <iostream>
using namespace std;
enum menu { INIT = 1,ADD, REMOVE, SHOW, EXIT };
/*
###
Disclamer: the main must be used together with 
the functions because the functions could not be pointer to pointer
###
*/
void stackMain()
{
    int choice = 0;
    unsigned int addValue = 0;
    stack* head = NULL;
    head = new stack;
    head->next = NULL;
    //Simple menu for easy checking
    initStack(head);
    do
    {
        cout << "stack menu:\n1: init and clear stack\n2: add to stack\n3: remove from stack\n4: show\n5:exit\n";
        cin >> choice;
        if (EXIT != choice)
        {
            if (INIT == choice)
            {
                if (head->next != NULL)
                {
                    cleanStack(head);
                }
                stack* head = NULL;
                head = new stack;
                initStack(head);
            }
            if (ADD == choice)
            {
                cout << "enter add value\n";
                cin >> addValue;
                if (head != NULL)
                {
                    push(head, addValue);
                }
                else
                {
                    stack* head = new (stack);
                    initStack(head, addValue);
                }
            }
            else if (REMOVE == choice)
            {
                if (pop(head) == -1)
                {
                    head = NULL;
                }
            }
            else if (SHOW == choice)
            {
                showStack(head);
            }
        }
    } while (EXIT != choice);
}
/*
This function prints every item in the stack
Input: pointer to head of stack
*/
void showStack(stack* head)
{
    stack* temp = head;
    if (temp != NULL)
    {

        while (temp != NULL)
        {
            cout << temp->inNode << endl;
            temp = temp->next;
        }
    }
    else
    {
        cout << "stack is empty" << endl;
    }
}
/*
This function intiats stack with givin input
*/
void initStack(stack* head,unsigned int addValue)
{
    head->inNode = addValue;
    head->next = NULL;
}
/*
This function intiats stack
*/
void initStack(stack* head)
{
    unsigned int addValue = 0;
    cout << "enter value for first item in stack:";
    cin >> addValue;
    head->inNode = addValue;
    head->next = NULL;
}
/*
This function cleans entire stack
*/
void cleanStack(stack* head)
{
    stack* nextStack = head;
    stack* cur = NULL;
    while (nextStack)
    {
        cur = nextStack->next;
        delete(nextStack);
        nextStack = cur;
    }
}
/*
This function removes the last node in the stack
Input : pointer to pointer of stack
Output : the value of the deleted node or -1 of empty
*/
int pop(stack* head)
{
    int returnValue = 0;
    stack* nextStack = head;
    stack* prev = NULL;
    while (nextStack->next)
    {
        prev = nextStack;
        nextStack = nextStack->next;
    }
    if (prev == NULL)
    {
        returnValue = -1;
        delete(head);
    }
    else
    {
        returnValue = nextStack->inNode;
        delete(nextStack);
        prev->next = NULL;
    }
    return returnValue;
}
/*
This function adds node to stack
Input: poiter to pointer of new node and pointer to pointer of head
Output: none
*/
void push(stack* head, unsigned int element)
{
    stack *newNode = new stack;
    newNode->inNode = element;
    newNode->next = NULL;
    stack* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;

    }
    temp->next = newNode;
}


