#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin>>N;
	bitset<1001> A;
	vector<int> B(N);
	for (int i = 0; i < N; ++i)
	{
		cin>>B[i];
		--B[i];
	}
	vector<vector<int> > solution;
	for (int i = 0; i < N ; ++i)
	{
		int j = i;
		if(!A[j])
		{
			vector<int> temp;
			do
			{
				temp.push_back(j+1);
				A.set(j);
				j=B[j];
			} while (!A[j]);
			temp.push_back(j+1);
			solution.push_back(temp);	
		}
	}

	cout<<solution.size()<<"\n";
	for (int i = 0; i < solution.size(); ++i)
	{
		for (int j = 0; j < solution[i].size(); ++j)
		{
			cout<<solution[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}