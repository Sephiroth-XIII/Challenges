#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;
int main()
{
	string stage,PDF,PNG,JPEG,MP3;
	ifstream fin;
	fin.open("INPUT");
	fin>>stage;
	fin>>JPEG;
	fin>>MP3;
	fin>>PDF;
	fin>>PNG;
	fin.close();
	string monitor="./Monitor "+stage,pipe=" | ",classifier="./Settler "+stage+" "+JPEG+" "+MP3+" "+PDF+" "+PNG; 
	system((monitor+pipe+classifier).c_str());
	return 0;
}