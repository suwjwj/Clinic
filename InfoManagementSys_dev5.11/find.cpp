#include<iostream>
#include<map>
#include<sstream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<cstring>
#include"head.h"
#include<fstream>
using namespace std;

void Student::find(){
string str;
 int i=0;
 while (true)
 {
  ifstream iFile("student.txt");
  if (!iFile)
  {cout<<"cannot open the file!"<<endl;}
  string m;
  cout<<"请输入要查找的学生的信息的编号(000~999)"<<endl;
	cin>>m;
  string strLine;
  while (getline(iFile,strLine))
  {
   if (strLine.find(m)!=-1)
   {str=strLine;}
 }
  cout<<str<<endl;
  cout<<"继续查找吗？（按0跳出查找功能，按任意键继续查找）:";
  char c;
  cin>>c;
  if (c=='0')
  { break;}
  iFile.close();
 }

}

void Teacher::find(){
string str;
 while (true)
 {
  ifstream iFile("teacher.txt");
  if (!iFile)
  {cout<<"cannot open the file"<<endl; }
  string m;
  cout<<"请输入要查找的教师的信息的编号(000~999)"<<endl;
	cin>>m;
  string strLine;
  while (getline(iFile,strLine))
  {
   if (strLine.find(m.c_str())!=-1)
   {str=strLine;}
 }
  cout<<str<<endl;
  cout<<"继续查找吗？（按0跳出查找功能，按任意键继续查找）:";
  char c;
  cin>>c;
  if (c=='0')
  {
   break;
  }
  iFile.close();
 }

}