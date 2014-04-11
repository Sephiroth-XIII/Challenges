//inotifywait -me create --format '%w%f' /home/chintan/Perley/Stage|while read LINE;do basename "$LINE";file -b -F '' "$LINE";done|./A /home/chintan/Perley/Stage
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main(int argc,char *argv[])
{
	string file,stage,PDF,PNG,JPEG,MP3,type,garbage;
	stage=argv[1];
	JPEG=argv[2];
	MP3=argv[3];
	PDF=argv[4];
	PNG=argv[5];
	string cmd1="mv "+stage;
	string dest,cmd;
	while(getline(cin,file))
	{
		cin>>type;
		cmd=cmd1+"/\""+file+"\" ";
		if(type=="JPEG")dest=JPEG+"/\""+file+".jpeg\"";
		else if(type=="MPEG")dest=MP3+"/\""+file+".mp3\"";
		else if(type=="PDF")dest=PDF+"/\""+file+".pdf\"";
		else if(type=="PNG")dest=PNG+"/\""+file+".png\"";
		system((cmd+dest).c_str());
		getline(cin,garbage);
	}
	return 0;
}