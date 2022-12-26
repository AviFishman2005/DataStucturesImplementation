#pragma once
#include <string>
#include <iostream>
template <class T>
class BSNode
{
public:
	BSNode(T data);
	BSNode(const BSNode& other);

	~BSNode();

	void insert(const T value);
	BSNode& operator=(const BSNode& other);

	bool isLeaf()const;
	T getData()const;
	BSNode* getLeft()const;
	BSNode* getRight()const;

	bool search(const T val)const;

	int getHeight()const;
	int getDepth(const BSNode& root)const;

	void printNodes();

private:
	T _data;
	BSNode* _left;
	BSNode* _right;

	int _count; //to count replicates
	int getCurrNodeDistFromInputNode(const BSNode* node)const; //auxiliary function for getDepth
};


template <class T>
BSNode<T>::BSNode(T data)
{

	this->_data = data;
	this->_left = nullptr;
	this->_right = nullptr;
	this->_count = 0;
}
template <class T>
BSNode<T>::BSNode(const BSNode<T>& other)
{
	this->_data = other._data;
	this->_count = other._count;
	if (this->getLeft())
	{
		this->_left = new BSNode(*this->getLeft());
	}
	if (this->getRight())
	{
		this->_right = new BSNode(*this->getRight());
	}
}
template <class T>
BSNode<T>::~BSNode()
{
}
template <class T>

void BSNode<T>::insert(const T value)
{
	if (value > this->_data)
	{
		if (this->_right == nullptr)
		{
			this->_right = new BSNode(value);
		}
		else
		{
			this->_right->insert(value);
		}
	}
	else if (value < this->_data)
	{
		if (this->_left == nullptr)
		{
			this->_left = new BSNode(value);
		}
		this->_left->insert(value);
	}
	else if (value == this->_data)
	{
		this->_count += 1;
	}

}
template <class T>

BSNode<T>& BSNode<T>::operator=(const BSNode& other)
{

	this->_data = other._data;
	this->_count = other._count;
	if (this->getLeft())
	{
		this->_left = new BSNode(*this->getLeft());
	}
	if (this->getRight())
	{
		this->_right = new BSNode(*this->getRight());
	}
	return *this;
}
template <class T>

bool BSNode<T>::isLeaf() const
{
	bool isLeaf = true;
	if (this->getLeft() || this->getRight())
	{
		isLeaf = false;
	}
	return isLeaf;
}
template <class T>

T BSNode<T>::getData() const
{
	return this->_data;
}
template <class T>

BSNode<T>* BSNode<T>::getLeft() const
{
	if (this->_left == nullptr)
	{
		return nullptr;
	}
	return this->_left;
}
template <class T>

BSNode<T>* BSNode<T>::getRight() const
{

	if (this->_right == nullptr)
	{
		return nullptr;
	}
	return this->_right;
}
template <class T>

bool BSNode<T>::search(const T val) const
{
	bool found = false;
	if (this->getData() == val)
	{
		return true;
	}
	if (this->getLeft())
	{
		found = this->getLeft()->search(val);
	}
	if (this->getRight())
	{
		if (!found)
		{
			found = this->getRight()->search(val);
		}
	}
	return found;
}

// find height
template <class T>
int BSNode<T>::getHeight() const
{
	int heightL = 1;
	int heightR = 1;
	if (this->isLeaf() == false)
	{
		if (this->getLeft() != nullptr)
		{
			heightL += this->getLeft()->getHeight();

		}
		if (this->getRight() != nullptr)
		{
			heightR += this->getRight()->getHeight();

		}
	}
	if (heightL > heightR)
	{
		return heightL;
	}
	else
	{
		return heightR;
	}
}

//return depth using other function
template <class T>

int BSNode<T>::getDepth(const BSNode& root) const
{
	if (this)
	{
		return root.getCurrNodeDistFromInputNode(this);
	}
	return 0;
}

template <class T>
void BSNode<T>::printNodes()
{


	if (this->getLeft())
	{

		/* first recur on left child */
		this->getLeft()->printNodes();
	}

	/* then print the data of node */
	std::cout << this->getData() << " ";
	if (this->getRight())
	{

		/* now recur on right child */
		this->getRight()->printNodes();
	}







}
//function based on the search function that counts each etiration from this
template <class T>
int BSNode<T>::getCurrNodeDistFromInputNode(const BSNode* node) const
{
	int dest = 1;
	if (this)
	{
		if (this->getData() != node->getData())
		{
			if (this->getLeft())
			{
				dest += this->getLeft()->getCurrNodeDistFromInputNode(node);
			}
			else if (this->getRight())
			{

				dest += this->getRight()->getCurrNodeDistFromInputNode(node);

			}
		}
	}

	return dest;



}

