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
	cout<<"***��ӭ����GDOUѧ����ʦ��Ϣ����ϵͳ***"<<endl;  
	cout<<"**************************************"<<endl<<endl;  
	cout<<"*      1-����ѧ����Ϣ����ϵͳ        *"<<endl; 
	cout<<"*      2-�����ʦ��Ϣ����ϵͳ        *"<<endl; 
	cout<<"*              0-�˳�                *"<<endl;  
	cout<<"*                                    *"<<endl;
	cout<<"*                    design by xxx*"<<endl;
	cout<<"**************************************"<<endl;  
	cout<<"�������ѡ��(0-2)"<<endl; 

	int i;
	cin>>i;     
	while(i<0||i>2)   //���������ȡֵ��Χ  
  {    cout<<"��������������������ѡ��(0-2):"<<endl;  
	   cin>>i; } 
	cout<<endl;  
	if(i==0){cout<<"�˳�ϵͳ��"<<endl;flag=0;}

	if(i==1)
	{
	int x;x=1;
	while(x){ 
	cout<<"       ***GDOUѧ����Ϣ����ϵͳ***     "<<endl;  
	cout<<"**************************************"<<endl;   
	cout<<"*          1-��ȡѧ����Ϣ            *"<<endl; 
	cout<<"*          2-����ѧ����Ϣ            *"<<endl; 
	cout<<"*          3-���ѧ����Ϣ            *"<<endl;  
	cout<<"*          4-����ѧ����Ϣ            *"<<endl;  
	cout<<"*          5-ɾ��ѧ����Ϣ            *"<<endl;  
	cout<<"*         6-��ѧ�Ų���ѧ��           *"<<endl;   
	cout<<"*              0-�˳�                *"<<endl;  
	cout<<"**************************************"<<endl;  
	cout<<"�������ѡ��(0-6)"<<endl;   
	int j;
	cin>>j;
	while(j<0||j>6){cout<<"��������������������ѡ��(0-6):"<<endl;  
	   cin>>j; } 
	cout<<endl;
	static int a;
	if(j==1)
	{Student::outfile();}

	if(j==2)
	{cout<<"������Ҫ¼��ϵͳ��ѧ������"<<endl;cin>>a;
	for(int i=0;i<a;i++)
	{	cout<<"�������"<<i+1<<"��ѧ����Ϣ"<<endl;
	stu[i].input();}}

	if(j==3){
	for(int i=0;i<a;i++)
	{stu[i].output();}}

	if(j==4){
		for(int i=0;i<a;i++)
		{stu[i].infile();}cout<<"������ϣ�"<<endl;}

	if(j==5){Student::del();
	}

	if(j==6){Student::find();}

	if(j==0){cout<<"���δ���������ټ�!"<<endl;
		x=0;}
	}
	}
	
	
	
if(i==2)
{int l;l=1;
while(l){
	cout<<"      ***GDOU��ʦ��Ϣ����ϵͳ***      "<<endl;  
	cout<<"**************************************"<<endl;   
	cout<<"*          1-��ȡ��ʦ��Ϣ            *"<<endl; 
	cout<<"*          2-�����ʦ��Ϣ            *"<<endl; 
	cout<<"*          3-�����ʦ��Ϣ            *"<<endl;  
	cout<<"*          4-�����ʦ��Ϣ            *"<<endl;  
	cout<<"*          5-ɾ����ʦ��Ϣ            *"<<endl;  
	cout<<"*         6-����Ų��ҽ�ʦ           *"<<endl;   
	cout<<"*              0-�˳�                *"<<endl;  
	cout<<"**************************************"<<endl;  
	cout<<"�������ѡ��(0-6)"<<endl;   
	int j;
	cin>>j;
	while(j<0||j>6){cout<<"��������������������ѡ��(0-6):"<<endl;  
	   cin>>j; } 
	cout<<endl;
	static int a;
	if(j==1){Teacher::outfile();}

	if(j==2){
cout<<"������Ҫ¼��ϵͳ�Ľ�ʦ����"<<endl;cin>>a;
	for(int i=0;i<a;i++)
	{	cout<<"�������"<<i+1<<"����ʦ��Ϣ"<<endl;
	tea[i].input();}}

	if(j==3){
	for(int i=0;i<a;i++)
	{	tea[i].output();}}
	if(j==4){for(int i=0;i<a;i++){tea[i].infile();}
	cout<<"������ϣ�"<<endl;}

	if(j==5){Teacher::del();}

	if(j==6){Teacher::find();}

	if(j==0){cout<<"���δ���������ټ�!"<<endl;
		l=0;}
	}
	}
	

 }

return 0;
}
