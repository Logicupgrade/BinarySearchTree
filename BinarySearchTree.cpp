
#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

//returns ptr to leaf node's child position or a ptr to BinaryNode with value
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::search(const ItemType& value, BinaryNode<ItemType>* currentRootPtr )
{ 

	//compare
	if( isEmpty() )
	{

		return nullptr;
	}

	else if ( currentRootPtr->getItem() == value )
	{
		return currentRootPtr;
	}

	//search right or left
	else if(value < currentRootPtr->getItem() )
	{

		if(currentRootPtr->getLeft() == nullptr)
		{
		}
		else
		{
			//if child is value store currentRootPtr
			if( currentRootPtr->getLeft()->getItem() == value )
			{
				oneUp = currentRootPtr;
				oneUpIsLeft = true;
			}

			currentRootPtr = search( value, currentRootPtr->getLeft() );
		}
	}
	else
	{
		if(currentRootPtr->getRight() == nullptr)
		{	
		}
		else
		{
			//if child is value store currentRootPtr
			if( currentRootPtr->getRight()->getItem() == value )
			{
				oneUp = currentRootPtr;
			}

			currentRootPtr = search( value, currentRootPtr->getRight() );
		}
	}
	

	return currentRootPtr;
}

//-1 = preorder, 0 = inorder, 1 = postorder
template<class ItemType>
void BinarySearchTree<ItemType>::traverse(void visit(ItemType&), BinaryNode<ItemType>* currentRoot, int traverseType)const
{
	if ( !isEmpty() )
	{
		if(currentRoot != nullptr)
		{
			//creating lvalue for client function parameter
			ItemType theItem = currentRoot->getItem();

			//visit if preorder
			if(traverseType == -1)
			{
				
				visit(theItem);
			}

			//recursive call to left tree
			traverse( visit, currentRoot->getLeft(), traverseType );

			//visit if inorder
			if(traverseType == 0)
			{
				visit(theItem);
			}

			//recursive call to right tree
			traverse( visit, currentRoot->getRight(), traverseType );
		
			//visit if postorder
			if(traverseType == 1)
			{
				visit(theItem);
			}
		}
		
	}

	else
	{
		cout<<"Tree's empty fool"<<endl;
	}
		
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr)const
{
	if(subTreePtr == nullptr)
	{
		return 0;
	}
	else
	{
		if( getHeightHelper( subTreePtr->getLeft() ) > getHeightHelper( subTreePtr->getRight() ) )
		{
			return 1+getHeightHelper( subTreePtr->getLeft() );
		}

		else
		{
			return 1+getHeightHelper( subTreePtr->getRight() );
		}
	}
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{

}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& newData)
{
	add(newData);
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& newData, 
												BinaryNode<ItemType>* lChild, 
												BinaryNode<ItemType>* rChild)
{
	add(newData);
	rootNodePtr->setLeft(lChild);
	rootNodePtr->setRight(rChild);
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
}


template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty()const
{
	return (numNodes == 0);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight()const
{

	return getHeightHelper(rootNodePtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes()const
{
	return numNodes;
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData()const
{
	if(isEmpty())
	{
		cout<<"No root data"<<endl;
		exit(0);
	}

	return rootNodePtr->getItem();
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
	if( !isEmpty() )
	{
		rootNodePtr->setItem(newData);
	}
	else
	{
		add(newData);
	}
}


template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
	BinaryNode<ItemType>* tempPtr = search(newData,rootNodePtr);

	bool added = false;

	if( isEmpty() )
	{
		rootNodePtr = new BinaryNode<ItemType>(newData);

		numNodes++;
		
		added = true;
	}
	else if(tempPtr == nullptr)
	{
		cout<<"There's a duplicate value";
		added = false;
	}
	else
	{
		BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);

		if( newData < tempPtr->getItem() )
		{
			tempPtr->setLeft(newNodePtr);
		}
		else
		{
			tempPtr->setRight(newNodePtr);
		}

		newNodePtr = nullptr;

		numNodes++;

		added = true;
	}
	
	return added;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& data)
{
	bool removed = false;
	BinaryNode<ItemType>* tempBNPtr = nullptr;

	if(isEmpty())
	{
		return removed;
	}

	tempBNPtr = search(data, rootNodePtr);
	// cout<<"dataptr: "<<tempBNPtr->getItem()<<endl;

	if(tempBNPtr == nullptr)
	{
		return removed;
	}
	// cout<<"dataisLeaf: "<<tempBNPtr->isLeaf()<<endl;
	
	//if Node is a leaf
	if( tempBNPtr->isLeaf() )
	{
		// cout<<"parent: "<<oneUp->getItem()<<endl;
		if(oneUpIsLeft)
		{
			oneUp->setLeft(nullptr);
		}
		else
		{
			oneUp->setRight(nullptr);
		}

		delete tempBNPtr;
		tempBNPtr = nullptr;

		numNodes--;
	}

	//if Node has only left child
	else if ( tempBNPtr->getLeft() != nullptr && tempBNPtr->getRight() == nullptr )
	{

	}

	//if Node has only right child
	else if ( tempBNPtr->getLeft() == nullptr && tempBNPtr->getRight() != nullptr )
	{
		
	}

	//if Node has both children
	else if ( tempBNPtr->getLeft() != nullptr && tempBNPtr->getRight() != nullptr )
	{
		
	}
	


	return true;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{

}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry)const
{
	return rootNodePtr->getItem();
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry)
{
	BinaryNode<ItemType>* tempBNPtr = search(anEntry, rootNodePtr);
	return ( tempBNPtr != nullptr );
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse( void visit(ItemType&) )const
{
	traverse(visit, rootNodePtr, -1);
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse( void visit(ItemType&) )const
{
	traverse(visit, rootNodePtr, 0);
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse( void visit(ItemType&) )const
{
	traverse(visit, rootNodePtr, 1);
}
