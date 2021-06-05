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

void input_T(linkStudent inf_student,Course inf_course[],Class inf_class[],
           linklocate_course lo_course,linklocate_class lo_class,int &Max1,int &Max2)
{
    int operation=1,flag;
    int num1=1,num2=1,flag1=0,flag2=0;
    while(operation)
    {
        gotoxy(40,7);
        printf("录入信息\n");
        printf ("\t\t----------------------------------------------------------------\n");
        printf("\t\t\t请选择输入接下来的操作(输入序号):\n");
        printf ("\t\t\t1.录入学生基本信息\n");
        printf ("\t\t\t2.录入学生成绩\n");
        printf ("\t\t\t3.录入学生选课信息\n");
        printf ("\t\t\t4.退出录入\n");
        printf ("\t\t----------------------------------------------------------------\n");
        gotoxy(57,9);
        scanf("%d",&flag);
        switch(flag)
        {
        case 1:
            system("cls");
            input_stu(inf_student,inf_course,inf_class,lo_course,lo_class);
            break;
        case 2:
            system("cls");
            input_stu_score(inf_student,inf_course,inf_class);
            break;
        case 3:
            system("cls");
            input_stu_course(inf_student,inf_course,inf_class,lo_course,lo_class);
            break;
        case 4:
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
