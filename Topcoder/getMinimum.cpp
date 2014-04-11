/*
Problem Statement
    	
Class Name: FlightConnections
Method Name: getMinimum
Parameters: String[], String, String
Returns: int

Implement a class FlightConnections, which contains a method getMinimum.
getMinimum takes a String[] representing a list of available flights, a String
representing the departure city, and a String representing the intended
destination.  It returns the minimum number of flights needed to arrive from
the departure city to the destination city.

Note:
*If the departure city and the intended destination are the same, no flights
are needed, so return 0.  
*If there is no possible connection from the departure city to the destination
city, return 0.
*If either the departure or arrival city is not mentioned in the String[],
return 0.
*City names are case sensitive.
*Departure and arrival times don't play any roll.
*Flights are directional.  That is if there is a flight from city A to city B
there isn't necessarily a flight in the reverse direction.
*Duplications in the String[] are ignored.
String[] elements are of the form:
"FROM, TO" (There is a comma followed by exactly one space between FROM and TO).
representing a flight from FROM to TO.  FROM and TO contain letters and dashes
('-'). 

Here is the method signature:
int getMinimum(String[] flights, String strDeparture, String strDestination);
Be sure your method is public.

* flights will be a String[] of the form above.  It has between 1 and 20
elements. Each element is at most 50 characters long.
* strDeparture and strDestination will be Strings consisting only of characters
from the set A-Z, a-z, and "-" (dash).

* TopCoder will check the validity of the inputs.
Examples(quotes are for clarity, but not included in the Strings):
   Flights: ["T, B", "O, F", "D, Y", "F, K", "K, C", "V, N", "B, O"]
   Departure From: T
   Destination: C
   Minimum flights: 5 (T to B; B to O; O to F; F to K; K to C)

   Flights: ["Y, C", "O, F", "Y, O", "M, O", "C, K", "O, K", "K, S", "K, M"]
   Departure From: Y
   Destination: Y
Minimum flights: 0 (the intended destination is the same as the departure
city)

   Flights: ["Here, Ba", "Ba, Ya", "Fa, Qa"]
   Departure From: Here
   Destination: Qa
   Minimum flights: 0 (no possible way to get from Here to Qa)
 
Definition
    	
Class:	FlightConnections
Method:	getMinimum
Parameters:	String[], String, String
Returns:	int
Method signature:	int getMinimum(String[] param0, String param1, String param2)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

class FlightConnections
{
	public:
		int getMinimum(vector<string> flights, string strDeparture, string strDestination)
		{
			if(strDeparture == strDestination)
				return 0;

			vector<string> from, to, v;

			for (int i = 0; i < flights.size(); ++i)
			{
				string s;
				istringstream iss(flights[i]);
				iss>>s;
				s = s.substr(0,s.size()-1);
				from.push_back(s);
				if(find(v.begin(), v.end(), s) == v.end())v.push_back(s);
				iss>>s;
				to.push_back(s);
				if(find(v.begin(), v.end(), s) == v.end())v.push_back(s);
			}

			if(find(v.begin(), v.end(), strDeparture) == v.end() || find(v.begin(), v.end(), strDestination) == v.end())
				return 0;

			int map[v.size()][v.size()];	

			for (int i = 0; i < v.size(); ++i)
			{
				for (int j = 0; j < v.size(); ++j)
				{
					map[i][j] = v.size() + 1;
				}
			}	

			for (int i = 0; i < from.size(); ++i)
			{
				map[find(v.begin(), v.end(), from[i])-v.begin()][find(v.begin(), v.end(), to[i])-v.begin()] = 1;
			}

			for (int i = 0; i < v.size(); ++i)
			{
				map[i][i] = 0;
			}

			for (int i = 0; i < v.size(); ++i)
			{
				for (int j = 0; j < v.size(); ++j)
				{
					for (int k = 0; k < v.size(); ++k)
					{
						if(map[i][j] + map[j][k] < map[i][k])
						{
							map[i][k] = map[i][j] + map[j][k];
						}
					}
				}
			}

			if(map[find(v.begin(), v.end(), strDeparture)-v.begin()][find(v.begin(), v.end(), strDestination)-v.begin()] == v.size() + 1)
				return 0;

			return map[find(v.begin(), v.end(), strDeparture)-v.begin()][find(v.begin(), v.end(), strDestination)-v.begin()];
		}
};

int main()
{
	FlightConnections *F = new FlightConnections;

	//string s = "S", e = "S", f[] = {"A, B", "K, A", "X, B", "R, G", "S, K", "Z, R", "K, I", "G, H", "B, Z", "U, O", "S, M"};
	//string s = "L", e = "X", f[] = {"C, K", "A, X", "V, T", "N, L", "B, N", "B, P", "F, Z", "V, H", "L, B", "A, V", "Z, Q", "F, G"};
	//string s = "T", e = "Y", f[] = {"T, Y", "M, W", "Y, W", "C, Q", "S, A", "H, B", "V, Y", "Q, J", "T, B", "W, T", "V, C", "Y, G", "L, V"};
	//string s = "I", e = "U", f[] = {"Y, H", "Q, M", "I, Z", "O, X", "D, Q", "S, A"};
	//string s = "Hartford", e = "Juan", f[] = {"Hartford, New-York", "New-York, Atlanta", "New-York, Miami", "Miami, Seattle", "Hartford, New-York", "Seattle, Juan", "Atlanta, Juan"};
	//string s = "a", e = "s", f[] = {"a, b", "c, d", "e, f", "g, h", "i, j", "k, l", "m, n", "o, p", "q, r", "s, t", "u, v", "w, x", "y, z", "aa, bb", "cc, dd", "ee, ff", "gg, hh", "ii, jj", "kk, ll", "mm, nn"};
	//string s = "A", e = "F", f[] = {"A, B", "B, C", "C, D", "E, F", "A, C"};
	//string s = "A", e = "B", f[] = {"A, B"}; 
	//string s = "G", e = "A", f[] = {"G, A", "C, F", "G, J", "J, L", "L, A", "G, L"};
	//string s = "a", e = "e", f[] = {"a, f", "a, g"};
	string s = "A", e = "C", f[] = {"A, B", "B, C", "A, C"};

	vector<string> v;
	v.insert(v.begin(), f , &f[sizeof(f)/sizeof(*f)]);
	cout<<F->getMinimum(v,s,e)<<"\n";
	return 0;
}