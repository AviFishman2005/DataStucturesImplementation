#ifndef QUEUE_H
#define QUEUE_H

#define SIZE 32
/* a queue contains positive integer values. */
typedef struct queue
{
	unsigned int * inQueue;
	unsigned int size = 0;
	int front = 0;
	int rear = 0;
} queue;

void initQueue(queue* q, unsigned int size);
void cleanQueue(queue* q);

void enqueue(queue* q, unsigned int newValue);
int dequeue(queue* q); // return element in top of queue, or -1 if empty
#endif 