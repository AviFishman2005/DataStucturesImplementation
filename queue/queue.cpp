#include "queue.h"
#include <iostream>
using namespace std;
/*
This function intialises the queue
Input: pointer to the queue struct and the size of the queue
*/
void initQueue(queue* q, unsigned int size)
{
	q->inQueue = new unsigned int[size];
	q->size = size;
	// -1 because 0 is the first place in the queue
	q->rear = -1;
	q->front = -1;
}
/*
This function releases the memory of the queue
Input: pointer to queue struct
*/
void cleanQueue(queue* q)
{
	delete[] q->inQueue;
	delete(q);
}
/*
This function adds a new value to the queue by adding one 
to the variable that decides the rear. Then it assignes the inputed value in to it
Input: Pointer to struct q
*/
void enqueue(queue* q, unsigned int newValue)
{
	if (q->rear == q->size -1)
	{
		cout << "Queue is full\n";
	}
	else
	{
		if (q->front == -1)
		{
			q->front = 0;
		}
		q->rear++;
		q->inQueue[q->rear] = newValue;
		
	}
}
/*
This function removes item from queue by moving the front by one
Input: pointer to struct
*/
int dequeue(queue* q)
{
	int returnValue = 0;
	if (q->front == -1 && q->rear == -1)
	{
		cout << "Queue is empty\n";
	}
	else
	{
		if (q->front == q->rear)
		{
			q->front = q->rear = - 1;
		}
		else
		{
			q->front++;
		}
	}
	if (q->front != -1)
	{
		returnValue = q->inQueue[q->front];
	}
	else
	{
		returnValue = -1;
	}
	return returnValue;
}