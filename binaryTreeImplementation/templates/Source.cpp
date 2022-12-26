#pragma once
#include <iostream>
#include "BSNode.h"
//can compair any two ints
template <typename T>
int compair(T x, T y)
{
	if (x != y)
	{
		return (x > y) ? -1 : 1;
	}
	return 0;
}
// Template is used here so a user can sort any class he wants
template <class T>
void bubbleSort(T a[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; i < j; j--)
		{
			if (a[j] < a[j - 1])
			{
				std::swap(a[j], a[j - 1]);

			}
		}
			
	}
	
}
// Template is used here so a user can sort any class he wants
template <class T>
void printSort(T a[], int n)
{
	bubbleSort<int>(a, n);

	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << "\n";

	}
	std::cout << "\n";
}
int main()
{

	int tInt[15] = { };
	std::string tStr = "";
	for (int i = 0; i < 15; i++)
	{
		tInt[i] = rand() % 10;
		tStr += rand() % 10 + 48;
	}
	for (int i = 0; i < 15; i++)
	{
		std::cout << tInt[i] << " ";
		
	}
	std::cout << "\n " << tStr;

	BSNode<char>* bsS = new BSNode<char>(tStr[0]);
	BSNode<int>* bsI = new BSNode<int>(tInt[0]);
	for (int i = 1; i < 15; i++)
	{
		bsI->insert(tInt[i]);
		bsS->insert(tStr[i]);
	}
	std::cout << "\nstring sorted\n";
	bsS->printNodes();
	std::cout << "\nint array sorted\n";
	bsI->printNodes();

	int n = 3;
	/*BSNode<char>* bs = new BSNode<char>('6'); **For testing**
	bs->insert('2');
	bs->insert('8');
	bs->insert('3');
	bs->insert('5');
	bs->insert('9');
	bs->insert('6');


	std::cout << "Tree height: " << bs->getHeight() << std::endl;
	std::cout << "depth of node with 5 depth: " << bs->getLeft()->getRight()->getRight()->getDepth(*bs) << std::endl;
	std::cout << "depth of node with 3 depth: " << bs->getLeft()->getRight()->getDepth(*bs) << std::endl;
	std::cout << "found - true: " << bs->search('9') << std::endl;
	std::cout << "found - false: " << bs->search('4') << std::endl;
	bs->printNodes();*/


	//printSort(a,n);
	return 0;
}