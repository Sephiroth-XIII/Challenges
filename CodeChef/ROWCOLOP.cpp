#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int N,Q;
	cin >> N >> Q;
	map<int,int> R,C;
	int maxR = 0,maxC = 0;
	for (int i = 0; i < Q; ++i)
	{
		string S;
		int D,X;

		cin >> S >> D >> X;

		if(S == "RowAdd")
		{
			if(R.find(D) == R.end())
				R[D] = 0;
			R[D] += X;
			if(R[D] > maxR)
				maxR = R[D];
		}
		else
		{
			if(C.find(D) == C.end())
				C[D] = 0;
			C[D] += X;
			if(C[D] > maxC)
				maxC = C[D];
		}
	}
	cout << maxR + maxC << "\n";
	return 0;
}