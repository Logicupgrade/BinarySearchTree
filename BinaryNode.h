
#ifndef _BINARY_NODE
#define _BINARY_NODE

template <class ItemType>
class BinaryNode
{
private:
	ItemType bNodeItem;
	BinaryNode<ItemType>* leftPtr = nullptr;
	BinaryNode<ItemType>* rightPtr = nullptr;
public:
	BinaryNode();
	BinaryNode( ItemType& newItem );
	BinaryNode( ItemType& newItem, BinaryNode<ItemType>* lPtr );
	BinaryNode( ItemType& newItem, BinaryNode<ItemType>* lPtr, BinaryNode<ItemType>* rPtr );
	virtual ~BinaryNode();

	bool addItem(ItemType& newItem);
	void setLeft(BinaryNode<ItemType>* lPtr);
	void setRight(BinaryNode<ItemType>* rPtr);

	ItemType getItem();
	BinaryNode<ItemType>* getLeft();
	BinaryNode<ItemType>* getRight();

};

#endif