#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef struct linkedList {
	unsigned int inNode = 0;
	linkedList* next;
} linkedList;
void linkedListMain();
void removeNode(linkedList** head);
void addNode(linkedList** head, linkedList** newNode);

#endif 