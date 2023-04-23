#include<iostream>
#include<iomanip>
#include<string>
#include"head.h"
#include<fstream>
using namespace std;

void Student::del(){
string str[100];
 int i=0;
 
  ifstream iFile("student.txt");
  if (!iFile)
  {cout<<"cannot open the file!"<<endl;}
  string m;
  cout<<"请输入要删除的学生的信息的编号(000~999)"<<endl;
	cin>>m;
  
  	for(string strLine; getline(iFile,strLine);)
  {if (strLine.find(m)==-1)
	{str[i]=strLine;i++;}}
 
  iFile.close();
	
	 ofstream in;
	 in.open("student.txt",ios::out);
	if(!in){cout<<"cannot open the 'student file' !"<<endl;exit(1);}
	for(int j=0;j<i;j++)
	in<<str[j]<<endl;
	in.close();
cout<<"删除完毕"<<endl;
 }

void Teacher::del(){
string str[100];
 int i=0;
 
  ifstream iFile("teacher.txt");
  if (!iFile)
  {cout<<"cannot open the file!"<<endl;}

  string m;
  cout<<"请输入要删除的老师的信息的编号(000~999)"<<endl;
	cin>>m;
  
  	for(string strLine; getline(iFile,strLine);)
  {if (strLine.find(m.c_str())==-1)
	{str[i]=strLine;i++;}}
 
  iFile.close();
	
	 ofstream in;
	 in.open("teacher.txt",ios::out);
	if(!in){cout<<"cannot open the 'teacher file' !"<<endl;exit(1);}
	for(int j=0;j<i;j++)
	in<<str[j]<<endl;

	
	in.close();
	cout<<"删除完毕"<<endl;
}
