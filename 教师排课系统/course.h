#pragma once
#include"teacher.h"

/*�����γ���*/
class Course
{
public:
	Course();
	~Course();
	void input();
	void preserve();
	friend pClist transform(Course&, char* s);
private:
	Clist* pc;		//�����ſνڵ�ṹ��ָ��
};

/*����course����*/
Course::Course()
{
	pc = NULL;
}

/*�����γ�ɾ������*/
Course::~Course()
{
	pClist p;
	while (pc)
	{
		p = pc;
		pc = pc->next;
		delete p;
	}
}

/*�����γ���Ϣ�����ɺ�������������γ���Ϣ*/
void Course::input()
{
	pClist p = pc;
	pClist s;
	char tag;
	int i = 0;
	cout << "������γ���Ϣ:" << endl;
	cout << "�γ���\t�γ̺�\t��ѧʱ\t��ѧʱ\t���ȼ�" << endl;
	do {
		if (i >= 1)
		{
			cout << "������γ���Ϣ:" << endl;
			cout << "�γ���\t�γ̺�\t��ѧʱ\t��ѧʱ\t���ȼ�" << endl;
		}
		s = (pClist)malloc(sizeof(Clist));
		cin >> s->name >> s->num >> s->week_time >> s->total_time >> s->priority;
		fflush(stdin);
		s->kb = true;
		s->next = NULL;
		i++;
		if (!pc)
		{
			pc = s;
			p = pc;
		}
		else
		{
			p->next = s;
			p = p->next;
		}
		cout << "�Ƿ��������γ���Ϣ? y/n" << endl;
		cin >> tag;
		system("cls");
	} while (tag == 'y' || tag == 'n');
}

/*�����γ̱��溯�������ڱ�������Ŀγ���Ϣ*/
void Course::preserve()
{
	char path[20] = "E:\\course.txt";
	pClist p = pc;
	char str[100] = { '\0' };
	cout << "�������ļ�����·��:" << endl;
	cin >> path;
	ofstream outfile(path);
	if (!outfile)
	{
		cerr << "����ʧ��,��������·���Ƿ���ȷ";
		return;
	}
	sprintf_s(str, "�γ���\t�γ̺�\t��ѧʱ\t��ѧʱ\t���ȼ�\n");
	outfile.write((char*)str, strlen(str));
	while (p)
	{
		sprintf_s(str, "%s\t%s\t%d\t%d\t%d\n", p->name, p->num, p->week_time, p->total_time, p->priority);
		outfile.write((char*)str, strlen(str));
		p = p->next;

	}
	outfile.close();
	cout << "����ɹ�!" << endl;
}

/*ƥ�亯��*/
pClist transform(Course& c, char* s)
{
	pClist p = c.pc;
	while (p)
	{
		if (0 == strcmp(p->name, s))
			return p;
		else
			p = p->next;
	}
	cout << "Ӧ�ó������!" << endl;
	return NULL;
}