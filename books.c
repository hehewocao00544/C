#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
char ch, c, h;//ѡ��
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
void DelRe(struct BOOK* HEAD);//ɾ���ظ�
void DelBook(struct BOOK* HEAD);//ɾ��ͼ�飨��Ż�������
void PX_b(struct BOOK* HEAD);//�������
void PX_p(struct BOOK* HEAD);//�۸�����
void Check();//ͼ���ѯ
void Change();//ͼ����Ϣ�޸�
int FRN();//�ж��Ƿ��ļ�Ϊ��
void menu();//���˵�
void menu5();//ѡ��5���˵�
void menu3();//ѡ��3���˵�
//��������

int main(void)
{	
	menu();
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
	gotoxy(80, 11); printf("*********ͼ�����ϵͳ*********");
	gotoxy(80, 13); printf("     |  1.ͼ����Ϣ¼��  |");
	gotoxy(80, 15); printf("     |  2.ͼ����Ϣ��ѯ  |");
	gotoxy(80, 17); printf("     |  3.ͼ����Ϣɾ��  |");
	gotoxy(80, 19); printf("     |  4.ͼ����Ϣ�޸�  |");
	gotoxy(80, 21); printf("     |  5.ͼ����Ϣ����  |");
	gotoxy(80, 23); printf("     |  6.�˳�����      |");
	gotoxy(86, 25); printf("������ţ�ѡ����");
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
	system("cls");
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
	gotoxy(80, 13); printf("     |  1.ɾ�����ظ���Ϣ  |");
	gotoxy(80, 15); printf("     |  2.��Ż�����ɾ��  |");
	gotoxy(80, 17); printf("     |  3.����ϵͳ������  |");
	gotoxy(86, 25); printf(" ������ţ�ѡ����");
	//c = getch();
}

void PXJM()
{
	system("cls");
	gotoxy(80, 11); printf("*********ͼ�����ϵͳ*********");
	gotoxy(80, 13); printf("     |  1.��ͼ��������  |");
	gotoxy(80, 15); printf("     |  2.��ͼ��۸�����  |");
	gotoxy(80, 17); printf("     |  3.����ϵͳ������  |");
	gotoxy(86, 19); printf(" ������ţ�ѡ����");
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
		Succeed();
		Sleep(1000);
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
	int a = 1;//ɾ���������ȼ�����
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q->next = NULL;
	struct BOOK* q1 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q1->next = NULL;
	struct BOOK* q2 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q2->next = NULL;
	if (HEAD->next != NULL)
	{
		q = HEAD->next;
	}
	while (q->next->next != NULL)
	{
		a++;
		q1 = q;
		q2 = q1;
		while (q1->next != NULL)
		{
			q2 = q1->next;
			if (q2->next != NULL&&strcmp(q2->bianhao, q->bianhao) == 0)
			{
				q1->next = q2->next;
				q2 = q2->next;
				continue;
			}
			else if (q2->next == NULL&&strcmp(q2->bianhao, q->bianhao) == 0)
			{
				q1->next = NULL;
				break;
			}
			q1 = q1->next;
		}
		q = q->next;
	}
	if (strcmp(q2->bianhao, q->bianhao) == 0)
	{
		q->next = NULL;
	}
	q = HEAD->next;
	FILE* fp = fopen("bookinformation.txt", "wt");
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
		q1 = HEAD->next;
		FILE* fp = fopen("bookinformation.txt", "wt");
		if (fp == NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
			return 0;
		}
		for (int i = 0; i < a; i++)
		{
			fprintf(fp, "%s %s %s %s %s %s %g\n", q1->bianhao, q1->bookname, q1->writer, q1->leibie, q1->chubanfang, q1->data, q1->price);
			q1 = q1->next;
		}
		fclose(fp);
		Succeed();
		Sleep(1000);
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
		fprintf(fp, "%s %s %s %s %s %s %g\n", q1->bianhao, q1->bookname, q1->writer, q1->leibie, q1->chubanfang, q1->data, q1->price);
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
		fprintf(fp, "%s %s %s %s %s %s %g\n", q1->bianhao, q1->bookname, q1->writer, q1->leibie, q1->chubanfang, q1->data, q1->price);
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
			t++;
			struct BOOK* q1 = (struct BOOK*)malloc(sizeof(struct BOOK));
			q1 = q->next;
			system("cls");
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
			fprintf(fp, "%s %s %s %s %s %s %g\n", q->bianhao, q->bookname, q->writer, q->leibie, q->chubanfang, q->data, q->price);
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
			gotoxy(33, 6); printf("-----------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("ͼ����        ����         ����         ͼ�����         ���淽         ��������         ͼ��۸�\n");
			gotoxy(33, 8); printf("-----------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 9 + t); printf("%s", q->next->bianhao);
			gotoxy(55, 9 + t); printf("%s", q->next->bookname);
			gotoxy(69, 9 + t); printf("%s", q->next->writer);
			gotoxy(82, 9 + t); printf("%s", q->next->leibie);
			gotoxy(99, 9 + t); printf("%s", q->next->chubanfang);
			gotoxy(114, 9 + t); printf("%s", q->next->data);
			gotoxy(131, 9 + t); printf("%g\n", q->next->price);
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
		CL();
		system("cls");
		gotoxy(80, 11); printf("����������������棡");
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
			gotoxy(80, 25); printf("�����������������棡");
			getch();
			menu5();
			break;
		case '2':
			FileRead(head);
			PX_p(head);
			output(head);
			gotoxy(80, 25);  printf("�����������������棡");
			getch();
			menu5();
			break;
		case '3':
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
			Del();
		loop1:
			h = getch();
			if (h == 'y' || h == 'Y')
			{
				FileRead(head);
				DelRe(head);
				Succeed();
				Sleep(1000);
				system("cls");
				gotoxy(80, 23); printf("�����������ɾ���˵���");
				getch();
				menu3();
			}
			else if (h == 'n' || h == 'N')
			{
				system("cls");
				gotoxy(85, 21); printf("�޸�δ���棡");
				gotoxy(80, 23); printf("�����������ɾ���˵���");
				getch();
				menu3();
			}
			else
			{
				goto loop1;
			}
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