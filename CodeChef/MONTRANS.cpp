#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int A,B,C;

		cin >> A >> B >> C;

		int MAX = 0, i = 0, index = 0;
		while(A*100 + B >= C && i <= 10000)
		{
			if(B >= C)
				B -= C;
			else
				B += 100, --A, B -= C;
			if(A*100 + B > MAX)
				MAX = A*100 + B,index = i;
			swap(A,B);
			++i;
		}
		cout << index << "\n";
	}
	return 0;
}