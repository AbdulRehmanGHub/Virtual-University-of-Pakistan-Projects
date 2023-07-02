/*	 BC200403287
	Abdul Rehman	*/

// Starting.
#include <iostream>
#include <conio.h>

using namespace std;

// Creating a TreeNode class to construct nodes for BST.
class TreeNode{
private:
    	int object; 
		TreeNode *left, *right;

public:
 		void setInfo(int a){
 		object = a;
 		}
 		
		int getInfo(){
 		 return object;
		}

	void setLeft(TreeNode *TN){
 		left = TN;
 	}
 		TreeNode* getLeft(){
 		 return left;
 
 	}
 	
	 void setRight(TreeNode *TN){
 		 right = TN;
 	}
 		
		TreeNode* getRight(){
		 return right;
	}
 
 	 bool isLeaf(TreeNode *TN){
 		if(TN -> getLeft() == NULL && TN -> getRight() == NULL)
			return true;
		else
			return false;
 	}
 
};

// Creating a Heap class to construct min-heap.
class Heap{
	private:
		int currentSize, capacity, *array;
  
public:
    Heap(){
		capacity = 15;
		
    	array = new int[capacity];
    	
    	currentSize =0;
	}
    	
	void insert(int a, int n){
    	if(isFull())
			cout<<"\n\n	Heap is full ";
		
		else if(n == 1){
			array[currentSize] = a;
		
			percolateDown();
		
			currentSize++;
	}
	
		else{
			array[currentSize] = a;
			
			currentSize++;	
		}
}

	bool isEmpty(){
		if(currentSize == 0)
		 return true;
	else
		return false;
	}
	
	bool isFull(){
		if(currentSize == capacity)
		 	return true;
	else
		 	return false;
	}
	
	void buildHeap(){
	s:
		int s, found=0, tmp, min;
		 
		 for(int i=currentSize; i>=0; i--){
			s = (i*2)+1;
		 
		 if(s < currentSize && (array[i] > array[s] || array[i] > array[s+1])){
			if(array[s] < array[s+1])
				min = s;
		
		else
			min = s+1;
			tmp = array[i];
			array[i]= array[min];
			array[min] = tmp;
			found++;
		}
	}
	
		if(found > 0)
			goto s;	
}

	void traverse(){
		for(int i=0; i<currentSize; i++)
		cout<<"	"<<array[i];
	}
		
	void percolateDown(){
		int s, found=0, tmp;
			for(int i=0; i<currentSize; i++)
			{
			s = (i*2)+1;
			 if(s <= currentSize && array[i] > array[s]){
				tmp = array[i];
				array[i]= array[s];
				array[s]= tmp;
				found++;
			 }

			if((s+1) <= currentSize && array[i] > array[s+1]){
				tmp = array[i];
				array[i] = array[s+1];
				array[s+1] = tmp;
				found++;
			}
		}
				if(found > 0)
				 percolateDown();
  	}
};

TreeNode *root=NULL;
int b[15],c=0;

// Defining non-member addNode() to insert a node into BST.
void addNode(int a){
	int found = 0;
		TreeNode *newNode = new TreeNode;
		newNode -> setInfo(a);
		newNode -> setLeft(NULL);
		newNode -> setRight(NULL);

	if(root == NULL){
		root = newNode;
		cout<<"\n"<<a<<" is inserted as root in BST";
	}

	else{
			TreeNode *pre = root;
			TreeNode *ptr = root;
	
		while(ptr != NULL){
	
	if(newNode -> getInfo() < ptr -> getInfo()){
			pre = ptr;
			ptr = ptr -> getLeft();
			
			if(ptr == NULL)
			pre -> setLeft(newNode);
		}

		else if(newNode ->getInfo() > ptr ->getInfo()){
			pre = ptr;
			ptr = ptr -> getRight();
			if(ptr == NULL)
			pre -> setRight(newNode);
		}
		
		else{
			cout<<"\nDuplicate Record Found ";
			delete newNode;
			found++;
			break;
	}
}
	
	if(found == 0){
		(a<10) ? cout<<"\n "<<a : cout<<"\n "<<a;
		cout<<" inserted in BST";
		}
	}
}

// Defining non-member inputData() to get data of BST from user.
void inputData(){
	int noOfNodes;
	int nodeValue;
	
	cout<<"How many nodes do you want to insert in BST: ";
	cin>>noOfNodes;
	cout<<"Enter "<<noOfNodes<<" values to insert into BST: ";
	
	for(int i=0; i<noOfNodes; i++){
		cin>>nodeValue;
		addNode(nodeValue);
	}
}

// Defining non-member postOrder() for pre-order traversal of BST.
void preOrder(TreeNode *TN){	
	if(TN != NULL){
		cout<<" "<<TN -> getInfo();
		b[c++] = TN -> getInfo();
		preOrder(TN -> getLeft());
		preOrder(TN -> getRight());
	}
}

// Defining non-member postOrder() for post-order traversal of BST...
void postOrder(TreeNode *TN){
	if(TN != NULL){
		postOrder(TN -> getLeft());
		postOrder(TN -> getRight());
		cout<<" "<<TN -> getInfo();
		b[c++] = TN -> getInfo();
	}
}

// Defining non-member populateTree() function to create BST...
	int populateTree(int a)
	{
		return b[a];
	}

// Starting main function...
main(){
	Heap H,H2;
	inputData();
	
	cout<<"\n\nPost-Order Traversal of BST:";
	postOrder(root);
	for(int i=0;i<=14;i++)
		H.insert(populateTree(i),1);
	
	cout<<"\nMin Heap Using Insert method:";
	H.traverse();
	c=0;
	
	cout<<"\n\nPre-Order Traversal of BST:";
	preOrder(root);
	for(int i=0;i<=14;i++)
		H2.insert(populateTree(i),2);
	H2.buildHeap();
	
	cout<<"\nMin Heap Using Build method:";
	H2.traverse();
	
	getch();
	return 0;
}

// End of the Program...
