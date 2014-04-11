/*
Problem Statement
    	
Class name:  Population
Method name:  getPop
parameters:  int,String[]
returns: int

Implement a class Population, which contains a method getPop.  getPop simulates
the building and abandoning of living quarters in a city.  It takes as
parameters an int that is the number of years to run the simulation and a
String[] of coordinates representing the initial locations of living quarters
within the city.  getPop returns the number of living quarters in the city
after the specified number of years.

The city is a 10x10 grid.  Each square in the grid can contain 0 or 1 living
quarters.  The squares are referred to by coordinates of the form (int,int)
where the first int ranges from 0 to 9 and represents the North/South position
and the second int ranges from 0 to 9 and represents the East/West position.
Each square can have up to 8 neighbors (i.e. north, south, east, west,
north-west, north-east, south-west, and south-east).

The program should simulate the building and abandoning of the living quarters
based on the following rules:
1.   Each living quarter that starts a year with two or three neighboring
quarters lasts the year.
2.   Each living quarter that starts a year with four or more neighbors is
abandoned (disappears) due to over-population during the year.
3.   Each living quarter that starts a year with one or zero neighbors is
abandoned (disappears) due to isolation during the year.
4.   Each empty location that starts a year adjacent to exactly three neighbors
will have a living quarter built on it during the year.

The method signature is:
public int getPop(int years, String[] locations);

-years ranges from 0 to 10, inclusive.
-location consists of strings of the form "int,int" where both ints range from
0 to 9, inclusive.  "3,2" is an example of a valid element.  "2.3 , 3.1" is not
valid because there are spaces and non-integers.  location has from 0 to 100
elements, inclusive.  Duplicate elements are ignored.
-Duplicates in locations should be ignored.

Note:
-If the input year is 0, the method should return the initial population.

Example (the quotes in the String[] below are for clarification, and should not
be part of your input):
-if years=3 and locations={"5,4","4,5","6,6","6,7","5,5","4,4"}
 After year 1, there are living quarters at: {"4,4","4,5","5,4","6,5","6,6"}
 After year 2: {"4,4","4,5","5,4","5,6","6,5"}
 After year 3: {"4,4","4,5","5,4","5,6","6,5"}
 And the method should return 5.
-if years=4 and locations={"0,0","1,0","0,1"}, the method should return 4.
 
Definition
    	
Class:	Population
Method:	getPop
Parameters:	int, String[]
Returns:	int
Method signature:	int getPop(int param0, String[] param1)
(be sure your method is public)
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Population
{
	private:
		bool grid[10][10];

		bool isOccupied(int row, int col)
		{
			return row>-1 && row <10 && col >-1 && col<10 && grid[row][col];
		}

		int countNeignbors(int row, int col)
		{
			int neighbors = 0;
			int dxy[][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}}; 
			for (int i = 0; i < 8; ++i)
			{
				if(isOccupied(row+dxy[i][0],col+dxy[i][1]))
					++neighbors;
			}
			return neighbors;
		}

	public:
		int getPop(int years, vector<string> locations)
		{
			for (int i = 0; i < locations.size(); ++i)
			{
				istringstream iss(locations[i]);
				
				string s;
				int a,b;

				getline(iss,s,',');
				istringstream num1(s);
				num1>>a;

				getline(iss,s);
				istringstream num2(s);
				num2>>b;

				grid[a][b] = true;
			}
			
			bool tmp[10][10];
			int num = locations.size();

			for (int i = 0; i < years; ++i)
			{
				for (int r = 0; r < 10; ++r)
				{
					for (int c = 0; c < 10; ++c)
					{
						int neighbors = countNeignbors(r,c);
						tmp[r][c] = grid[r][c];
						if(grid[r][c])
							tmp[r][c] = (neighbors>1 && neighbors<4);
						else
							tmp[r][c] = (neighbors==3);
					}
				}

				num = 0;
				for (int r = 0; r < 10; ++r)
				{
					for (int c = 0; c < 10; ++c)
					{
						if((grid[r][c]=tmp[r][c]))
							++num;
					}
				}				
			}
			return num;
		}	
};

int main()
{
	Population *P = new Population;
	
	int y;

	//y = 3;
	//string s[] = {};

	//y = 8;
	//string s[] = {"3,4", "3,5", "3,6", "4,3", "4,4", "4,5", "4,6", "4,7", "5,4", "5,5", "5,6", "9,9", "9,8", "8,9"};

	//y = 2;
	//string s[] = {"0,0", "2,5", "3,5", "4,7", "5,7", "0,1", "2,6", "3,7", "5,5", "7,1", "1,0", "2,7", "4,5", "5,6", "7,2", "7,2", "0,1"};

	//y = 0;
	//string s[] =  {"1,1", "3,3", "5,5"};

	y = 10;
	string s[] = {"3,4", "3,5", "3,6", "4,4", "4,6", "5,4", "5,5", "5,6"};

	vector<string> v;
	v.insert(v.begin(),s,&s[sizeof(s)/sizeof(*s)]);
	cout<<P->getPop(y,v)<<"\n";
	return 0;
}