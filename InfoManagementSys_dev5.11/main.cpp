#include<iostream>
#include<iomanip>
#include<string>
#include"head.h"
#include<fstream>
using namespace std;

int n;
int main()
{
	Teacher tea[100];Student stu[100];
 int flag;flag=1;
 while(flag){
	cout<<endl; 
	cout<<endl;   
	cout<<"***欢迎进入GDOU学生教师信息管理系统***"<<endl;  
	cout<<"**************************************"<<endl<<endl;  
	cout<<"*      1-进入学生信息管理系统        *"<<endl; 
	cout<<"*      2-进入教师信息管理系统        *"<<endl; 
	cout<<"*              0-退出                *"<<endl;  
	cout<<"*                                    *"<<endl;
	cout<<"*                    design by xxx*"<<endl;
	cout<<"**************************************"<<endl;  
	cout<<"输入你的选择(0-2)"<<endl; 

	int i;
	cin>>i;     
	while(i<0||i>2)   //限制输入的取值范围  
  {    cout<<"输入错误，请重新输入你的选择(0-2):"<<endl;  
	   cin>>i; } 
	cout<<endl;  
	if(i==0){cout<<"退出系统！"<<endl;flag=0;}

	if(i==1)
	{
	int x;x=1;
	while(x){ 
	cout<<"       ***GDOU学生信息管理系统***     "<<endl;  
	cout<<"**************************************"<<endl;   
	cout<<"*          1-读取学生信息            *"<<endl; 
	cout<<"*          2-输入学生信息            *"<<endl; 
	cout<<"*          3-输出学生信息            *"<<endl;  
	cout<<"*          4-保存学生信息            *"<<endl;  
	cout<<"*          5-删除学生信息            *"<<endl;  
	cout<<"*         6-按学号查找学生           *"<<endl;   
	cout<<"*              0-退出                *"<<endl;  
	cout<<"**************************************"<<endl;  
	cout<<"输入你的选择(0-6)"<<endl;   
	int j;
	cin>>j;
	while(j<0||j>6){cout<<"输入错误，请重新输入你的选择(0-6):"<<endl;  
	   cin>>j; } 
	cout<<endl;
	static int a;
	if(j==1)
	{Student::outfile();}

	if(j==2)
	{cout<<"请输入要录入系统的学生人数"<<endl;cin>>a;
	for(int i=0;i<a;i++)
	{	cout<<"请输入第"<<i+1<<"个学生信息"<<endl;
	stu[i].input();}}

	if(j==3){
	for(int i=0;i<a;i++)
	{stu[i].output();}}

	if(j==4){
		for(int i=0;i<a;i++)
		{stu[i].infile();}cout<<"保存完毕！"<<endl;}

	if(j==5){Student::del();
	}

	if(j==6){Student::find();}

	if(j==0){cout<<"本次处理结束，再见!"<<endl;
		x=0;}
	}
	}
	
	
	
if(i==2)
{int l;l=1;
while(l){
	cout<<"      ***GDOU教师信息管理系统***      "<<endl;  
	cout<<"**************************************"<<endl;   
	cout<<"*          1-读取教师信息            *"<<endl; 
	cout<<"*          2-输入教师信息            *"<<endl; 
	cout<<"*          3-输出教师信息            *"<<endl;  
	cout<<"*          4-保存教师信息            *"<<endl;  
	cout<<"*          5-删除教师信息            *"<<endl;  
	cout<<"*         6-按编号查找教师           *"<<endl;   
	cout<<"*              0-退出                *"<<endl;  
	cout<<"**************************************"<<endl;  
	cout<<"输入你的选择(0-6)"<<endl;   
	int j;
	cin>>j;
	while(j<0||j>6){cout<<"输入错误，请重新输入你的选择(0-6):"<<endl;  
	   cin>>j; } 
	cout<<endl;
	static int a;
	if(j==1){Teacher::outfile();}

	if(j==2){
cout<<"请输入要录入系统的教师人数"<<endl;cin>>a;
	for(int i=0;i<a;i++)
	{	cout<<"请输入第"<<i+1<<"个教师信息"<<endl;
	tea[i].input();}}

	if(j==3){
	for(int i=0;i<a;i++)
	{	tea[i].output();}}
	if(j==4){for(int i=0;i<a;i++){tea[i].infile();}
	cout<<"保存完毕！"<<endl;}

	if(j==5){Teacher::del();}

	if(j==6){Teacher::find();}

	if(j==0){cout<<"本次处理结束，再见!"<<endl;
		l=0;}
	}
	}
	

 }

return 0;
}
