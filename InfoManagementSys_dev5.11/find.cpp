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
  cout<<"������Ҫ���ҵ�ѧ������Ϣ�ı��(000~999)"<<endl;
	cin>>m;
  string strLine;
  while (getline(iFile,strLine))
  {
   if (strLine.find(m)!=-1)
   {str=strLine;}
 }
  cout<<str<<endl;
  cout<<"���������𣿣���0�������ҹ��ܣ���������������ң�:";
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
  cout<<"������Ҫ���ҵĽ�ʦ����Ϣ�ı��(000~999)"<<endl;
	cin>>m;
  string strLine;
  while (getline(iFile,strLine))
  {
   if (strLine.find(m.c_str())!=-1)
   {str=strLine;}
 }
  cout<<str<<endl;
  cout<<"���������𣿣���0�������ҹ��ܣ���������������ң�:";
  char c;
  cin>>c;
  if (c=='0')
  {
   break;
  }
  iFile.close();
 }

}