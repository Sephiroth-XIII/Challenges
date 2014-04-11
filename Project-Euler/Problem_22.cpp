/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
What is the total of all the name scores in the file?
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;

int main()
{
	vector<string> NAMES;
	ifstream myFile("names.txt");
	
	char N;
	string name="";
	
	if(myFile.is_open()) 
	{
        while(!myFile.eof()) 
        {
            N = myFile.get();

            if(isalpha(N))
                name.push_back(N);
            else {
                if(!name.empty()) 
                {
                    NAMES.push_back(name);
                    name.clear();
                }
            }
        }
    }
    myFile.close();
	
	long long score=0;
	sort(NAMES.begin(),NAMES.end());
	for(int i=0;i<NAMES.size();i++)
	{
		long long SUM=0;
		for(int j=0;j<NAMES[i].size();j++)
			SUM+=(NAMES[i][j]-64);
		SUM*=(i+1);
		score+=SUM;
	}
	cout<<score<<"\n";
	return 0;
}

