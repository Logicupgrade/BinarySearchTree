
#include "BinaryNode.cpp"
#include "BinarySearchTree.cpp"

#include <cstdlib>
#include <time.h>
#include <cmath>
#include <fstream>

using namespace std;

void displayInt( int& intVal );
void printIntFile( int& intVal );
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
		moneyTree.add(intArray[i]);
	}

	cout<<"height: "<<moneyTree.getHeight()<<endl;

	cout<<"preorder: "<<endl;
	moneyTree.preorderTraverse(displayInt);
	// moneyTree.preorderTraverse(printIntFile);
	cout<<endl;

	cout<<"inorder: "<<endl;
	moneyTree.inorderTraverse(displayInt);
	// moneyTree.inorderTraverse(printIntFile);
	cout<<endl;

	cout<<"postorder: "<<endl;
	moneyTree.postorderTraverse(displayInt);
	// moneyTree.postorderTraverse(printIntFile);
	cout<<endl;

	return 0;
}

void displayInt( int& intVal )
{
	cout<<intVal<<',';
}

void printIntFile( int& intVal )
{
	ofstream theFile;
	theFile.open("output.txt", ios::app);
	theFile<<intVal<<',';
	theFile.close();
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