#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

int FACT[12];

void factorial()
{
	FACT[0] = 1;
	for (int i = 1; i < 12; ++i)
	{
		FACT[i] = FACT[i-1]*i;
	}
	return;
}

int nCr(int n, int r)
{
	return FACT[n]/FACT[r]/FACT[n-r];
}

bool compare(int A, int B)
{
	return A > B;
}

int main()
{
	int T;
	cin>>T;

	factorial();

	for(;T--;)
	{	
		vector<int> score(11);
		for (int i = 0; i < 11; ++i)
			cin>>score[i];
		int N;
		cin>>N;
		
		sort(score.begin(),score.end(),compare);

		int n = count(score.begin(),score.end(),score[N-1]);
		int r = count(score.begin(),score.begin()+N,score[N-1]);

		cout<<nCr(n,r)<<"\n";
	}
	return 0;
}