
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
	swapForBalancedTree(intArray, 100, 200);

	BinarySearchTree<int> moneyTree;

	for(int i=0;i<100;i++)
	{
		// cout<<"intArray["<<i<<"]: "<<intArray[i]<<endl;
		moneyTree.add(intArray[i]);
	}

	cout<<"height: "<<moneyTree.getHeight()<<endl;

	cout<<"preorder: "<<endl;
	moneyTree.preorderTraverse(displayInt);
	cout<<endl;

	cout<<"inorder: "<<endl;
	moneyTree.inorderTraverse(displayInt);
	cout<<endl;

	cout<<"postorder: "<<endl;
	moneyTree.postorderTraverse(displayInt);
	cout<<endl;

	BinarySearchTree<int> bTree(60);
	cout<<bTree.getRootData()<<endl;
	cout<<"count: "<<bTree.getNumberOfNodes()<<endl;
	bTree.add(20);
	bTree.add(70);
	bTree.add(10);
	bTree.add(40);
	bTree.add(30);
	bTree.add(50);
	cout<<"height"<<bTree.getHeight()<<endl;
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

	cout<<"height"<<bTree.getHeight()<<endl;
	bTree.add(11);
	cout<<"height"<<bTree.getHeight()<<endl;
	bTree.add(12);
	cout<<"height"<<bTree.getHeight()<<endl;

	cout<<"count2: "<<bTree.getNumberOfNodes()<<endl;
	bTree.clear();
	cout<<"count3: "<<bTree.getNumberOfNodes()<<endl;


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
		swapInt( tempRandArray[i],tempRandArray[rand() % 200] );
	}

	//take 100 distinct rand values
	for(int i = 0;i<arrSize;i++)
	{
		arrayPtr[i] = tempRandArray[i];
	}
	
}


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