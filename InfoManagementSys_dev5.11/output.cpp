#include<iostream>
#include<iomanip>
#include<string>
#include"head.h"
#include<fstream>
using namespace std;


void Student::output()
{cout<<"ѧ������Ϣ���£�"<<endl;
stu.output();cout<<"ϵ��"<<xibie<<"  "<<"�༶��"<<banji<<endl;}

void Teacher::output()
{cout<<"��ʦ����Ϣ���£�"<<endl;
	tea.output();cout<<"ְ�ƣ�"<<zhicheng<<"  "<<"���ţ�"<<bumen<<endl;}