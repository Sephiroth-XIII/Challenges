#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	for(;T--;)
	{
		int N;
		scanf("%d",&N);

		int MIN = 1000001, MAX = 0, dif = 0; 
		for(;N--;)
		{
			int g;
			scanf("%d",&g);
			if(g > MAX)
			{
				MAX = g;
				if(MAX-MIN > dif)
					dif = MAX - MIN;
			}
			if(g < MIN)
			{
				MIN = g;
				MAX = g;
			}
		}
		dif > 0 ? printf("%d\n",dif) : printf("UNFIT\n");
	}
	return 0;
}