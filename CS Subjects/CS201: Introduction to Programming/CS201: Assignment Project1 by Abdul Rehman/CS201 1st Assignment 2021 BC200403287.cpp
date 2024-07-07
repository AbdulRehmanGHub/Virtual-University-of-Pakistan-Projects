// START
#include<iostream>

using namespace std;

// MAIN BODY
int main()
{
// DATA TYPES
int x;
int y;
int Z;

// VALUES & EXPRESSION
	x=2;
	y=1;	

int r=1, VUID_lastdigit=7;
Z= (x*x + 2*x*y)-(x/y);
	
	cout<<"After Evaluation of Given Expression the Value of Z= " <<Z<< endl;
	
	cout<<"Last Digit of My VU ID is " <<VUID_lastdigit<<endl;
	
	VUID_lastdigit= VUID_lastdigit+Z;

// FOR EVEN NUMBER
if(VUID_lastdigit%2==0)
{
	cout<<"I Got an Even Number " <<VUID_lastdigit<<endl;
while (r<=VUID_lastdigit)
{
	cout<<"Iteration: " <<r<<endl;
	cout<<"My Name is Abdul Rehman " <<endl;
	r++;
}
}

// FOR ODD NUMBER
else {
	cout<<"I Got an Odd Number " <<VUID_lastdigit<<endl;
while(r<=VUID_lastdigit)
{
	cout<<"Iteration: " <<r<<endl;
	cout<<"My VU Student ID is BC200403287 " <<endl;
	r++;
}
}
}
//END
