/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
{20,48,52}, {24,45,51}, {30,40,50}
For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int p[1001];
	fill_n(p,1001,0);
	for (int i = 1; i < 501; ++i)
		for (int j = i; j < 501; ++j)
			for (int k = j; k < 501; ++k)
				if(k*k==i*i+j*j)++p[i+j+k];
	cout<<max_element(p,p+1001)-p<<"\n";
	return 0;
}