
#include "BinarySearchTree.h"

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::search(ItemType& value)
{
	//start with root
	//compare
	//search right or left
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty()const
{
	return (numNodes == 0);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight()const
{
	return treeHeight;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes()const
{
	return numNodes;
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData()const
{
	return rootNodePtr->getItem();
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
	if(numNodes > 0)
	{
		rootNodePtr->setItem(newData);
	}
	else
	{
		add(newData);
	}
}

//***start here

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
	return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& data)
{
	return true;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{

}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry)const
{
	return rootNode->getItem();
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry)const
{
	return true;
}

//-1 = preorder, 0 = inorder, 1 = postorder

template<class ItemType>
void BinarySearchTree<ItemType>::traverse(void visit(ItemType&), int traverseType)const
{
	//if (!isEmpty)
		//if(traverseType == -1)
			//visit root
		//traverse(left subtree)
		//if(traverseType == 0)
			//visit root
		//traverse(right subtree)
		//if(traverseType == 1)
			//visit root
}
