#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include"function.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
using namespace std;

void view(linkStudent inf_student,Course inf_course[],Class inf_class[],linklocate_course lo_course,linklocate_class lo_class)
{
    int flag=0,operation=1;
    while (operation)
    {
        gotoxy(40,7);
        printf("查看信息\n");
        printf ("\t\t----------------------------------------------------------------\n");
        printf ("\t\t\t请选择输入接下来的操作(输入序号):\n");
        printf ("\t\t\t1.查看学生信息\n");
        printf ("\t\t\t2.查看班级信息(学生选课情况及考试成绩)\n");
        printf ("\t\t\t3.查看课程信息\n");
        printf ("\t\t\t4.查看所有学生已修学分及不及级课程\n");
        printf ("\t\t\t5.返回\n");
        printf ("\t\t----------------------------------------------------------------\n");
        gotoxy(57,9);
        scanf("%d",&flag);
        switch(flag)
        {
        case 1:
            system("cls");
            see_stu(inf_student);
            break;
        case 2:
            system("cls");
            see_class(inf_class);
            break;
        case 3:
            system("cls");
            see_course(inf_course,lo_course);
            break;
        case 4:
            system("cls");
            see_all_stu(inf_student);
            break;
        case 5:
            system("cls");
            return;
        default:
            system("cls");
            gotoxy(40,7);
            printf("查看信息\n");
            printf ("\t\t----------------------------------------------------------------\n");
            printf ("\t\t\t\t输入序号错误,请重新输入\n");
            printf ("\t\t----------------------------------------------------------------\n");
            Sleep(2000);
        }
        system("cls");
    }
};
