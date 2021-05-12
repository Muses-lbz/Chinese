#pragma once
#include"course.h"

/*������ʦ�ſκ���*/
void sort(Teacher& t, Course& c)
{
	pTlist q = t.pt;
	pTlist n = t.pt;
	pTlist m = n;
	int sum = 0;
	int num = -1;
	srand(time(0));		//������������������ĳ�ʼ������
	for (int i = 0; i < M; i++)
	{
		while (m)
		{
			m = n->next;
			if (m == NULL)
				break;
			for (int j = 0; j < M; j++)
				if ((m->tc[i].expectation == n->tc[j].expectation) && (0 == strcmp(m->tc[i].name, n->tc[j].name)))
				{
					num = rand() % 2;
					switch (num)
					{
					case 0:
						(transform(c, q->tc[num].name))->kb = false;
						break;
					case 1:
						(transform(c, q->tc[num].name))->kb = false;
						break;
					default:
						break;
					}
				}
			n = n->next;
		}
	}
	while (q)
	{
		for (int i = 0; i < M; i++)
		{
			if ((transform(c, q->tc[i].name))->kb)
			{
				sum += (transform(c, q->tc[i].name))->total_time;
				(transform(c, q->tc[i].name))->kb = false;
				if (i == 0)
					strcpy_s(q->cbuf, q->tc[i].name);
				else
				{
					strcat_s(q->cbuf, " ");
					strcat_s(q->cbuf, q->tc[i].name);
				}

				if (sum >= q->work_time)
					break;
			}
		}
		sum = 0;
		q = q->next;
	}
	cout << "�γ����ź�!" << endl;

}

class Zombie
{
public:
	int intput();
};

int Zombie::intput()
{
	ofstream   ofresult("E:\\teacher.txt ", ios::app);
	ofresult << "������" << "\t" << "20003" << "\t" << "30" << endl;
	ofresult << "����Ӧ�γ̵�����ֵ:" << endl;
	ofresult << "����" << "\t" << "1" << endl;
	ofresult << "����" << "\t" << "2" << endl;
	ofresult << "����" << "\t" << "3" << endl;
	return 0;
}

class Ghost
{
public:
	int intput();
};

int Ghost::intput()
{
	ofstream   ofresult("E:\\course.txt ", ios::app);
	ofresult << "����" << "\t" << "1006" << "\t" << "3" << "\t" << "12" << "\t" << "6" << endl;
	ofresult << "����" << "\t" << "1007" << "\t" << "3" << "\t" << "6"  << "\t" << "7" << endl;
	return 0;
}

class Vampire
{
public:
	int intput();
};

int Vampire::intput()
{
	ofstream ofile;               //��������ļ�
	ofile.open("E:\\surprice.txt");     //��Ϊ����ļ���
	ofile << "��л��ʦ�ļ�顣" << endl;   //����д���ļ�
	ofile << "������ҵĿγ���ơ�" << endl;
	ofile.close();                //�ر��ļ�
	return 0;
}

Teacher   tea;
Course    cou;
Zombie    zom;
Ghost     gho;
Vampire   vam;

/*�����溯��*/
void dis_menu()
{
	bool ttag = false;
	bool ctag = false;
	char tag;
	int choice = 0;
	do {
		system("cls");
		cout << "========��ӭʹ�ý�ʦ�ſ�ϵͳ,�������ʾ�����ز���========" << endl;
		cout << "===			1:�����ʦ��Ϣ			===" << endl;
		cout << "===			2:����γ���Ϣ			===" << endl; 
		cout << "===			3:�洢��ʦ��Ϣ			===" << endl;
		cout << "===			4:�洢�γ���Ϣ			===" << endl;
		cout << "===			5:��ʼ��ʦ�ſ�			===" << endl;
		cout << "===			6:��ӡ�ſν��			===" << endl;
		cout << "===			7.��ʦ��Ϣ�޸�			===" << endl;
		cout << "===			8.�γ���Ϣ�޸�			===" << endl;
		cout << "===			9.ϵͳ��������			===" << endl;
		cout << "===			0:�˳��ſ�ϵͳ			===" << endl;
		cout << "===========================================================" << endl;
		fflush(stdin);
		cout << "������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "------------��ʦ��Ϣ����------------" << endl;
			tea.input();
			ttag = true;
			break;
		case 2:
			system("cls");
			cout << "------------�γ���Ϣ����------------" << endl;
			cou.input();
			ctag = true;
			break;
		case 3:
			system("cls");
			cout << "------------��ʦ��Ϣ����------------" << endl;
			if (!ttag)
				cout << "���������ʦ��Ϣ" << endl;
			else
				tea.preserve();
			break;
		case 4:
			system("cls");
			cout << "------------�γ���Ϣ����------------" << endl;
			if (!ctag)
				cout << "��������γ���Ϣ" << endl;
			else
				cou.preserve();
			break;
		case 5:
			system("cls");
			cout << "------------��ʦ�������------------" << endl;
			if (!ttag || !ctag)
				cout << "�������������Ϣ:" << endl;
			else
				sort(tea, cou);
			break;
		case 6:
			system("cls");
			cout << "------------�ſ���Ϣ��ӡ------------" << endl;
			if (!ttag || !ctag)
				cout << "�������������Ϣ:" << endl;
			else
				print(tea);
			break;
		case 7:
			system("cls");
			cout << "------------��ʦ��Ϣ�޸�------------" << endl;
			zom.intput();
			break;
		case 8:
			system("cls");
			cout << "------------�γ���Ϣ�޸�------------" << endl;
			gho.intput();
			break;
		case 9:
			system("cls");
			cout << "------------ϵͳ��������------------" << endl;
			vam.intput();
			break;
		default:
			system("cls");
			cout << "\t-------------------THANKS FOR YOUR USE-------------------" << endl;
			cout << "\t-------------------  ��лʹ�ñ�ϵͳ!  -------------------" << endl;
			exit(0);
		}
		cout << "ϵͳʹ����........." << endl;
		cout << "�Ƿ������������? y/n" << endl;
		cin >> tag;
	} while (tag == 'y' || tag == 'n');

}