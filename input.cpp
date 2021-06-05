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

void input(linkStudent inf_student,Course inf_course[],Class inf_class[],
           linklocate_course lo_course,linklocate_class lo_class,int &Max1,int &Max2)
{
    int operation=1,flag;
    int num1=1,num2=1,flag1=0,flag2=0;
    while(operation)
    {
        gotoxy(40,7);
        printf("录入信息\n");
        printf ("\t\t----------------------------------------------------------------\n");
        printf ("\t\t\t请选择输入接下来的操作(输入序号):\n");
        printf ("\t\t\t1.录入课程信息\n");
        printf ("\t\t\t2.录入班级信息\n");
        printf ("\t\t\t3.录入学生基本信息\n");
        printf ("\t\t\t4.录入学生成绩\n");
        printf ("\t\t\t5.录入学生选课信息\n");
        printf ("\t\t\t6.退出录入\n");
        printf ("\t\t----------------------------------------------------------------\n");
        gotoxy(57,9);
        scanf("%d",&flag);
        switch(flag)
        {
        case 1:
            system("cls");
            if ((num2=input_course(inf_course,lo_course,Max2,flag2))!=0)
            {
                inf_course=(struct Course *)realloc (inf_course,(num2+10)*sizeof(struct Course));
                flag2=num2;
                Max2=num2+10;
                input_course(inf_course,lo_course,Max2,flag2);
            }
            break;
        case 2:
            system("cls");
            if ((num1=input_class(inf_class,lo_class,Max1,flag1))!=0)
            {
                inf_class=(struct Class *)realloc (inf_class,(num1+10)*sizeof(struct Class));
                flag1=num1;
                Max1=num1+10;
                input_class(inf_class,lo_class,Max1,flag1);
            }
            break;
        case 3:
            system("cls");
            input_stu(inf_student,inf_course,inf_class,lo_course,lo_class);
            break;
        case 4:
            system("cls");
            input_stu_score(inf_student,inf_course,inf_class);
            break;
        case 5:
            system("cls");
            input_stu_course(inf_student,inf_course,inf_class,lo_course,lo_class);
            break;
        case 6:
            system("cls");
            return;
        default:
            system("cls");
            gotoxy(40,7);
            printf("录入信息\n");
            printf ("\t\t----------------------------------------------------------------\n");
            printf ("\t\t\t\t输入序号错误,请重新输入\n");
            printf ("\t\t----------------------------------------------------------------\n");
            Sleep(2000);
        }
        system("cls");
    }

};
