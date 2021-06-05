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
void student(linkStudent inf_student,Course inf_course[],Class inf_class[],
             char name[],linklocate_course lo_course,linklocate_class lo_class)
{
    int operation=1,flag;
    while (operation)
    {
        gotoxy(40,7);
        printf ("Student\n");
        printf ("\t\t----------------------------------------------------------------\n");
        printf ("\t\t\t请根据菜单操作序号选择您接下来的操作(输入操作序号):\n");
        printf ("\t\t\t1.查看个人信息及成绩\n");
        printf ("\t\t\t2.选课\n");
        printf ("\t\t\t3.退出程序\n");
        printf ("\t\t----------------------------------------------------------------\n");
        flag=0;
        gotoxy(75,9);
        scanf("%d",&flag);
        switch(flag)
        {
        case 1:
            system("cls");
            stu_see_self(inf_student,name);
            break;
        case 2:
            system("cls");
            input_stu_self_course(inf_student,inf_course,inf_class,lo_course,lo_class,name);
            break;
        case 3:
            system("cls");
            gotoxy(40,7);
            printf ("Student\n");
            printf ("\t\t----------------------------------------------------------------\n\n\n\n");
            printf ("\t\t----------------------------------------------------------------\n");
            gotoxy(40,10);
            printf ("Goodbye");
            output_course(inf_course,lo_course);
            output_class(inf_class,lo_class);
            output_stu(inf_student);
            Sleep(2000);
            system("cls");
            exit(0);
        default:
            system("cls");
            gotoxy(40,7);
            printf ("Student\n");
            printf ("\t\t----------------------------------------------------------------\n\n\n\n");
            printf ("\t\t----------------------------------------------------------------\n");
            gotoxy(35,10);
            printf ("输入序号错误,请重新输入\n");
            Sleep(2000);
        }
        system("cls");
    }
};
