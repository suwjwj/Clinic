#include<iostream> //标准库 
#include<iomanip> //标准库 
#include<string> //标准库 
#include<fstream> //标准库 

#include<map>
#include<sstream>
#include<cstdlib>	//调用exit(1)需要包含cstdlib
#include<cstring>

using namespace std; //命名空间 

//head.h
class person {
	
private:
	string num;
	string name;
	string sex;
	int age;
public:
	void input()
	{
		string n; int a; string s, x;
		cout << "请输入编号（000~999）、姓名、性别和年龄：" << endl; cin >> n >> s >> x >> a;
		num = n; name = s;
		sex = x; age = a;
	}

	void output() {
		cout << "编号：" << num << '\t' << "姓名：" << name << "  "
			<< "性别：" << sex << '\t' << "年龄：" << age;
	}

	void infile1() {
		ofstream in;
		in.open("doctor.txt", ios::app);	//打开文件 使文件流与c++.txt文件建立关联
		if (!in) { cout << "cannot open the 'doctor file' !" << endl; exit(1); }	//如果输入流初始化失败就是文件不存在  
		in << setw(8) << num << setw(10) << name << setw(8) << sex << setw(8) << age;	//将文件内容赋给字符数组a  若读取到空格，赋值会终止
		in.close();	//关闭文件 使文件流与c++.txt文件断开关联.人走带门
	}

	void infile2() {
		ofstream in;
		in.open("patient.txt", ios::app);	//打开文件 使文件流与c++.txt文件建立关联
		if (!in) { cout << "cannot open the 'patient file' !" << endl; exit(1); }
		in << setw(8) << num << setw(10) << name << setw(8) << sex << setw(8) << age;	//将文件内容赋给字符数组a  若读取到空格，赋值会终止
		in.close();	//关闭文件 使文件流与c++.txt文件断开关联.人走带门
	}



};
class Doctor :public person {
private:
	string zhuanye;
	string zhenfei;
	person doc;
public:
	void input();
	void output();
	void infile();
	static void find();
	static void outfile();
	static void del();

};
class Patient :public person {
private:
	string yaofei;
	string yisheng;
	string zhenfei; 
	person pat;
public:
	void input();
	void output();
	void infile();
	static void find();
	static void outfile();
	static void del();
};

//input录入信息到临时 1
void Patient::input()
{

	{
		pat.input(); cout << "请输入患者的药费和主治医生：" << endl;
		string c, d; cin >> c >> d;
		yaofei = c; yisheng = d; }
}

void Doctor::input()
{

	{
		doc.input(); cout << "请输入医生的专业和诊费：" << endl;
		string a; string b; cin >> b >> a;
		zhuanye = a; zhenfei = b; }
}

//output外部文件读取信息，保存到临时，打印临时
void Doctor::output()
{
	cout << "医生的信息如下：" << endl;
	doc.output(); cout << "专业：" << zhuanye << "  " << "诊费：" << zhenfei << endl;
}

void Patient::output()
{
	cout << "患者的信息如下：" << endl;
	pat.output(); cout << "主治医生：" << yisheng << "  " << "药费：" << yaofei << endl;
}

//infile临时信息保存到外部文件,临时转永久 公共属性自带 1
void Doctor::infile() {
	doc.infile1();//公共属性自带
	ofstream in;
	in.open("doctor.txt", ios::app);
	if (!in) { cout << "cannot open the 'doctor file' !" << endl; exit(1); }

	in << setw(8) << zhuanye << setw(8) << zhenfei << '\n';		//有待调试
	in.close();
}

void Patient::infile() {
	pat.infile2();
	ofstream in;
	in.open("patient.txt", ios::app);
	if (!in) { cout << "cannot open the 'patient file' !" << endl; exit(1); }
	in << setw(8) << yisheng << setw(8) << yaofei << '\n';	//有待调试
	in.close();
}

//find 1
void Doctor::find() {
	string str;
	int i = 0;
	while (true)
	{
		ifstream iFile("doctor.txt");
		if (!iFile)
		{
			cout << "cannot open the file!" << endl;
		}
		string m;
		cout << "请输入要查找的医生的信息的编号(000~999)" << endl;
		cin >> m;
		string strLine;
		while (getline(iFile, strLine))
		{
			if (strLine.find(m) != -1)
			{
				str = strLine;
			}
		}
		cout << str << endl;
		cout << "继续查找吗？（按0跳出查找功能，按任意键继续查找）:";
		char c;
		cin >> c;
		if (c == '0')
		{
			break;
		}
		iFile.close();	 //读入完毕要关闭文件
	}

}

void Patient::find() {
	string str;
	while (true)
	{
		ifstream iFile("patient.txt");
		if (!iFile)
		{
			cout << "cannot open the file" << endl;
		}
		string m;
		cout << "请输入要查找的患者的信息的编号(000~999)" << endl;
		cin >> m;
		string strLine;
		while (getline(iFile, strLine))
		{
			if (strLine.find(m.c_str()) != -1)
			{
				str = strLine;
			}
		}
		cout << str << endl;
		cout << "继续查找吗？（按0跳出查找功能，按任意键继续查找）:";
		char c;
		cin >> c;
		if (c == '0')
		{
			break;
		}
		iFile.close();	//读入完毕要关闭文件
	}

}

//outfile读取外部文件 
void Doctor::outfile() {

	fstream out;
	out.open("doctor.txt", ios::in);	//文件以输入方式打开(文件数据输入到内存)
	if (!out) { cout << "cannot open the 'doctor file' !" << endl; exit(1); }	//exit(1);打开不成功，则提示后退出

	for (string str; getline(out, str);)//getline()逐行读取文本
		cout << str << endl;

	out.close();	//关闭文件.在对已打开的磁盘文件的读写操作完成后,应关闭该文件。关闭文件用成员函数close。所谓关闭,实际上是解除该磁盘文件与文件流的关联,原来设置的工作方式也失效，这样,就不能再通过文件流对该文件进行输入或输出。
}

void Patient::outfile() {

	fstream out;
	out.open("patient.txt", ios::in);	//文件以输入方式打开(文件数据输入到内存)
	if (!out) { cout << "cannot open the 'patient file' !" << endl; exit(1); }	//exit(1);打开不成功，则提示后退出
	for (string str; getline(out, str);)//getline()逐行读取文本
		cout << str << endl;
	out.close();	//关闭文件。用完了必须关闭，否则会丢失数据
}

//del，覆盖？
void Doctor::del() {
	string str[100];
	int i = 0;

	ifstream iFile("doctor.txt");
	if (!iFile)
	{
		cout << "cannot open the file!" << endl;
	}
	string m;
	cout << "请输入要删除的医生的信息的编号(000~999)" << endl;
	cin >> m;

	for (string strLine; getline(iFile, strLine);)
	{
		if (strLine.find(m) == -1)
		{
			str[i] = strLine; i++;//这里
		}
	}

	iFile.close();

	ofstream in;
	in.open("doctor.txt", ios::out);//打开文件，要使用文件必须正确打开，对输出文件，注意写ios::out
	if (!in) { cout << "cannot open the 'doctor file' !" << endl; exit(1); }//测试文件打开操作是否成功 //打开不成功，则提示后退出。
	for (int j = 0; j < i; j++)
		in << str[j] << endl;//这里
	in.close();	//关闭文件。用完了必须关闭，否则会丢失数据
	cout << "删除完毕" << endl;
}

void Patient::del() {
	string str[100];
	int i = 0;

	ifstream iFile("patient.txt");
	if (!iFile)
	{
		cout << "cannot open the file!" << endl;
	}

	string m;
	cout << "请输入要删除的患者的信息的编号(000~999)" << endl;
	cin >> m;

	for (string strLine; getline(iFile, strLine);)
	{
		if (strLine.find(m.c_str()) == -1)
		{
			str[i] = strLine; i++;//这里
		}
	}

	iFile.close();

	ofstream in;
	in.open("patient.txt", ios::out);
	if (!in) { cout << "cannot open the 'patient file' !" << endl; exit(1); }
	for (int j = 0; j < i; j++)
		in << str[j] << endl;//这里


	in.close();
	cout << "删除完毕" << endl;
}

//main
int n;
int main()
{
	Patient pat[100]; Doctor doc[100];

	//主页面 	
	int flag; flag = 1;



	while (flag) {
		cout <<
			"███████╗ █████╗ ███╗   ██╗ ██████╗██╗   ██╗██████╗ ██╗ ██████╗\n"
			"██╔════╝██╔══██╗████╗  ██║██╔════╝╚██╗ ██╔╝██╔══██╗██║██╔════╝\n"
			"█████╗  ███████║██╔██╗ ██║██║      ╚████╔╝ ██████╔╝██║██║  ███╗\n"
			"██╔══╝  ██╔══██║██║╚██╗██║██║       ╚██╔╝  ██╔═══╝ ██║██║   ██║\n"
			"██║     ██║  ██║██║ ╚████║╚██████╗   ██║   ██║     ██║╚██████╔╝\n"
			"╚═╝     ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝   ╚═╝   ╚═╝     ╚═╝ ╚═════╝ \n";
		cout << endl;
		cout << endl;
		cout << "***欢迎进入GDOU医院诊所信息管理系统***" << endl;
		cout << "**************************************" << endl << endl;
		cout << "*      1-进入医生信息管理系统        *" << endl;
		cout << "*      2-进入患者信息管理系统        *" << endl;
		cout << "*              0-退出                *" << endl;
		cout << "*                                    *" << endl;
		cout << "*                    design by xxx*" << endl;
		cout << "**************************************" << endl;
		cout << "输入你的选择(0-2)" << endl;

		//场景切换 
		int i;
		cin >> i;
		while (i < 0 || i>2)   //限制输入的取值范围  
		{
			cout << "输入错误，请重新输入你的选择(0-2):" << endl;
			cin >> i;
		}
		cout << endl;
		if (i == 0) { cout << "退出系统！" << endl; flag = 0; }


		if (i == 1) //医生信息管理系统
		{
			int x; x = 1;
			while (x) {
				cout << "       ***GDOU医生信息管理系统***     " << endl;
				cout << "**************************************" << endl;
				cout << "*          1-读取医生信息            *" << endl;
				cout << "*          2-输入医生信息            *" << endl;
				cout << "*          3-输出医生信息            *" << endl;
				cout << "*          4-保存医生信息            *" << endl;
				cout << "*          5-删除医生信息            *" << endl;
				cout << "*         6-按编号查找医生         *" << endl;
				cout << "*              0-退出                *" << endl;
				cout << "**************************************" << endl;
				cout << "输入你的选择(0-6)" << endl;

				//场景切换 
				int j;
				cin >> j;
				while (j < 0 || j>6) {
					cout << "输入错误，请重新输入你的选择(0-6):" << endl;
					cin >> j;
				}
				cout << endl;

				//读取打印医生信息 outfile
				static int a;
				if (j == 1)
				{
					Doctor::outfile();
				}

				//录入医生信息 1
				if (j == 2)
				{
					cout << "请输入要录入系统的医生人数" << endl; cin >> a;
					for (int i = 0; i < a; i++)
					{
						cout << "请输入第" << i + 1 << "个医生信息" << endl;
						doc[i].input();
					}
				}

				//外部读取医生信息 output
				if (j == 3) {
					for (int i = 0; i < a; i++)
					{
						doc[i].output();
					}
				}

				//更新医生信息储存 1
				if (j == 4) {
					for (int i = 0; i < a; i++)
					{
						doc[i].infile();//公共属性自带
					}cout << "保存完毕！" << endl;
				}

				//删除医生信息 
				if (j == 5) {
					Doctor::del();
				}

				//按编号查找医生信息 
				if (j == 6) { Doctor::find(); }

				//退出 
				if (j == 0) {
					cout << "本次处理结束，再见!" << endl;
					x = 0;
				}
			}
		}


		//患者信息管理系统
		if (i == 2)
		{
			int l; l = 1;
			while (l) {
				cout << "      ***GDOU患者信息管理系统***      " << endl;
				cout << "**************************************" << endl;
				cout << "*          1-读取患者信息            *" << endl;
				cout << "*          2-输入患者信息            *" << endl;
				cout << "*          3-输出患者信息            *" << endl;
				cout << "*          4-保存患者信息            *" << endl;
				cout << "*          5-删除患者信息            *" << endl;
				cout << "*         6-按编号查找患者           *" << endl;
				cout << "*              0-退出                *" << endl;
				cout << "**************************************" << endl;
				cout << "输入你的选择(0-6)" << endl;

				//场景切换 
				int j;
				cin >> j;
				while (j < 0 || j>6) {
					cout << "输入错误，请重新输入你的选择(0-6):" << endl;
					cin >> j;
				}
				cout << endl;

				// 读取打印患者信息
				static int a;
				if (j == 1) { Patient::outfile(); }

				// 录入患者信息
				if (j == 2) {
					cout << "请输入要录入系统的患者人数" << endl; cin >> a;
					for (int i = 0; i < a; i++)
					{
						cout << "请输入第" << i + 1 << "个患者信息" << endl;
						pat[i].input();
					}
				}

				//外部输出患者信息 
				if (j == 3) {
					for (int i = 0; i < a; i++)
					{
						pat[i].output();
					}
				}
				if (j == 4) {
					for (int i = 0; i < a; i++) { pat[i].infile(); }
					cout << "保存完毕！" << endl;
				}

				//删除患者信息 
				if (j == 5) { Patient::del(); }

				//按编号查找患者
				if (j == 6) { Patient::find(); }

				//退出 
				if (j == 0) {
					cout << "本次处理结束，再见!" << endl;
					l = 0;
				}
			}
		}


	}

	return 0;
}

