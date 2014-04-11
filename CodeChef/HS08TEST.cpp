#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int w;
	float b;
	cin>>w>>b;
	w%5==0 && w+0.5 <= b?cout<<fixed<<setprecision(2)<<b-w-0.5<<"\n":cout<<fixed<<setprecision(2)<<b<<"\n";
	return 0;
}