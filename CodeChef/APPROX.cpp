#include <iostream>
#include <string>

using namespace std;

string Pi;

int main()
{
	Pi += "3.";
	int D = 33102, N = (103993%D)*10, R = 0; 
	for (int i = 0; i < 1000005; ++i)
	{
		Pi += char('0'+N/D);
		N = (N % D)*10;
	}

	int T;
	cin >> T;

	for(;T--;)
	{
		int N;
		cin >> N;
		cout << (N == 0 ? "3" : Pi.substr(0,N+2)) <<"\n";
	}
	return 0;
}