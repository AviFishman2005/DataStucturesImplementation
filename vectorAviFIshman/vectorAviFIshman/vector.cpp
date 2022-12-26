#include "vector.h"
// initialize vector
Vector::Vector(int n)
{
	if (2 >= n)
	{
		n = 2;
	}
	this->_elements = new int[n];
	this->_capacity = n;
	this->_size = 0;
	this->_resizeFactor = n;
}
// free array memeory in vector
Vector::~Vector()
{
	delete []_elements;
}

int Vector::size() const
{
	return this->_size;
}

int Vector::capacity() const
{
	return this->_capacity;
}
//amount to resize every time
int Vector::resizeFactor() const
{
	return this->_resizeFactor;
}
//check if empty
bool Vector::empty() const
{
	return (EMPTY == this->_size);
}
// add element to vector
void Vector::push_back(const int& val)
{
	int i = 0;
	//If vector full resize memory to resize factor
	if (this->_capacity == this->_size)
	{
		int* temp = new int[this->_resizeFactor + this->_capacity];
		// add existing values to newly allocated array
		for (i = 0; i < this->_capacity; i++)
		{
			temp[i] = this->_elements[i];
		}
		delete[] this->_elements;
		this->_capacity += this->_resizeFactor;
		this->_elements = temp;
	}
	this->_elements[this->_size] = val;
	this->_size++;
}
//delete last element in string 
int Vector::pop_back()
{
	int returnElement = 0;
	//Check if array empty
	if (this->empty())
	{
		std::cout << "error: pop from empty\n";
		returnElement = -9999;
	}
	else
	{
		//delete last element
		returnElement = this->_elements[this->_size - 1];
		this->_elements[this->_size - 1] = NULL;
		this->_size--;
	}
	return returnElement;
}
//change the capasity in units of resizefactor
void Vector::reserve(const int n)
{
	int i = 0;
	//amount of times to double 
	int doubleBy = 0;
	if (this->_capacity < n)
	{
		// add existing values to newly allocated array
		while(this->_resizeFactor *  doubleBy + this->_capacity < n)
		{
			doubleBy += 1;
		}
		int* temp = new int[doubleBy * this->_resizeFactor +  this->_capacity];
		for (i = 0; i < this->_capacity; i++)
		{
			temp[i] = this->_elements[i];
		}
		delete[] this->_elements;
		this->_capacity += this->_resizeFactor * doubleBy;
		this->_elements = temp;
	}
}
// changes size to n and refactors vector
void Vector::resize(const int n)
{
	int i = 0;
	if (n <= this->_capacity)
	{
		if (n >= this->_size)
		{
			//delete all elements that are under index n
			while(this->_size <= n)
			{
				this->pop_back();
			}
		}
	}
	if (n > this->_capacity)
	{
		this->reserve(n);
	}
	this->_size = n;
}
//insert val into all free places in array
void Vector::assign(const int val)
{
	int i = 0;
	for (i = 0; i < this->_size; i++)
	{
		this->_elements[i] = val;
	}
}
// resize just filling element with something
void Vector::resize(const int n, const int& val)
{
	int i = 0;
	if (n <= this->_capacity)
	{
		if (n >= this->_size)
		{
			//delete all elements that are under index n
			while (this->_size <= n)
			{
				this->pop_back();
			}
		}
	}
	if (n > this->_capacity)
	{
		this->reserve(n);
		while (this->_size <= n)
		{
			this->push_back(val);
		}
	}
	this->_size = n;
}
//shallow copy 
Vector::Vector(const Vector& other)
{
		this->_capacity = other._capacity;
	this->_resizeFactor = other._resizeFactor;
	this->_size = other._size;
	this->_elements = new int[other._capacity];
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = other._elements[i];
	}
}
// return copy of vector
Vector& Vector::operator=(const Vector& other)
{
	this->_capacity = other._capacity;
	this->_resizeFactor = other._resizeFactor;
	this->_size = other._size;
	this->_elements = new int[other._capacity];
	for (int i = 0; i < this->_size; i++)
	{
		this->_elements[i] = other._elements[i];
	}
	return *this;
}
//Return value at index n or if out of range index 0
int& Vector::operator[](int n) const
{
	int none = 0;
	if (n >= this->_size || n < 0)
	{
		std::cerr << "index does not exist\n";
		return this->_elements[0];
	}
	return this->_elements[n];
}

