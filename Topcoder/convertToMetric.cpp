/*
Problem Statement
    	
Class Name: MetricClock
Method Name: convertToMetric
Parameters: String
Returns: String

Implement a class MetricClock, which contains a method convertToMetric.
convertToMetric takes a String in the form "HH:MM:SS" (where HH is between 00
and 23, MM is between 00 and 59 and SS is between 00 and 59) representing the
current time of day according to standard clocks (in military time), and
returns a String in the form "H:MM:SS" (where H is between 0 and 9, MM is
between 00 and 99, and SS is between 00 and 99) representing the current time
of day according to the metric clock.

According to the metric clock, there are 10 metric hours in a day, 100 metric
minutes in a metric hour, and 100 metric seconds in a metric minute.  There are
86400 standard seconds in a day, thus 86400 standard seconds make up 1 metric
day (100000 metric seconds).  The metric clock day starts at 0:00:00 and ends
at 9:99:99.

When converting to the metric clock, partial seconds are always truncated, not
rounded.  (9:20:38.833... returns 9:20:38.)

Here is the method signature:
public String convertToMetric(String strStandardTime);

strStandardTime is of the form above.

Examples:
Given the String "01:45:17", the method returns "0:73:11"
Given the String "03:17:45", the method returns "1:37:32"
Given the String "08:12:22", the method returns "3:41:92"
Given the String "12:00:00", the method returns "5:00:00"
Given the String "12:15:21", the method returns "5:10:65"
Given the String "19:58:59", the method returns "8:32:62"
Given the String "23:59:59", the method returns "9:99:98"
 
Definition
    	
Class:	MetricClock
Method:	convertToMetric
Parameters:	String
Returns:	String
Method signature:	String convertToMetric(String param0)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class MetricClock
{
	private:
		int stringToInteger(string s)
		{
			istringstream iss(s);
			int n;
			iss >> n;
			return n;
		}

		string timeToString(int mh, int mm, int ms)
		{
			ostringstream oss;
			oss<<mh;
			string mhs = oss.str();
			ostringstream oss1;
			oss1<<mm;
			string mms = oss1.str();
			mm < 10 ? mms.insert(0,"0") : mms;
			ostringstream oss2;
			oss2<<ms;
			string mss = oss2.str();
			ms < 10 ? mss.insert(0,"0") : mss;

			return mhs + ":" + mms + ":" + mss;
		}

	public:
		string convertToMetric(string strStandardTime)
		{
			int h, m ,s;
			istringstream iss(strStandardTime);
			string S;
			getline(iss,S,':');
			h = stringToInteger(S);
			getline(iss,S,':');
			m = stringToInteger(S);
			getline(iss,S);
			s = stringToInteger(S);

			int t = h;
			t *= 60;
			t += m;
			t *= 60;
			t += s;

			t = (int) ((double)t * (100000.00/86400.00));

			int mh, mm, ms;

			ms = t % 100;
			t /= 100;
			mm = t % 100;
			t /= 100;
			mh = t;

			return timeToString(mh, mm, ms);
		}	
};

int main()
{
	MetricClock *M = new MetricClock;
	cout<<M->convertToMetric("01:45:17")<<"\n";
	cout<<M->convertToMetric("03:17:45")<<"\n";
	cout<<M->convertToMetric("08:12:22")<<"\n";
	cout<<M->convertToMetric("12:00:00")<<"\n";
	cout<<M->convertToMetric("12:15:21")<<"\n";
	cout<<M->convertToMetric("19:58:59")<<"\n";
	cout<<M->convertToMetric("23:59:59")<<"\n";
	return 0;
}