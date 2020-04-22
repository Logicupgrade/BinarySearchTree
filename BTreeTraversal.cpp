
#include "BinaryNode.cpp"
#include "BinarySearchTree.cpp"

#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

void displayInt( int& intVal );
void randomizeData(int arrayPtr[], int arrSize);
void swapForBalancedTree(int arrayPtr[], int arrSize, int maxVal);
void swapInt(int& one, int& another);

int main()
{
	int intArray[100];
	//fill intArray with "random" 100  ints between 1-200 
	randomizeData( intArray, 100 );
	//attempt to make tree node start at close to mid val
	//swapForBalancedTree(intArray, 100, 200);

	for(int i=0;i<100;i++)
	{
		cout<<"intArray["<<i<<"]: "<<intArray[i]<<endl;
	}

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

void randomizeData(int arrayPtr[], int arrSize)
{
	int tempRandArray[200];
	srand( time(NULL) );

	//array with 1-200
	for(int i = 0;i<200;i++)
	{
		tempRandArray[i] = i+1;
	}

	//shuffle
	for(int i = 0;i<200;i++)
	{
		swapInt( tempRandArray[i],tempRandArray[rand() % 200 + 1] );
	}

	//take 100 distinct rand values
	for(int i = 0;i<arrSize;i++)
	{
		arrayPtr[i] = tempRandArray[i];
	}
	
}

//****Swaps in a 0 value....fix
void swapForBalancedTree(int arrayPtr[], int arrSize, int maxVal)
{
	int closeToMid = 0;
	int closeToMidIndex = 0;
	int mid = maxVal/2;

	//search array for close to mid val
	for(int i = 0;i<arrSize;i++)
	{
		
		int arrDiff = abs(arrayPtr[i]-mid);
		int closeDiff = abs(closeToMid-mid);

		//compare for mid and update
		if(arrDiff < closeDiff)
		{
			closeToMid = arrayPtr[i];
			closeToMidIndex = i; 
		}
	}

	//swap index 0 for closest to mid
	swapInt( arrayPtr[0], arrayPtr[closeToMidIndex] );
}

void swapInt(int& one, int& another)
{
	int tempInt = one;
	one = another;
	another = tempInt;
}