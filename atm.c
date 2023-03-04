#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
char ch[16] = { "0123456789123456" };
void menu();
int deposit();
int GetCash();
int Transf();
void Checkmoney();
int checkPass();
void modiPass();
void Exit();
int i, n;
int main()
{
	int x;
	while (1)
	{
		checkPass();
		menu();
		while (1)
		{
			printf("\n请选择业务:");
			while (1)
			{
				scanf("%d", &x);
				if (x > 6 || x < 0)
				{
					printf("\n输入有误，请重新输入:");
				}
				else break;
			}
			switch (x)
			{
			case 1: deposit();
				break;
			case 2: GetCash();
				break;
			case 3: Transf();
				break;
			case 4: Checkmoney();
				break;
			case 5: modiPass();
				break;
			case 6: Exit();
				x = 6;
				break;
			default: break;
			}
			if (x == 6)
				break;
		}
	}
	return(0);
}
void menu()
{
	system("cls");
	printf("\t\t  Please Select Service\n\n");
	printf("\n\n\t\t\t**电子现金**\n\n");
	printf("\t\t1.存款业务      2.取款业务\n\n");
	printf("\t\t3.转账业务      4.查询业务\n\n");
	printf("\t\t5.修改密码      6.退卡\n\n");
}
int deposit()
{
	int m;
	printf("请输入您的存入金额\n");
	scanf("%d", &m);
	printf("成功存入 %d 元\n", m);
	i += m;
	return(i);
}
int GetCash()
{
	int n;
	if (i <= 0)
	{
		printf("余额不足\n");
		return(i);
	}
	printf("请输入您的取出金额\n");
	while (1)
	{
		scanf("%d", &n);
		if (n > i)
		{
			printf("请输入少于%d 元\n", i);
		}
		else
			break;
	}
	printf("成功取出 %d 元\n", n);
	i -= n;
	return(i);
}
int Transf()
{
	int		n;
	long int	number;
	if (i <= 0)
	{
		printf("余额不足\n");
		return(i);
	}
	printf("请输入您要转帐的银行卡号\n");
	scanf("%ld", &number);
	printf("请输入您的转出金额\n");
	while (1)
	{
		scanf("%d", &n);
		if (n > i)
		{
			printf("请输入少于%d 元\n", i);
		}
		else
			break;
	}
	printf("成功向%ld 账号转账 %d 元\n", number, n);
	i -= n;
	return(i);
}
void Checkmoney()
{
	if (i <= 0)
		printf("您的账户余额: 0 元\n");
	else
		printf("您的账户余额: %d 元\n", i);
}
int checkPass()
{
	int a;
	system("cls");
	char m[7];
	printf("\n\t\t\t\t\t\t欢迎来到广软银行\n");
	printf("\n\n\n");
	printf("请输入您的银行卡号\n");
	scanf("%d", &a);
	printf("请输入密码:\n");
	printf("Please input your Press Enter\n\n");
	while (1)
	{
		for (n = 0; n < 6; n++)
		{
			m[n] = _getch();
			printf("*");
		}
		if (strncmp(ch, m, 6) == 0)
		{
			printf("\n\n\t\t    正在进行ID认证，请稍等");
			printf(".");
			Sleep(400);
			printf(".");
			Sleep(400);
			printf(".");
			Sleep(400);
			printf(".");
			printf("\n\n\t\t     登录成功.....\n");
			break;
		}
		puts("\n密码错误，请重新输入密码:\n");
	}
	return(0);
}
void modiPass()
{
	char mi[7];
	printf("请输入原来的密码:\n");
	while (1)
	{
		for (n = 0; n < 6; n++)
		{
			mi[n] = _getch();
			printf("*");
		}
		printf("\n");
		if (strncmp(mi, ch, 6) == 0)
		{
			puts("请输入新的密码:\n");
			for (n = 0; n < 6; n++)
			{
				ch[n] = _getch();
				printf("*");
			}
			printf("\n");
			if (strcmp(mi, ch) != 0)
			{
				printf("密码修改成功！\n");
				break;
			}
			else
				printf("密码修改失败(新密码与旧密码相同)，请重新修改.\n请输入原来的密码:\n");
		}
		else
			printf("密码错误，请重新输入:\n");
	}
}
void Exit()
{
	printf("交易结束，请取回您的卡\n");
	Sleep(1000);
}
