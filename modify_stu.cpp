#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include"function.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
using namespace std;

void modify_stu(linkStudent &inf_student,Course inf_course[],Class inf_class[])
{
    gotoxy(40,3);
    printf("修改学生信息\n");
    printf ("\t\t----------------------------------------------------------------\n");
    //找到学生
    if (inf_student->next==NULL)
    {
        printf("\t\t\t\t未录入学生信息,请返回录入\n");
        return;
    }
    printf ("\t\t\t请输入您想要修改的学生的学号:");
    int flag=0,i,flag1=0;
    linkStudent p,r,l;
    p=new Student;
    l=new Student;
    p=inf_student->next;
    r=new Student;
    l=inf_student;
    r=inf_student;
    char num[20];
    scanf("%s",num);
    if (strcmp(num,p->stu_num)==0)
    {
        flag=1;
    }
    while (strcmp(num,p->stu_num)!=0&&r->next!=NULL&&flag!=1)
    {
        if (p->next!=NULL)
        {
            l=p;
            p=p->next;
        }
        r=r->next;
        if (strcmp(num,p->stu_num)==0)
        {
            flag=1;
            break;
        }
    }
//    printf ("flag=%d\n",flag);
    while (flag==0)
    {
        printf("\t\t\t\t无法查询到该学生,(输入1继续输入学生学号,输入2返回上一步):");
        scanf("%d",&flag1);
        if (flag1==2)
        {
            return;
        }
        printf ("\t\t\t请输入您想要修改的学生学号:");
        for (i=0; num[i]!='\0'; i++)
        {
            num[i]='\0';
        }
        scanf("%s",num);
        p=new Student;
        p=inf_student->next;
        l=new Student;
        l=inf_student;
        r=new Student;
        r=inf_student;
        if (strcmp(num,p->stu_num)==0)
        {
            flag=1;
        }
        while (strcmp(num,p->stu_num)!=0&&r->next!=NULL&&flag!=1)
        {
            if (p->next!=NULL)
            {
                l=p;
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
    //找到学生


    //输出学生信息
    printf ("\t\t\t学生基本信息\n\n");
    printf ("\t\t\t学生姓名:%s\n",p->name);
    printf ("\t\t\t学生性别:%s\n",p->sex);
    printf ("\t\t\t学生手机号:%s\n",p->phone_num);
    printf ("\t\t\t学生年级:%s\n",p->grade);
    printf ("\t\t\t学生专业:%s\n",p->major);
    printf ("\t\t\t学生年龄:%d\n",p->age);
    printf ("\t\t\t学生宿舍号:%d\n",p->dor_num);
    printf ("\t\t\t学生班级编号:%d\n",p->stu_class_num);
    printf ("\t\t\t学生班级名称:%s\n",p->stu_class_name);
    printf ("\t\t\t学生班级号:%s\n",p->classnumber_char);
    printf ("\t\t\t学生所选课程数:%d\n",p->choose_course_num);
    printf ("\t\t\t学生已修学分:%d\n\n\n",p->credit);
    printf ("\t\t\t\t\t课程具体信息\n\n");
    for (i=0; i<p->choose_course_num; i++)
    {
        printf ("\t\t\t%d.%s\n",i+1,p->course[i].name);
        printf ("\t\t\t考试成绩:%.2f\n\t\t\t平时成绩:%.2f\n\t\t\t综合成绩:%.2f\n\n",p->course[i].test_score,p->course[i].usual_score,p->course[i].result_score);
    }
    //输出学生信息
    //选择操作
    printf ("\t\t\t1.修改该学生信息\n");
    printf ("\t\t\t2.返回主界面\n");
    printf ("\t\t\t请选择您接下来的操作:");
    int flag2=0,flag3=0;
    int x,y,z,m;
    scanf("%d",&flag2);
    switch(flag2)
    {
    case 1:
        printf ("\n\t\t\t\t\t 修改信息\n");
        printf ("\t\t\t1.姓名\t2.性别\t3.手机号\n\t\t\t4.年级\t5.专业\t6.年龄\t7.宿舍号\n");
        printf("\t\t\t请选择修改的信息:");
        scanf ("%d",&flag3);
        switch(flag3)
        {
        case 1:
            for (x=0; p->name[x]!='\0'; x++)
            {
                p->name[x]='\0';
            }
            printf ("\t\t\t请输入学生姓名:");
            scanf ("%s",p->name);
            for(x=0; inf_class[p->stu_class_num].stu_name[p->classpoint][x]!='\0'; x++)
            {
                inf_class[p->stu_class_num].stu_name[p->classpoint][x]='\0';
            }
            strcpy(inf_class[p->stu_class_num].stu_name[p->classpoint],p->name);
            for (x=0; x<p->choose_course_num; x++)
            {
                for (y=0; inf_course[p->course[x].course_num].stu_name[p->coursepoint[x]][y]!='\0'; y++)
                {
                    inf_course[p->course[x].course_num].stu_name[p->coursepoint[x]][y]='\0';
                }
                strcpy(inf_course[p->course[x].course_num].stu_name[p->coursepoint[x]],p->name);
            }
            break;
        case 2:
            for (x=0; p->sex[x]!='\0'; x++)
            {
                p->sex[x]='\0';
            }
            printf ("\t\t\t请输入性别:");
            scanf ("%s",p->sex);
            break;
        case 3:
            for (x=0; p->phone_num[x]!='\0'; x++)
            {
                p->phone_num[x]='\0';
            }
            printf ("\t\t\t请输入手机号:");
            scanf("%s",p->phone_num);
            break;
        case 4:
            for (x=0; p->grade[x]!='\0'; x++)
            {
                p->grade[x]='\0';
            }
            printf ("\t\t\t请输入年级:");
            scanf("%s",p->grade);
            break;
        case 5:
            for (x=0; p->major[x]!='\0'; x++)
            {
                p->major[x]='\0';
            }
            printf ("\t\t\t请输入专业:");
            scanf("%s",p->major);
        case 6:
            printf ("\t\t\t请输入年龄:");
            scanf("%d",&p->age);
            break;
        case 7:
            printf ("\t\t\t请输入宿舍号:");
            scanf("%d",&p->dor_num);
            break;
        }
        printf ("\t\t\t\t修改成功\n");
        printf ("\t\t----------------------------------------------------------------\n");
        printf ("\t\t\t");
        system("pause");
        break;

    case 2:
        break;
    }

    return;
};

