#include<iostream> //��׼�� 
#include<iomanip> //��׼�� 
#include<string> //��׼�� 
#include<fstream> //��׼�� 

#include<map>
#include<sstream>
#include<cstdlib>	//����exit(1)��Ҫ����cstdlib
#include<cstring>

using namespace std; //�����ռ� 

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
		cout << "�������ţ�000~999�����������Ա�����䣺" << endl; cin >> n >> s >> x >> a;
		num = n; name = s;
		sex = x; age = a;
	}

	void output() {
		cout << "��ţ�" << num << '\t' << "������" << name << "  "
			<< "�Ա�" << sex << '\t' << "���䣺" << age;
	}

	void infile1() {
		ofstream in;
		in.open("doctor.txt", ios::app);	//���ļ� ʹ�ļ�����c++.txt�ļ���������
		if (!in) { cout << "cannot open the 'doctor file' !" << endl; exit(1); }	//�����������ʼ��ʧ�ܾ����ļ�������  
		in << setw(8) << num << setw(10) << name << setw(8) << sex << setw(8) << age;	//���ļ����ݸ����ַ�����a  ����ȡ���ո񣬸�ֵ����ֹ
		in.close();	//�ر��ļ� ʹ�ļ�����c++.txt�ļ��Ͽ�����.���ߴ���
	}

	void infile2() {
		ofstream in;
		in.open("patient.txt", ios::app);	//���ļ� ʹ�ļ�����c++.txt�ļ���������
		if (!in) { cout << "cannot open the 'patient file' !" << endl; exit(1); }
		in << setw(8) << num << setw(10) << name << setw(8) << sex << setw(8) << age;	//���ļ����ݸ����ַ�����a  ����ȡ���ո񣬸�ֵ����ֹ
		in.close();	//�ر��ļ� ʹ�ļ�����c++.txt�ļ��Ͽ�����.���ߴ���
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

//input¼����Ϣ����ʱ 1
void Patient::input()
{

	{
		pat.input(); cout << "�����뻼�ߵ�ҩ�Ѻ�����ҽ����" << endl;
		string c, d; cin >> c >> d;
		yaofei = c; yisheng = d; }
}

void Doctor::input()
{

	{
		doc.input(); cout << "������ҽ����רҵ����ѣ�" << endl;
		string a; string b; cin >> b >> a;
		zhuanye = a; zhenfei = b; }
}

//output�ⲿ�ļ���ȡ��Ϣ�����浽��ʱ����ӡ��ʱ
void Doctor::output()
{
	cout << "ҽ������Ϣ���£�" << endl;
	doc.output(); cout << "רҵ��" << zhuanye << "  " << "��ѣ�" << zhenfei << endl;
}

void Patient::output()
{
	cout << "���ߵ���Ϣ���£�" << endl;
	pat.output(); cout << "����ҽ����" << yisheng << "  " << "ҩ�ѣ�" << yaofei << endl;
}

//infile��ʱ��Ϣ���浽�ⲿ�ļ�,��ʱת���� ���������Դ� 1
void Doctor::infile() {
	doc.infile1();//���������Դ�
	ofstream in;
	in.open("doctor.txt", ios::app);
	if (!in) { cout << "cannot open the 'doctor file' !" << endl; exit(1); }

	in << setw(8) << zhuanye << setw(8) << zhenfei << '\n';		//�д�����
	in.close();
}

void Patient::infile() {
	pat.infile2();
	ofstream in;
	in.open("patient.txt", ios::app);
	if (!in) { cout << "cannot open the 'patient file' !" << endl; exit(1); }
	in << setw(8) << yisheng << setw(8) << yaofei << '\n';	//�д�����
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
		cout << "������Ҫ���ҵ�ҽ������Ϣ�ı��(000~999)" << endl;
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
		cout << "���������𣿣���0�������ҹ��ܣ���������������ң�:";
		char c;
		cin >> c;
		if (c == '0')
		{
			break;
		}
		iFile.close();	 //�������Ҫ�ر��ļ�
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
		cout << "������Ҫ���ҵĻ��ߵ���Ϣ�ı��(000~999)" << endl;
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
		cout << "���������𣿣���0�������ҹ��ܣ���������������ң�:";
		char c;
		cin >> c;
		if (c == '0')
		{
			break;
		}
		iFile.close();	//�������Ҫ�ر��ļ�
	}

}

//outfile��ȡ�ⲿ�ļ� 
void Doctor::outfile() {

	fstream out;
	out.open("doctor.txt", ios::in);	//�ļ������뷽ʽ��(�ļ��������뵽�ڴ�)
	if (!out) { cout << "cannot open the 'doctor file' !" << endl; exit(1); }	//exit(1);�򿪲��ɹ�������ʾ���˳�

	for (string str; getline(out, str);)//getline()���ж�ȡ�ı�
		cout << str << endl;

	out.close();	//�ر��ļ�.�ڶ��Ѵ򿪵Ĵ����ļ��Ķ�д������ɺ�,Ӧ�رո��ļ����ر��ļ��ó�Ա����close����ν�ر�,ʵ�����ǽ���ô����ļ����ļ����Ĺ���,ԭ�����õĹ�����ʽҲʧЧ������,�Ͳ�����ͨ���ļ����Ը��ļ���������������
}

void Patient::outfile() {

	fstream out;
	out.open("patient.txt", ios::in);	//�ļ������뷽ʽ��(�ļ��������뵽�ڴ�)
	if (!out) { cout << "cannot open the 'patient file' !" << endl; exit(1); }	//exit(1);�򿪲��ɹ�������ʾ���˳�
	for (string str; getline(out, str);)//getline()���ж�ȡ�ı�
		cout << str << endl;
	out.close();	//�ر��ļ��������˱���رգ�����ᶪʧ����
}

//del�����ǣ�
void Doctor::del() {
	string str[100];
	int i = 0;

	ifstream iFile("doctor.txt");
	if (!iFile)
	{
		cout << "cannot open the file!" << endl;
	}
	string m;
	cout << "������Ҫɾ����ҽ������Ϣ�ı��(000~999)" << endl;
	cin >> m;

	for (string strLine; getline(iFile, strLine);)
	{
		if (strLine.find(m) == -1)
		{
			str[i] = strLine; i++;//����
		}
	}

	iFile.close();

	ofstream in;
	in.open("doctor.txt", ios::out);//���ļ���Ҫʹ���ļ�������ȷ�򿪣�������ļ���ע��дios::out
	if (!in) { cout << "cannot open the 'doctor file' !" << endl; exit(1); }//�����ļ��򿪲����Ƿ�ɹ� //�򿪲��ɹ�������ʾ���˳���
	for (int j = 0; j < i; j++)
		in << str[j] << endl;//����
	in.close();	//�ر��ļ��������˱���رգ�����ᶪʧ����
	cout << "ɾ�����" << endl;
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
	cout << "������Ҫɾ���Ļ��ߵ���Ϣ�ı��(000~999)" << endl;
	cin >> m;

	for (string strLine; getline(iFile, strLine);)
	{
		if (strLine.find(m.c_str()) == -1)
		{
			str[i] = strLine; i++;//����
		}
	}

	iFile.close();

	ofstream in;
	in.open("patient.txt", ios::out);
	if (!in) { cout << "cannot open the 'patient file' !" << endl; exit(1); }
	for (int j = 0; j < i; j++)
		in << str[j] << endl;//����


	in.close();
	cout << "ɾ�����" << endl;
}

//main
int n;
int main()
{
	Patient pat[100]; Doctor doc[100];

	//��ҳ�� 	
	int flag; flag = 1;



	while (flag) {
		cout <<
			"���������������[ �����������[ �������[   �����[ �������������[�����[   �����[�������������[ �����[ �������������[\n"
			"�����X�T�T�T�T�a�����X�T�T�����[���������[  �����U�����X�T�T�T�T�a�^�����[ �����X�a�����X�T�T�����[�����U�����X�T�T�T�T�a\n"
			"�����������[  ���������������U�����X�����[ �����U�����U      �^���������X�a �������������X�a�����U�����U  �������[\n"
			"�����X�T�T�a  �����X�T�T�����U�����U�^�����[�����U�����U       �^�����X�a  �����X�T�T�T�a �����U�����U   �����U\n"
			"�����U     �����U  �����U�����U �^���������U�^�������������[   �����U   �����U     �����U�^�������������X�a\n"
			"�^�T�a     �^�T�a  �^�T�a�^�T�a  �^�T�T�T�a �^�T�T�T�T�T�a   �^�T�a   �^�T�a     �^�T�a �^�T�T�T�T�T�a \n";
		cout << endl;
		cout << endl;
		cout << "***��ӭ����GDOUҽԺ������Ϣ����ϵͳ***" << endl;
		cout << "**************************************" << endl << endl;
		cout << "*      1-����ҽ����Ϣ����ϵͳ        *" << endl;
		cout << "*      2-���뻼����Ϣ����ϵͳ        *" << endl;
		cout << "*              0-�˳�                *" << endl;
		cout << "*                                    *" << endl;
		cout << "*                    design by xxx*" << endl;
		cout << "**************************************" << endl;
		cout << "�������ѡ��(0-2)" << endl;

		//�����л� 
		int i;
		cin >> i;
		while (i < 0 || i>2)   //���������ȡֵ��Χ  
		{
			cout << "��������������������ѡ��(0-2):" << endl;
			cin >> i;
		}
		cout << endl;
		if (i == 0) { cout << "�˳�ϵͳ��" << endl; flag = 0; }


		if (i == 1) //ҽ����Ϣ����ϵͳ
		{
			int x; x = 1;
			while (x) {
				cout << "       ***GDOUҽ����Ϣ����ϵͳ***     " << endl;
				cout << "**************************************" << endl;
				cout << "*          1-��ȡҽ����Ϣ            *" << endl;
				cout << "*          2-����ҽ����Ϣ            *" << endl;
				cout << "*          3-���ҽ����Ϣ            *" << endl;
				cout << "*          4-����ҽ����Ϣ            *" << endl;
				cout << "*          5-ɾ��ҽ����Ϣ            *" << endl;
				cout << "*         6-����Ų���ҽ��         *" << endl;
				cout << "*              0-�˳�                *" << endl;
				cout << "**************************************" << endl;
				cout << "�������ѡ��(0-6)" << endl;

				//�����л� 
				int j;
				cin >> j;
				while (j < 0 || j>6) {
					cout << "��������������������ѡ��(0-6):" << endl;
					cin >> j;
				}
				cout << endl;

				//��ȡ��ӡҽ����Ϣ outfile
				static int a;
				if (j == 1)
				{
					Doctor::outfile();
				}

				//¼��ҽ����Ϣ 1
				if (j == 2)
				{
					cout << "������Ҫ¼��ϵͳ��ҽ������" << endl; cin >> a;
					for (int i = 0; i < a; i++)
					{
						cout << "�������" << i + 1 << "��ҽ����Ϣ" << endl;
						doc[i].input();
					}
				}

				//�ⲿ��ȡҽ����Ϣ output
				if (j == 3) {
					for (int i = 0; i < a; i++)
					{
						doc[i].output();
					}
				}

				//����ҽ����Ϣ���� 1
				if (j == 4) {
					for (int i = 0; i < a; i++)
					{
						doc[i].infile();//���������Դ�
					}cout << "������ϣ�" << endl;
				}

				//ɾ��ҽ����Ϣ 
				if (j == 5) {
					Doctor::del();
				}

				//����Ų���ҽ����Ϣ 
				if (j == 6) { Doctor::find(); }

				//�˳� 
				if (j == 0) {
					cout << "���δ���������ټ�!" << endl;
					x = 0;
				}
			}
		}


		//������Ϣ����ϵͳ
		if (i == 2)
		{
			int l; l = 1;
			while (l) {
				cout << "      ***GDOU������Ϣ����ϵͳ***      " << endl;
				cout << "**************************************" << endl;
				cout << "*          1-��ȡ������Ϣ            *" << endl;
				cout << "*          2-���뻼����Ϣ            *" << endl;
				cout << "*          3-���������Ϣ            *" << endl;
				cout << "*          4-���滼����Ϣ            *" << endl;
				cout << "*          5-ɾ��������Ϣ            *" << endl;
				cout << "*         6-����Ų��һ���           *" << endl;
				cout << "*              0-�˳�                *" << endl;
				cout << "**************************************" << endl;
				cout << "�������ѡ��(0-6)" << endl;

				//�����л� 
				int j;
				cin >> j;
				while (j < 0 || j>6) {
					cout << "��������������������ѡ��(0-6):" << endl;
					cin >> j;
				}
				cout << endl;

				// ��ȡ��ӡ������Ϣ
				static int a;
				if (j == 1) { Patient::outfile(); }

				// ¼�뻼����Ϣ
				if (j == 2) {
					cout << "������Ҫ¼��ϵͳ�Ļ�������" << endl; cin >> a;
					for (int i = 0; i < a; i++)
					{
						cout << "�������" << i + 1 << "��������Ϣ" << endl;
						pat[i].input();
					}
				}

				//�ⲿ���������Ϣ 
				if (j == 3) {
					for (int i = 0; i < a; i++)
					{
						pat[i].output();
					}
				}
				if (j == 4) {
					for (int i = 0; i < a; i++) { pat[i].infile(); }
					cout << "������ϣ�" << endl;
				}

				//ɾ��������Ϣ 
				if (j == 5) { Patient::del(); }

				//����Ų��һ���
				if (j == 6) { Patient::find(); }

				//�˳� 
				if (j == 0) {
					cout << "���δ���������ټ�!" << endl;
					l = 0;
				}
			}
		}


	}

	return 0;
}

