/*
Problem Statement
    	
Class Name: Shipping
Method Name: mostExpensive
Parameters: int,String[],int,int,int
Returns: int

Tom's Shipping Company is a marine based shipping company.  The Company has W
warehouses on shores throughout the world.  The warehouses are referred to by
number and are numbered 0 to W-1.  There are regular direct trips (call them
legs) between certain pairs of warehouses. Each leg has a distance in miles and
a cost in dollars per ton-mile.  Each leg is bidirectional (if there is a leg
from 0 to 1, there is an identical leg from 1 to 0).

Customers request to ship cargo of a specified weight from one warehouse to
another warehouse.

Tom's Shipping Company is looking to rip off its customers as severely as
possible.  It does this by finding the series of legs that results in the
highest cost.  However, the series of legs cannot result in the cargo visiting
the same warehouse more than once - this would allow the customers realize they
were being ripped off.  The cost of shipping cargo on each leg is the weight of
the cargo multiplied by the length of the leg multiplied by the cost (per
weight-distance) of shipping on the leg.  The total cost of shipping the cargo
is the sum of the cost of shipping the cargo on each leg the cargo goes on.

Tom's Shipping Company has hired you to write a program to help them rip off
their customers.

Implement a class Shipping, which contains a method mostExpensive.  This method
takes as parameters:
an int: the number of warehouses
an String[]: the leg data - contains info on the two warehouses at either end
of the leg, the distance of the leg, and the cost of shipping cargo on the leg
an int: warehouse number customer wants to ship from
an int: warehouse number customer wants to ship to
an int: weight of the cargo in tons
The method returns an int that is the highest possible price in dollars Tom's
Shipping Company can charge.

The elements in the String[] are of the form (the quotes are for clarity, but
are not included in the actual elements):
"W1 W2 LENGTH COST" where W1 and W2 are integers that are the two warehouses at
either end of the leg, LENGTH is the integer length of the leg, in miles, and
COST is the integer cost in dollars per ton-mile of shipping on that leg.  Note
there is exactly 1 space between each of the 4 integers.

If there is no possible series of legs to get the customers cargo from the
requested starting warehouse to the requested ending warehouse, the method
returns -1.
If the data is invalid, the method returns -1.  Data is invalid if:
*any String[] element is not of the exact correct form.
*the elements in the String[] refer to non-existent warehouses.  That is, the
warehouse number is greater than or equal to the number of warehouses.
*two elements in the String[] refer to the same leg.  For instance "1 0 1 1"
and "0 1 1 1" (remember legs are bidirectional).
*the length of a leg is greater than 1000 or less than or equal to 0.
*the cost is greater than 20 or less than or equal to 0.
*the customer's request refers to non-existent warehouses.

The method signature is:
public int mostExpensive(int numWarehouses,String[] legs,int shipFrom,int
shipTo,int cargoWeight);

numWarehouses is less than 20 and greater than 0.
legs has less than 100 elements in it, each element a String with length less
than 100.
shipFrom and shipTo are greater than or equal to 0 and less than 19.
cargoWeight is greater than 0 and less than 100.

Note:
-If a customer requests to ship cargo from a warehouse to itself, the method
should return 0.
-Solution must run in under 6 seconds on TopCoder's tester.
-A leg from a warehouse to itself can be ignored because the cargo would visit
the same warehouse twice.  However, data including a leg from a warehouse to
itself is not necessarily invalid.

Examples:
*If numWarehouses=4, legs={"0 1 8 2","0 2 1 1","3 0 6 3","1 2 8 3","1 3 10
10","3 2 2 4"}, shipFrom=0, shipTo=2, and weight=1, the route with the highest
cost is 0->3->1->2, and the method should return the highest cost: 1*6*3 +
1*10*10 + 1*8*3 = 142.
 
Definition
    	
Class:	Shipping
Method:	mostExpensive
Parameters:	int, String[], int, int, int
Returns:	int
Method signature:	int mostExpensive(int param0, String[] param1, int param2, int param3, int param4)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Shipping
{
	private:
		int best;
		int dist[20][20];
		int cost[20][20];
		int visited[20];
		int goal;
		int W;

		int stringToInteger(string s)
		{
			istringstream iss(s);
			int n;
			iss>>n;
			return n;
		}

		void search(int here, int soFar)
		{
			if(here == goal)
			{
				if(soFar > best)
					best = soFar;
				return;
			}

			if(visited[here] == 1)
				return;

			visited[here] = 1;
			for (int i = 0; i < W; ++i)
				if(dist[here][i] >= 0 && visited[i] == 0)
					search(i, soFar + cost[here][i]*dist[here][i]);
			visited[here] = 0;
		}

	public:
		int mostExpensive(int numWarehouses, vector<string> legs, int shipFrom, int shipTo, int cargoWeight)
		{
			W = numWarehouses;

			if(shipFrom < 0 || shipFrom >= numWarehouses || shipTo < 0 || shipTo >= numWarehouses)
				return -1;

			for(int i = 0; i < numWarehouses; i++)
				for(int j = 0; j < numWarehouses; j++)
					dist[i][j] = -1;

			for(int i = 0; i < numWarehouses; i++)
				for(int j = 0; j < numWarehouses; j++)
					cost[i][j] = 0;

			for (int i = 0; i < legs.size(); ++i)
			{
				int W1, W2, LENGTH, COST;
				istringstream iss(legs[i]);
				
				if(!(iss>>W1))
					return -1;
				if(!(iss>>W2))
					return -1;
				if(!(iss>>LENGTH))
					return -1;
				if(!(iss>>COST))
					return -1;

				if(W1 >= numWarehouses || W2 >= numWarehouses || W1 < 0 || W2 < 0 || dist[W1][W2] != -1)
					return -1;

				if(COST > 20 || COST <= 0 || LENGTH > 1000 || LENGTH <= 0)
					return -1;

				dist[W1][W2] = dist[W2][W1] = LENGTH;
				cost[W1][W2] = cost[W2][W1] = COST;
			}
			if(shipFrom == shipTo)
				return 0;

			best = -1;
			goal = shipTo;
			search(shipFrom, 0);
			if(best >= 0)
				best = best * cargoWeight;
			return best;
		}
};

int main()
{
	string arr0[] = {"1 1 10 12", "2 3 14 14"};
	string arr1[] = {"0 1 2 3", "1 2 4 6", "0 4 10 12", "4 2 3 3", "2 3 8 12", "3 4 4 5", "0 3 1 1"};
	string arr2[] = {"1:2 3 4"};
	string arr3[] = {"0 1 1 1", "1 2 1 1", "2 3 1 1", "0 3 1 1", "3 3 1 1"};
	string arr4[] = {"1 2 3 4", "2 9 10 2"};

	vector<string> legs0;
	legs0.insert(legs0.begin(), arr0, &arr0[sizeof(arr0)/sizeof(*arr0)]);

	vector<string> legs1;
	legs1.insert(legs1.begin(), arr1, &arr1[sizeof(arr1)/sizeof(*arr1)]); 

	vector<string> legs2;
	legs2.insert(legs2.begin(), arr2, &arr2[sizeof(arr2)/sizeof(*arr2)]);

	vector<string> legs3;
	legs3.insert(legs3.begin(), arr3, &arr3[sizeof(arr3)/sizeof(*arr3)]);

	vector<string> legs4;
	legs4.insert(legs4.begin(), arr4, &arr4[sizeof(arr4)/sizeof(*arr4)]);

	Shipping *S = new Shipping;
	cout<<S->mostExpensive(10, legs0, 1, 1, 10)<<"\n";
	cout<<S->mostExpensive(5, legs1, 0, 3, 10)<<"\n";
	cout<<S->mostExpensive(10, legs2, 1, 2, 1)<<"\n";
	cout<<S->mostExpensive(4, legs3, 0, 3, 1)<<"\n";
	cout<<S->mostExpensive(10, legs4, 0, 7, 2)<<"\n";

	return 0;
}