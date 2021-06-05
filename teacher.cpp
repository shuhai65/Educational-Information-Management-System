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
void teacher(linkStudent inf_student,Course inf_course[],Class inf_class[],linklocate_course lo_course,linklocate_class lo_class,int Max1,int Max2)
{
    int operation=1,flag,num1=1,flag1=0;
    while (operation)
    {
        gotoxy(40,7);
        printf ("Teacher\n");
        printf ("\t\t----------------------------------------------------------------\n");
        printf ("\t\t\t请根据菜单操作序号选择您接下来的操作(输入操作序号):\n");
        printf ("\t\t\t1.录入信息\n");
        printf ("\t\t\t2.查看信息\n");
        printf ("\t\t\t3.修改成绩\n");
        printf ("\t\t\t4.退出程序\n");
        printf ("\t\t----------------------------------------------------------------\n");
        flag=0;
        gotoxy(75,9);
        scanf("%d",&flag);
        switch (flag)
        {
        case 1:
            system("cls");
            input_T(inf_student,inf_course,inf_class,lo_course,lo_class,Max1,Max2);
            break;
        case 2:
            system("cls");
            view(inf_student,inf_course,inf_class,lo_course,lo_class);
            break;
        case 3:
            system("cls");
            modify(inf_student,inf_course,inf_class,lo_course,lo_class,Max1,Max2);
            break;
        case 4:
            system("cls");
            gotoxy(40,7);
            printf ("Teacher\n");
            printf ("\t\t----------------------------------------------------------------\n\n\n\n");
            printf ("\t\t----------------------------------------------------------------\n");
            gotoxy(40,10);
            printf ("Goodbye");
            Sleep(2000);
            output_course(inf_course,lo_course);
            output_class(inf_class,lo_class);
            output_stu(inf_student);
            system("cls");
            exit(0);
        default:
            system("cls");
            gotoxy(40,7);
            printf ("Teacher\n");
            printf ("\t\t----------------------------------------------------------------\n\n\n\n");
            printf ("\t\t----------------------------------------------------------------\n");
            gotoxy(35,10);
            printf ("输入序号错误,请重新输入\n");
            Sleep(2000);
        }
        system("cls");
    }

};
