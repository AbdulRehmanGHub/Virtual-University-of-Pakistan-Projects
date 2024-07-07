/*	  Abdul Rehman.
	  BC200403287.	*/
#include<iostream>
#include<conio.h>

using namespace std;

//Base or Parent class (Person).
class Person{
	private:
		int age;
		string name, gender, address;
		long phone;
	public:
		Person(){
			name = "";
			age = 0;
			gender = "";
			address = "";
			phone = 0;
	}
// Creating setter functions.		
			void setName(){
			cout<<"\n 	Enter Name: ";
			cin>>name;
		}
			
			void setAge(){
			cout<<"\n 	Enter Age: ";
			cin>>age;
		}
			
			void setGender(){
			cout<<"\n 	Enter Gender: ";
			cin>>gender;
		}
			
			void setAddress(){
			cout<<"\n 	Enter Address: ";
			cin>>address;
		}
		
			void setPhone(){
			cout<<"\n 	Enter Phone: ";
			cin>>phone;
		}
// Creating getter functions.
		string getName(){
		 return name;
		}
		
		int getAge(){
		 return age;
		}
		
		string getGender(){
		 return gender;
		}
		
		string getAddress(){
		 return address;
		}
		
		long getPhone(){
		 return phone;
		}

// Funtions to save and display information.
		void Save_Information(){
		 setName();
		 setGender();
		 setAge();
		 setAddress();
		 setPhone();
		}
		
		void Display_Information(){
		 cout<<"\n\n	Name: "<<getName();
		 cout<<"\n 	Gender: "<<getGender();
		 cout<<"\n 	Age: "<<getAge();
		 cout<<"\n 	Address: "<<getAddress();
		 cout<<"\n 	Phone: "<<getPhone();
		}
};

// Derived or child class (Teacher).
class Teacher: public Person{	
	private:
		int salary;
		string qualification;
	public:
		Teacher(){
			salary = 0;
			qualification = "";
		}
// Creating setter functions.
		void setSalary(){
			cout<<"\n	Enter Salary: ";
			cin>>salary;
		}
		void setQualification(){
			cout<<"\n	Enter Qualification: ";
			cin>>qualification;
		}

// Creating getter functions.
		int getSalary(){
			return salary;
		}
			string getQualification(){
			return qualification;
		}
// Functions to save and display information.		

		void Save_Information(){
			Person::Save_Information();
			setSalary();
			setQualification();
		}
		void Display_Information(){
			Person::Display_Information();
			cout<<"\n	Teacher's Qualification "<<getQualification();
			cout<<"\n	Teacher's Salary: "<<getSalary();
		}
};

// Child or derived class (Student).
class Student: public Person{
private:
	int totalMarks, obtainedMarks;
	string previousEducation;
public:
	Student(){
		totalMarks = 0.0;
		obtainedMarks = 0.0;
		previousEducation = "";
	}
// Creating setter functions.
	void setTotalMarks(){
		cout<<"\n 	Enter Total Marks: ";
		cin>>totalMarks;
	}
	void setObtainedMarks(){
		cout<<"\n 	Enter Obtained Marks:";
		cin>>obtainedMarks;	
	}
	void setPreviousEducation(){
		cout<<"\n 	Enter Previous Education: ";
		cin>>previousEducation;
	}
	
// Creating getter functions.
	int getTotalMarks(){
		return totalMarks;
	}
	int getObtainedMarks(){
		return obtainedMarks;
	}
	string getPreviousEducation(){
		return previousEducation;
	}
	
// Functions to save and display information.
	void Save_Information(){
		Person::Save_Information();
		setPreviousEducation();
		setTotalMarks();
		setObtainedMarks();
	}
	void Display_Information(){
		Person::Display_Information();
		cout<<"\n 	Previous Education: "<<getPreviousEducation();
		cout<<"\n 	Total Marks: "<<getTotalMarks();
		cout<<"\n 	Obtained Marks: "<<getObtainedMarks();
	}
};
// Main function.
main(){
	int i=0, j=0;
	char choice, x;
	
	Teacher *T[9];
	Student *S[9];
	
		cout<<"\n	Enter Choice: ";
		cout<<"\n	--------------";
		cout<<"\n\n 	T for Teacher ";
		cout<<"\n 	S for Student "<<endl;
		cout<<"\t";
		cin>>choice;
		cout<<"\n _________________________________________";
	
	if(choice== 't' || choice == 'T'){
		cout<<"\n	Enter following data for Teacher";
		cout<<endl;
		do{
			T[i]= new Teacher;
			T[i] -> Save_Information();
			i++;
			cout<<"\n\n 	Do you want to enter more data (Press Y for Yes, N for No): ";
			cin>>x;
		}
		while(x == 'y' || x == 'Y');
			cout<<"\n _________________________________________";
			cout<<"\n	----Teacher Record ----";
		 for(int a=0; a<i; a++)
			T[a] -> Display_Information();
	}
	
	else if(choice== 's' || choice == 'S'){
		cout<<"\n\n 	Enter following data for Student: ";
		cout<<endl;
	 do{
			S[j] = new Student;
			S[j] -> Save_Information();
			j++;
		cout<<"\n _________________________________________";
		cout<<"\n\n 	Do you want to enter more data (Press Y for Yes, N for No): ";
		cin>>x;
		}
		
		while(x == 'y' || x == 'Y');
			cout<<"\n _________________________________________";
			cout<<"\n	----Student Record ----";
		 for(int a=0; a<j; a++)
			S[a] -> Display_Information();
	}
	
	getch();
	return 0;
}

// End.
