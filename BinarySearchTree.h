
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"

template <class ItemType>
class BinarySearchTree: public BinaryTreeInterface<ItemType>
{
private:
	int treeHeight = 0;
	int numNodes = 0;
	BinaryNode<ItemType>* rootNodePtr = nullptr;
	BinaryNode<ItemType>* search(const ItemType& value, 
									BinaryNode<ItemType>* currentRootPtr );

	//-1 = preorder, 0 = inorder, 1 = postorder
	void traverse(void visit(ItemType&), BinaryNode<ItemType>* currentRoot, int traverseType)const;

public:
	BinarySearchTree();
	BinarySearchTree(const ItemType& newData);
	BinarySearchTree(const ItemType& newData, 
								BinaryNode<ItemType>* lChild, 
								BinaryNode<ItemType>* rChild);
	~BinarySearchTree();
	bool isEmpty()const;
	int getHeight()const;
	int getNumberOfNodes()const;
	ItemType getRootData()const;
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newData);
	bool remove(const ItemType& data);
	void clear();
	ItemType getEntry(const ItemType& anEntry) const;
	bool contains(const ItemType& anEntry)const;
	void preorderTraverse( void visit(ItemType&) )const;
	void inorderTraverse( void visit(ItemType&) )const;
	void postorderTraverse( void visit(ItemType&) )const;

	

};

#endif