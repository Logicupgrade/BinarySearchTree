
#include "BinaryNodeTree.h"

bool BinaryNodeTree<ItemType>::isEmpty()
{
	return (numNodes == 0);
}

int BinaryNodeTree<ItemType>::getHeight()
{
	return treeHeight;
}

int BinaryNodeTree<ItemType>::getNumberOfNodes()
{
	return numNodes;
}

ItemType BinaryNodeTree<ItemType>::getRootData()
{
	return rootNodePtr->getItem();
}

void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
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

// void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&))
// {
// 	//if (!empty)
// 	//visit root
// 	//preOrder(left subtree)
// 	//preOrder(right subtree)
// }

// void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&))
// {
// 	//if (!empty)
// 	//inOrder(left subtree)
// 	//visit root
// 	//inOrder(right subtree)
// }

// void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&))
// {
// 	//if (!empty)
// 	//postOrder(left subtree)
// 	//postOrder(right subtree)
// 	//visit root
// }

//-1 = preorder, 0 = inorder, 1 = postorder
void BinaryNodeTree<ItemType>::traverse(void visit(ItemType&), int traverseType)
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
