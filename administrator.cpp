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

void administrator(linkStudent inf_student,Course inf_course[],Class inf_class[],
                   linklocate_course lo_course,linklocate_class lo_class,int Max1,int Max2)
{
    int operation=1,flag;
    while(operation)
    {
        //system("cls");
        gotoxy(40,7);
        printf ("Administrator\n");
        printf ("\t\t----------------------------------------------------------------\n");
        printf ("\t\t\t请根据菜单操作序号选择您接下来的操作(输入操作序号):\n");
        printf ("\t\t\t1.为管理员或教师或学生注册账号\n");
        printf ("\t\t\t2.录入信息\n");
        printf ("\t\t\t3.查看信息\n");
        printf ("\t\t\t4.修改信息\n");
        printf ("\t\t\t5.退出程序\n");
        printf ("\t\t----------------------------------------------------------------\n");
        flag=0;
        gotoxy(75,9);
        scanf ("%d",&flag);
        switch (flag)
        {
        case 1:
            system("cls");
            Register();
            break;
        case 2:
            system("cls");
            input(inf_student,inf_course,inf_class,lo_course,lo_class,Max1,Max2);
            break;
        case 3:
            system("cls");
            view(inf_student,inf_course,inf_class,lo_course,lo_class);
            break;
        case 4:
            system("cls");
            modify(inf_student,inf_course,inf_class,lo_course,lo_class,Max1,Max2);
            break;
        case 5:
            system("cls");
            gotoxy(40,7);
            printf ("Administrator\n");
            printf ("\t\t----------------------------------------------------------------\n\n\n\n");
            printf ("\t\t----------------------------------------------------------------\n");
            gotoxy(43,10);
            printf ("Goodbye");
            output_course(inf_course,lo_course);
            output_class(inf_class,lo_class);
            output_stu(inf_student);
            Sleep(2000);
            system("cls");
            exit(0);
            break;
        default:
            system("cls");
            gotoxy(40,7);
            printf ("Administrator\n");
            printf ("\t\t----------------------------------------------------------------\n\n\n\n");
            printf ("\t\t----------------------------------------------------------------\n");
            gotoxy(35,10);
            printf ("输入序号错误,请重新输入\n");
            Sleep(2000);
        }
        system("cls");
    }
};
