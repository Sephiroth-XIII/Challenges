/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
012   021   102   120   201   210
What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int COUNT=0,nums[]={0,1,2,3,4,5,6,7,8,9};
	do
	{
		if(++COUNT==1000000)
		{
			for(int i=0;i<10;i++)
				cout<<nums[i];
			cout<<"\n";
			break;
		}
	}while(next_permutation(nums,nums+10));
	
	return 0;
}
