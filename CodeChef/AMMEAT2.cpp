#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int A,B;
		cin >> A >> B;

		if(B == 1)
			cout << A;
		else if(2*B > A)
			cout << "-1";
		else
			for (int i = 2,j = 0; i <= A && j < B; i+=2,j++)
				cout << i << " ";
		cout << "\n";
	}
	return 0;
}