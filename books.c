#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
char ch, c, h;//选择
struct BOOK
{
	char bianhao[11];//图书编号
	char bookname[50];//书名
	char writer[50];//作者
	char leibie[20];//图书类型
	char chubanfang[50];//出版方
	char data[11];//出版日期
	float price;//价格
	int num;//数量
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
void DelWriter(struct BOOK* HEAD);//删除作者
void DelBook(struct BOOK* HEAD);//删除图书（编号或书名）
void PX_b(struct BOOK* HEAD);//编号排序
void PX_p(struct BOOK* HEAD);//价格排序
void Check();//图书查询
void Change();//图书信息修改
int FRN();//判断是否文件为空
void menu();//主菜单
void menu5();//选项5复菜单
void menu3();//选项3复菜单
int ReCheck(char str[]);//判断输入编号是否重复
void FileReadAdmin(struct admin*head);//用户信息读取
void loginJM();//登陆界面
void registerJM();//注册界面
void SaveAdmin(struct admin* s);//保存用户信息
void menulog();//注册和登陆菜单
void registermenu(); //注册功能
void loginmenu();//登陆功能
void menulogJM();//注册和登陆菜单选择界面
struct admin* CreatAdmin();//创建保存一个用户
void welcome();//欢迎使用
void output_writer();//输出作者统计结果
void output_type();//输出类型统计结果


void FileSaveCheck(struct admin*s);//用户注册重复检查
void usermenu();//用户菜单
void userJM();//用户菜单界面
void CheckBor();//用户查询借阅功能
void attention();//注意提示框

//主函数：

int main(void)
{	
	menulog();
	return 0;
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
	printf("*请最大化使用*");
	gotoxy(80, 11); printf("*********图书管理系统*********");
	gotoxy(80, 13); printf("     |  1.图书信息录入  |");
	gotoxy(80, 15); printf("     |  2.图书信息查询  |");
	gotoxy(80, 17); printf("     |  3.图书信息删除  |");
	gotoxy(80, 19); printf("     |  4.图书信息修改  |");
	gotoxy(80, 21); printf("     |  5.图书信息总览  |");
	gotoxy(80, 23); printf("     |  6.退出程序      |");
	gotoxy(80, 25); printf("     |  7.注销用户      |");
	gotoxy(86, 27); printf("输入序号，选择功能");
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
	gotoxy(75, 32);	printf("      输入y继续录入信息，输入n结束录入！");
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
	//system("cls");
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
	gotoxy(80, 13); printf("     |  1.删除某作者图书  |");
	gotoxy(80, 15); printf("     |  2.编号或书名删除  |");
	gotoxy(80, 17); printf("     |  3.返回系统主界面  |");
	gotoxy(86, 25); printf(" 输入序号，选择功能");
}

void PXJM()
{
	system("cls");
	gotoxy(80, 11); printf("*********图书管理系统*********");
	gotoxy(80, 13); printf("     |  1.按图书编号排序  |");
	gotoxy(80, 15); printf("     |  2.按图书价格排序  |");
	gotoxy(80, 17); printf("     |  3.按作者统计图书  |");
	gotoxy(80, 19); printf("     |  4.按类型统计图书  |");
	gotoxy(80, 21); printf("     |  5.返回系统主界面  |");
	gotoxy(86, 23); printf(" 输入序号，选择功能");
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
		loop1:scanf("%s", s->bianhao);
		if (ReCheck(s->bianhao) == -1)
		{
			system("cls");
			gotoxy(80, 11); printf("输入的编号重复！请重新输入编号：");
			goto loop1;
		}
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
			gotoxy(80, 25); printf("请输入图书数量：");
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
			//文件存储
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
				gotoxy(90, 25); printf("修改未保存！");
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
	gotoxy(40, 7); printf("图书编号        书名         作者         图书类别         出版方         出版日期         图书价格         图书数量\n");
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
			printf("打开文件失败！\n");
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
		printf("文件打开失败！\n");
		return 0;
	}
	struct BOOK* p = (struct BOOK*)malloc(sizeof(struct BOOK));
	p->next = NULL;
	while (!feof(fp))//判断是否读到文件尾
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
	int a = 0;//删除后链表长度计数器
	char ch[50];
	struct BOOK* q1 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q1->next = NULL;
	struct BOOK* q2 = (struct BOOK*)malloc(sizeof(struct BOOK));
	q2->next = NULL;
	q1 = HEAD;
	gotoxy(75, 20); printf("请输入要删除的图书的作者：");
	scanf("%s", ch);

	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q = HEAD;
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->writer) == 0)
		{
			system("cls");
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("图书编号        书名         作者         图书类别         出版方         出版日期         图书价格         图书数量\n");
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
				printf("打开文件失败！\n");
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
			gotoxy(83, 22); printf("修改未保存！");
			gotoxy(83, 25); printf("按任意键返回删除菜单！");
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
		gotoxy(80, 22); printf("没有找到此作者！！！");
		Sleep(1000);
	}
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
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q = HEAD;
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->bianhao) == 0 || strcmp(ch, q->next->bookname) == 0 )
		{
			system("cls");
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("图书编号        书名         作者         图书类别         出版方         出版日期         图书价格         图书数量\n");
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
				printf("打开文件失败！\n");
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
			gotoxy(83, 22); printf("修改未保存！");
			gotoxy(83, 25); printf("按任意键返回删除菜单！");
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
		fprintf(fp, "%s %s %s %s %s %s %g %d\n", q1->bianhao, q1->bookname, q1->writer, q1->leibie, q1->chubanfang, q1->data, q1->price, q1 ->num);
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
	gotoxy(80, 15); printf("请输入需要查询图书的编号或书名：");
	scanf("%s", ch);
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->bianhao) == 0 || strcmp(ch, q->next->bookname) == 0)
		{
			system("cls");
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("图书编号        书名         作者         图书类别         出版方         出版日期         图书价格         图书数量\n");
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
			gotoxy(80, 25); printf("请重新输入图书数量：");
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
			fprintf(fp, "%s %s %s %s %s %s %g %d\n", q->bianhao, q->bookname, q->writer, q->leibie, q->chubanfang, q->data, q->price, q ->num);
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
	head->next = NULL;
	FileRead(head);
	struct BOOK* q = (struct BOOK*)malloc(sizeof(struct BOOK));
	q = head;
	char ch[50];
	gotoxy(80, 15); printf("请输入需要查询图书的编号或书名或作者：");
	gotoxy(80, 17); scanf("%s", ch);
	system("cls");
	int t = 0;
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->bianhao) == 0 || strcmp(ch, q->next->bookname) == 0 || strcmp(ch, q->next->writer) == 0)
		{
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("图书编号        书名         作者         图书类别         出版方         出版日期         图书价格         图书数量\n");
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
		gotoxy(80, 25); printf("按任意键返回主界面！");
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
			gotoxy(80, 23); printf("还没添加一本图书信息呢，先去添加一本吧！");
		}
		gotoxy(80, 25); printf("按任意键返回主界面！");
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
			gotoxy(80, 23); printf("还没添加一本图书信息呢，先去添加一本吧！");
		}
		gotoxy(80, 25); printf("按任意键返回主界面！");
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
			gotoxy(60, 5); printf("按任意键返回浏览界面！");
			getch();
			menu5();
			break;
		case '2':
			FileRead(head);
			PX_p(head);
			output(head);
			gotoxy(60, 5); printf("按任意键返回浏览界面！");
			getch();
			menu5();
			break;
		case '3':output_writer(); gotoxy(60, 5); printf("按任意键返回浏览界面！"); getch(); menu5(); break;
		case '4':output_type(); gotoxy(60, 5); printf("按任意键返回浏览界面！"); getch(); menu5(); break;
		case '5':
			menu();
			break;
		default:menu5();
		}
	}
	else
	{
		system("cls");
		gotoxy(80, 23); printf("还没添加一本图书信息呢，先去添加一本吧！");
		gotoxy(80, 25); printf("按任意键返回主界面！");
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
			gotoxy(80, 23); printf("按任意键返回删除菜单！");
			getch();
			menu3();
			break;
		case '2':
			system("cls");
			FileRead(head);
			DelBook(head);
			gotoxy(80, 24); printf("按任意键返回删除菜单！");
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
		gotoxy(80, 23); printf("还没添加一本图书信息呢，先去添加一本吧！");
		gotoxy(80, 25); printf("按任意键返回主界面！");
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
	gotoxy(80, 16); printf("**********图书管理系统登录**********\n");
	gotoxy(80, 17); printf("*                                  *\n");
	gotoxy(80, 18); printf("*   帐号：                         *\n");
	gotoxy(80, 19); printf("*                                  *\n");
	gotoxy(80, 20); printf("*   密码：                         *\n");
	gotoxy(80, 21); printf("*                                  *\n");
	gotoxy(80, 22); printf("************************************\n");
}

void registerJM()
{
	system("cls");
	gotoxy(80,16); printf("**********图书管理系统注册**********\n");
	gotoxy(80, 17); printf(" *                                *\n");
	gotoxy(80, 18); printf(" *   帐号：                       *\n");
	gotoxy(80, 19); printf(" *                                *\n");
	gotoxy(80, 20); printf(" *   密码：                       *\n");
	gotoxy(80, 21); printf(" *                                *\n");
	gotoxy(80, 22); printf(" *   手机号：                     *\n");
	gotoxy(80, 23); printf(" *                                *\n");
	gotoxy(80, 24); printf(" *------------再次输入------------*\n");
	gotoxy(80, 25); printf(" *                                *\n");
	gotoxy(80, 26); printf(" *   帐号：                       *\n");
	gotoxy(80, 27); printf(" *                                *\n");
	gotoxy(80, 28); printf(" *   密码：                       *\n");
	gotoxy(80, 29); printf(" *                                *\n");
	gotoxy(80, 30); printf(" *   手机号：                     *\n");
	gotoxy(80, 31); printf(" *                                *\n");
	gotoxy(80, 32); printf("************************************\n");
}


void output_writer()
{
	system("cls");
	gotoxy(75, 9); printf("--------------------------------------------------\n");
	gotoxy(75, 10); printf("           作者             个人作品数量             \n");
	gotoxy(75, 11); printf("--------------------------------------------------\n");
	struct BOOK* head = (struct BOOK*)malloc(sizeof(struct BOOK));
	struct BOOK* p = (struct BOOK*)malloc(sizeof(struct BOOK));
	head->next = NULL;
	FileRead(head);
	if (FRN() == -1)
	{
		gotoxy(85, 15); printf("还没有添加图书呢，先去添加一本吧！"); Sleep(1000); menu();
	}
	p = head->next;
	int t = 0;//输出次数计数器
	int sum = 1;//统计数量计数器
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
	gotoxy(75, 10); printf("           类型               作品数量             \n");
	gotoxy(75, 11); printf("--------------------------------------------------\n");
	struct BOOK* head = (struct BOOK*)malloc(sizeof(struct BOOK));
	struct BOOK* p = (struct BOOK*)malloc(sizeof(struct BOOK));
	head->next = NULL;
	FileRead(head);
	if (FRN() == -1)
	{
		gotoxy(85, 15); printf("还没有添加图书呢，先去添加一本吧！"); Sleep(1000); menu();
	}
	p = head->next;
	int t = 0;//输出次数计数器
	int sum = 1;//统计数量计数器
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
			gotoxy(90, 19); printf("两次输入不一致，请重新输入！\n"); Sleep(1000);
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
		
		printf("打开文件失败！\n");
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
		gotoxy(80, 13); printf("还没注册管理员账号呢，先去注册一个吧！"); Sleep(1000);
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
		gotoxy(92, 19); printf("账号或密码错误！"); Sleep(1000); menulog();
	}
}
void FileReadAdmin(struct admin*head)
{
	FILE *fp = fopen("Admin.data", "rb");
	if (fp == NULL)
	{
		printf("打开文件失败！\n");
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
	printf("*请最大化使用*");
	gotoxy(80, 16); printf("********图书管理系统登陆********");
	gotoxy(80, 18); printf("     |  1.     注册         |");
	gotoxy(80, 20); printf("     |  2.     登陆         |");
	gotoxy(80, 22); printf("     |  3.    退出程序       |");
	gotoxy(86, 24); printf("输入序号，选择功能");
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
	gotoxy(80, 20); printf(" |         登陆成功          |\n");
	gotoxy(80, 22); printf(" |        o(*￣▽￣*)o       |\n");
	gotoxy(80, 24); printf(" |         欢迎使用          |\n");
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
				gotoxy(90, 19); printf("该用户名已被注册，请重新注册！\n"); Sleep(1000);
				registermenu();
			}
			p = p->next;
		}
	}
}

/*void userJM()
{
	system("cls");
	printf("*请最大化使用*");
	gotoxy(80, 11); printf("************图书借阅系统************");
	gotoxy(80, 13); printf("     |  1.图书信息查询与借阅  |");
	gotoxy(80, 15); printf("     |  2.图书信息总览       |");
	gotoxy(80, 17); printf("     |  3.我的借阅信息       |");
	gotoxy(80, 19); printf("     |  4.退出程序          |");
	gotoxy(80, 21); printf("     |  5.注销用户          |");
	gotoxy(80, 23); printf("       输入序号，选择功能");
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
	gotoxy(80, 16); printf("************注意*************\n");
	gotoxy(80, 18); printf("*                          *\n");
	gotoxy(80, 19); printf("*        是否借阅此书？      *\n");
	gotoxy(80, 20); printf("*    1.确定      2.取消     *\n");
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
	gotoxy(80, 15); printf("请输入需要查询图书的编号或书名或作者：");
	gotoxy(80, 17); scanf("%s", ch);
	system("cls");
	int t = 0;
	q = head;
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->bianhao) == 0 || strcmp(ch, q->next->bookname) == 0 || strcmp(ch, q->next->writer) == 0)
		{
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("图书编号        书名         作者         图书类别         出版方         出版日期         图书价格         图书数量\n");
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

	gotoxy(80, 15); printf("请输入需要借阅图书的编号：");
	gotoxy(80, 17); scanf("%s", ch);
	q = head;
	while (q->next != NULL)
	{
		if (strcmp(ch, q->next->bianhao) == 0 || strcmp(ch, q->next->bookname) == 0 || strcmp(ch, q->next->writer) == 0)
		{
			gotoxy(33, 6); printf("----------------------------------------------------------------------------------------------------------------------------------\n");
			gotoxy(40, 7); printf("图书编号        书名         作者         图书类别         出版方         出版日期         图书价格         图书数量\n");
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
		case '2':system("cls"); gotoxy(90, 19); printf("已取消借阅！\n"); Sleep(1000); usermenu();
		default: goto loop; break;
		}
	}
}

void FileSaveBor()
{
	FILE *fp = fopen("MyBor.txt", "wt");
	if (fp == NULL)
	{
		printf("打开文件失败！\n");
		return 0;
	}

}
*/