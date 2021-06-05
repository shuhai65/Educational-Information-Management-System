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

struct locate_class *findlast_loclass(linklocate_class L)
{
    linklocate_class r;
    r=new locate_class;
    r=L;
    while(L->next!=NULL)
    {
        L=L->next;
        r=L;
    }
    return r;
};

int input_class(Class L[],linklocate_class &lo_class,int Max,int flag)
{
    //找到尾节点
    linklocate_class p,r;
    p=new locate_class;
    r=new locate_class;
    r=findlast_loclass(lo_class);
    //找到尾节点
    int num;
    gotoxy(40,3);
    printf("录入班级信息\n");
    printf ("\t\t----------------------------------------------------------------\n");
    if (flag==0)
    {
        printf ("\t\t\t请输入班级编号(大于0的正整数):");
        scanf ("%d",&num);
        if (num>Max)
        {
            system("cls");
            return num;
        }
    }
    else
    {
        num=flag;
        printf ("\t\t\t请输入班级编号(大于0的正整数):%d\n",num);
    }

    //读取储存位置
    p->num=num;
    p->next=NULL;
    r->next=p;
    r=p;
    //读取储存位置
    L[num].numbing=num;
    printf ("\t\t\t请输入班级号:");
    scanf ("%s",L[num].class_num);
    printf ("\t\t\t请输入班级名称:");
    scanf ("%s",L[num].class_name);
    printf ("\t\t\t请输入学生人数:");
    scanf ("%d",&L[num].stu_num);
    printf ("\t\t\t请输入所在年级:");
    scanf ("%s",L[num].grade);
    L[num].flag=1;
    printf ("\t\t\t\t录入完成\n");
    printf ("\t\t----------------------------------------------------------------\n");
    printf ("\t\t\t");
    system("pause");
    return 0;
};
