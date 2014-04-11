/*
Problem Statement
    	
Class Name: Profit
Method Name: maxProfit
Parameters: int,int[]
Returns: int

George owns a circus and brings his circus from town to town.  He knows how
much revenue he can take in on any day in a series of days in a town.  He also
knows the constant daily cost to run his circus.  George wants to bring his
circus to town for the series of days that results in the highest profit.

Implement a class Profit which contains a method maxProfit.  The method takes
an int and an int[] as parameters.  The int is the constant daily cost of
operating the circus.  The int[] contains elements representing the revenue the
circus will earn on given days. The 0th element of the int[] is "Day 1".  Index
1 is "Day 2", etc...  The method returns an int that is the maximum profit
George's circus can make by bringing the circus to town for a series of
sequential days that is a subset of the days in the int[].

For example, if the circus costs $20 a day to run, and the revenue per day is
{$18,$35,$6,$80,$15,$21}, George can make the most money by bringing his circus
to town from Day 2 to Day 4.  He will make (35+6+80)-(3*20) = $61.

Note:
-The series of days George brings his circus to town can be between 0 days and
the int[] size days, inclusive.
-If George brings his circus to town for 0 days, he makes 0 profit.

Here is the method signature:
int maxProfit(int perDayCost, int[] revenues);
Be sure your method is public.

perDayCost is a postive integer less than 1000.
revenues is a int[] of between 1 and 50 elements, inclusive.  Each element is a
positive integer less than 1000.

Examples:
*If perDayCost=20 and revenues={18,35,6,80,15,21}, the most money can be made
by bringing the circus to town from Day 2 to Day 4.  The method returns the
maximum profit, 61.
*If perDayCost=40 and revenues={30,20,10,38}, George will make no money by
bringing his circus to the town, so George will bring his circus to town for 0
days and make 0 profit.  The method returns 0.
*If perDayCost=10 and revenues={30,20,10,38}, George will make the most money
by bringing his circus to town for all four days.  The method returns the
profit, 58.
 
Definition
    	
Class:	Profit
Method:	maxProfit
Parameters:	int, int[]
Returns:	int
Method signature:	int maxProfit(int param0, int[] param1)
(be sure your method is public)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Profit
{
	public:
		int maxProfit(int perDayCost, vector<int> revenues)
		{

			int maxRevenue = 0, currentRevenue = 0;

			for(int i = 0; i < revenues.size(); i++)
			{
				revenues[i] -= perDayCost;
				currentRevenue = currentRevenue + revenues[i];
				maxRevenue = max(currentRevenue,maxRevenue);
				currentRevenue = currentRevenue > 0 ? currentRevenue : 0;
			}

			return maxRevenue;
		}
};

int main()
{
	vector<int> v;
	Profit *P = new Profit;
	
	//int perDayCost = 20;int revenues[] = {18,35,6,80,15,21};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 40;int revenues[] = {30,20,10,38};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 10;int revenues[] = {30,20,10,38};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	
	//int perDayCost = 30;int revenues[] = {100, 100, 10 ,10, 10};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 20;int revenues[] = {100};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 20;int revenues[] = {509,59};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 30;int revenues[] = {10, 10, 10, 100, 100};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 5;int revenues[] = {20};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 12;int revenues[] = {6,10,11,11,10,8};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 100;int revenues[] = {101,101,102,300,350,100,103};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 70;int revenues[] = {80, 50, 90, 100, 30, 10, 5, 1, 1};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 60;int revenues[] = {65, 60, 70, 10, 10, 10, 10, 70, 70, 70};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 12;int revenues[] = {1, 1, 1, 999, 1, 1, 999, 1};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 10;int revenues[] = {100};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 10;int revenues[] = {30};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 20;int revenues[] = {40,10,10};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 1;int revenues[] = {2};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 20;int revenues[] = {50};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 10;int revenues[] = {20,9,20};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	//int perDayCost = 10;int revenues[] = {50};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);
	int perDayCost = 5;int revenues[] = {2,10,10,11};v.insert(v.begin(),revenues,&revenues[sizeof(revenues)/sizeof(*revenues)]);

	cout<<P->maxProfit(perDayCost,v)<<"\n";
	return 0;
}