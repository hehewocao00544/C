#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
char ch;//ѡ��
struct BOOK
{
	char bianhao[11];
	char bookname[50];
	char writer[50];
	char leibie[20];
	char chubanfang[50];
	char data[11];
	float price;
	struct BOOK* next;
};
struct BOOK* head;
struct BOOK* p;
void gotoxy(int x, int y);//����ƶ�
void JM();//����
void Next();//����y�����������������˳�
void output(struct BOOK* head);//�������
void CL();//������������
void Save();//������ʾ��
void FileSave();//�ļ�����
void FileRead(struct BOOK* HEAD);//�ļ���ȡ
void DelRe(struct BOOK* HEAD);//ɾ���ظ�
void DelBook(struct BOOK* HEAD);//ɾ��ͼ�飨��Ż�������
//��������



int main(void)
{
	head = (struct BOOK*)malloc(sizeof(struct BOOK));
	head->next = NULL;
	/*JM();
	if (ch == '1')
	{
		CL();
	}
	else if (ch == '2')
	{
		FileRead(head);
		DelRe(head);
	}
	else if (ch == '6')
	{
		return 0;
	}*/
	FileRead(head);
	DelBook(head);
	output(head);
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
	gotoxy(80, 11); printf("*********ͼ�����ϵͳ*********");
	gotoxy(80, 13); printf("     |  1.ͼ����Ϣ¼��  |");
	gotoxy(80, 15); printf("     |  2.ͼ����Ϣ��ѯ  |");
	gotoxy(80, 17); printf("     |  3.ͼ����Ϣɾ��  |");
	gotoxy(80, 19); printf("     |  4.ͼ����Ϣ�޸�  |");
	gotoxy(80, 21); printf("     |  5.ͼ����Ϣ����  |");
	gotoxy(80, 23); printf("     |  6.�˳�����     |");
	gotoxy(86, 25); printf("������ţ�ѡ����");
	ch = getch();
	system("cls");
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
	gotoxy(75, 32);	printf("                ����y���棡");
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
	gotoxy(80, 32);	printf("        ����y���棡");
}

void DelJM()
{
	system("cls");
	gotoxy(80, 11); printf("*********ͼ�����ϵͳ*********");
	gotoxy(80, 13); printf("     |  1.ɾ�����ظ���Ϣ  |");
	gotoxy(80, 15); printf("     |  2.��ͼ����ɾ��  |");
	gotoxy(80, 17); printf("     |  3.��ͼ����ɾ��  |");
	gotoxy(80, 19); printf("     |  4.��ͼ����ɾ��  |");
	gotoxy(80, 21); printf("     |  5.��ͼ����ɾ��  |");
	gotoxy(80, 23); printf("     |  6.����ϵͳ������  |");
	gotoxy(86, 25); printf(" ������ţ�ѡ����");
}


void CL()//��������
{
	p = (struct BOOK*)malloc(sizeof(struct BOOK));
	p->next = NULL;
loop:
	{
		struct BOOK* s = (struct BOOK*)malloc(sizeof(struct BOOK));
		gotoxy(80, 11); printf("������ͼ���ţ�С��10λ����");
		scanf("%s", s->bianhao);
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
		FileSave();

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
	gotoxy(33, 6); printf("-----------------------------------------------------------------------------------------------------------------\n");
	gotoxy(40, 7); printf("ͼ����        ����         ����         ͼ�����         ���淽         ��������         ͼ��۸�\n");
	gotoxy(33, 8); printf("-----------------------------------------------------------------------------------------------------------------\n");
	while (p->next != NULL)
	{
		gotoxy(40, 9 + t); printf("%s", p->next->bianhao);
		gotoxy(55, 9 + t); printf("%s", p->next->bookname);
		gotoxy(69, 9 + t); printf("%s", p->next->writer);
		gotoxy(82, 9 + t); printf("%s", p->next->leibie);
		gotoxy(99, 9 + t); printf("%s", p->next->chubanfang);
		gotoxy(114, 9 + t); printf("%s", p->next->data);
		gotoxy(131, 9 + t); printf("%g\n", p->next->price);
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
		fprintf(fp, "%s %s %s %s %s %s %g\n", p->bianhao, p->bookname, p->writer, p->leibie, p->chubanfang, p->data, p->price);
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
		fscanf(fp, "%s %s %s %s %s %s %f\n", s->bianhao, s->bookname, s->writer, s->leibie, s->chubanfang, s->data, &s->price);
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

void DelRe(struct BOOK* HEAD)
{
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	struct BOOK* q1 = (struct BOOK*)malloc(sizeof(struct BOOK));
	struct BOOK* q2 = (struct BOOK*)malloc(sizeof(struct BOOK));
	if (HEAD->next != NULL)
	{
		q = HEAD->next;
		while (q->next != NULL)
		{
			q1 = q;
			q2 = q->next;
			while (q2->next != NULL)
			{
				if (strcmp(q->bianhao,q2->bianhao)==0)
				{
					q1->next = q2->next;
					continue;
				}
				else
				{
					q1 = q1->next;
				}
				q2 = q2->next;
			}
			if (strcmp(q->bianhao,q2->bianhao)==0)
			{
				q1->next = NULL;
			}
			q = q->next;
		}
	}
	output(head);
	/*FILE* fp = fopen("bookinformation.txt", "wt");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return 0;
	}
	for (int i = 0; i < a; i++)
	{
		fprintf(fp, "%s %s %s %s %s %s %g\n", q->bianhao, q->bookname, q->writer, q->leibie, q->chubanfang, q->data, q->price);
		q = q->next;
	}
	fclose(fp);
	*/
}

void DelBook(struct BOOK* HEAD)
{
	char ch[50];
	struct BOOK* q1 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q1->next = NULL;
	struct BOOK* q2 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q2->next = NULL;
	q1 = HEAD;
	gotoxy(75, 20); printf("������Ҫɾ����ͼ��ı�Ż�������");
	scanf("%s", ch);
	while (q1->next != NULL)
	{
		q2 = q1->next;
		if (q2->next!=NULL && (strcmp(ch, q2->bianhao) == 0 || strcmp(ch, q2->bookname) == 0))
		{
			q1->next = q2->next;
			q2 = q2->next;
			continue;
		}
		else if (q2->next == NULL && (strcmp(ch, q2->bianhao) == 0 || strcmp(ch, q2->bookname) == 0))
		{
			q1->next = NULL;
			break;
		}
		q1 = q1->next;
	}
}