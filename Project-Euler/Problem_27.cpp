/*
Euler published the remarkable quadratic formula:
n² + n + 41
It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.
Using computers, the incredible formula  n^2 − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.
Considering quadratics of the form:
    n² + an + b, where |a| < 1000 and |b| < 1000
    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |−4| = 4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/

#include<iostream>
#include<cmath>

using namespace std;

int is_prime[2000];

int MEuler(int a,int b,int n);
void generate_primes();

int main()
{
	int a,b,n,x,start=-999,end=999,count,max=0,maxa=0,maxb=0;
	generate_primes();	
	for(a=start;a<=end;a++)
	{
		for(b=start;b<=end;b++)
		{
			if(is_prime[b])
			{
				count=0;
				for(n=0;n<2000;n++)
				{
					x=MEuler(a,b,n);
					if(x>0 && x<2000)
						if(is_prime[x])
							count++;
					else break;
				}
				if(count>max)
				{
					max=count;
					maxa=a;
					maxb=b;
				}
			}
		}
	}
	cout<<maxa*maxb<<"\n";
	return 0;
}

int MEuler(int a,int b,int n)
{
	return int(pow(double(n),2)+(a*n)+b); 
}

void generate_primes()
{
	fill_n(is_prime,2000,1);
	is_prime[0]=is_prime[1]=0;
	for(int i=0;i<=sqrt(2000);i++)
	{
		if(is_prime[i])
		{
			for(int j=i*i;j<2000;j+=i)
				is_prime[j]=0;
		}
	}
	return;
}
