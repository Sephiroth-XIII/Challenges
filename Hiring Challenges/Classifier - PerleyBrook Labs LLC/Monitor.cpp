#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	string stage=argv[1];
	string cmd="inotifywait -me create --format '%w%f' ";
	string cmd1="|while read LINE;do basename \"$LINE\";file -b -F '' \"$LINE\";done";
	system((cmd+stage+cmd1).c_str());
	return 0;
}