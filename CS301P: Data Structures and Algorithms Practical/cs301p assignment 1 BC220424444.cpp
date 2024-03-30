/*
	Name: Abdul Rehman
	VU-ID: BC220424444
*/
#include <iostream>
#include <conio.h>

using namespace std;

// Class to represent individual tasks
class Task {
	private:
		int taskID;
		string taskName, description, dueDate;
		Task *next;
	
	public:
// Setter and getter methods
		void setTaskID(int id) {
			taskID = id;
		}
		int getTaskID() {
			return taskID;
		}
		
		void setTaskName(string name) {
			taskName = name;
		}
		string getTaskName() {
			return taskName;
		}
		
		void setDescription(string desc) {
			description = desc;
		}
		string getDescription() {
			return description;
		}
		
		void setDueDate(string date) {
			dueDate = date;
		}
		string getDueDate() {
			return dueDate;
		}
		
		void setNext(Task *nextNode) {
			next = nextNode;
		}
		Task* getNext() {
			return next;
		}	
};

// Class to manage a stack
class TaskStack {
	private:
		Task *head;
	
	public:
// Constructor that initialize empty stack
		TaskStack(){
			head =NULL;
		}

// To push a new task
		void pushTask(int taskID, string taskName, string taskDesc, string date) {
			Task *newNode = new Task;
			newNode -> setTaskID(taskID);
			newNode -> setTaskName(taskName);
			newNode -> setDescription(taskDesc);
			newNode -> setDueDate(date);
			newNode -> setNext(head);
			head = newNode;
		}

// Pop the top task	
		void popTask() {
			Task *ptr = head;
			head = head -> getNext();
			delete ptr;
		}

// Display the details	
		void topTask() {
			cout<<"Top Task - Name: "<<head -> getTaskName();
			cout<<", ID: "<<head -> getTaskID();
			cout<<", Description: "<<head -> getDescription();
			cout<<", Due Date: "<<head -> getDueDate() <<endl;
		}

// Display details of all tasks
		void displayTask() {
			Task *ptr = head;
			while(ptr != NULL) {
				cout<<"Name: "<<ptr -> getTaskName();
				cout<<", ID: "<<ptr -> getTaskID();
				cout<<", Description: "<<ptr -> getDescription();
				cout<<", Due Date: "<<ptr -> getDueDate() <<endl;
				ptr = ptr -> getNext();
			}
		}
};

// Main function
int main() {
	TaskStack TS;
	while(true) {
		int choice, id;
		string name, desc, date;
		cout<<"Task Management System " <<endl;
		cout<<"1: Push A Task To The Stack " <<endl;
		cout<<"2: Pop A Task From The Stack " <<endl;
		cout<<"3: Display A Top Task " <<endl;
		cout<<"4: Display The Entire Stack " <<endl;
		cout<<"5: Exit " <<endl;
		cout<<"Enter Your Choice: ";
		cin>>choice;
		
		switch(choice) {
			case 1:
				cout<<"Enter Task Name: ";
				cin>>name;
				
				cout<<"Enter Task ID: ";
				cin>>id;
				
				cout<<"Enter Task Description: ";
				cin>>desc;
				
				cout<<"Enter Task Due Date: ";
				cin>>date;
				
				TS.pushTask(id, name, desc, date);
				break;
				
			case 2:
				TS.popTask();
				break;
				
			case 3:
				TS.topTask();
				break;
			
			case 4:
				cout<<"Task Stack: "<<endl;
				TS.displayTask();
				break;
				
			case 5:
				exit(0);	
		}
	}
}



