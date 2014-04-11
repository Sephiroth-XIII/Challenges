/*
Problem Statement
    	
Implement a class StockCalc, which contains a method getProfit.  This method
takes an int[] representing the stock price for a given stock on a sequence of
days, and returns, as an int, the maximum profit that can be reaped by buying
on one of those days and selling on a later day.

Here is the method signature:
public int getProfit(int[] prices);

prices is an int[].  Each Integer must be greater than 0 and less than 1000.
There must be at least 1 element in the int[] and at most 100 elements.

Note:
-If no profit can be made, return 0.

Examples:
-prices={3,5,10,20,80,70,40,1}, returns 77
-prices={80,70,40,3,2,1}, returns 0
 
Definition
    	
Class:	StockCalc
Method:	getProfit
Parameters:	int[]
Returns:	int
Method signature:	int getProfit(int[] param0)
(be sure your method is public)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class StockCalc
{
	public:
		int getProfit(vector<int> prices)
		{
			int maxProfit = 0;
			for (int i = 0; i <prices.size() ; ++i)
			{
				int currentProfit = *max_element(prices.begin()+i,prices.end())-prices[i];
				if( currentProfit > maxProfit)
					maxProfit = currentProfit;
			}
			return maxProfit;
		}	
};

int main()
{
	StockCalc *S = new StockCalc;
	vector<int> v;

	//int arr[] = {1};
	//int arr[] = {10,9,8,7,6};	
	//int arr[] = {59,40,70,80,90,200};
	//int arr[] = {1,3,8,10,20,14,12,1,17};
	int arr[] = {2,3,8,1,99,8};
	v.insert(v.begin(),arr,&arr[sizeof(arr)/ sizeof(*arr)]);
	cout<<S->getProfit(v)<<"\n";
	return 0;
}