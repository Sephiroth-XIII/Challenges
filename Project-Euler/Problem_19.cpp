/*
You are given the following information, but you may prefer to do some research for yourself.
    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include<iostream>

using namespace std;

int main()
{
	int year,month=0,day=1,SUM=0;
	
	for(year=1900;year<=2000;year++)
	{
		for(month=0;month<=11;month++)
		{
			if(year>=1901 && day==0)			
				++SUM;
			if(month==3 || month==5 || month==8 || month==10)
				day+=30;
			else if(month==1)
				day+=((year%1000!=0 && year%4==0) || (year%1000==0 && year%400==0)?29:28);
			else
				day+=31;
			day%=7;	
		}
	}
	cout<<SUM<<"\n";
	return 0;
}
	
