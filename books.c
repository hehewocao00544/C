#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
char ch, c, h;//ѡ��
struct BOOK
{
	char bianhao[11];//ͼ����
	char bookname[50];//����
	char writer[50];//����
	char leibie[20];//ͼ������
	char chubanfang[50];//���淽
	char data[11];//��������
	float price;//�۸�
	int num;//����
	struct BOOK* next;
};
struct admin
{
	char adname[20];
	char mima[20];
	char phone[12];
	struct admin * next;
};
struct BOOK* head;
struct BOOK* p;
void gotoxy(int x, int y);//����ƶ�
void JM();//����
void DelJM();//ɾ�����ܽ���
void Next();//����y�����������������˳�
void output(struct BOOK* head);//�������
void CL();//������������
void Save();//������ʾ��
void Del();//ɾ����ʾ��
void Succeed();//�ɹ�
void FileSave();//�ļ�����
void PXJM();//�������
void FileRead(struct BOOK* HEAD);//�ļ���ȡ
void DelWriter(struct BOOK* HEAD);//ɾ������
void DelBook(struct BOOK* HEAD);//ɾ��ͼ�飨��Ż�������
void PX_b(struct BOOK* HEAD);//�������
void PX_p(struct BOOK* HEAD);//�۸�����
void Check();//ͼ���ѯ
void Change();//ͼ����Ϣ�޸�
int FRN();//�ж��Ƿ��ļ�Ϊ��
void menu();//���˵�
void menu5();//ѡ��5���˵�
void menu3();//ѡ��3���˵�
int ReCheck(char str[]);//�ж��������Ƿ��ظ�
void FileReadAdmin(struct admin*head);//�û���Ϣ��ȡ
void loginJM();//��½����
void registerJM();//ע�����
void SaveAdmin(struct admin* s);//�����û���Ϣ
void menulog();//ע��͵�½�˵�
void registermenu(); //ע�Ṧ��
void loginmenu();//��½����
void menulogJM();//ע��͵�½�˵�ѡ�����
struct admin* CreatAdmin();//��������һ���û�
void welcome();//��ӭʹ��
void output_writer();//�������ͳ�ƽ��
void output_type();//�������ͳ�ƽ��


void FileSaveCheck(struct admin*s);//�û�ע���ظ����
void usermenu();//�û��˵�
void userJM();//�û��˵�����
void CheckBor();//�û���ѯ���Ĺ���
void attention();//ע����ʾ��

//��������

int main(void)
{	
	menulog();
	return 0;
}




//�Զ��庯����

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}
void JM()
{
	system("cls");
	printf("*�����ʹ��*");
	gotoxy(80, 11); printf("*********ͼ�����ϵͳ*********");
	gotoxy(80, 13); printf("     |  1.ͼ����Ϣ¼��  |");
	gotoxy(80, 15); printf("     |  2.ͼ����Ϣ��ѯ  |");
	gotoxy(80, 17); printf("     |  3.ͼ����Ϣɾ��  |");
	gotoxy(80, 19); printf("     |  4.ͼ����Ϣ�޸�  |");
	gotoxy(80, 21); printf("     |  5.ͼ����Ϣ����  |");
	gotoxy(80, 23); printf("     |  6.�˳�����      |");
	gotoxy(80, 25); printf("     |  7.ע���û�      |");
	gotoxy(86, 27); printf("������ţ�ѡ����");
}

void Next()
{
	printf("����y�����������������˳�");
}

void Continue()
{
	system("cls");
	gotoxy(75, 20); printf("----------------------------------------\n");
	gotoxy(75, 22); printf("|                                      |\n");
	gotoxy(75, 24); printf("|    Continue to enter information?    |\n");
	gotoxy(75, 26); printf("|                y / n                 |\n");
	gotoxy(75, 28); printf("|                                      |\n");
	gotoxy(75, 30); printf("----------------------------------------\n");
	gotoxy(75, 32);	printf("      ����y����¼����Ϣ������n����¼�룡");
}

void Save()
{
	system("cls");
	gotoxy(80, 20); printf("---------------------------\n");
	gotoxy(80, 22); printf("|                         |\n");
	gotoxy(80, 24); printf("|    Are you save it ?    |\n");
	gotoxy(80, 26); printf("|          y / n          |\n");
	gotoxy(80, 28); printf("|                         |\n");
	gotoxy(80, 30); printf("---------------------------\n");
	gotoxy(80, 32);	printf("     ����y���棡����nȡ����");
}

void Del()
{
	//system("cls");
	gotoxy(80, 20); printf("---------------------------\n");
	gotoxy(80, 22); printf("|                         |\n");
	gotoxy(80, 24); printf("|    Are you delete it ?    |\n");
	gotoxy(80, 26); printf("|          y / n          |\n");
	gotoxy(80, 28); printf("|                         |\n");
	gotoxy(80, 30); printf("---------------------------\n");
	gotoxy(80, 32);	printf("     ����y���棡����nȡ����");
}

void DelJM()
{
	system("cls");
	gotoxy(80, 11); printf("*********ͼ�����ϵͳ*********");
	gotoxy(80, 13); printf("     |  1.ɾ��ĳ����ͼ��  |");
	gotoxy(80, 15); printf("     |  2.��Ż�����ɾ��  |");
	gotoxy(80, 17); printf("     |  3.����ϵͳ������  |");
	gotoxy(86, 25); printf(" ������ţ�ѡ����");
}

void PXJM()
{
	system("cls");
	gotoxy(80, 11); printf("*********ͼ�����ϵͳ*********");
	gotoxy(80, 13); printf("     |  1.��ͼ��������  |");
	gotoxy(80, 15); printf("     |  2.��ͼ��۸�����  |");
	gotoxy(80, 17); printf("     |  3.������ͳ��ͼ��  |");
	gotoxy(80, 19); printf("     |  4.������ͳ��ͼ��  |");
	gotoxy(80, 21); printf("     |  5.����ϵͳ������  |");
	gotoxy(86, 23); printf(" ������ţ�ѡ����");
}


void CL()//��������
{
	head->next = NULL;
	p = (struct BOOK*)malloc(sizeof(struct BOOK));
	p->next = NULL;
loop:
	{
		struct BOOK* s = (struct BOOK*)malloc(sizeof(struct BOOK));
		gotoxy(80, 11); printf("������ͼ���ţ�С��10λ����");
		loop1:scanf("%s", s->bianhao);
		if (ReCheck(s->bianhao) == -1)
		{
			system("cls");
			gotoxy(80, 11); printf("����ı���ظ��������������ţ�");
			goto loop1;
		}
			gotoxy(80, 13); printf("������������С��25�֣���");
			scanf("%s", s->bookname);
			gotoxy(80, 15); printf("����������������С��25�֣���");
			scanf("%s", s->writer);
			gotoxy(80, 17); printf("������ͼ�����С��10�֣���");
			scanf("%s", s->leibie);
			gotoxy(80, 19); printf("������ͼ����淽��С��25�֣���");
			scanf("%s", s->chubanfang);
			gotoxy(80, 21); printf("������ͼ��������ڣ���2018.03.03����");
			scanf("%s", s->data);
			gotoxy(80, 23); printf("������ͼ��۸�");
			scanf("%f", &s->price);
			gotoxy(80, 25); printf("������ͼ��������");
			scanf("%d", &s->num);
			if (head->next == NULL)
			{
				head->next = s;
				s->next = NULL;
			}
			else
			{
				p->next = s;
				s->next = NULL;
			}
			p = s;
			//�ļ��洢
			Save();
			char a;
			loop2:
			a = getch();
			if (a == 'y' || a == 'Y')
			{
				FileSave();
				Succeed();
				Sleep(1000);
			}
			else if (a == 'n' || a == 'N')
			{
				system("cls");
				gotoxy(90, 25); printf("�޸�δ���棡");
				Sleep(1000);
				system("cls");
			}
			else
			{
				goto loop2;
			}
			gotoxy(80, 25); Continue();
			ch = getch();
			if (ch == 'y' || ch == 'Y')
			{
				system("cls");
				goto loop;
			}
		}
	
}

void output(struct BOOK* s)
{
	int t = 0;
	system("cls");
	struct BOOK* p = (struct BOOK*)malloc(sizeof(struct BOOK));
	p = s;
	gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
	gotoxy(40, 7); printf("ͼ����        ����         ����         ͼ�����         ���淽         ��������         ͼ��۸�         ͼ������\n");
	gotoxy(33, 8); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
	while (p->next != NULL)
	{
		gotoxy(40, 9 + t); printf("%s", p->next->bianhao);
		gotoxy(55, 9 + t); printf("%s", p->next->bookname);
		gotoxy(69, 9 + t); printf("%s", p->next->writer);
		gotoxy(82, 9 + t); printf("%s", p->next->leibie);
		gotoxy(99, 9 + t); printf("%s", p->next->chubanfang);
		gotoxy(114, 9 + t); printf("%s", p->next->data);
		gotoxy(131, 9 + t); printf("%g", p->next->price);
		gotoxy(150, 9 + t); printf("%d\n", p->next->num);
		t = t + 2;
		p = p->next;
	}
}

void FileSave()
{
	char a;
	a = getch();
	system("cls");
	if (a == 'y' || a == 'Y')
	{
		FILE* fp = fopen("bookinformation.txt", "a");
		if (fp == NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			return 0;
		}
		fprintf(fp, "%s %s %s %s %s %s %g %d\n", p->bianhao, p->bookname, p->writer, p->leibie, p->chubanfang, p->data, p->price,p->num);
		fclose(fp);
	}
}

void FileRead(struct BOOK* HEAD)
{
	FILE *fp = fopen("bookinformation.txt", "rt");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return 0;
	}
	struct BOOK* p = (struct BOOK*)malloc(sizeof(struct BOOK));
	p->next = NULL;
	while (!feof(fp))//�ж��Ƿ�����ļ�β
	{
		struct BOOK* s = (struct BOOK*)malloc(sizeof(struct BOOK));
		fscanf(fp, "%s %s %s %s %s %s %f %d\n", s->bianhao, s->bookname, s->writer, s->leibie, s->chubanfang, s->data, &s->price, &s->num);
		if (HEAD->next == NULL)
		{
			HEAD->next = s;
			s->next = NULL;
		}
		else
		{
			p->next = s;
			s->next = NULL;
		}
		p = s;
	}
}

void DelWriter(struct BOOK* HEAD)
{
	int t = 0;
	int a = 0;//ɾ���������ȼ�����
	char ch[50];
	struct BOOK* q1 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q1->next = NULL;
	struct BOOK* q2 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q2->next = NULL;
	q1 = HEAD;
	gotoxy(75, 20); printf("������Ҫɾ����ͼ������ߣ�");
	scanf("%s", ch);

	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q = HEAD;
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->writer) == 0)
		{
			system("cls");
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("ͼ����        ����         ����         ͼ�����         ���淽         ��������         ͼ��۸�         ͼ������\n");
			gotoxy(33, 8); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 9 + t); printf("%s", q->next->bianhao);
			gotoxy(55, 9 + t); printf("%s", q->next->bookname);
			gotoxy(69, 9 + t); printf("%s", q->next->writer);
			gotoxy(82, 9 + t); printf("%s", q->next->leibie);
			gotoxy(99, 9 + t); printf("%s", q->next->chubanfang);
			gotoxy(114, 9 + t); printf("%s", q->next->data);
			gotoxy(131, 9 + t); printf("%g", q->next->price);
			gotoxy(150, 9 + t); printf("%d\n", q->next->num);
			t += 2;
		}
		q = q->next;
	}


	while (q1->next != NULL)
	{
		a++;
		q2 = q1->next;
		if (q2->next != NULL && (strcmp(ch, q2->writer) == 0 ))
		{
			t++;
			a--;
			q1->next = q2->next;
			q2 = q2->next;
			continue;
		}
		else if (q2->next == NULL && (strcmp(ch, q2->writer)==0))
		{
			t++;
			a--;
			q1->next = NULL;
			break;
		}
		q1 = q1->next;
	}
	if (t != 0)
	{
		loop:
		Del();
		char c;
		c = getch();
		if (c == 'y' || c == 'Y')
		{
			q1 = HEAD->next;
			FILE* fp = fopen("bookinformation.txt", "wt");
			if (fp == NULL)
			{
				printf("���ļ�ʧ�ܣ�\n");
				return 0;
			}
			for (int i = 0; i < a; i++)
			{
				fprintf(fp, "%s %s %s %s %s %s %g %d\n", q1->bianhao, q1->bookname, q1->writer, q1->leibie, q1->chubanfang, q1->data, q1->price, q1->num);
				q1 = q1->next;
			}
			fclose(fp);
			Succeed();
			Sleep(1000);
			system("cls");
		}
		else if (c == 'n' || c == 'N')
		{
			system("cls");
			gotoxy(83, 22); printf("�޸�δ���棡");
			gotoxy(83, 25); printf("�����������ɾ���˵���");
			getch();
			menu3();
		}
		else
		{
			goto loop;
		}
	}
	else if (t==0)
	{
		gotoxy(80, 22); printf("û���ҵ������ߣ�����");
		Sleep(1000);
	}
}

void DelBook(struct BOOK* HEAD)
{
	int t = 0;
	int a = 0;//ɾ���������ȼ�����
	char ch[50];
	struct BOOK* q1 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q1->next = NULL;
	struct BOOK* q2 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q2->next = NULL;
	q1 = HEAD;
	gotoxy(75, 20); printf("������Ҫɾ����ͼ��ı�Ż�������");
	scanf("%s", ch);
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q = HEAD;
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->bianhao) == 0 || strcmp(ch, q->next->bookname) == 0 )
		{
			system("cls");
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("ͼ����        ����         ����         ͼ�����         ���淽         ��������         ͼ��۸�         ͼ������\n");
			gotoxy(33, 8); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 9 + t); printf("%s", q->next->bianhao);
			gotoxy(55, 9 + t); printf("%s", q->next->bookname);
			gotoxy(69, 9 + t); printf("%s", q->next->writer);
			gotoxy(82, 9 + t); printf("%s", q->next->leibie);
			gotoxy(99, 9 + t); printf("%s", q->next->chubanfang);
			gotoxy(114, 9 + t); printf("%s", q->next->data);
			gotoxy(131, 9 + t); printf("%g", q->next->price);
			gotoxy(150, 9 + t); printf("%d\n", q->next->num);
			t += 2;
		}
		q = q->next;
	}

	while (q1->next != NULL)
	{
		a++;
		q2 = q1->next;
		if (q2->next != NULL && (strcmp(ch, q2->bianhao) == 0 || strcmp(ch, q2->bookname) == 0))
		{
			t++;
			a--;
			q1->next = q2->next;
			q2 = q2->next;
			continue;
		}
		else if (q2->next == NULL && (strcmp(ch, q2->bianhao) == 0 || strcmp(ch, q2->bookname) == 0))
		{
			t++;
			a--;
			q1->next = NULL;
			break;
		}
		q1 = q1->next;
	}
	if (t != 0)
	{
		loop:
		Del();
		char c;
		c = getch();
		if (c == 'y' || c == 'Y')
		{
			q1 = HEAD->next;
			FILE* fp = fopen("bookinformation.txt", "wt");
			if (fp == NULL)
			{
				printf("���ļ�ʧ�ܣ�\n");
				return 0;
			}
			for (int i = 0; i < a; i++)
			{
				fprintf(fp, "%s %s %s %s %s %s %g %d\n", q1->bianhao, q1->bookname, q1->writer, q1->leibie, q1->chubanfang, q1->data, q1->price, q1->num);
				q1 = q1->next;
			}
			fclose(fp);
			Succeed();
			Sleep(1000);
			system("cls");
		}
		else if (c == 'n' || c == 'N')
		{
			system("cls");
			gotoxy(83, 22); printf("�޸�δ���棡");
			gotoxy(83, 25); printf("�����������ɾ���˵���");
			getch();
			menu3();
		}
		else
		{
			goto loop;
		}
	}
	else
	{
		gotoxy(80, 22); printf("�Ȿ�黹û������أ�����");
	}
}

void PX_b(struct BOOK* HEAD)
{
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q = HEAD;
	int a = 0;//�����ȼ�����
	while (q->next != NULL)
	{
		a++;
		q = q->next;
	}
	struct BOOK* q1 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q1->next = NULL;
	struct BOOK* q2 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q2->next = NULL;
	if (HEAD->next->next != NULL)
	{
		for (int i = 0; i<a - 1; i++)
		{
			q = HEAD;
			q1 = q->next;
			q2 = q1->next;
			while (q2->next != NULL)
			{
				if (strcmp(q1->bianhao, q2->bianhao) > 0)
				{
					q->next = q1->next;
					q1->next = q2->next;
					q2->next = q1;
					q2 = q1->next;
					q = q->next;
					continue;
				}
				q = q->next;
				q1 = q1->next;
				q2 = q2->next;
			}
			if (strcmp(q1->bianhao, q2->bianhao) > 0)
			{
				q->next = q2;
				q2->next = q1;
				q1->next = NULL;
			}
		}
	}
	q1 = HEAD->next;
	FILE* fp = fopen("bookinformation.txt", "wt");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return 0;
	}
	for (int i = 0; i < a; i++)
	{
		fprintf(fp, "%s %s %s %s %s %s %g %d\n", q1->bianhao, q1->bookname, q1->writer, q1->leibie, q1->chubanfang, q1->data, q1->price, q1 ->num);
		q1 = q1->next;
	}
	fclose(fp);
}

void PX_p(struct BOOK* HEAD)
{
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q = HEAD;
	int a = 0;//�����ȼ�����
	while (q->next != NULL)
	{
		a++;
		q = q->next;
	}
	struct BOOK* q1 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q1->next = NULL;
	struct BOOK* q2 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q2->next = NULL;
	if (HEAD->next->next != NULL)
	{
		for (int i = 0; i< a - 1; i++)
		{
			q = HEAD;
			q1 = q->next;
			q2 = q1->next;
			while (q2->next != NULL)
			{
				if (q1->price > q2->price)
				{
					q->next = q1->next;
					q1->next = q2->next;
					q2->next = q1;
					q2 = q1->next;
					q = q->next;
					continue;
				}
				q = q->next;
				q1 = q1->next;
				q2 = q2->next;
			}
			if (q1->price > q2->price)
			{
				q->next = q2;
				q2->next = q1;
				q1->next = NULL;
			}
		}
	}
	q1 = HEAD->next;
	FILE* fp = fopen("bookinformation.txt", "wt");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return 0;
	}
	for (int i = 0; i < a; i++)
	{
		fprintf(fp, "%s %s %s %s %s %s %g %d\n", q1->bianhao, q1->bookname, q1->writer, q1->leibie, q1->chubanfang, q1->data, q1->price, q1 ->num);
		q1 = q1->next;
	}
	fclose(fp);
}


void Change()
{
	int t = 0;
	system("cls");
	FileRead(head);
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q = head;
	char ch[50];
	gotoxy(80, 15); printf("��������Ҫ��ѯͼ��ı�Ż�������");
	scanf("%s", ch);
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->bianhao) == 0 || strcmp(ch, q->next->bookname) == 0)
		{
			system("cls");
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("ͼ����        ����         ����         ͼ�����         ���淽         ��������         ͼ��۸�         ͼ������\n");
			gotoxy(33, 8); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 9 ); printf("%s", q->next->bianhao);
			gotoxy(55, 9 ); printf("%s", q->next->bookname);
			gotoxy(69, 9 ); printf("%s", q->next->writer);
			gotoxy(82, 9 ); printf("%s", q->next->leibie);
			gotoxy(99, 9 ); printf("%s", q->next->chubanfang);
			gotoxy(114, 9 ); printf("%s", q->next->data);
			gotoxy(131, 9 ); printf("%g", q->next->price);
			gotoxy(150, 9 ); printf("%d\n", q->next->num);

			t++;
			struct BOOK* q1 = (struct BOOK*)malloc(sizeof(struct BOOK));
			q1 = q->next;
			struct BOOK* s = (struct BOOK*)malloc(sizeof(struct BOOK));
			gotoxy(80, 11); printf("����������ͼ���ţ�С��10λ����");
			scanf("%s", s->bianhao);
			gotoxy(80, 13); printf("����������������С��25�֣���");
			scanf("%s", s->bookname);
			gotoxy(80, 15); printf("��������������������С��25�֣���");
			scanf("%s", s->writer);
			gotoxy(80, 17); printf("����������ͼ�����С��10�֣���");
			scanf("%s", s->leibie);
			gotoxy(80, 19); printf("����������ͼ����淽��С��25�֣���");
			scanf("%s", s->chubanfang);
			gotoxy(80, 21); printf("����������ͼ��������ڣ���2018.03.03����");
			scanf("%s", s->data);
			gotoxy(80, 23); printf("����������ͼ��۸�");
			scanf("%f", &s->price);
			gotoxy(80, 25); printf("����������ͼ��������");
			scanf("%d", &s->num);
			char a;
			Save();
		loop:a = getch();
			if (a == 'y' || a == 'Y')
			{
				Succeed();
				Sleep(1000);
				system("cls");
				q->next = s;
				s->next = q1->next;
			}
			else if (a == 'n' || a == 'N')
			{
				system("cls");
				gotoxy(90, 25); printf("�޸�δ���棡");
				Sleep(1000);
				system("cls");
			}
			else
			{
				gotoxy(80, 34); printf("����������y��n��");
				goto loop;
			}
		}
		q = q->next;
	}
	if (t != 0)
	{
		q = head;
		int a = 0;//�����ȼ�����
		while (q->next != NULL)
		{
			a++;
			q = q->next;
		}
		q = head->next;
		FILE* fp = fopen("bookinformation.txt", "wt");
		if (fp == NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			return 0;
		}
		for (int i = 0; i < a; i++)
		{
			fprintf(fp, "%s %s %s %s %s %s %g %d\n", q->bianhao, q->bookname, q->writer, q->leibie, q->chubanfang, q->data, q->price, q ->num);
			q = q->next;
		}
		fclose(fp);
	}
	else
	{
		gotoxy(80, 22); printf("�Ȿ�黹û������أ�����");
	}
}

void Check()
{
	system("cls");
	head->next = NULL;
	FileRead(head);
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q = head;
	char ch[50];
	gotoxy(80, 15); printf("��������Ҫ��ѯͼ��ı�Ż����������ߣ�");
	gotoxy(80, 17); scanf("%s", ch);
	system("cls");
	int t = 0;
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->bianhao) == 0 || strcmp(ch, q->next->bookname) == 0 || strcmp(ch, q->next->writer) == 0)
		{
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("ͼ����        ����         ����         ͼ�����         ���淽         ��������         ͼ��۸�         ͼ������\n");
			gotoxy(33, 8); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 9 + t); printf("%s", q->next->bianhao);
			gotoxy(55, 9 + t); printf("%s", q->next->bookname);
			gotoxy(69, 9 + t); printf("%s", q->next->writer);
			gotoxy(82, 9 + t); printf("%s", q->next->leibie);
			gotoxy(99, 9 + t); printf("%s", q->next->chubanfang);
			gotoxy(114, 9 + t); printf("%s", q->next->data);
			gotoxy(131, 9 + t); printf("%g", q->next->price);
			gotoxy(150, 9 + t); printf("%d\n", q->next->num);
			t += 2;
		}
		q = q->next;
	}
	if (t == 0)
	{
		system("cls");
		gotoxy(80, 21); printf("�Ȿ�黹û�������⣡����");
	}
}

void Succeed()
{
	system("cls");
	gotoxy(80, 20); printf("---------------------------\n");
	gotoxy(80, 22); printf("|          �� �� !         |\n");
	gotoxy(80, 24); printf("---------------------------\n");
}

int FRN()
{
	FILE *fp;
	if (fp = fopen("bookinformation.txt", "rt") == NULL)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


void menu()
{
	head = (struct BOOK*)malloc(sizeof(struct BOOK));
	head->next = NULL;
	system("cls");
	char str;
	JM();
	str = getch();
	switch (str)
	{
	case '1':
		system("cls");
		CL();
		system("cls");
		gotoxy(80, 25); printf("����������������棡");
		getch(); 
		menu();
		break;
	case '2':
		if (FRN() == 0)
		{
			Check();
		} 
		else
		{
			system("cls");
			gotoxy(80, 23); printf("��û���һ��ͼ����Ϣ�أ���ȥ���һ���ɣ�");
		}
		gotoxy(80, 25); printf("����������������棡");
		getch();
		menu();
		break;
	case '3':
		menu3();
		break;
	case '4':
		if (FRN() == 0)
		{
			Change();
		}
		else
		{
			system("cls");
			gotoxy(80, 23); printf("��û���һ��ͼ����Ϣ�أ���ȥ���һ���ɣ�");
		}
		gotoxy(80, 25); printf("����������������棡");
		getch();
		menu();
		break;
	case '5':
		menu5();
		break;
	case '6':system("cls"); exit(0); break;
	case '7': Succeed(); Sleep(1000); menulog(); break;
	default: menu();
	}
}

void menu5()
{
	system("cls");
	if (FRN() == 0)
	{
		PXJM();
		char c;
		c = getch();
		switch (c)
		{
		case '1':
			FileRead(head);
			PX_b(head);
			output(head);
			gotoxy(60, 5); printf("�����������������棡");
			getch();
			menu5();
			break;
		case '2':
			FileRead(head);
			PX_p(head);
			output(head);
			gotoxy(60, 5); printf("�����������������棡");
			getch();
			menu5();
			break;
		case '3':output_writer(); gotoxy(60, 5); printf("�����������������棡"); getch(); menu5(); break;
		case '4':output_type(); gotoxy(60, 5); printf("�����������������棡"); getch(); menu5(); break;
		case '5':
			menu();
			break;
		default:menu5();
		}
	}
	else
	{
		system("cls");
		gotoxy(80, 23); printf("��û���һ��ͼ����Ϣ�أ���ȥ���һ���ɣ�");
		gotoxy(80, 25); printf("����������������棡");
		getch();
		menu();
	}
}

void menu3()
{
	system("cls");
	if (FRN() == 0)
	{
		DelJM();
		char c;
		c = getch();
		switch (c)
		{
		case '1':
			system("cls");
			FileRead(head);
			DelWriter(head);
			system("cls");
			gotoxy(80, 23); printf("�����������ɾ���˵���");
			getch();
			menu3();
			break;
		case '2':
			system("cls");
			FileRead(head);
			DelBook(head);
			gotoxy(80, 24); printf("�����������ɾ���˵���");
			getch();
			menu3();
			break;
		case '3':
			menu();
			break;
		default:menu3();
		}
	}
	else
	{
		system("cls");
		gotoxy(80, 23); printf("��û���һ��ͼ����Ϣ�أ���ȥ���һ���ɣ�");
		gotoxy(80, 25); printf("����������������棡");
		getch();
		menu();
	}
}

int ReCheck(char str[])
{
	if (FRN() == 0)
	{
		struct BOOK* Head = (struct BOOK*)malloc(sizeof(struct BOOK));
		Head->next = NULL;
		FileRead(Head);
		struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
		q = Head;
		while (q->next != NULL)
		{
			if (strcmp(str, q->next->bianhao) == 0)
			{
				return -1;
			}
			q = q->next;
		}
		return 0;
	}
	else
	{
		return 0;
	}
}
int FileReadNULL()
{
	FILE *fp;
	if (fp = fopen("Admin.data", "rb") == NULL)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void loginJM()
{
	system("cls");
	gotoxy(80, 16); printf("**********ͼ�����ϵͳ��¼**********\n");
	gotoxy(80, 17); printf("*                                  *\n");
	gotoxy(80, 18); printf("*   �ʺţ�                         *\n");
	gotoxy(80, 19); printf("*                                  *\n");
	gotoxy(80, 20); printf("*   ���룺                         *\n");
	gotoxy(80, 21); printf("*                                  *\n");
	gotoxy(80, 22); printf("************************************\n");
}

void registerJM()
{
	system("cls");
	gotoxy(80,16); printf("**********ͼ�����ϵͳע��**********\n");
	gotoxy(80, 17); printf(" *                                *\n");
	gotoxy(80, 18); printf(" *   �ʺţ�                       *\n");
	gotoxy(80, 19); printf(" *                                *\n");
	gotoxy(80, 20); printf(" *   ���룺                       *\n");
	gotoxy(80, 21); printf(" *                                *\n");
	gotoxy(80, 22); printf(" *   �ֻ��ţ�                     *\n");
	gotoxy(80, 23); printf(" *                                *\n");
	gotoxy(80, 24); printf(" *------------�ٴ�����------------*\n");
	gotoxy(80, 25); printf(" *                                *\n");
	gotoxy(80, 26); printf(" *   �ʺţ�                       *\n");
	gotoxy(80, 27); printf(" *                                *\n");
	gotoxy(80, 28); printf(" *   ���룺                       *\n");
	gotoxy(80, 29); printf(" *                                *\n");
	gotoxy(80, 30); printf(" *   �ֻ��ţ�                     *\n");
	gotoxy(80, 31); printf(" *                                *\n");
	gotoxy(80, 32); printf("************************************\n");
}


void output_writer()
{
	system("cls");
	gotoxy(75, 9); printf("--------------------------------------------------\n");
	gotoxy(75, 10); printf("           ����             ������Ʒ����             \n");
	gotoxy(75, 11); printf("--------------------------------------------------\n");
	struct BOOK* head = (struct BOOK*)malloc(sizeof(struct BOOK));
	struct BOOK* p = (struct BOOK*)malloc(sizeof(struct BOOK));
	head->next = NULL;
	FileRead(head);
	if (FRN() == -1)
	{
		gotoxy(85, 15); printf("��û�����ͼ���أ���ȥ���һ���ɣ�"); Sleep(1000); menu();
	}
	p = head->next;
	int t = 0;//�������������
	int sum = 1;//ͳ������������
	while (head->next != NULL && head->next->next != NULL)
	{
		char ch[50];
		strcpy(ch, head->next->writer);
		while (p->next != NULL)
		{
			if (strcmp(ch, p->next->writer) == 0)
			{
				sum++;
				if (p->next->next != NULL)
				{
					p->next = p->next->next;
					continue;
				}
				else if (p->next->next == NULL)
				{
					if (head->next->next->next == NULL&&strcmp(head->next->writer, head->next->next->writer) == 0)
					{
						gotoxy(86, 12 + t); printf("%s", head->next->writer);
						gotoxy(108, 12 + t); printf("%d", sum);
						head->next = NULL;
						break;
					}
					else
					{
						p->next = NULL;
						continue;
					}
				}
			}
			p = p->next;
		}
		if (head->next != NULL)
		{
			gotoxy(86, 12 + t); printf("%s", head->next->writer);
			gotoxy(108, 12 + t); printf("%d", sum);
			t += 2;
			if (head->next->next != NULL)
			{
				
					p = head->next;
					head->next = p->next;
					p = head->next;
				
			}
			sum = 1;
		}
		if ( head->next != NULL)
		{
			gotoxy(86, 12 + t); printf("%s", head->next->writer);
			gotoxy(108, 12 + t); printf("%d", sum);
		}
	}
}

void output_type()
{
	system("cls");
	gotoxy(75, 9); printf("--------------------------------------------------\n");
	gotoxy(75, 10); printf("           ����               ��Ʒ����             \n");
	gotoxy(75, 11); printf("--------------------------------------------------\n");
	struct BOOK* head = (struct BOOK*)malloc(sizeof(struct BOOK));
	struct BOOK* p = (struct BOOK*)malloc(sizeof(struct BOOK));
	head->next = NULL;
	FileRead(head);
	if (FRN() == -1)
	{
		gotoxy(85, 15); printf("��û�����ͼ���أ���ȥ���һ���ɣ�"); Sleep(1000); menu();
	}
	p = head->next;
	int t = 0;//�������������
	int sum = 1;//ͳ������������
	while (head->next != NULL && head->next->next != NULL)
	{
		char ch[50];
		strcpy(ch, head->next->leibie);
		while (p->next != NULL)
		{
			if (strcmp(ch, p->next->leibie) == 0)
			{
				sum++;
				if (p->next->next != NULL)
				{
					p->next = p->next->next;
					continue;
				}
				else if (p->next->next == NULL)
				{
					if (head->next->next->next == NULL&&strcmp(head->next->leibie, head->next->next->leibie) == 0)
					{
						gotoxy(86, 12 + t); printf("%s", head->next->leibie);
						gotoxy(108, 12 + t); printf("%d", sum);
						head->next = NULL;
						break;
					}
					else
					{
						p->next = NULL;
						continue;
					}
				}
			}
			p = p->next;
		}
		if (head->next != NULL)
		{
			gotoxy(86, 12 + t); printf("%s", head->next->leibie);
			gotoxy(108, 12 + t); printf("%d", sum);
			t += 2;
			if (head->next->next != NULL)
			{

				p = head->next;
				head->next = p->next;
				p = head->next;

			}
			sum = 1;
		}
		if (head->next != NULL)
		{
		gotoxy(86, 12 + t); printf("%s", head->next->leibie);
		gotoxy(108, 12 + t); printf("%d", sum);
		}
	}
}

struct admin* CreatAdmin()
{
	struct admin* p = (struct admin*)malloc(sizeof(struct admin));
	
loop:
	{
		registerJM();
		struct admin* s = (struct admin*)malloc(sizeof(struct admin));
		gotoxy(92, 18); scanf("%s", &s->adname);
		gotoxy(92, 20); scanf("%s", &s->mima);
		gotoxy(93, 22); scanf("%s", &s->phone);

		struct admin* s2 = (struct admin*)malloc(sizeof(struct admin));
		gotoxy(92, 26); scanf("%s", &s2->adname);
		gotoxy(92, 28); scanf("%s", &s2->mima);
		gotoxy(93, 30); scanf("%s", &s2->phone);

		if (strcmp(s->adname, s2->adname) == 0 && strcmp(s->mima, s2->mima) == 0 && strcmp(s->phone, s2->phone) == 0)
		{
			FileSaveCheck(s);
			return s;
		}
		else
		{
			system("cls");
			gotoxy(90, 19); printf("�������벻һ�£����������룡\n"); Sleep(1000);
			goto loop;
		}
	}
}
void SaveAdmin(struct admin* s)
{
	FILE *fp = NULL;
	fp = fopen("Admin.data", "ab");
	if (fp == NULL)
	{
		
		printf("���ļ�ʧ�ܣ�\n");
		return;
	}
	fprintf(fp, "%s\t%s\t%s\n", s->adname, s->mima, s->phone);
	fclose(fp);
	Succeed();
	Sleep(1000);
}

void loginmenu()
{
	if (FileReadNULL() == -1)
	{
		system("cls");
		gotoxy(80, 13); printf("��ûע�����Ա�˺��أ���ȥע��һ���ɣ�"); Sleep(1000);
		registermenu();
	}
	loginJM();
	struct admin* q = (struct admin*)malloc(sizeof(struct admin));
	gotoxy(92, 18); scanf("%s", &q->adname);
	gotoxy(92, 20); scanf("%s", &q->mima);
	struct admin* p = (struct admin*)malloc(sizeof(struct admin));
	struct admin* head = (struct BOOK*)malloc(sizeof(struct BOOK));
	head->next = NULL;
	FileReadAdmin(head);
	p = head;
	while (p->next != NULL)
	{
		if (strcmp(p->next->adname, q->adname) == 0 && strcmp(p->next->mima, q->mima) == 0)
		{
			welcome();
			Sleep(1000);
			menu();
		}
		p = p->next;
	}
	if (p->next == NULL)
	{
		gotoxy(92, 19); printf("�˺Ż��������"); Sleep(1000); menulog();
	}
}
void FileReadAdmin(struct admin*head)
{
	FILE *fp = fopen("Admin.data", "rb");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return;
	}
	struct admin* p = (struct admin*)malloc(sizeof(struct admin));
	int i = 0;
	while (!feof(fp))
	{
		struct admin* s = (struct admin*)malloc(sizeof(struct admin));
		fscanf(fp, "%s\t%s\t%s\n", &s->adname, &s->mima, &s->phone);
		if (i == 0)
		{
			head->next = s;
			s->next = NULL;
		}
		else
		{
			s->next = NULL;
			p->next = s;
		}
		p = s;
		i++;
	}
}
void menulogJM()
{
	system("cls");
	printf("*�����ʹ��*");
	gotoxy(80, 16); printf("********ͼ�����ϵͳ��½********");
	gotoxy(80, 18); printf("     |  1.     ע��         |");
	gotoxy(80, 20); printf("     |  2.     ��½         |");
	gotoxy(80, 22); printf("     |  3.    �˳�����       |");
	gotoxy(86, 24); printf("������ţ�ѡ����");
}
void menulog()
{
	menulogJM();
	char ch = getch();
	switch (ch)
	{
	case '1':registermenu(); break;
	case '2':loginmenu(); break;
	case '3':system("cls"); exit(0); break;
	default:menulog(); break;
	}
}
void registermenu()
{
	SaveAdmin(CreatAdmin());
	menulog();
}
                                                    
void welcome()
{
	system("cls");
	gotoxy(80, 18); printf("******************************\n");
	gotoxy(80, 20); printf(" |         ��½�ɹ�          |\n");
	gotoxy(80, 22); printf(" |        o(*������*)o       |\n");
	gotoxy(80, 24); printf(" |         ��ӭʹ��          |\n");
	gotoxy(80, 26); printf("******************************\n");
}

void FileSaveCheck(struct admin*s)
{
	struct admin*head = (struct admin*)malloc(sizeof(struct admin));
	struct admin*p = (struct admin*)malloc(sizeof(struct admin));
	if (FileReadNULL() == 0)
	{
		FileReadAdmin(head);
		p = head;
		while (p->next != NULL)
		{
			if (strcmp(s->adname, p->next->adname) == 0)
			{
				system("cls");
				gotoxy(90, 19); printf("���û����ѱ�ע�ᣬ������ע�ᣡ\n"); Sleep(1000);
				registermenu();
			}
			p = p->next;
		}
	}
}

/*void userJM()
{
	system("cls");
	printf("*�����ʹ��*");
	gotoxy(80, 11); printf("************ͼ�����ϵͳ************");
	gotoxy(80, 13); printf("     |  1.ͼ����Ϣ��ѯ�����  |");
	gotoxy(80, 15); printf("     |  2.ͼ����Ϣ����       |");
	gotoxy(80, 17); printf("     |  3.�ҵĽ�����Ϣ       |");
	gotoxy(80, 19); printf("     |  4.�˳�����          |");
	gotoxy(80, 21); printf("     |  5.ע���û�          |");
	gotoxy(80, 23); printf("       ������ţ�ѡ����");
}

void usermenu()
{
	userJM();
	char ch = getch();
	switch (ch)
	{
	case '1':CheckBor(); break;
	case '2':
	case '3':
	case '4':exit(0); break;
	case '5':Succeed(); Sleep(1000); menulog(); break;
	default:usermenu(); break;
	}
}

void attention()
{
	system("cls");
	gotoxy(80, 16); printf("************ע��*************\n");
	gotoxy(80, 18); printf("*                          *\n");
	gotoxy(80, 19); printf("*        �Ƿ���Ĵ��飿      *\n");
	gotoxy(80, 20); printf("*    1.ȷ��      2.ȡ��     *\n");
	gotoxy(80, 20); printf("*                          *\n");
	gotoxy(80, 22); printf("****************************\n");
}

void CheckBor()
{
	struct BOOK* head = (struct BOOK*)malloc(sizeof(struct BOOK));
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	head->next = NULL;
	FileRead(head);
	char ch[50];
	system("cls");
	gotoxy(80, 15); printf("��������Ҫ��ѯͼ��ı�Ż����������ߣ�");
	gotoxy(80, 17); scanf("%s", ch);
	system("cls");
	int t = 0;
	q = head;
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->bianhao) == 0 || strcmp(ch, q->next->bookname) == 0 || strcmp(ch, q->next->writer) == 0)
		{
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("ͼ����        ����         ����         ͼ�����         ���淽         ��������         ͼ��۸�         ͼ������\n");
			gotoxy(33, 8); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 9 + t); printf("%s", q->next->bianhao);
			gotoxy(55, 9 + t); printf("%s", q->next->bookname);
			gotoxy(69, 9 + t); printf("%s", q->next->writer);
			gotoxy(82, 9 + t); printf("%s", q->next->leibie);
			gotoxy(99, 9 + t); printf("%s", q->next->chubanfang);
			gotoxy(114, 9 + t); printf("%s", q->next->data);
			gotoxy(131, 9 + t); printf("%g", q->next->price);
			gotoxy(150, 9 + t); printf("%d\n", q->next->num);
			t += 2;
		}
		q = q->next;
	}

	gotoxy(80, 15); printf("��������Ҫ����ͼ��ı�ţ�");
	gotoxy(80, 17); scanf("%s", ch);
	q = head;
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->bianhao) == 0 || strcmp(ch, q->next->bookname) == 0 || strcmp(ch, q->next->writer) == 0)
		{
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("ͼ����        ����         ����         ͼ�����         ���淽         ��������         ͼ��۸�         ͼ������\n");
			gotoxy(33, 8); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 9 ); printf("%s", q->next->bianhao);
			gotoxy(55, 9 ); printf("%s", q->next->bookname);
			gotoxy(69, 9 ); printf("%s", q->next->writer);
			gotoxy(82, 9 ); printf("%s", q->next->leibie);
			gotoxy(99, 9 ); printf("%s", q->next->chubanfang);
			gotoxy(114, 9 ); printf("%s", q->next->data);
			gotoxy(131, 9 ); printf("%g", q->next->price);
			gotoxy(150, 9 ); printf("%d\n", q->next->num);
		}
		q = q->next;
	}
loop:
	{	
		attention();
		char ch = getch();
		switch (ch)
		{
		case '1':FileSaveBor(); break;
		case '2':system("cls"); gotoxy(90, 19); printf("��ȡ�����ģ�\n"); Sleep(1000); usermenu();
		default: goto loop; break;
		}
	}
}

void FileSaveBor()
{
	FILE *fp = fopen("MyBor.txt", "wt");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return 0;
	}

}
*/