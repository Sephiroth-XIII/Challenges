#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		string C;
		cin >> C;

		for (int i = C.size()-4; i >= 0; --i)
		{
			if((C[i] == '?' || C[i] == 'C') && (C[i+1] == '?' || C[i+1] == 'H') && (C[i+2] == '?' || C[i+2] == 'E') && (C[i+3] == '?' || C[i+3] == 'F'))
				C[i] = 'C', C[i+1] = 'H', C[i+2] = 'E', C[i+3] = 'F';
		}

		for (int i = 0; i < C.size(); ++i)
		{
			if(C[i] == '?')
				C[i] = 'A';
		}

		cout << C << "\n";
	}
	return 0;
}