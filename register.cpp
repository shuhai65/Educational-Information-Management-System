#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include"function.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
using namespace std;

void Register()
{
    system("cls");
    FILE *fp,*fq;
    char USERNAME[20];
    char PASSWORD[20];
    gotoxy(45,7);
    printf ("注册账号\n");
    printf ("\t\t----------------------------------------------------------------\n");
    printf ("\t\t\t请选择注册账号的身份(请输入编号):\n\t\t\t1.管理员\n\t\t\t2.教师\n\t\t\t3.学生(提示：学生账号与学生学号相同)\n\t\t\t4.退出注册界面\n");
    printf ("\t\t----------------------------------------------------------------\n");
    int flag=0;
    gotoxy(57,9);
    scanf ("%d",&flag);
    switch (flag)
    {
    case 1:
        fp=fopen("name_M.txt","a+");
        fq=fopen("pass_M.txt","a+");
        break;
    case 2:
        fp=fopen("name_T.txt","a+");
        fq=fopen("pass_T.txt","a+");
        break;
    case 3:
        fp=fopen("name_S.txt","a+");
        fq=fopen("pass_S.txt","a+");
        break;
    case 4:
        return;
    default:
        system("cls");
        gotoxy(45,7);
        printf ("注册账号\n");
        printf ("\t\t----------------------------------------------------------------\n");
        printf("\t\t\t\t  输入编号错误,将返回主界面\n");
        printf ("\t\t----------------------------------------------------------------\n");
        Sleep(2000);
        return;
    }
    system("cls");
    gotoxy(45,7);
    printf ("注册账号\n");
    printf ("\t\t----------------------------------------------------------------\n\n");
    printf ("\t\t\t请输入用户名:\n");
    printf ("\t\t\t请输入密码:\n\n");
    printf ("\t\t----------------------------------------------------------------\n");
    gotoxy(37,10);
    scanf("%s",USERNAME);
    fputs(USERNAME,fp);
    fputc('\n',fp);
    gotoxy(35,11);
    get_password(PASSWORD,20);
    fputs(PASSWORD,fq);
    fputc('\n',fq);
    fclose(fp);
    fclose(fq);
    system("cls");
    gotoxy(45,7);
    printf ("注册账号\n");
    printf ("\t\t----------------------------------------------------------------\n\n");
    gotoxy(45,10);
    printf("注册成功\n\n");
    printf ("\t\t----------------------------------------------------------------\n");
    Sleep(3000);
};
