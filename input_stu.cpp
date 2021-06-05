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

struct Student *findlast(linkStudent inf_student)
{
    linkStudent tail,head;
    tail=new Student;
    head=new Student;
    head=inf_student;
    tail=head;
    while (head->next!=NULL)
    {
        head=head->next;
        tail=head;
    }
    return tail;
};


void input_stu(linkStudent &inf_student,Course inf_course[],Class inf_class[],linklocate_course lo_course,linklocate_class lo_class)//后插法
{
    gotoxy(40,3);
    printf ("录入学生基本信息\n");
    printf ("\t\t----------------------------------------------------------------\n");
    linkStudent p,r,h,hr;
    int i=0,j,flag=0,x,y;
    int course_num=0;//所选课程数
    int coursenuming=0;//课程编号
    int cao;//初始化字符数组
    p=new Student;
    r=new Student;
    h=new Student;
    hr=new Student;
    hr=inf_student;
    if (inf_student->next!=NULL)
    {
        h=inf_student->next;
    }
    r=findlast(inf_student);
    p->next=NULL;

    printf ("\t\t\t请输入学号:");
    scanf ("%s",p->stu_num);
    //检查是否已经输入该学生信息
    while (flag==0)
    {
        while(strcmp(h->stu_num,p->stu_num)!=0&&hr->next!=NULL)
        {
            if (h->next!=NULL)
            {
                h=h->next;
            }
            hr=hr->next;
        }
        if(strcmp(h->stu_num,p->stu_num)==0)
        {
            printf ("\t\t\t该学生信息已录入(如果需要录入其他同学请输入1，退出到主界面请输入2):");
            scanf("%d",&x);
            if (x==1)
            {
                printf ("\t\t\t请输入学号:");
                scanf ("%s",p->stu_num);
            }
            else if (x==2)
            {
                return;
            }
        }
        else
        {
            break;
        }
    }

    //检查是否已经输入该学生信息
    printf ("\t\t\t请输入学生姓名:");
    scanf ("%s",p->name);
    printf ("\t\t\t请输入性别:");
    scanf ("%s",p->sex);
    printf ("\t\t\t请输入手机号:");
    scanf ("%s",p->phone_num);
    printf ("\t\t\t请输入年级:");
    scanf ("%s",p->grade);
    printf ("\t\t\t请输入专业:");
    scanf ("%s",p->major);
    printf ("\t\t\t请输入年龄:");
    scanf ("%d",&p->age);
    printf ("\t\t\t请输入宿舍号:");
    scanf ("%d",&p->dor_num);
    //
    printf ("\t\t\t请输入所属班级编号:");
    scanf ("%d",&p->stu_class_num);
    //检查是否存在此班级
    while (inf_class[p->stu_class_num].flag!=1)
    {
        printf("\t\t\t不存在此班级，请重新输入\n");
        printf ("\t\t\t请输入所属班级编号:");
        scanf ("%d",&p->stu_class_num);
    }
    //检查是否存在此班级
    printf ("\t\t\t学生所在班级为:%s\n",inf_class[p->stu_class_num].class_name);
    strcpy(p->stu_class_name,inf_class[p->stu_class_num].class_name);
    strcpy(p->classnumber_char,inf_class[p->stu_class_num].class_num);
    printf ("\t\t\t请输入已修学分:");
    scanf ("%d",&p->credit);
     if (inf_class[p->stu_class_num].stu_num<=inf_class[p->stu_class_num].inpustu)
    {
        inf_class[p->stu_class_num].stu_num++;
    }
    strcpy(inf_class[p->stu_class_num].stu_name[inf_class[p->stu_class_num].inpustu],p->name);
    p->classpoint=inf_class[p->stu_class_num].inpustu;
    inf_class[p->stu_class_num].inpustu++;
    r->next=p;
    r=p;
    printf ("\t\t\t\t录入完成\n");
    printf ("\t\t----------------------------------------------------------------\n");
    printf ("\t\t");
    system("pause");
};
