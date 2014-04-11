#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int Ds, Dt, D;

		cin >> Ds >> Dt >> D;

		cout << max(max(max(0 , D-Ds-Dt),Ds-D-Dt),Dt-D-Ds) << "\n";
	}
	return 0;
}
