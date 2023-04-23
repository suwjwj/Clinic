#include<iostream>
#include<iomanip>
#include<string>
#include"head.h"
#include<fstream>
using namespace std;

void Student::outfile(){

	fstream out;
	out.open("student.txt",ios::in);
	if(!out){cout<<"cannot open the 'student file' !"<<endl;exit(1);}

	for(string str; getline(out,str);)//getline()逐行读取文本
    cout<<str<<endl;
	
	out.close();
}


void Teacher::outfile(){

	fstream out;
	out.open("teacher.txt",ios::in);
	if(!out){cout<<"cannot open the 'teacher file' !"<<endl;exit(1);}
	for(string str; getline(out,str);)//getline()逐行读取文本
    cout<<str<<endl;
	out.close();
}