/*
Problem Statement
    	
Class Name: DayAge
Method Name: getDaysOld
Parameters: String, String
Returns: int

Implement a class DayAge which contains a method getDaysOld.  The method is
passed, as Strings, someone's birth date and a current date  and returns the
number of days old the person is, as an int.

The input Strings will be of form mm/dd/yyyy.
m, d, and y represent digits (0 through 9).
mm is between 01 and 12, inclusive.
dd is between 01 and 31, inclusive.
yyyy is between 1901 and 2001, inclusive.

Keep in mind:
Thirty days has September, April, June and November; all the rest have
thirty-one, but February twenty-eight alone except in leap year once in four
when February has one day more.
From 1901 to 2001, the leap years are 1904, 1908, ... 2000 (Every 4 years, no
exceptions).
There are 365 days in a non-leap year, 366 in a leap year.

Assume the time the person was born is noon and the time on the current day is
noon.

Here is the method signature:
public int getDaysOld(String birthdate, String currdate);

Notes:
- Both Strings are of the form given above.  TopCoder will prevent improperly
formatted input parameters from reaching your method.
- Both dates exist (no february 30ths or anything) and the birthday is not
after the current day.  TopCoder will check this too.
- If the birth date and current date are the same, the method should return 0.
- The string "Calendar" cannot occur anywhere in your code.

Examples:
If birthdate="10/10/1999" and currdate="10/10/2000", the method returns 366.
If birthdate="02/03/1940" and currdate="12/04/1999", the method returns 21854.
 
Definition
    	
Class:	DayAge
Method:	getDaysOld
Parameters:	String, String
Returns:	int
Method signature:	int getDaysOld(String param0, String param1)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class DayAge
{
	private:
		int stringToInteger(string s)
		{
			int n;
			istringstream iss(s);
			iss>>n;
			return n;
		}

	public:
		int getDaysOld(string birthdate, string currdate)
		{
			if(birthdate == currdate)
				return 0;

			int daysInMonth[] = {0, 31, 28, 31, 30, 31 ,30 ,31, 31, 30, 31, 30, 31};

			int bmm, bdd, byyyy, cmm, cdd, cyyyy;
			bmm = stringToInteger(birthdate.substr(0,2));
			bdd = stringToInteger(birthdate.substr(3,2));
			byyyy = stringToInteger(birthdate.substr(6,4));
			cmm = stringToInteger(currdate.substr(0,2));
			cdd = stringToInteger(currdate.substr(3,2));
			cyyyy = stringToInteger(currdate.substr(6,4));

			//cout<<bmm<<"/"<<bdd<<"/"<<byyyy<<" -> "<<cmm<<"/"<<cdd<<"/"<<cyyyy<<"\n";

			byyyy -= 1900;
			cyyyy -= 1900;

			int bday = byyyy*365+byyyy/4;
			for(int i = 1; i < bmm; i++)
				bday += daysInMonth[i];
			bday += bdd;

			int cday = cyyyy*365+cyyyy/4;
			for(int i = 1; i < cmm; i++)
				cday += daysInMonth[i];
			cday += cdd;

			if(byyyy % 4 == 0 && bmm < 3)
				bday--;

			if(cyyyy % 4 == 0 && cmm < 3)
				cday--;

			return (cday-bday);
		}	
};

int main()
{
	DayAge *D = new DayAge;
	cout<<D->getDaysOld("10/10/1999", "10/10/2000")<<"\n";
	cout<<D->getDaysOld("02/03/1940", "12/04/1999")<<"\n";
	
	cout<<D->getDaysOld("03/02/1999", "03/04/1999")<<"\n";
	cout<<D->getDaysOld("10/12/1992", "10/12/1992")<<"\n";
	cout<<D->getDaysOld("12/31/1960", "05/03/2001")<<"\n";
	cout<<D->getDaysOld("04/30/1999", "06/10/2001")<<"\n";
	cout<<D->getDaysOld("03/31/1910", "10/02/1977")<<"\n";
	return 0;
}