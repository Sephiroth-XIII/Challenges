/*
Problem Statement
    	
Class Name: Schedule
Method Name: maxClubs
Paramaters: String[]
Returns: int

Ed is an over achieveing, over active college student.  He wants to be in as
many clubs as possible.   Each club has a meeting time, and in order to be in a
club, Ed has to attend the club's meeting, in its entirety.  Each club meets
weekly, one day a week.  Also, being the overachiever he is, Ed has invented a
teleportation system so the time it takes him to get from meeting to meeting is
negligable.  That is, if one club's meeting ends at 10:00 and another club's
meeting starts at 10:00, Ed can be in both clubs.

Implement a class Schedule which contains a method maxClubs.  maxClubs takes a
String[] as a parameter.  The String[] contains the times of clubs' meetings.
The method returns an int that is the maximum number of clubs Ed can be in.

Each element in the String[] represents one club's information and is a String
of the form:
"CLUBNAME d hh:mm LENGTH". (The quotes are for clarity and are not part of the
String).
CLUBNAME is the name of the club and consists of only letters (at least 1 and
at most 20).
d is the day of the meeting.  It is a number from 1 to 7.  1 is Sunday, 2 is
Monday ... 7 is Saturday.
hh:mm is the starting time of the club's meeting, in military time.  It
consists of two numerical digits representing the hour, a colon, and two more
numerical digits representing the minute.  The hour is between 00 and 23,
inclusive.  The minute is between 00 and 59, inclusive.
LENGTH is the length of the meeting in hours.  The length of the meeting is an
integer between 1 and 24, inclusive.

Note:
-There is exactly one space beween CLUBNAME and d, between d and hh:mm, and
between hh:mm and LENGTH.
-Club names are not necessarily unique.
-The solution must run in under 6 seconds on TopCoder's tester.
-If the String[] is empty, Ed can be in 0 clubs.

The method signature is:
public int maxClubs(String[] meetingtimes);

meetingtimes has at most 14 elements.  Each element is a String of the form
given above (TopCoder will check this).

Examples:
If meetingtimes={"MATHTEAM 2 11:00 3","CHESSCLUB 2 12:00 1","FIGURESKATING 2
13:00 2"}, Ed can maximize the number of clubs he is in by being in CHESSCLUB
and FIGURESKATING and the method returns the maximum number of clubs he can be
in: 2.
 
Definition
    	
Class:	Schedule
Method:	maxClubs
Parameters:	String[]
Returns:	int
Method signature:	int maxClubs(String[] param0)
(be sure your method is public)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Schedule
{
	private:
		int stringToInteger(string s)
		{
			istringstream iss(s);
			int n;
			iss>>n;
			return n;
		}

	public:
		int maxClubs(vector<string> meetingtimes)
		{
			int best[10*24*60];

			vector<string> strs;
			vector<int> starts;
			vector<int> ends;

			for (int i = 0; i < meetingtimes.size(); ++i)
			{
				strs.push_back(meetingtimes[i].substr(meetingtimes[i].find(' ')+1));
			}

			sort(strs.begin(),strs.end());

			for (int i = 0; i < meetingtimes.size() ; ++i)
			{
				int days = stringToInteger(strs[i].substr(0,1))-1;
				int hour = stringToInteger(strs[i].substr(2,2));
				int minute = stringToInteger(strs[i].substr(5,2));
				starts.push_back(minute + 60*(hour + 24 * days));
				ends.push_back(starts[i] + 60*(stringToInteger(strs[i].substr(8))));
			}

			for (int i = 0; i < 7*24*60; ++i)
			{
				best[i] = i>0? best[i-1] : 0;
				for(int j = 0; j <meetingtimes.size(); j++)
				{
					if(ends[j] == i)
					{
						if(best[i] <= best[starts[j]])
							best[i] = best[starts[j]] + 1;
					}
				}
			}
			return best[7*24*60-1];
		}
};

int main()
{
	Schedule *S = new Schedule;

	//string str[] = {"A 7 15:00 24", "Bb 1 02:00 1"};
	//string str[] = {"aaa 2 10:00 1", "bbb 2 10:30 1", "aaa 2 11:00 1", "ccc 2 11:15 1", "ddd 2 12:00 1"}	;
	//string str[] = {};
	//string str[] = {"A 4 10:00 24", "B 5 02:00 1", "C 5 03:00 2", "D 5 02:01 1", "E 6 10:30 1"};
	string str[] = {"O 1 10:00 1", "X 2 12:00 1", "Z 3 23:00 3", "N 4 23:01 1", "ZZ 5 00:01 2"};

	vector<string> vstr;
	vstr.insert(vstr.begin(),str,&str[sizeof(str)/sizeof(*str)]);

	cout<<S->maxClubs(vstr)<<"\n";

	return 0;
}