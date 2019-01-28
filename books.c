#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
char ch, c, h;//选择
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
void gotoxy(int x, int y);//光标移动
void JM();//界面
void DelJM();//删除功能界面
void Next();//输入y继续，输入其他键退出
void output(struct BOOK* head);//输出链表
void CL();//创建保存链表
void Save();//保存提示框
void Del();//删除提示框
void Succeed();//成功
void FileSave();//文件保存
void PXJM();//排序界面
void FileRead(struct BOOK* HEAD);//文件读取
void DelRe(struct BOOK* HEAD);//删除重复
void DelBook(struct BOOK* HEAD);//删除图书（编号或书名）
void PX_b(struct BOOK* HEAD);//编号排序
void PX_p(struct BOOK* HEAD);//价格排序
//void PX_n(struct BOOK* HEAD);//书名排序
void Check();//图书查询
void Change();//图书信息修改
int FRN();//判断是否文件为空
//主函数：

int main(void)
{
loop:
	head = (struct BOOK*)malloc(sizeof(struct BOOK));
	head->next = NULL;
	JM();
	if (ch == '1')
	{
		CL();
		system("cls");
		gotoxy(80, 11); printf("按任意键返回主界面！");
		getch();
		goto loop;
	}
	else if (ch == '2')
	{
		if (FRN() == 0)
		{
			Check();
		}
		else
		{
			system("cls");
			gotoxy(80, 23); printf("还没添加一本图书信息呢，先去添加一本吧！");
		}
		gotoxy(80, 25); printf("按任意键返回主界面！");
		getch();
		goto loop;
	}
	else if (ch == '3')
	{
		if (FRN() == 0)
		{
		loop1:
			DelJM();
			if (c == '1')
			{
			loop3:
				Del();
				h = getch();
				if (h == 'y' || h == 'Y')
				{
					FileRead(head);
					DelRe(head);
					Succeed();
					Sleep(1000);
					system("cls");
					gotoxy(80, 23); printf("按任意键返回主界面！");
					getch();
					goto loop;
				}
				else if (h == 'n' || h == 'N')
				{
					system("cls");
					gotoxy(85, 21); printf("修改未保存！");
					gotoxy(80, 23); printf("按任意键返回主界面！");
					getch();
					goto loop;
				}
				else
				{
					goto loop3;
				}
			}
			else if (c == '2')
			{
				system("cls");
				FileRead(head);
				DelBook(head);
				gotoxy(80, 24); printf("按任意键返回主界面！");
				getch();
				goto loop;
			}
			else if (c == '3')
			{
				goto loop;
			}
			else
			{
				goto loop1;
			}
		}
		else
		{
			system("cls");
			gotoxy(80, 23); printf("还没添加一本图书信息呢，先去添加一本吧！");
			gotoxy(80, 25); printf("按任意键返回主界面！");
			getch();
			goto loop;
		}
	}
	else if (ch == '4')
	{
		if (FRN() == 0)
		{
			Change();
		}
		else
		{
			system("cls");
			gotoxy(80, 23); printf("还没添加一本图书信息呢，先去添加一本吧！");
		}
		gotoxy(80, 25); printf("按任意键返回主界面！");
		getch();
		goto loop;
	}
	else if (ch == '5')
	{
		if (FRN() == 0)
		{
			char c;
		loop5:
			PXJM();
			c = getch();
			if (c == '1')
			{
				FileRead(head);
				PX_b(head);
				output(head);
				gotoxy(80, 25); printf("按任意键返回主界面！");
				getch();
				goto loop;
			}
			else if (c == '2')
			{
				FileRead(head);
				PX_p(head);
				output(head);
				gotoxy(80, 25); printf("按任意键返回主界面！");
				getch();
				goto loop;
			}
			else if (c == '3')
			{
				goto loop;
			}
			else
			{
				goto loop5;
			}
		}
		else
		{
			system("cls");
			gotoxy(80, 23); printf("还没添加一本图书信息呢，先去添加一本吧！");
			gotoxy(80, 25); printf("按任意键返回主界面！");
			getch();
			goto loop;
		}
	}
	else if (ch == '6')
	{
		exit(0);
	}
	else
	{
		goto loop;
	}
	return 0;
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



//自定义函数：

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}
void JM()
{
	system("cls");
	gotoxy(80, 11); printf("*********图书管理系统*********");
	gotoxy(80, 13); printf("     |  1.图书信息录入  |");
	gotoxy(80, 15); printf("     |  2.图书信息查询  |");
	gotoxy(80, 17); printf("     |  3.图书信息删除  |");
	gotoxy(80, 19); printf("     |  4.图书信息修改  |");
	gotoxy(80, 21); printf("     |  5.图书信息总览  |");
	gotoxy(80, 23); printf("     |  6.退出程序      |");
	gotoxy(86, 25); printf("输入序号，选择功能");
	ch = getch();
	system("cls");
}

void Next()
{
	printf("输入y继续，输入其他键退出");
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
	gotoxy(75, 32);	printf("                输入y保存！");
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
	gotoxy(80, 32);	printf("     输入y保存！输入n取消！");
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
	gotoxy(80, 32);	printf("     输入y保存！输入n取消！");
}

void DelJM()
{
	system("cls");
	gotoxy(80, 11); printf("*********图书管理系统*********");
	gotoxy(80, 13); printf("     |  1.删除其重复信息  |");
	gotoxy(80, 15); printf("     |  2.编号或书名删除  |");
	gotoxy(80, 17); printf("     |  3.返回系统主界面  |");
	gotoxy(86, 25); printf(" 输入序号，选择功能");
	c = getch();
}

void PXJM()
{
	system("cls");
	gotoxy(80, 11); printf("*********图书管理系统*********");
	gotoxy(80, 13); printf("     |  1.按图书编号排序  |");
	gotoxy(80, 15); printf("     |  2.按图书价格排序  |");
	gotoxy(80, 17); printf("     |  3.返回系统主界面  |");
	gotoxy(86, 19); printf(" 输入序号，选择功能");
}


void CL()//创建链表
{
	head->next = NULL;
	p = (struct BOOK*)malloc(sizeof(struct BOOK));
	p->next = NULL;
loop:
	{
		struct BOOK* s = (struct BOOK*)malloc(sizeof(struct BOOK));
		gotoxy(80, 11); printf("请输入图书编号（小于10位）：");
		scanf("%s", s->bianhao);
		gotoxy(80, 13); printf("请输入书名（小于25字）：");
		scanf("%s", s->bookname);
		gotoxy(80, 15); printf("请输入作者姓名（小于25字）：");
		scanf("%s", s->writer);
		gotoxy(80, 17); printf("请输入图书类别（小于10字）：");
		scanf("%s", s->leibie);
		gotoxy(80, 19); printf("请输入图书出版方（小于25字）：");
		scanf("%s", s->chubanfang);
		gotoxy(80, 21); printf("请输入图书出版日期（如2018.03.03）：");
		scanf("%s", s->data);
		gotoxy(80, 23); printf("请输入图书价格：");
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
		//文件存储
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
	gotoxy(40, 7); printf("图书编号        书名         作者         图书类别         出版方         出版日期         图书价格\n");
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
			printf("打开文件失败！\n");
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
		printf("文件打开失败！\n");
		return 0;
	}
	struct BOOK* p = (struct BOOK*)malloc(sizeof(struct BOOK));
	p->next = NULL;
	while (!feof(fp))//判断是否读到文件尾
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
	int a = 1;//删除后链表长度计数器
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
		printf("打开文件失败！\n");
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
	int a = 0;//删除后链表长度计数器
	char ch[50];
	struct BOOK* q1 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q1->next = NULL;
	struct BOOK* q2 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q2->next = NULL;
	q1 = HEAD;
	gotoxy(75, 20); printf("请输入要删除的图书的编号或书名：");
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
			printf("打开文件失败！\n");
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
		gotoxy(80, 22); printf("这本书还没有入库呢！！！");
	}
}

void PX_b(struct BOOK* HEAD)
{
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q = HEAD;
	int a = 0;//链表长度计数器
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
		printf("打开文件失败！\n");
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
	int a = 0;//链表长度计数器
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
		printf("打开文件失败！\n");
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
	gotoxy(80, 15); printf("请输入需要查询图书的编号或书名：");
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
			gotoxy(80, 11); printf("请重新输入图书编号（小于10位）：");
			scanf("%s", s->bianhao);
			gotoxy(80, 13); printf("请重新输入书名（小于25字）：");
			scanf("%s", s->bookname);
			gotoxy(80, 15); printf("请重新输入作者姓名（小于25字）：");
			scanf("%s", s->writer);
			gotoxy(80, 17); printf("请重新输入图书类别（小于10字）：");
			scanf("%s", s->leibie);
			gotoxy(80, 19); printf("请重新输入图书出版方（小于25字）：");
			scanf("%s", s->chubanfang);
			gotoxy(80, 21); printf("请重新输入图书出版日期（如2018.03.03）：");
			scanf("%s", s->data);
			gotoxy(80, 23); printf("请重新输入图书价格：");
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
				gotoxy(90, 25); printf("修改未保存！");
				Sleep(1000);
				system("cls");
			}
			else
			{
				gotoxy(80, 34); printf("请重新输入y或n！");
				goto loop;
			}
		}
		q = q->next;
	}
	if (t != 0)
	{
		q = head;
		int a = 0;//链表长度计数器
		while (q->next != NULL)
		{
			a++;
			q = q->next;
		}
		q = head->next;
		FILE* fp = fopen("bookinformation.txt", "wt");
		if (fp == NULL)
		{
			printf("打开文件失败！\n");
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
		gotoxy(80, 22); printf("这本书还没有入库呢！！！");
	}
}

void Check()
{
	system("cls");
	FileRead(head);
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q = head;
	char ch[50];
	gotoxy(80, 15); printf("请输入需要查询图书的编号或书名：");
	gotoxy(80, 17); scanf("%s", ch);
	int t = 0;
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->bianhao) == 0 || strcmp(ch, q->next->bookname) == 0)
		{
			t++;
			system("cls");
			gotoxy(33, 6); printf("-----------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("图书编号        书名         作者         图书类别         出版方         出版日期         图书价格\n");
			gotoxy(33, 8); printf("-----------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 9); printf("%s", q->next->bianhao);
			gotoxy(55, 9); printf("%s", q->next->bookname);
			gotoxy(69, 9); printf("%s", q->next->writer);
			gotoxy(82, 9); printf("%s", q->next->leibie);
			gotoxy(99, 9); printf("%s", q->next->chubanfang);
			gotoxy(114, 9); printf("%s", q->next->data);
			gotoxy(131, 9); printf("%g\n", q->next->price);
		}
		q = q->next;
	}
	if (t == 0)
	{
		system("cls");
		gotoxy(80, 21); printf("这本书还没有添加入库！！！");
	}
}

void Succeed()
{
	system("cls");
	gotoxy(80, 20); printf("---------------------------\n");
	gotoxy(80, 22); printf("|          成 功 !         |\n");
	gotoxy(80, 24); printf("---------------------------\n");
}