/*
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation
    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:
    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/

#include<iostream>
#define Target 200

using namespace std;

int main()
{
	int coins[8]={1,2,5,10,20,50,100,200},i,j,sum,counter[Target+1];
	fill_n(counter,Target+1,0);
	counter[0]=1;
	for(i=0;i<8;i++)
		for(j=coins[i];j<=Target;j++)
			counter[j]+=counter[j-coins[i]];
	cout<<counter[Target]<<"\n";
	return 0;
}