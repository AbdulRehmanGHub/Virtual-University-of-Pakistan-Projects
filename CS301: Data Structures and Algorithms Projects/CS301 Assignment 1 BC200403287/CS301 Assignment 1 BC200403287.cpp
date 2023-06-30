/*  BC200403287
   Abdul Rehman */

// Program start.

#include<iostream>
#include<conio.h>

using namespace std;

int size=0;

// structure of the node.
class Student{
    public:
        string name;
        int marks;
        Student *nextStudent;
        
	void setName(string setn)
	{
    	name=setn;
    }
        string getName()
	{
    return name;
    }
        
	void setMarks(int setm)
	{
        marks=setm;
    }
    
	int getMarks()
	{
	 return marks;
	}
    
	void setNextStudent(Student *setAddress)
	{
        nextStudent=setAddress;
    }
    
	Student* getNextStudent()
	{
    return nextStudent;
    }
};
// Start stack class.
class Stack{
    public:
        Student *headStudent=NULL;
        
	bool isEmpty()
	 {
        if(headStudent==NULL)
	 {
        cout<<endl<<"Stack is Empty"<<endl;
        return true;
     }
    	else{
        return false;
        	}
     }

// Insert the top element of the stack.
    void push()
	{
        string n;
    int m;
        Student *newNode=new Student;
        cout<<endl;
        cout<<"Enter the name of Student: ";
    cin>>n;
        newNode->setName(n);
        cout<<"Enter the marks of Student: ";
    cin>>m;
        newNode->setMarks(m);
        newNode->setNextStudent(NULL);
    
	if(headStudent==NULL)
	{
    headStudent=newNode;
    }
    else{
        Student *ptr=headStudent;
    
	while ( ptr-> getNextStudent()!=NULL )
        {
            ptr=ptr->getNextStudent();
        }
            ptr->setNextStudent(newNode);
        }

    cout<<endl<<"Student information saved successfully. \n"<<endl;
    size++;
	}
  
// Remove the top element of the stack and return it. 
	void pop()
	{
     if(!isEmpty())
	 	{
         Student *pre=headStudent;
         Student *ptr=headStudent;
     
	 while (ptr->getNextStudent()!=NULL)
         {
        	pre=ptr;
            ptr=ptr->getNextStudent();
        }
        
	 if(ptr==headStudent)
	 {
        headStudent==NULL;
     }
    else{
         pre->setNextStudent(NULL);
        }
    delete ptr;
    size--;
    cout<<endl;
	cout<<"Student is successfully remove from the Stack \n"<<endl;
    	}
    }
    
// function to display the stacks
    void display()
	{
    if(!isEmpty())
	{
     string n[size];
     int m[size],i=0,j=0;
     cout<<"The information of all students: "<<endl;
     cout<<"Name \t\t   Marks"<<endl;
     Student *ptr=headStudent;
    
	while(ptr != NULL)
    {
        n[i++]=ptr->getName();
        m[j++]=ptr->getMarks();
        ptr=ptr->getNextStudent();
    }
    
	for(int k=size-1;k>=0;k--)
	{
     cout<<n[k]<<" \t\t "<<m[k]<<endl;
    }
     cout<<"			"<<endl<<endl<<endl;
    }
    }

    void sortStack()
	{
    for(int i=0;i<size;i++)
	{
    Student *ptr=headStudent;
    
	for(int j=0;j<size-1;j++)
	{
    string tmp;
    if(ptr->getMarks()<ptr->getNextStudent()->getMarks())
	
    ptr=ptr->getNextStudent();
        }
      }
    }

// Return the top element without removing it from the stack.
    void top(){
    if(!isEmpty())
	 {
    	cout<<endl<<endl<<"Top Positions:"<<endl;
        cout<<endl<<"Name \t\t   Marks";
        Student *ptr=headStudent;
        for(int k=0;k<3;k++)
		{
            cout<<endl<<ptr->getName()<<" \t\t  "<<ptr->getMarks();
            ptr=ptr->getNextStudent();
        }
        
		cout<<endl<<endl;
     }
   }
};

// Main Function
int main()
{
	Stack s;
	while(true)
	{
	 int choice;
		cout<<"1. To add a student in Stack"<<endl;
		cout<<"2. To remove a Student from the Stack"<<endl;
		cout<<"3. Display all students of Stack"<<endl;
		cout<<"4. Display top 3 students of Stack"<<endl;
		cout<<"5. Press 5 or any other key to close the program"<<endl <<endl;
		cout<<"Enter your choice (1 ,2, 3, 4 or 5): ";
		 
	cin>>choice;

// Switch Statement
	switch(choice)
	{
	case 1:
		s.push();
	break;
			 
	case 2:
		s.pop();
	break;
			 
	case 3:
		s.display();
	break;
			 
	case 4:
		s.top();
	break;
			 
	default :
		exit(0);
	break;
	}
	 }
	 return 0;
}
// Program End
