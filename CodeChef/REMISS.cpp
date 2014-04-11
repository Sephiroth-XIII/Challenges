#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int A,B;
		cin >> A >> B;
		cout << max(A,B) << " " << A+B << "\n";
	}
	return 0;
}