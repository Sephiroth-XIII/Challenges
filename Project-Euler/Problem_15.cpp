/*
Starting in the top left corner of a 2×2 grid, there are 6 routes (without backtracking) to the bottom right corner.
			start---*---*
				|	|	|
				*---*---*
				|	|	|
				*---*---end
How many routes are there through a 20×20 grid?
*/

/*
SOLUTION UNDERSTOOD FROM : http://zacharydenton.com/project-euler-solutions/15/ 
*/

#include<iostream>
#include<cmath>

#define GRID 20

using namespace std;

int main()
{
	int i;
	double n=1,k=1;
	//FINDING Binomial coefficient of 2n C n
	for(i=GRID+1;i<=2*GRID;i++)
		n*=i;
	for(i=1;i<=GRID;i++)
		k*=i;
	cout<<(unsigned long long)ceil(n/k)<<"\n";
	return 0;
}
