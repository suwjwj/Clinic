#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

class person{
private:
	string num;
	string name;
	string sex;
	int age;
public:
	void input()
	{string n;int a;string s,x;
	cout<<"�������ţ�000~999�����������Ա�����䣺"<<endl;cin>>n>>s>>x>>a;
	num=n;name=s;
	sex=x;age=a;}

	void output(){cout<<"��ţ�"<<num<<'\t'<<"������"<<name<<"  "
		<<"�Ա�"<<sex<<'\t'<<"���䣺"<<age;}

	void infile1(){	ofstream in;
	in.open("student.txt",ios::app);
	if(!in){cout<<"cannot open the 'student file' !"<<endl;exit(1);}
	in<<setw(8)<<num<<setw(10)<<name<<setw(8)<<sex<<setw(8)<<age;
	in.close();}

	void infile2(){ofstream in;
	in.open("teacher.txt",ios::app);
	if(!in){cout<<"cannot open the 'teacher file' !"<<endl;exit(1);}
	in<<setw(8)<<num<<setw(10)<<name<<setw(8)<<sex<<setw(8)<<age;
	in.close();}
	
	
	
};
class Student:public person{
private:
	string xibie;
	string banji;
	person stu;
public:
	void input();
	void output();
	void infile();
	static void find();
	static void outfile();
	static void del();

};
class Teacher:public person{
private:
	string zhicheng;
	string bumen;
	person tea;
public:
	void input();
	void output();
	void infile();
	static void find();
	static void outfile();
	static void del();
};