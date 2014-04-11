#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int R,C;
	cin >> R >> C;


	vector<vector<int> > A(R);
	for (int i = 0; i < R; ++i)
	{
		vector<int> Col(C);
		for (int j = 0; j < C; ++j)
		{
			cin >> Col[j];
		}
		A[i] = Col;
	}

	bool flag = true,found = true;
	int N = 0;
	for (int i = 0; i < R; ++i)
	{
		int MIN = *min_element(A[i].begin(),A[i].end());
		for (int j = 0; j < C; ++j)
		{
			if(A[i][j] == MIN)
			{
				found = true;
				for(int k = 0 ; k < R; ++k)
				{
					if(MIN < A[k][j])
					{
						found = false;
						break;
					}
				}
			
				if(found)
				{
					flag = false;
					N = MIN;
					break;
				}
			}
		}
		if(found)
			break;
	}

	if(found)
		cout << N << "\n";
	else
		cout << "GUESS\n";

	return 0;
}