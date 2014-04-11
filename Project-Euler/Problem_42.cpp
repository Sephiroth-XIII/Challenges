/*
The nth term of the sequence of triangle numbers is given by, tn = n(n+1)/2; so the first ten triangle numbers are:
1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

int Tri[101];

void gen_tri()
{
	for (int i = 0; i < 101; ++i)
	{
		Tri[i]=(i*(i+1))/2;
	}
	return;
}

bool is_tcoded(string in)
{
	int sum=0;
	for (int i = 0; i < in.size(); ++i)
	{
		sum+=(in[i]-'A'+1);
	}
	return binary_search(Tri,Tri+101,sum);
}

int main()
{
	gen_tri();
	string in;
	int count=0;
	ifstream fin;
	fin.open("words.txt");
	while(getline(fin,in,','))
	{
		in=in.substr(1,in.size()-2);
		if(is_tcoded(in))count++;
	}
	cout<<count<<"\n";
	return 0;
}