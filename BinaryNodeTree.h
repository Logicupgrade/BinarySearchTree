
#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"

template <class ItemType>
class BinaryNodeTree: public BinaryTreeInterface<ItemType>
{
private:
	int treeHeight;
	int numNodes;
	BinaryNode<ItemType>* rootNodePtr;
public:
	// bool isEmpty();
	// int getHeight();
	// int getNumberOfNodes();
	// ItemType getRootData();
	// void setRootData(const ItemType& newData);
	// bool add(const ItemType& newData);
	// bool remove(const ItemType& data);
	// void clear();
	// ItemType getEntry(const ItemType& anEntry);
	// bool contains(const ItemType& anEntry);
	// void preorderTraverse(void visit(ItemType&));
	// void inorderTraverse(void visit(ItemType&));
	// void postorderTraverse(void visit(ItemType&));
};

#endif