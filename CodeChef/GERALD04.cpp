#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int stringToInt(string s)
{
	istringstream iss(s);
	int n;
	iss >> n;
	return n;
}

int main()
{
	int T;
	cin >> T;

	for(;T--;)
	{
		cin.ignore();
		string s;
		int T1h,T1m,T2h,T2m,D;
		getline(cin,s,':');
		T1h = stringToInt(s);
		cin >> T1m;
		getline(cin,s,':');
		T2h = stringToInt(s);
		cin >> T2m;
		cin >> D;

		cout << setprecision(1) << fixed;
		int md = (T1h*60+T1m) - (T2h*60+T2m);
		if(md >= 0)
		{
			if(md >= 2*D)
				cout << float(md+D) << " " << float(md) << "\n";
			else
				cout << float(md+D) << " " <<md + float(2*D-md)/2 << "\n";
		}
		else
		{
			cout << float(D) << " " << float(D) << "\n";
		}
	}
	return 0;
}