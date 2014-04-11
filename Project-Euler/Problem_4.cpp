/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include<iostream>

using namespace std;

int Palindrome(int result);

int main()
{
	int i,j,candidates[998003];
	//SIEVE OF ERATOSTHENES ALGORITHM TO MARK EVERY MULTIPLE OF TWO 3-DIGIT NOs in [10000,998001] to 0 
	//10001 IS LOWEST POSSIBLE PALINDROME AND 997799 IS HIGHEST POSSIBLE PALLINDROME IN [10000,998001]
	fill_n(candidates,998003,1);

	for(i=100;i<1000;i++)
	{
		if(candidates[i])
		{
			for(j=i;j<1000;j++)
			{
				candidates[i*j]=0;
			}
		}
	}
	
	for(i=998002;i>=10001;i--)
	{
		if(candidates[i]==0)
		{
			if(Palindrome(i))
			{
				cout<<i<<"\n";
				break;
			}
		}
	}
	return 0;
}

int Palindrome(int result)
{
    int reverse=0,test=result;
    while(test!=0)
    {
    	reverse*=10;
    	reverse+=test%10;
    	test/=10;
    }
    if(reverse==result)
    	return 1;
    else
    	return 0;
}
