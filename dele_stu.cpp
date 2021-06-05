#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include"function.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
using namespace std;

void dele_stu(linkStudent &inf_student,Course inf_course[],Class inf_class[])
{
    gotoxy(40,3);
    printf("删除学生信息\n");
    printf ("\t\t----------------------------------------------------------------\n");
    //找到学生
    if (inf_student->next==NULL)
    {
        printf("\t\t\t\t未录入学生信息,请返回录入\n");
        return;
    }
    printf ("\t\t\t请输入您想要删除的学生的学号:");
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
        printf ("\t\t\t请输入您想要删除的学生学号:");
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
    printf ("\t\t\t1.删除该学生信息\n");
    printf ("\t\t\t2.返回主界面\n");
    printf ("\t\t\t请选择您接下来的操作:");
    int flag2=0,flag3=0;
    int x,y,z,m;
    scanf("%d",&flag2);
    switch(flag2)
    {
    case 1:
        for (x=0; x<p->choose_course_num; x++)
        {
            for (y=0; inf_course[p->course[x].course_num].stu_name[p->coursepoint[x]][y]!='\0'; y++)
            {
                inf_course[p->course[x].course_num].stu_name[p->coursepoint[x]][y]='\0';
            }
            for (y=p->coursepoint[x]; y<inf_course[p->course[x].course_num].instu; y++)
            {
                strcpy(inf_course[p->course[x].course_num].stu_name[y],inf_course[p->course[x].course_num].stu_name[y+1]);
                for (z=0; inf_course[p->course[x].course_num].stu_name[y+1][z]!='\0'; z++)
                {
                    inf_course[p->course[x].course_num].stu_name[y+1][z]='\0';
                }
            }
            for (y=p->coursepoint[x]; y<inf_course[p->course[x].course_num].instu; y++)
            {
                strcpy(inf_course[p->course[x].course_num].stu_score[y],inf_course[p->course[x].course_num].stu_score[y+1]);
                for (z=0; inf_course[p->course[x].course_num].stu_score[y+1][z]!='\0'; z++)
                {
                    inf_course[p->course[x].course_num].stu_score[y+1][z]='\0';
                }
            }
//            printf ("课程人数:%d\n",inf_course[p->course[x].course_num].Stu_num);
            inf_course[p->course[x].course_num].instu--;
            inf_course[p->course[x].course_num].Stu_num--;
        }
        //
        for (x=0; inf_class[p->stu_class_num].stu_name[p->classpoint][x]!='\0'; x++)
        {
            inf_class[p->stu_class_num].stu_name[p->classpoint][x]='\0';
        }
        for (x=p->classpoint; x<inf_class[p->stu_class_num].inpustu; x++)
        {
            strcpy(inf_class[p->stu_class_num].stu_name[x],inf_class[p->stu_class_num].stu_name[x+1]);
            for (y=0; inf_class[p->stu_class_num].stu_name[x+1][y]!='\0'; y++)
            {
                inf_class[p->stu_class_num].stu_name[x+1][y]='\0';
            }
        }
        //删除班级数据
        for (x=0; x<p->choose_course_num; x++)
        {

            for (y=0; strcmp(p->course[x].name,inf_class[p->stu_class_num].course[y])!=0&&y<inf_class[p->stu_class_num].course_num; y++);
            if (inf_class[p->stu_class_num].course_people[y]<=1)
            {
                for (z=y; z<inf_class[p->stu_class_num].course_num; z++)
                {
                    inf_class[p->stu_class_num].course_people[z]=inf_class[p->stu_class_num].course_people[z+1];
                }
                for (z=0; inf_class[p->stu_class_num].course[y][z]!='\0'; z++)
                {
                    inf_class[p->stu_class_num].course[y][z]='\0';
                }
                for (z=y; z<inf_class[p->stu_class_num].course_num; z++)
                {
                    strcpy(inf_class[p->stu_class_num].course[z],inf_class[p->stu_class_num].course[z+1]);
                    for (m=0; inf_class[p->stu_class_num].course[z+1][m]!='\0'; m++)
                    {
                        inf_class[p->stu_class_num].course[z+1][m]='\0';
                    }
                }
                for (z=y; z<inf_class[p->stu_class_num].course_num; z++)
                {
                    inf_class[p->stu_class_num].averscore[z]=inf_class[p->stu_class_num].averscore[z+1];
                }
                inf_class[p->stu_class_num].course_num--;
            }
            else
            {
                inf_class[p->stu_class_num].course_people[y]--;
                inf_class[p->stu_class_num].averscore[y]=(inf_class[p->stu_class_num].averscore[y]*(inf_class[p->stu_class_num].course_people[y]+1)-p->course[x].result_score)/(inf_class[p->stu_class_num].course_people[y]*1.0);
            }
        }
        inf_class[p->stu_class_num].inpustu--;
        inf_class[p->stu_class_num].stu_num--;
        l->next=p->next;
        p->next=NULL;
        printf ("\n\t\t\t\t\t删除成功\n");
        printf ("\t\t----------------------------------------------------------------\n");
        printf ("\t\t\t");
        system("pause");
        return;
    case 2:
        break;
    }
    system("cls");
    return;
};
