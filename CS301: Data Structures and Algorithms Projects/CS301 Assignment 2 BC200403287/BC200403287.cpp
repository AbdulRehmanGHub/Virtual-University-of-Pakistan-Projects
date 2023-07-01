/* BC200403287
 Abdul Rehman */

// Starting Patient's Information System of a Hospital.

#include <iostream.h>
#include <conio.h>

using namespace std;

// declaration of the node class.
class node
{
public:
	int age;
	node *next;
};

// declaration of priority queue class.
class priority_queue
{
private:
	node *c;
public:
	priority_queue()
	{
 	c = NULL;
 	}
 
// Age entry of a patient in descending order.
void insert(int p)
{
 node *d, *q;
 d = new node;
 d->age = p;
	if (c == NULL || p > c->age)
	{
	 d->next = c;
	 c = d;
	}
 	else
	{
	 q = c;
	while (q->next != NULL && q->next->age >= p)
		 q = q->next;
		 d->next = q->next;
		 q->next = d;
	}
}

// Delete entry of a patient from the queue.
void delet()
{
 node *d;
	if (c == NULL)		// if queue is empty.
	 cout << "Queue is empty\n";
	else
	{
	 d = c;
	 cout << "Deleted age value is: " << d->age << endl;		// if there is any value in queue.
	 c = c->next;
	delete(d);
	}
}

// Display information of patients on the basis of age (priority) in the queue.
void show()
{
 node *ptr;
 ptr = c;
	if (c == NULL)		// if queue is empty.
	 cout << "Queue is empty " <<endl;
	else
	{
	 cout << "\nQueue is: " <<endl;		// if there is any value in queue.
	while (ptr != NULL)
	{
	 cout << ptr->age << endl;
	 ptr = ptr->next;
	}
	}
}
};

// starting main function.
int main()
{
 int a, b;
  priority_queue pq;
  cout << "Welcome to Patient Information System" << endl;
 do
 {
  cout << "		" << endl;
  cout << "Enter your choice of the activity" << endl;
  cout << "		" << endl;
  cout << "1. Insert" <<endl;
  cout << "2. Delete" <<endl;
  cout << "3. Display" <<endl;
  cout << "4. Exit" <<endl;
  cout << "Enter your choice : ";
 cin >> a;

// switch statement.
switch (a)
{
 case 1:
   cout << "Input the age value to be added in the queue : ";
  cin >> b;
   pq.insert(b);
 break;

 case 2:
  pq.delet();
 break;

 case 3:
  pq.show();
 break;

 case 4:
 break;

default:
 cout << "Incorrect choice" <<endl;
}

 } while (a != 4);
	cout << endl;

 return 0;
}

// End of the Program.
