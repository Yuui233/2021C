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
			printf("\n��ѡ��ҵ��:");
			while (1)
			{
				scanf("%d", &x);
				if (x > 6 || x < 0)
				{
					printf("\n������������������:");
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
	printf("\n\n\t\t\t**�����ֽ�**\n\n");
	printf("\t\t1.���ҵ��      2.ȡ��ҵ��\n\n");
	printf("\t\t3.ת��ҵ��      4.��ѯҵ��\n\n");
	printf("\t\t5.�޸�����      6.�˿�\n\n");
}
int deposit()
{
	int m;
	printf("���������Ĵ�����\n");
	scanf("%d", &m);
	printf("�ɹ����� %d Ԫ\n", m);
	i += m;
	return(i);
}
int GetCash()
{
	int n;
	if (i <= 0)
	{
		printf("����\n");
		return(i);
	}
	printf("����������ȡ�����\n");
	while (1)
	{
		scanf("%d", &n);
		if (n > i)
		{
			printf("����������%d Ԫ\n", i);
		}
		else
			break;
	}
	printf("�ɹ�ȡ�� %d Ԫ\n", n);
	i -= n;
	return(i);
}
int Transf()
{
	int		n;
	long int	number;
	if (i <= 0)
	{
		printf("����\n");
		return(i);
	}
	printf("��������Ҫת�ʵ����п���\n");
	scanf("%ld", &number);
	printf("����������ת�����\n");
	while (1)
	{
		scanf("%d", &n);
		if (n > i)
		{
			printf("����������%d Ԫ\n", i);
		}
		else
			break;
	}
	printf("�ɹ���%ld �˺�ת�� %d Ԫ\n", number, n);
	i -= n;
	return(i);
}
void Checkmoney()
{
	if (i <= 0)
		printf("�����˻����: 0 Ԫ\n");
	else
		printf("�����˻����: %d Ԫ\n", i);
}
int checkPass()
{
	int a;
	system("cls");
	char m[7];
	printf("\n\t\t\t\t\t\t��ӭ������������\n");
	printf("\n\n\n");
	printf("�������������п���\n");
	scanf("%d", &a);
	printf("����������:\n");
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
			printf("\n\n\t\t    ���ڽ���ID��֤�����Ե�");
			printf(".");
			Sleep(400);
			printf(".");
			Sleep(400);
			printf(".");
			Sleep(400);
			printf(".");
			printf("\n\n\t\t     ��¼�ɹ�.....\n");
			break;
		}
		puts("\n���������������������:\n");
	}
	return(0);
}
void modiPass()
{
	char mi[7];
	printf("������ԭ��������:\n");
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
			puts("�������µ�����:\n");
			for (n = 0; n < 6; n++)
			{
				ch[n] = _getch();
				printf("*");
			}
			printf("\n");
			if (strcmp(mi, ch) != 0)
			{
				printf("�����޸ĳɹ���\n");
				break;
			}
			else
				printf("�����޸�ʧ��(���������������ͬ)���������޸�.\n������ԭ��������:\n");
		}
		else
			printf("�����������������:\n");
	}
}
void Exit()
{
	printf("���׽�������ȡ�����Ŀ�\n");
	Sleep(1000);
}
