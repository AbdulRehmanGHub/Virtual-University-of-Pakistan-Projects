#include<iostream>

using namespace std;

int main () {
	
	int y[10], *y1, *y2;
	y1 = &y[0];
	y2 = &y[3];
	 
	 cout << y2 - y1;
}
