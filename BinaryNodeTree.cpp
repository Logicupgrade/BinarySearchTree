
#include "BinaryNodeTree.h"

bool BinaryNodeTree<ItemType>::isEmpty()
{
	return true;
}

int BinaryNodeTree<ItemType>::getHeight()
{
	return 0;
}

int BinaryNodeTree<ItemType>::getNumberOfNodes()
{
	return 0;
}

ItemType BinaryNodeTree<ItemType>::getRootData()
{
	return rootNode->getItem();
}

void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{

}

bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
	return true;
}

bool BinaryNodeTree<ItemType>::remove(const ItemType& data)
{
	return true;
}

void BinaryNodeTree<ItemType>::clear()
{

}

ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry)
{
	return rootNode->getItem();
}

bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry)
{
	return true;
}

void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&))
{

}

void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&))
{

}

void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&))
{

}
