#include <iostream>
#include <map>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(;T--;)
	{
		int N;
		cin>>N;

		map<int,int> A;
		int MAXCOUNT = 0,index= 0;
		for (int i = 0; i < N; ++i)
		{
			int x;
			cin>>x;
			if(A.find(x) == A.end())
				A[x]=0;
			++A[x];
		}
		for(map<int,int>::iterator i = A.begin(); i != A.end(); i++)
		{
			if(i->second > MAXCOUNT)
			{
				MAXCOUNT = i->second;
				index = i->first;
			}
		}
		A.clear();
		cout<<index<<" "<<MAXCOUNT<<"\n";
	}
	return 0;
}