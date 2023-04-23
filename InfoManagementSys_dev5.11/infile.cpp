#include<iostream>
#include<iomanip>
#include<string>
#include"head.h"
#include<fstream>
using namespace std;

void Student::infile(){
	stu.infile1();
	ofstream in;
	in.open("student.txt",ios::app);
	if(!in){cout<<"cannot open the 'student file' !"<<endl;exit(1);}

	in<<setw(8)<<xibie<<setw(8)<<banji<<'\n';
	in.close();
}


void Teacher::infile(){
	tea.infile2();
	ofstream in;
	in.open("teacher.txt",ios::app);
	if(!in){cout<<"cannot open the 'teacher file' !"<<endl;exit(1);}
	in<<setw(8)<<zhicheng<<setw(8)<<bumen<<'\n';
	in.close();
}