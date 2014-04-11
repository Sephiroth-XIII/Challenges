#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		double D,U;
		int N;
		cin >> D >> U >> N;

		int index = 0;
		double e = D*U;
		for (int i = 1; i <= N; ++i)
		{
			double M,R,C;
			cin >> M >> R >> C;
			double _e = (C/M) + (R*U);
			if(_e < e)
				e = _e , index = i;
		}
		cout << index << "\n";
	}
	return 0;
}