/*	Name: Abdul Rehman.
	VUID: BC220424444.	*/
	
#include<iostream>
#include<conio.h>

using namespace std;

// Declaring a two-dimensional array of order 3 * 3.
int arr[3][3] = { { 56, 27, 9 },{ 25, 32, 18 },{ 88, 11, 23 } };

// display function, which will take RowWise sorted array and ColWise sorted array as an input and print its elements.
void display(int arr[][3])
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			cout<<arr[i][j]<<"	";
		}
		cout<<endl;
	}
}

// sortRow function, which will take the given array as input and sort its element RowWise.
void sortRow(int arr[][3])
{
	int temp;
	for (int i=0; i<3; i++)
	{	
		for (int j=0; j<3; j++)
		{
			for (int k=j+1; k<3; k++)
			{
				if (arr[i][j]>arr[i][k])
				{
					temp = arr[i][j];
					arr[i][j] = arr[i][k];
					arr[i][k] = temp;
				}
			}	
		}
	}
}

// sortCol function, which will take RowWise sorted array as input and sort its elements ColWise.
void sortCol(int arr[][3])
{
	int temp;
	for (int j=0; j<3; j++)
	{
		for (int i=0; i<3; i++)
		{
			for (int k=i+1; k<3; k++)
			{
				if (arr[i][j]>arr[k][j])
				{
					temp = arr[i][j];
					arr[i][j] = arr[k][j];
					arr[k][j] = temp;
				}
			}
		}
	}
}

// diagonalSum function, which will calculate the sum of diagonal elements of RowWise array and display them on screen.
void diagonalSum(int arr[3][3])
{
	int sum = 0;
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if (i==j)
			{
				sum += arr[i][j];
			}
		}
	}
	cout<<"Sum of diagonal Elements for RowWise Sorted Array is: "<<sum<<endl;
}

// diagonalSum1 function, which will calculate the sum of diagonal elements of ColWise array and display them on screen.
void diagonalSum1(int arr[3][3])
{
	int sum1 = 0;
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if (i==j)
			{
				sum1 += arr[i][j];
			}
		}
	}
	cout<<"Sum of diagonal Elements for ColWise Sorted Array is: "<<sum1<<endl;
}

//	Main Function.
int main()
{
	cout<<"RowWise Sorted Arrays: "<<endl;
	sortRow(arr);
	display(arr);
	cout<<endl;
	
	diagonalSum(arr);
	
	cout<<"\nColWise Sorted Arrays: "<<endl;
	sortCol(arr);
	display(arr);
	cout<<endl;
	
	diagonalSum1(arr);
	
	getch();
	return 0;
}
