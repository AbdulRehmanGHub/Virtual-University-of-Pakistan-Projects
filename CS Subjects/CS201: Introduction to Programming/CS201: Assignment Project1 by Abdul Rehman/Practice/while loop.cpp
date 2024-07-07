#include<iostream>
#include<conio.h>

using namespace std;

main()
{
		int sum, number, UpperLimit;
	sum =0;
	number =1;
	
	cout<< "please enter the upper limit for which you want to sum ";
	
	cin>>UpperLimit;
	
	while(number<=UpperLimit){
		if ((number %2) ==0)
		{
		sum= sum+number;
	}
	    number= number+1;
}

  cout <<"The sum of all even integers between 1 and " <<UpperLimit << "is " <<sum;
		
	return 0;
}
