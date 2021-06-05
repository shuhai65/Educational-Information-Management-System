#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include"function.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
using namespace std;
void see_stu(linkStudent Stu)
{
    gotoxy(40,3);
    printf("查询学生信息\n");
    printf ("\t\t----------------------------------------------------------------\n");
    if (Stu->next==NULL)
    {
        printf("\t\t\t未录入学生信息,请返回录入\n");
        return;
    }
    linkStudent p,r;
    p=new Student;
    p=Stu->next;
    r=new Student;
    r=Stu;
    printf ("\t\t\t请输入学生学号查询:");
    char num[20];
    int flag=0,i,flag1=0;
    scanf("%s",num);
    if (strcmp(num,p->stu_num)==0)
    {
        flag=1;
    }
    while (strcmp(num,p->stu_num)!=0&&r->next!=NULL&&flag!=1)
    {
        if (p->next!=NULL)
        {
            p=p->next;
        }
        r=r->next;
        if (strcmp(num,p->stu_num)==0)
        {
            flag=1;
            break;
        }
    }
    while (flag==0)
    {
        printf("\t\t\t无法查询到该学生,(输入1继续输入学生学号,输入2返回上一步):");
        scanf("%d",&flag1);
        if (flag1==2)
        {
            return;
        }
        for (i=0; num[i]!='\0'; i++)
        {
            num[i]='\0';
        }
        printf ("\t\t\t请输入学生学号查询\n");
        scanf("%s",num);
        p=new Student;
        p=Stu->next;
        r=new Student;
        r=Stu;
        if (strcmp(num,p->stu_num)==0)
        {
            flag=1;
        }
        while (strcmp(num,p->stu_num)!=0&&r->next!=NULL&&flag!=1)
        {
            if (p->next!=NULL)
            {
                p=p->next;
            }
            r=r->next;
            if (strcmp(num,p->stu_num)==0)
            {
                flag=1;
                break;
            }
        }
    }
    printf ("\t\t\t学生姓名:%s\n",p->name);
    printf ("\t\t\t学生性别:%s\n",p->sex);
    printf ("\t\t\t学生手机号:%s\n",p->phone_num);
    printf ("\t\t\t学生年级:%s\n",p->grade);
    printf ("\t\t\t学生专业:%s\n",p->major);
    printf ("\t\t\t学生年龄:%d\n",p->age);
    printf ("\t\t\t学生宿舍号:%d\n",p->dor_num);
    printf ("\t\t\t学生班级编号:%d\n",p->stu_class_num);
    printf ("\t\t\t学生班级号:%s\n",p->classnumber_char);
    printf ("\t\t\t学生班级名称:%s\n",p->stu_class_name);
    printf ("\t\t\t学生所选课程数:%d\n",p->choose_course_num);
    printf ("\t\t\t学生已修学分:%d\n",p->credit);
    printf ("\t\t\t\t学生选课信息\n\n");
    for (i=0; i<p->choose_course_num; i++)
    {

        printf ("\t\t\t\t%d.%s\n",i+1,p->course[i].name);
        if (p->course[i].flag==1)
        {
            printf ("\t\t\t\t考试成绩:%.2f\n\t\t\t\t平时成绩:%.2f\n\t\t\t\t综合成绩:%.2f\n\n",p->course[i].test_score,p->course[i].usual_score,p->course[i].result_score);
        }
        else
        {
            printf ("\t\t\t\t本课程暂时未录入成绩\n");
        }
    }
    printf ("\t\t\t\t\tComplete\n");
    printf ("\t\t----------------------------------------------------------------\n");
    printf ("\t\t\t");
    system("pause");
};
