#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;

	long long nines[] = {0,9,99,999,9999,99999,999999,9999999,99999999,999999999}, 
	tens[] = {0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

	for(;T--;)
	{
		long long L,R,ld,rd,res;
		cin >> L >> R;

		ld = (long long)log10(L)+1;
		rd = (long long)log10(R)+1;
		res = 0;

		while(ld != rd)
		{
			res += (long long)((L+nines[ld])*(nines[ld]-L+1)*ld)/2;
			++ld;
			L = tens[ld];
			res %= 1000000007;
		}

		res += (long long)((L+R)*(R-L+1)*ld)/2;
		res %= 1000000007;
		cout << res << "\n";

	}
	return 0;
}