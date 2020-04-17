
#include "BinaryNode.h"

template <class ItemType>
BinaryNode<ItemType>::BinaryNode()
{
}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode( ItemType& newItem ):bNodeItem(newItem)
{
}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode( ItemType& newItem, BinaryNode<ItemType>* lPtr ):bNodeItem(newItem),
																					leftPtr(lPtr)
{

}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode( ItemType& newItem, 
									BinaryNode<ItemType>* lPtr,
									BinaryNode<ItemType>* rPtr ):bNodeItem(newItem),
																	leftPtr(lPtr),
																	rightPtr(rPtr)
{
}

// template <class ItemType>
// ~BinaryNode<ItemType>::BinaryNode()
// {
// }

template <class ItemType>
bool BinaryNode<ItemType>::addItem(ItemType& newItem)
{
	bNodeItem = newItem;
	return true;
}

template <class ItemType>
void BinaryNode<ItemType>::setLeft(BinaryNode<ItemType>* lPtr)
{
	leftPtr = lPtr;
}

template <class ItemType>
void BinaryNode<ItemType>::setRight(BinaryNode<ItemType>* rPtr)
{
	rightPtr = rPtr;
}

template <class ItemType>
ItemType BinaryNode<ItemType>::getItem()
{
	return bNodeItem;
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeft()
{
	return leftPtr;
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRight()
{
	return rightPtr;
}