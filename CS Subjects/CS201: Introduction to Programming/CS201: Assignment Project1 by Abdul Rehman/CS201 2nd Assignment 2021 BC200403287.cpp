// Starting the CS201 Assignment No.2 2021
#include<iostream>
#include<conio.h>

using namespace std;

// To display matrix
int showMatrix()
{
	int row=2 , column=2;
	int Matrix [2][2] = {{8 , -4} , {-6 , 2}};
	
	cout<<"Matrix is: " <<endl;
	for	(int i=0; i<row; ++i)
	{
	for	(int j=0; j<column; ++j)
	cout <<Matrix [i][j] <<" ";
	cout <<endl;
	}
}

// To show transpose
int showTranspose()
{
	int Transpose [2][2] , row=2 , column=2 , i , j ;
	int Matrix [2][2] = {{8 , -4} , {-6 , 2}};
	cout <<endl;
	for (int i=0; i<row; ++i)
	for (int j=0; j<column; ++j)
	{
		Transpose [j][i] = Matrix [i][j];
	}
	cout <<"Transpose of given Matrix is: " <<endl;
	for (int i=0; i<column; ++i)
	{
		for (int j=0; j<row; ++j)
		cout <<Transpose [i][j] <<" ";
		cout <<endl;
	}
}

// To find determinant
int calculateDeterminant()
{
	int	determMatrix[2][2],	determinant;
	int matrix[2][2] = {{8 , -4}, {-6 , 2}};
	determinant = ((matrix[0][0]*matrix[1][1])) - ((matrix[0][1]*matrix[1][0]));
	cout <<"\nDeterminant of given Matrix is: " <<determinant;
}

// To show adjoint
int showAdjoint()
{
	int ch, A2[2][2] = {{8 , -4} , {-6 , 2}}, AD2[2][2] , C2[2][2];
	
//calculating cofactors of a Matrix of order 2 x 2
	C2[0][0] = A2[1][1]; C2[0][1] = -A2[1][0];
	C2[1][0] =-A2[0][1]; C2[1][1] = A2[0][0];
	
//calculating adjoint of a Matrix of order 2 x 2
	AD2[0][0] = C2[0][0]; AD2[0][1] = C2[1][0];
	AD2[1][0] = C2[0][1]; AD2[1][1] = C2[1][1];
		cout <<"\n\nAdjoint of given Matrix is:\n\n";
		cout <<"\t" <<AD2[0][0] <<"\t" <<AD2[0][1] <<"\t\n\t" <<AD2[1][0] <<"\t" <<AD2[1][1];
}

// Main Body
int main()
{
	int choice=0;
		cout << "Enter your choice" <<endl;
//	When 1 is pressed
		cout <<"Press 1 to display Matrix and its Transpose" <<endl;

//	When 2 is pressed
		cout <<"Press 2 to find Adjoint and Determinant of the Matrix" <<endl;

//	When any other key is pressed
		cout <<"Press any other key to Exit" <<endl;

//Input
			cin>>choice;

// for key 1
				if(choice == 1)
{
	showMatrix();
				cout<< endl;
	showTranspose();
}

// for key 2
		else if(choice == 2)
		{
			showAdjoint();
				cout<< endl;
			calculateDeterminant();
		}
// for any key other than 1 and 2
		else
		system ("exit");
}

// The End of CS201 Assignment No.2 2021 by Abdul Rehman ( BC200403287 )
