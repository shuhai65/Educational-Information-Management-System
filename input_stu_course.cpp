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
void input_stu_course(linkStudent &Stu,Course inf_course[],Class inf_class[],linklocate_course lo_course,linklocate_class lo_class)
{
    gotoxy(40,3);
    printf ("录入学生选课信息\n");
    printf ("\t\t----------------------------------------------------------------\n");
    if (Stu->next==NULL)
    {
        printf("\t\t未录入学生信息,请返回录入\n");
        system("pause");
        return;
    }
    linkStudent p,r;
    p=new Student;
    p=Stu->next;
    r=new Student;
    r=Stu;
    printf ("\t\t\t请输入学生学号:");
    char num[20];
    int flag=0,i,j,k,x,y,z,flag1=0,io,cao;
    int choosenumber=0;//录入课程数
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
        printf("\t\t\t无法查询到该学生,请选择接下来的操作\n\t\t\t输入1继续输入学生学号\n\t\t\t输入2退出录入\n");
        printf("\t\t\t请输入:");
        scanf("%d",&flag1);
        if (flag1==2)
        {
            return;
        }
        for (i=0; num[i]!='\0'; i++)
        {
            num[i]='\0';
        }
        printf ("\t\t\t请输入学生学号:");
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
    printf ("\n\t\t\t\t该学生个人信息\n");
    printf ("\t\t\t\t学生姓名:%s\n",p->name);
    printf ("\t\t\t\t学生年级:%s\n",p->grade);
    printf ("\t\t\t\t学生专业:%s\n",p->major);
    printf ("\t\t\t\t学生班级编号:%d\n",p->stu_class_num);
    printf ("\t\t\t\t学生班级名称:%s\n",p->stu_class_name);
    printf ("\t\t\t\t学生已选课程数:%d\n",p->choose_course_num);
    printf ("\t\t\t\t学生已修学分:%d\n",p->credit);
    printf ("\n\t\t\t请输入本次录入课程数(大于0):");
    scanf("%d",&choosenumber);
    for (i=0; i<choosenumber; i++)
    {
        printf ("\t\t\t请选择是否查询课程(输入1查询,输入2取消查询):");
        scanf("%d",&y);
        while (y==1)
        {
            search_see_course(inf_course,lo_course);
            printf ("\t\t\t请选择继续是否查询课程(输入1查询,输入2取消查询):");
            scanf("%d",&y);
        }
        printf ("\t\t\t请输入所选第%d个课程编号:",i+1);
        scanf("%d",&x);
        while (inf_course[x].flag!=1)
        {
            printf ("\t\t\t不存在该课程,请重新输入:");
            scanf("%d",&x);
        }
        printf ("\t\t\t\t上课时间\n");
        for (z=1; z<8; z++)
        {
            for (y=1; y<14; y++)
            {
                if (inf_course[x].time[y][z]==1)
                {
                    printf("\t\t\t");
                    printf ("星期");
                    if (z==1)
                    {
                        printf ("一");
                    }
                    else if (z==2)
                    {
                        printf ("二");
                    }
                    else if (z==3)
                    {
                        printf ("三");
                    }
                    else if (z==4)
                    {
                        printf ("四");
                    }
                    else if (z==5)
                    {
                        printf ("五");
                    }
                    else if (z==6)
                    {
                        printf ("六");
                    }
                    else if (z==7)
                    {
                        printf ("日");
                    }
                    printf ("   第%d节课   ",y);
                    switch (y)
                    {
                    case 1:
                        printf ("上课时间：8:00-8:45\n");
                        break;
                    case 2:
                        printf ("上课时间：8:50-9:35\n");
                        break;
                    case 3:
                        printf ("上课时间：10:05-10:50\n");
                        break;
                    case 4:
                        printf ("上课时间：10:55-11:40\n");
                        break;
                    case 5:
                        printf ("上课时间：12:30-13:15\n");
                        break;
                    case 6:
                        printf ("上课时间：13:20-14:05\n");
                        break;
                    case 7:
                        printf ("上课时间：14:30-15:15\n");
                        break;
                    case 8:
                        printf ("上课时间：15:20-16:05\n");
                        break;
                    case 9:
                        printf ("上课时间：16:35-17:20\n");
                        break;
                    case 10:
                        printf ("上课时间：17:25-18:10\n");
                        break;
                    case 11:
                        printf ("上课时间：19:30-20:15\n");
                        break;
                    case 12:
                        printf ("上课时间：20:20-21:05\n");
                        break;
                    case 13:
                        printf ("上课时间：21:10-21:55\n");
                        break;
                    }
                }
            }
        }
        strcpy( p->course[p->choose_course_num+i].name,inf_course[x].name);
        p->course[p->choose_course_num+i].credit=inf_course[x].score;
        p->course[p->choose_course_num+i].course_num=x;
        printf("\t\t\t请输入本课程是否属于重修(输入是或否):");
        scanf("%s",p->course[p->choose_course_num+i].rebuilt);
        if(strcmp(p->course[p->choose_course_num+i].rebuilt,"是")==0)
        {
            printf("\t\t\t请输入重修次数:");
            scanf("%d",&p->course[p->choose_course_num+i].rebuilt_num);
        }
        //录入班级课程名
        io=0;
        for(j=0; j<inf_class[p->stu_class_num].course_num; j++)
        {
            if (strcmp(p->course[p->choose_course_num+i].name,inf_class[p->stu_class_num].course[j])==0)
            {
                io=1;
                break;
            }
        }
        for(cao=0; p->course[p->choose_course_num+i].name[cao]!='\0'&&io!=1; cao++)
        {
            inf_class[p->stu_class_num].course[j][cao]=p->course[p->choose_course_num+i].name[cao];
        }
        if (io==0)
        {
            inf_class[p->stu_class_num].course_num++;
        }
        inf_class[p->stu_class_num].course_people[j]++;
        //录入课程人数和学生名字
        if (inf_course[x].Stu_num<=inf_course[x].instu)
        {
            inf_course[x].Stu_num++;
        }
        for (cao=0; p->name[cao]!='\0'; cao++)
        {
            inf_course[x].stu_name[inf_course[x].instu][cao]=p->name[cao];
        }
        p->coursepoint[p->choose_course_num+i]=inf_course[x].instu;
        inf_course[x].instu++;
    }
    p->choose_course_num=p->choose_course_num+choosenumber;
    printf ("\t\t\t\t录入完成\n");
    printf ("\t\t----------------------------------------------------------------\n");
    printf ("\t\t\t");
    system("pause");
};
