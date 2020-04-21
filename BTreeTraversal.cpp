
#include "BinaryNode.cpp"
#include "BinarySearchTree.cpp"

using namespace std;

void displayInt( int& intVal );

int main()
{
	BinarySearchTree<int> bTree(14);
	cout<<bTree.getRootData()<<endl;
	cout<<"count: "<<bTree.getNumberOfNodes()<<endl;
	bTree.add(7);
	bTree.add(5);
	bTree.add(21);
	bTree.add(9);
	cout<<"count: "<<bTree.getNumberOfNodes()<<endl;

	cout<<"preorder: ";
	bTree.preorderTraverse(displayInt);
	cout<<endl;

	cout<<"inorder: ";
	bTree.inorderTraverse(displayInt);
	cout<<endl;

	cout<<"postorder: ";
	bTree.postorderTraverse(displayInt);
	cout<<endl;
	return 0;
}

void displayInt( int& intVal )
{
	cout<<intVal<<',';
}