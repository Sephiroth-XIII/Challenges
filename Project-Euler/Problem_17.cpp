/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

//NOTE : If u spell 40 as "fourty" the anwer is 21224 and if as "forty" then the anwer is 21124

#include<iostream>
#include<string>

#define MAX 1000

using namespace std;

int main()
{
	string UNITS_TENS[20]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"},
	TENS[8]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"},
	HUNDRED="hundred",
	AND="and",
	THOUSAND="thousand";

	int i,j=0,letters=0;
	
	for(i=0;i<=MAX;i++)
	{
		if(i%100<20)
			letters+=UNITS_TENS[i%100].size();
		if(i>99 && i%1000<1000 & i%1000!=0)
			letters+=HUNDRED.size()+UNITS_TENS[(i%1000)/100].size();
		if(i%100>19 && i%100<100 && i%100!=0)
			letters+=TENS[(i%100)/10-2].size()+UNITS_TENS[i%10].size();
		if(i>100 && i%100!=0 && i%1000!=0)
			letters+=AND.size();
		if(i>=1000)
			letters+=THOUSAND.size()+UNITS_TENS[i/1000].size();
	}
	cout<<letters<<"\n";

		return 0;
}
			
