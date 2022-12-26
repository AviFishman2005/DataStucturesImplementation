#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#define EMPTY 0
class Vector
{
private:
	//Fields
	int* _elements;
	int _capacity; //Total memory allocated
	int _size; //Size of vector to access
	int _resizeFactor; // how many cells to add when need to reallocate
public:

	//A
	Vector(int n = 10);
	~Vector();
	int size() const;//return size of vector
	int capacity() const;//return capacity of vector
	int resizeFactor() const; //return vector's resizeFactor
	bool empty() const; //returns true if size = 0

	//B
	//Modifiers
	void push_back(const int& val);//adds element at the end of the vector
	int pop_back();//removes and returns the last element of the vector
	void reserve(const int n);//change the capacity
	void resize(const int n);//change _size to n, unless n is greater than the vector's capacity
	void assign(const int val);//assigns val to all elemnts
	void resize(const int n, const int& val);//same as above, if new elements added their value is val

	//C
	//The big three (d'tor is above)
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);

	//D
	//Element Access
	int& operator[](int n) const;//n'th element

	//E
	// (Bonus) - Operator Overloading
};

#endif