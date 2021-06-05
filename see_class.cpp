#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include"function.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
using namespace std;

void see_class(Class L[])
{
    int i,num;
    gotoxy(40,3);
    printf("查询班级信息\n");
    printf ("\t\t----------------------------------------------------------------\n");
    printf ("\t\t\t请输入查询的班级编号:");
    scanf("%d",&num);
    if (L[num].flag!=1)
    {
        printf ("\t\t\t不存在该班级信息,将退出查询\n");
        Sleep(2000);
        return;
    }
    printf ("\t\t\t班级号为:%s\n",L[num].class_num);
    printf ("\t\t\t班级名为:%s\n",L[num].class_name);
    printf ("\t\t\t班级所属年级:%s\n",L[num].grade);
    printf("\t\t\t班级人数为:%d\n",L[num].stu_num);
    if (L[num].inpustu>=1)
    {
        printf ("\t\t\t班级学生姓名:\n");
    }else
    {
        printf ("\t\t\t未录入班级学生信息\n");
    }

    for (i=0;i<L[num].inpustu;i++)
    {
        printf ("\t\t\t%d:%s\n",i+1,L[num].stu_name[i]);
    }
    printf ("\t\t\t班级所选课程数:%d\n\n",L[num].course_num);
    for (i=0; i<L[num].course_num; i++)
    {
        printf ("\t\t\t第%d个课程\n",i+1);
        printf ("\t\t\t课程名:%s\n",L[num].course[i]);
        printf ("\t\t\t平均成绩:%.2lf\n\n",L[num].averscore[i]);
    }
    printf ("\t\t\t\t\tComplete\n");
    printf ("\t\t----------------------------------------------------------------\n");
    printf ("\t\t\t");
    system("pause");
};
