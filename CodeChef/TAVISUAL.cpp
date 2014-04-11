#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		int N,C,Q;
		cin >> N >> C >> Q;

		for(;Q--;)
		{
			int L,R;
			cin >> L >> R;

			if(L<=C && C<=R)
				C = L + R - C;
		}
		cout << C <<"\n";
	}
}