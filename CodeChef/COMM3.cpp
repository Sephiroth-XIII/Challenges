#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int R,x1,y1,x2,y2,x3,y3;
		cin>>R;
		cin>>x1>>y1;
		cin>>x2>>y2;
		cin>>x3>>y3;

		float D1 = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		float D2 = sqrt(pow(x1-x3,2)+pow(y1-y3,2));
		float D3 = sqrt(pow(x2-x3,2)+pow(y2-y3,2));

		(D1 <= R && D2 <= R) || (D1 > R && D2 <= R && D3 <= R) || (D2 > R && D1 <= R && D3 <= R) ? cout<<"yes\n":cout<<"no\n";
	}
	return 0;
}