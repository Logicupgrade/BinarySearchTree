
#include "BinaryNode.cpp"
#include "BinarySearchTree.cpp"

using namespace std;

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
	return 0;
}