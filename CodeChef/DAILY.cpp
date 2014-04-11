#include <iostream>
#include <bitset>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int factorial(int n)
{
	if(n <= 1)
		return 1;
	return n*factorial(n-1);
}

int NCR(int r,int n)
{
	return factorial(n)/factorial(r)/factorial(n-r);
}

bitset<54> reverseBitset(string S)
{
	bitset<54> B(string(S.rbegin(),S.rend()));
	return B;
}

int main()
{
	int N, X;
	cin >> N >> X;

	map<int,int> seatCar;
	for (int i = 0, j = -1; i < 54; ++i)
	{
		if(i % 4 == 0 && i <= 36)
			++j;
		if(i % 2 == 0 && i >= 36)
			--j;
		seatCar[i] = j;
	}

	vector<bitset<54> > C(X);
	string S;
	for (int i = 0; i < X; ++i)
		cin >> S, C[i] = reverseBitset(S);

	vector<int> empty(X*9,0);
	unsigned long long total_ways = 0;

	for (int i = 0; i < X; ++i)
	{
		for (int j = 0; j < 54; ++j)
		{ 
			if(C[i][j] == 0)
				++empty[i*9+seatCar[j]];
		}
	}

	for (int i = 0; i < empty.size(); ++i)
	{
		if(N <= empty[i])
			total_ways += NCR(N,empty[i]);
	}
	cout << total_ways << "\n";
	return 0;
}