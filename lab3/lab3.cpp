#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	binaryTree* tree = new binaryTree(16);
	tree->insert(7);
	tree->insert(1);
	tree->insert(13);
	tree->insert(4);
	tree->insert(3);
	tree->insert(10);
	tree->insert(14);
	tree->insert(6);

	cout << "Deth-first traverse: \n";
	NLRIterator* nlr_iterator = tree->createNLRIterator();
	while (nlr_iterator->hasNext())
		cout << nlr_iterator->next()->key << " ";

	cout << endl << "Breadth-first travers: \n";;
	BFSIterator* bfs_iterator = tree->createBFSIterator();
	while (bfs_iterator->hasNext())
		cout << bfs_iterator->next()->key << " ";

	return 0;
}
