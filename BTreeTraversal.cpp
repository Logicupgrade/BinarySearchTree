
#include "BinaryNode.cpp"
#include "BinarySearchTree.cpp"

using namespace std;

void visit( int intVal );

int main()
{
	BinarySearchTree<int> bTree(5);
	cout<<bTree.getRootData()<<endl;
	cout<<"count: "<<bTree.getNumberOfNodes()<<endl;
	bTree.add(7);
	bTree.add(14);
	bTree.add(21);
	bTree.add(9);
	cout<<"count: "<<bTree.getNumberOfNodes()<<endl;

	bTree.inorderTraverse(visit);//displayInt);
	cout<<endl;
	return 0;
}

void visit( int intVal )
{
	cout<<intVal<<',';
}