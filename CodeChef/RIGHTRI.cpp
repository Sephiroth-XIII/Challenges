#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int count = 0;
	for(;T--;)
	{
		int x1,y1,x2,y2,x3,y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

		int D1 = pow(x1-x2,2) + pow(y1-y2,2);
		int D2 = pow(x2-x3,2) + pow(y2-y3,2);
		int D3 = pow(x1-x3,2) + pow(y1-y3,2);

		if((D1 == D2 + D3) || (D2 == D1 + D3) || (D3 == D1 + D2))
			++count;
	}
	cout<<count<<"\n";
	return 0;
}
