#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string add(string A, string B)
{
	string C = "";
	int n1 = A.size(),n2= B.size(), i = 1,rem = 0, ad = 1;
	while(i <= max(n2,n1) || rem > 0)
	{
		if(n1-i >=0 && n2-i >=0)
			ad = int(A[n1-i]-'0') + int(B[n2-i]-'0') + rem;
		else if(n1-i >= 0)
			ad = int(A[n1-i]-'0') + rem;
		else if(n2-i >= 0)
			ad = int(B[n2-i]-'0') + rem;
		C = char(ad%10+'0')+C;
		rem = ad/10;
		ad /= 10;
		i++;
	}
	return C;
}

void calcFibo(vector<string> &Fibo)
{
	Fibo.push_back("0");
	Fibo.push_back("1");

	int i = 2;
	while(Fibo[i-1].size() <= 1000)
	{
		Fibo.push_back(add(Fibo[i-1],Fibo[i-2]));
		++i;
	}
	return;
}

int main()
{
	int T=-1;
	cin >> T;

	vector<string> Fibo;
	calcFibo(Fibo);

	for(;T--;)
	{
		string S;
		cin >> S;
		if(find(Fibo.begin(),Fibo.end(),S) != Fibo.end())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}