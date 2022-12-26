#include "BSNode.h"

BSNode::BSNode(std::string data)
{

	this->_data = data;
	this->_left = nullptr;
	this->_right = nullptr;
	this->_count = 0;
}

BSNode::BSNode(const BSNode& other)
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

BSNode::~BSNode()
{
}

void BSNode::insert(const std::string value)
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

BSNode& BSNode::operator=(const BSNode& other)
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

bool BSNode::isLeaf() const
{
	bool isLeaf = true;
	if (this->getLeft() || this->getRight() )
	{
		isLeaf = false;
	}
	return isLeaf;
}

std::string BSNode::getData() const
{
	return this->_data;
}

BSNode* BSNode::getLeft() const
{
	if (this->_left == nullptr)
	{
		return nullptr;
	}
	return this->_left;
}

BSNode* BSNode::getRight() const
{

	if (this->_right == nullptr)
	{
		return nullptr;
	}
	return this->_right;
}

bool BSNode::search(const std::string val) const
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
int BSNode::getHeight() const
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
int BSNode::getDepth(const BSNode& root) const
{
	return root.getCurrNodeDistFromInputNode(this);
}

void BSNode::printNodes()
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
int BSNode::getCurrNodeDistFromInputNode(const BSNode* node) const
{
	int dest = 1;
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
	return dest;


	
}
