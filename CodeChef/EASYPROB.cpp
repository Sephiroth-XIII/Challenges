#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

string stringRep(int n)
{
	ostringstream oss;
	oss << n;
	return oss.str();
} 

int main()
{
	int A[] = {137,1315,73,136,255,1384,16385};

	vector<string> presentation(33);
	presentation[0] = "0";
	for (int i = 1; i <=32; ++i)
	{
		vector<int> powers;
		string rep = "";
		int p = 31,sum=0;
		while(sum<i)
		{
			if(pow(2,p) <= i-sum)
			{
				powers.push_back(p);
				sum += pow(2,p);
			}
			--p;
		}
		for (int j = powers.size()-1; j >=0 ; --j)
		{
			if(powers[j] == 1)
				rep = "2+"+rep;
			else if (powers[j] > 2)
				rep = "2("+presentation[powers[j]]+")+"+rep;
			else
				rep = "2("+stringRep(powers[j])+")+"+rep;
		}
		rep = rep.substr(0,rep.size()-1);
		presentation[i] = rep;
	}

	for (int i = 0; i < 7; ++i)
	{
		bitset<32> rep(A[i]);
		string s="";
		for(int j = 31; j >= 0; j--)
		{
			string x ="";
			if(rep[j]==1)
			{
				x = "2("+presentation[j]+")+";
				if(x == "2(2(0))+")
					x = "2+";
				s += x;
			}
		}
		s = s.substr(0,s.size()-1);
		cout<<A[i]<<"="<<s<<"\n";
	}
	return 0;
}