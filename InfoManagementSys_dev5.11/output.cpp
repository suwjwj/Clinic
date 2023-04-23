#include<iostream>
#include<iomanip>
#include<string>
#include"head.h"
#include<fstream>
using namespace std;


void Student::output()
{cout<<"学生的信息如下："<<endl;
stu.output();cout<<"系别："<<xibie<<"  "<<"班级："<<banji<<endl;}

void Teacher::output()
{cout<<"老师的信息如下："<<endl;
	tea.output();cout<<"职称："<<zhicheng<<"  "<<"部门："<<bumen<<endl;}