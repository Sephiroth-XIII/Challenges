#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N,M;
		cin >> N >> M;

		map<int,int> C,L;
		for (int i = 0; i < N; ++i)
		{
			int c,l;
			cin >> c >> l;
			if(C.find(l) == C.end())
				C[l] = 0;
			C[l] += c;
		}
		for (int i = 0; i < M; ++i)
		{
			int c,l;
			cin >> c >> l;
			if(L.find(l) == L.end())
				L[l] = 0;
			L[l] += c;
		}

		int total = 0;
		for(map<int,int>::iterator i = C.begin(); i != C.end(); i++)
		{
			int l = i->first;
			if(C[l] < L[l])
				total += L[l] - C[l];
		}
		cout << total << "\n";
	}
	return 0;
}