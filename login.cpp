#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>

void get_password(char *pswd, int maxlen)
{
    int index = 0;
    char buff = '\0';

    while ((buff = getch()) != '\r')
    {
        if (buff == '\b' && index != 0)
        {
            index--;
            printf("\b \b");
        }
        else if (index < maxlen - 1 && buff != '\b')
        {
            pswd[index++] = buff;
            putchar('*');
        }
    }
    pswd[index] = '\0';
};

int login(char name[])
{
    int flag;
    int j=5;
    char username[20],password[20];
    while (j--)
    {
        gotoxy(32,6);
        printf("****************用户登录****************");
        gotoxy(32,7);
        printf ("请输入帐号:");
        scanf("%s",username);
        gotoxy(32,8);
        printf("请输入密码:");
        get_password(password,20);
//        printf("password=%s\n",password);
        if ((flag=if_loginuser(username,password))>0)
        {
            if(flag==3)
            {
                strcpy(name,username);
            }
            gotoxy (32,9);
            printf ("****************登录成功****************\n");
//            Sleep(2000);
            return flag;
        }
        else
        {
            gotoxy (32,9);
            printf ("*******账号或密码错误,请重新输入********");
            Sleep(1000);
            system("cls");
        }

    }
    printf("由于您多次登录失败，进程自动结束");
    exit(1);
};

