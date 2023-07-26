/*	Name:	Abdul Rehman.
	VU ID:	BC220424444.	*/

#include<iostream>
#include<conio.h>

using namespace std;

// Student class.
class Student
{
	private:
		string st_id;
		string st_name;
		float quizmarks[4];
		float assignmentmarks[2];
		float midMarks;
		float finalMarks;
		float totalMarks;
	
	public:
		Student()
		{
		}
		Student(string i, string n, float q[], float a[], float m, float f)
		{
			st_id = i;
			st_name = n;
			for(int i=0;i<=3;i++)
				quizmarks[i] = q[i];
			for(int i=0; i<=1; i++)
				assignmentmarks[i] = a[i];
			midMarks = m;
			finalMarks = f;
		}

// Starting enterData function.
	void enterData()
	{
		cout<<"Enter Student Id: ";
		cin>>st_id;
		
		cout<<"Enter Studnt Name: ";
		cin>>st_name;
		
		for(int i=0; i<=3; i++)
		{
			again:
				cout<<"Enter marks For Quiz "<<i + 1<<" <out of 10>: ";
				cin>>quizmarks[i];
				
				if(quizmarks[i] > 10)
				{
					cout<<"Invalid Marks, Marks Should Be Between 0-10.\n";
			goto again;
				}
		}

	for(int i=0; i<=1; i++)
	{
		again1:
			cout<<"Enter marks For Assignment "<<i+1<<" <out of 20>: ";
			cin>>assignmentmarks[i];
			
			if(assignmentmarks[i] > 20)
			{
				cout<<"Invallid Marks, Marks Should Be Between 0-20.\n";
		goto again1;
			}
	}
	
	cout<<"Enter Marks in Mid Term <out of 40>: ";
	cin>>midMarks;
	
	cout<<"Enter Marks in final Term <out of 60>: ";
	cin>>finalMarks;
	}

// Starting calculateResult function.
	float calculateResult()
	{
		float quiz;
		float assignment;
		float mid;
		float final;
		quiz = (quizmarks[0] + quizmarks[1] + quizmarks[2] + quizmarks[3])/40*10;
		assignment = (assignmentmarks[0] + assignmentmarks[1])/40*20;
		mid = midMarks/40*30;
		final = finalMarks/60*40;
		return quiz + assignment + mid + final;
	}

// Starting displayData function.
	void displayData(float totalMarks)
	{
		cout<<st_id<<"\t" <<st_name<<"\t\t" <<(int)midMarks<<"\t\t" <<(int)finalMarks<<"\t\t" <<totalMarks<<"\n";
	}
};

// Starting main function.
int main()
{
	Student *a[3];
	float quizmarks[4] = {};
	float assignmentmarks[2] = {};
	a[0] = new Student("BC220424444", "Rehman", quizmarks, assignmentmarks, 30, 40);
	a[1] = new Student;
	a[2] = new Student;
	a[1] -> enterData();
	a[2] = a[1];
	cout<<"\nStudentID\tStudentName\tMidTermMarks\tFinalTermMarks\tTotalMarks\n";
	cout<<"----------------------------------------------------------------------------\n";
	for(int i=0; i<=2; i++)
		a[i] -> displayData(a[i] -> calculateResult());
	
	return 0;
}
