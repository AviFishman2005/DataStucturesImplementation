#ifndef BSNode_H
#define BSNode_H

#include <string>
#include <iostream>
class BSNode
{
public:
	BSNode(std::string data);
	BSNode(const BSNode& other);

	~BSNode();
	
	void insert(const std::string value);
	BSNode& operator=(const BSNode& other);

	bool isLeaf()const;
	std::string getData()const;
	BSNode* getLeft()const;
	BSNode* getRight()const;

	bool search(const std::string val)const;

	int getHeight()const;
	int getDepth(const BSNode& root)const;

	void printNodes() ; 

private:
	std::string _data;
	BSNode* _left;
	BSNode* _right;

	int _count; //to count replicates
	int getCurrNodeDistFromInputNode(const BSNode* node)const; //auxiliary function for getDepth

};

#endif