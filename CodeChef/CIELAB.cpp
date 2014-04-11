#include <iostream>

using namespace std;

int main()
{
	int A,B;
	cin>>A>>B;
	(A-B)%10==9?cout<<A-B-1:cout<<A-B+1<<"\n";
	return 0;
}
