// CS201 Assignment No.3 Spring 2021.
// Name: Abdul Rehman.	VU ID: BC200403287.

// START THE PROGRAM
#include<iostream>
using namespace std;

// defining value of pi first.
double pi=3.14159265359;

// CIRCLE CLASS.
class Circle
{
	private:
    	double radius;
    public:
    	Circle()
	{
    radius=0.0;
    }

// function prototype for setRadius.
	void setRadius()
	{
	radius=5.6;
	}
// function prototype for computeAreaCirc.
	void computeAreaCirc()
	{
     cout<< " Area of circle is: " << pi*(radius*radius) <<endl;
     cout<< " Circumference of circle is: " <<2*pi*radius;
	}
};

// RECTANGLE CLASS.
class Rectangle
{
	private:
    	double height , width;
    public:
		Rectangle()
	{
	height=0.0;
	width=0.0;
    }

// Value of Length.
	void setLength()
	{
	height=5.0;
    }
    
// Value of Width.
	void setWidth()
	{
	width=4.0;
	}

// Computing AREA.
	void computeArea()
	{
	cout<< " Area of Rectangle is: " <<height*width;
	}
};

// MAIN BODY.
main()
{
	Circle Circle;
	Rectangle Rectangle;
	Circle.setRadius();
	Rectangle.setLength();
	Rectangle.setWidth();

char i='Y';
int n;

// TO DISPLAY ON SCREEN (INPUT + OUTPUT).
cout << "**********************SCIENTIFIC-CALCULATOR***********************";
cout <<endl;
cout <<endl;

while (i=='Y')
	{
	cout<< endl <<" OPTION 1 for computing Area and Circumference of the circle ";
	cout<< endl <<" OPTION 2 for computing Area Rectangle ";
	cout<< endl <<" Select your desired option(1-2): ";
	cin >> n;

// IF ELSE STATEMENT.
if(n==1)
	Circle.computeAreaCirc();
else
{
	if(n==2)
		Rectangle.computeArea();
	else
		{
    	cout<<endl<<" Invalid Option!! , Option should be from (1-2) ";
    	continue;
		}
}

	cout<<endl;
	cout<<" Do you want to perform any other Calculation(Y/N): ";
	cin>> i;
	cout<< endl;
	}
}

// END OF PROGRAM.
