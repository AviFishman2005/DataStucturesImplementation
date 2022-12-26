#include "linkedList.h"
#include <iostream>
using namespace std;
enum menu { ADD = 1, REMOVE, SHOW, EXIT };
void linkedListMain()
{
    int choice = 0;
    linkedList* head = NULL;
	linkedList* newNode = NULL;
	//Simple menu for easy checking
	do
	{
		cout << "list menu:\n1: add to list\n2: remove from list\n3: show\n4:exit\n";
		cin >> choice;
		if (EXIT != choice)
		{
			if (ADD == choice)
			{
				
				addNode(&head, &newNode);
			}
			else if (REMOVE == choice)
			{
				removeNode(&head);
			}
			else if (SHOW == choice)
			{
                linkedList* temp = head;
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
                    cout << "List is empty";
                }
			}
		}
	} while (EXIT != choice);
}
/*
This function removes the last node in the linked list
Input: pointer to pointer of linked list
Output: Node
*/
void removeNode(linkedList** head)
{
    if (*head != NULL)
    {

        if ((*head)->next == NULL)
        {
            *head = NULL;
        }
        else
        {
            linkedList* temp = *head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            linkedList* lastNode = temp->next;
            temp->next = NULL;
            delete(lastNode);
        }
    }
}
/*
This function adds node to linked list
Input: poiter to pointer of new node and pointer to pointer of head
Output: none
*/
void addNode(linkedList** head, linkedList** newNode)
{
    cout << "enter value to list" << endl;
    *newNode = new linkedList;
    cin >> (*newNode)->inNode;
    (*newNode)->next = NULL;
    if (*head != NULL)
    {
        linkedList* temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;

        }
        temp->next = *newNode;
    }
    else
    {
        (*head) = (*newNode);
    }
}


