#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin>>T;
	double maxi,mini;
	double a,b,c,max =0,min =4000000,A,s;
	for(int i = 1; i <= T; ++i)
	{
		double x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;

		a=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		b=sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
		c=sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
		s = (a+b+c)*1.0/2;
		A = sqrt(s*(s-a)*(s-b)*(s-c));
		if(A>=max) { max = A ; maxi = i;}
		if(A<=min) { min = A ; mini = i;}
	}
	cout<<mini<<" "<<maxi<<"\n"; 
	return 0;
}