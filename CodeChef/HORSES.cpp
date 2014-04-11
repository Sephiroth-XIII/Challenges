#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N;
		cin>>N;

		vector<int> horseSkill(N);
		for(int i = 0; i < N; i++)
		{
			cin>>horseSkill[i];
		}

		sort(horseSkill.begin(),horseSkill.end());

		int dif = 1000000000;

		for(int i = 1; i < N; i++)
		{
			if(horseSkill[i] - horseSkill[i-1] < dif)
				dif = horseSkill[i] - horseSkill[i-1];
		}

		cout<<dif<<"\n";
	}
	return 0;
}