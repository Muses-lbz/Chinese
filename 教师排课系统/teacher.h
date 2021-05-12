#pragma once
#include<iostream>   //�������ͷ�ļ�
#include<cstdlib>
#include<fstream>
#include<ctime>
#define N 5          
#define M 3          
#define SIZE 40      
using namespace std;

typedef struct tcnode
{
	char name[20];
	int  expectation;
}tclist, * ptclist;
/*class tcnode
{
public:
	char name[20];		//�γ���
	int  expectation;   //���ȼ�
	tcnode* next;
};*/

class linklist		//����
{
public:
	typedef struct node;
	typedef struct Node;
};

typedef struct node
{
	char name[20];
	char num[20];
	int  work_time;
	tcnode tc[M];
	char cbuf[SIZE];
	struct node* next;		//�ṹָ��
}Tlist, * pTlist;

typedef struct Node
{
	char name[20];
	char num[20];
	int week_time;
	int total_time;
	int priority;
	bool kb;		//�Ƿ�ѡ
	struct Node* next;		//ָ����һ�ڵ��ָ��
}Clist, * pClist;

/*������ʦ��*/
class Teacher
{
public:
	Teacher();
	~Teacher();
	void input();		//ɾ������
	void preserve();		//���溯��
	friend void print(Teacher&);	//��Ԫ����(�������������ⶨ��)
	Tlist* pt;

};

/*����teacher����*/
Teacher::Teacher()
{
	pt = NULL;
}

/*������ʦɾ������*/
Teacher::~Teacher()
{
	pTlist p;
	while (pt)
	{
		p = pt;
		pt = pt->next;
		delete p;
	}

}

/*������ʦ��Ϣ�����ɺ��������������ʦ��Ϣ*/
void Teacher::input()
{
	char tag;		//һ�������ж�ѡ��ķ��ϱ�־
	pTlist p = pt;
	pTlist s;
	int t = 0;
	cout << "�������ʦ��Ϣ:" << endl;
	cout << "����\t��ʦ��\t������" << endl;
	do
	{
		if (t >= 1)
		{
			cout << "�������ʦ��Ϣ:" << endl;
			cout << "����\t��ʦ��\t������" << endl;
		}
		s = (pTlist)malloc(sizeof(Tlist));
		cin >> s->name >> s->num >> s->work_time;
		cout << "��������Ӧ�γ���������ֵ(�Ӹߵ���,Ĭ�ϲ�����3��):" << endl;
		for (int i = 0; i < M; i++)
			cin >> s->tc[i].name >> s->tc[i].expectation;
		fflush(stdin);
		s->next = NULL;
		if (!pt)
		{
			pt = s;
			p = pt;
		}
		else
		{
			p->next = s;
			p = p->next;
		}
		t++;
		cout << "�Ƿ����������Ϣ:" << endl;
		fflush(stdin);
		cin >> tag;
		system("cls");
	} while (tag == 'y' || tag == 'n');

}

/*������ʦ���溯�������ڱ�������Ľ�ʦ��Ϣ*/
void Teacher::preserve()
{
	pTlist p = pt;
	char path[20] = "E:\\teacher.txt";		//·��
	char str[50] = { '\0' };
	cout << "��ѡ�񱣴��ʦ��Ϣ�ļ���·��:" << endl;
	cin >> path;
	ofstream outfile(path);		//��·����Ϣ���ڴ棬д��Ӳ�̱���
	if (!outfile)
	{
		cerr << "����ʧ��,������ѡ·���Ƿ���ȷ!" << endl;
		return;
	}
	sprintf_s(str, "����\t��ʦ��\t������\n");
	outfile.write((char*)str, strlen(str));		//���ַ������ַ�����ʽд���ļ���
	while (p)
	{
		sprintf_s(str, "%s\t%s\t%d\n", p->name, p->num, p->work_time);
		outfile.write((char*)str, strlen(str));		
		sprintf_s(str, "����Ӧ�γ̵�����ֵ:\n");
		outfile.write((char*)str, strlen(str));
		for (int i = 0; i < M; i++)
		{
			sprintf_s(str, "%s\t%d\n", p->tc[i].name, p->tc[i].expectation);
			outfile.write((char*)str, strlen(str));
		}
		sprintf_s(str, "\n");
		outfile.write((char*)str, strlen(str));
		p = p->next;
	}
	outfile.close();
	cout << "����ɹ�!" << endl;

}

/*������ӡ����*/
void print(Teacher& t)
{
	pTlist p = t.pt;
	cout << "�����ſ����:" << endl;
	cout << "��ʦ����\t������\t���ڿγ�" << endl;
	while (p)
	{
		cout << p->name << "\t\t" << p->work_time << "\t" << p->cbuf << endl;
		p = p->next;
	}
}