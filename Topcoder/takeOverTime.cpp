/*
Class Name:  AlienTakeover
Method Name: takeOverTime
Parameters:  String[]
Returns:     int

Zorono is the King of an alien tribe planning to take over Earth.  Taking over
Earth consists of many tasks, some tasks cannot occur until other tasks are
complete.  Each task has a specified duration - the time it takes the task to
complete.  Conveniently, Zorono's alien kingdom has infinite labor and
resources, so as many tasks as necessary can be done simultaneously.

Zorono wants a timetable for how long it will take the alien tribe to
completely takeover the Earth and has hired you to write a program to give him
his timetable.

Implement a class AlienTakeover, which contains a method takeOverTime.  The
method takes a String[] as a parameter.  The String[] contains information on
all the tasks that must be performed, the length of the tasks, and which tasks
must be completed before other tasks.  The method returns the minimum length of
time, in hours, the takeover will take (all tasks are completed).

ArrayList elements are of the form:
"TASKNAME LENGTH D1,D2,..."
Where:
*TASKNAME is the name of the task containing between 1 and 20 letters and
*LENGTH is the integer length of time the task takes, in hours between 1 and
100 and
*D1,D2,... is the dependency list - a list of task names seperated by commas
that must be performed before the task can begin. Repeat task names in the same
list should be ignored.
If the task depends on no other tasks, LENGTH is the last item in the String[]
element.
There is exactly 1 space between TASKNAME and LENGTH and between LENGTH and
D1,D2,... If there are no dependencies, there are no characters after LENGTH.

If there are any contradictions in the String[], the method returns -1.  There
is a contradiction if:
*there is no way to order the tasks such that all dependencies are resolved.
*dependency lists refers to jobs that are not defined (don't have their own
element) in the String[].
*the tasks are not uniquely named - more than one element in the String[] has
the same TASKNAME.

The method signature is:
public int takeOverTime(String[] tasks);

tasks is an String[] of elements defining between 1 and 20 tasks, inclusive.
Elements in the String[] are of the syntax described above(TopCoder will check
this).

Examples:
If the String[] is:
{"KILLPEOPLE 50",
 "BUILDHOUSES 10 LAND",
 "LAND 2 KILLPEOPLE",
 "CLEANUPBODIES 5 KILLPEOPLE,LAND",
 "PLANTNEWLAWN 10 CLEANUPBODIES,LAND"}
First KILLPEOPLE must be done, then LAND, then BUILDHOUSES and CLEANUPBODIES
can be worked on simultaneously. When CLEANUPBODIES is done, PLANTNEWLAWN can
start (BUILDHOUSES will still be going on).
At Time=0,  KILLPEOPLE starts.
At Time=50, KILLPEOPLE is done and LAND starts.
At Time=52, LAND is done and CLEANUPBODIES and BUILDHOUSES starts.
At Time=57, CLEANUPBODIES is done and PLANTNEWLAWN starts.
At Time=62, BUILDHOUSES is done.
At Time=67, PLANTNEWLAWN is done.
The method returns the time for everything to be completed: 67.
 
Definition
    	
Class:	AlienTakeover
Method:	takeOverTime
Parameters:	String[]
Returns:	int
Method signature:	int takeOverTime(String[] param0)
(be sure your method is public)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class AlienTakeover
{
	private:
		map<string, pair<int,vector<string> > > tasksOnList;
		string currentTask, processedTask;

		int stringToInteger(string s)
		{
			istringstream iss(s);
			int n;
			iss >> n;
			return n;
		}

		void extractTaskInfo(vector<string> tasks)
		{
			for (int i = 0; i < tasks.size(); ++i)
			{
				istringstream iss(tasks[i]);
				string taskName, taskTime, prerequisiteTasks, eachTask;
				vector<string> prerequisiteTasksVector;
				iss>>taskName;
				iss>>taskTime; 
				iss>>prerequisiteTasks;
				istringstream pss(prerequisiteTasks);
				while(getline(pss,eachTask,','))
				{
					prerequisiteTasksVector.push_back(eachTask);
				}
				tasksOnList[taskName] = make_pair(stringToInteger(taskTime),prerequisiteTasksVector);
			}
			return;
		}

		int minTimeForTask(string Name)
		{
			if(tasksOnList.find(Name) == tasksOnList.end())
				return -1;

			vector<string> Prerequisistes = tasksOnList[Name].second;

			if(Prerequisistes.size() == 0)
				return tasksOnList[Name].first;

			vector<int> taskTime;
			for (int i = 0; i < Prerequisistes.size() ; ++i)
			{
				processedTask = Prerequisistes[i];
				if(processedTask == currentTask)
					return -1;
				int curTaskTime = minTimeForTask(Prerequisistes[i]);
				if(curTaskTime == -1)
					return -1;
				taskTime.push_back(curTaskTime);
			}
			return *max_element(taskTime.begin(),taskTime.end())+tasksOnList[Name].first;
		}

	public:
		int takeOverTime(vector<string> tasks)
		{
			extractTaskInfo(tasks);
			if(tasksOnList.size() < tasks.size())
				return -1;

			int curMax = 0;
			for(map<string, pair<int,vector<string> > >::iterator i = tasksOnList.begin(); i != tasksOnList.end(); i++)
			{
				vector<string> currentPrerequisites = i->second.second;
				set<string> uniquePrerequisites(currentPrerequisites.begin(), currentPrerequisites.end());
				if(uniquePrerequisites.size() != currentPrerequisites.size())
					return -1;

				currentTask = i->first;
				int curTaskTime = minTimeForTask(i->first);
				if(curTaskTime == -1)
					return -1;
				curMax = max(curMax,curTaskTime);
			}

			return curMax;
		}
};

int main()
{
	string taskList[] = {"A 3", "B 1 A,C", "C 2 A", "D 10 A,B", "E 2 D", "F 12"};
	//string taskList[] = {"A 1 C", "B 2 C", "C 2 D,E", "D 1", "E 2 A", "F 12 A"};
	//string taskList[] = {"A 2 E,F", "B 3", "C 6 B,G", "D 1 A", "E 9 G,H", "F 2 C", "G 8", "H 7"};
	//string taskList[] = {"LONGNAME 1", "AL 2", "CB 3 LONGNAME", "LONGNAME 2 A"};
	//string taskList[] = {"TESTER 4 ANOTHER", "ANOTHER 2 TA,TB,TC", "TA 1", "TB 1", "TC 1", "YOR 8 ANOTHER", "AL 1 TESTER"};
	//string taskList[] = {"A 1 A", "B 1 C", "C 1 B"};
	//string taskList[] = {"A 20"};
	//string taskList[] = {"A 5","A 6"};
	//string taskList[] = {"A 50 B", "B 50 C", "C 50 D", "D 50"};
	//string taskList[] = {"A 5 X", "B 4"};
	//string taskList[] = {"TAKEOVERWORLD 50"};
	//string taskList[] = {"A 1", "B 1 A", "C 1 A,B,C", "D 1 E", "E 1 D"};
	//string taskList[] = {"A 1 B,B", "B 1"};
	//string taskList[] = {"A 1 A"};
	
	vector<string> v;
	v.insert(v.begin(),taskList,&taskList[sizeof(taskList)/sizeof(*taskList)]);

	AlienTakeover *A = new AlienTakeover;
	cout<<A->takeOverTime(v)<<"\n";

	return 0;
}