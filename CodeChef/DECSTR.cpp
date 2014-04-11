#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;

		if(N%25)
			for (int i = 97 + N % 25; i >= 97; i--)
				cout<<char(i);
		for (int j = 0; j < N/25; ++j)
			for (int i = 122; i >= 97 ; i--)
				cout<<char(i);
		cout<<"\n";
	}

	return 0;
}