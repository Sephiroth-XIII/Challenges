#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int N,Q;
	cin >> N >> Q;

	map<string,string> extType;

	for(;N--;)
	{
		string ext,type;
		cin >> ext >> type;
		extType[ext] = type; 
	}

	for(;Q--;)
	{
		string fileName;
		cin >> fileName;

		if(fileName.find('.') == string::npos)
			cout << "unknown\n";
		else
		{
			string ext = fileName.substr(fileName.rfind('.')+1,fileName.size() - fileName.rfind('.') - 1);
			if(extType.find(ext) != extType.end())
				cout << extType[ext] << "\n";
			else
				cout << "unknown\n";
		}
	}

	return 0;
}