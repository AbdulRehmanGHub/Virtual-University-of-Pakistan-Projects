/*	Name: Abdul Rehman.
	VUID: BC220424444.	*/
	
#include<iostream>
#include<conio.h>

using namespace std;

//	Main Function.
int main(){
//	Print VU ID.
	string VUId = "BC220424444";

//	Add first and last numeric digit of VU Id.
	int first_digit = 2;
	int last_digit = 4;

//	Store the result in variable "sum".
	int sum = first_digit + last_digit;
	
//	Display the result of sum on screen.
	cout<<"My VU Id is: "<<VUId;
	cout<<endl;
	cout<<"The sum of first and last digit of VU ID is "<<sum;
	
//	If sum is greater than 7 then print the "Welcome to VU".
//	Number of iterations of FOR loop should be equal to the sum.
	if(sum >= 7){
		for(int i=1; i<=sum; i++)
		cout<<"\nIteartion "<< i <<": Welcome to VU ";
	}
	
//	If sum is less than 7 then print the "Welcome to CS201P".
//	Number of iterations of FOR loop should be equal to the sum.
	else{
		for(int i=1; i<=sum; i++)
		cout<<"\nIteartion "<< i <<": Welcome to CS201P ";
	}
	
	getch();
	return 0;
}
