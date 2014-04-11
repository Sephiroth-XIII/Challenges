#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	while(cin>>N && N!=0)
	{
		vector<int> num(N),pos(N);
		for(int i = 0; i < N; i++)
		{
			cin>>num[i];
			pos[num[i]-1] = i+1;
		}
		if(pos == num)
			cout<<"ambiguous\n";
		else
			cout<<"not ambiguous\n";
	}
	return 0;
}