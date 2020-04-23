
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"

template <class ItemType>
class BinarySearchTree: public BinaryTreeInterface<ItemType>
{
private:
	int numNodes = 0;
	BinaryNode<ItemType>* rootNodePtr = nullptr;
	BinaryNode<ItemType>* oneUp = nullptr;
	bool oneUpIsLeft = false;
	BinaryNode<ItemType>* search(const ItemType& value, 
									BinaryNode<ItemType>* currentRootPtr );

	//-1 = preorder, 0 = inorder, 1 = postorder
	void traverse(void visit(ItemType&), BinaryNode<ItemType>* currentRoot, int traverseType)const;
	int getHeightHelper(BinaryNode<ItemType>* subTreePtr)const;
	BinaryNode<ItemType>* mosLef(BinaryNode<ItemType>* nodeToGetLeft);

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
	bool contains(const ItemType& anEntry);
	void preorderTraverse( void visit(ItemType&) )const;
	void inorderTraverse( void visit(ItemType&) )const;
	void postorderTraverse( void visit(ItemType&) )const;

};

#endif