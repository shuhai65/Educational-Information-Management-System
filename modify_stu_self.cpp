#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include"function.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
using namespace std;

void modify_stu_self(linkStudent &inf_student,Course inf_course[],Class inf_class[],char name[])
{
    int flag=0,i,flag1=0;
    linkStudent p,l;
    p=new Student;
    l=new Student;
    p=inf_student->next;
//    r=new Student;
    l=inf_student;
//    r=inf_student;
    while (strcmp(name,p->stu_num)!=0&&p->next!=NULL)
    {
        l=p;
        p=p->next;
    }
    //输出学生信息
    printf ("\t学生基本信息\n\n");
    printf ("\t学生姓名:%s\n",p->name);
    printf ("\t学生性别:%s\n",p->sex);
    printf ("\t学生手机号:%s\n",p->phone_num);
    printf ("\t学生年级:%s\n",p->grade);
    printf ("\t学生专业:%s\n",p->major);
    printf ("\t学生年龄:%d\n",p->age);
    printf ("\t学生宿舍号:%d\n",p->dor_num);
    printf ("\t学生班级编号:%d\n",p->stu_class_num);
    printf ("\t学生班级名称:%s\n",p->stu_class_name);
    printf ("\t学生班级号:%s\n",p->classnumber_char);
    printf ("\t学生所选课程数:%d\n",p->choose_course_num);
    printf ("\t学生已修学分:%d\n\n\n",p->credit);
    printf ("\t课程具体信息\n\n");
    for (i=0; i<p->choose_course_num; i++)
    {
        printf ("\t%d.%s\n",i+1,p->course[i].name);
        printf ("\t考试成绩:%.2f\n\t平时成绩:%.2f\n\t综合成绩:%.2f\n\n",p->course[i].test_score,p->course[i].usual_score,p->course[i].result_score);
    }
    printf ("\tComplete\n\n");
    //输出学生信息
    //选择操作
    printf ("\t1.修改信息\n");
    printf ("\t2.返回主界面\n");
    printf ("\t请选择您接下来的操作:");
    int flag2=0,flag3=0;
    int x,y,z,score,m,n;
    scanf("%d",&flag2);
    switch(flag2)
    {
    case 1:
        printf("\t请选择修改的信息\n");
        printf ("\t1.姓名\t2.性别\t3.手机号\n\t4.年级\t5.专业\t6.年龄\t7.宿舍号\n");
        scanf ("%d",&flag3);
        switch(flag3)
        {
        case 1:
            for (x=0; p->name[x]!='\0'; x++)
            {
                p->name[x]='\0';
            }
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
            scanf ("%s",p->sex);
            break;
        case 3:
            for (x=0; p->phone_num[x]!='\0'; x++)
            {
                p->phone_num[x]='\0';
            }
            scanf("%s",p->phone_num);
            break;
        case 4:
            for (x=0; p->grade[x]!='\0'; x++)
            {
                p->grade[x]='\0';
            }
            scanf("%s",p->grade);
            break;
        case 5:
            for (x=0; p->major[x]!='\0'; x++)
            {
                p->major[x]='\0';
            }
            scanf("%s",p->major);
        case 6:
            scanf("%d",&p->age);
            break;
        case 7:
            scanf("%d",&p->dor_num);
            break;
        }
        break;
//    case 2:
//        printf ("%d\n",p->choose_course_num);
//        for (x=0; x<p->choose_course_num; x++)
//        {
//            printf ("x=%d",x);
//            printf ("%s\n",inf_course[p->course[x].course_num].name);
//            for (y=0; inf_course[p->course[x].course_num].stu_name[p->coursepoint[x]][y]!='\0'; y++)
//            {
//                inf_course[p->course[x].course_num].stu_name[p->coursepoint[x]][y]='\0';
//            }
//            for (y=p->coursepoint[x]; y<inf_course[p->course[x].course_num].instu; y++)
//            {
//                strcpy(inf_course[p->course[x].course_num].stu_name[y],inf_course[p->course[x].course_num].stu_name[y+1]);
//                for (z=0; inf_course[p->course[x].course_num].stu_name[y+1][z]!='\0'; z++)
//                {
//                    inf_course[p->course[x].course_num].stu_name[y+1][z]='\0';
//                }
//            }
//            for (y=p->coursepoint[x]; y<inf_course[p->course[x].course_num].instu; y++)
//            {
//                strcpy(inf_course[p->course[x].course_num].stu_score[y],inf_course[p->course[x].course_num].stu_score[y+1]);
//                for (z=0; inf_course[p->course[x].course_num].stu_score[y+1][z]!='\0'; z++)
//                {
//                    inf_course[p->course[x].course_num].stu_score[y+1][z]='\0';
//                }
//            }
//            printf ("课程人数:%d\n",inf_course[p->course[x].course_num].Stu_num);
//            inf_course[p->course[x].course_num].instu--;
//            inf_course[p->course[x].course_num].Stu_num--;
//        }
//        //
//        for (x=0; inf_class[p->stu_class_num].stu_name[p->classpoint][x]!='\0'; x++)
//        {
//            inf_class[p->stu_class_num].stu_name[p->classpoint][x]='\0';
//        }
//        for (x=p->classpoint; x<inf_class[p->stu_class_num].inpustu; x++)
//        {
//            strcpy(inf_class[p->stu_class_num].stu_name[x],inf_class[p->stu_class_num].stu_name[x+1]);
//            for (y=0; inf_class[p->stu_class_num].stu_name[x+1][y]!='\0'; y++)
//            {
//                inf_class[p->stu_class_num].stu_name[x+1][y]='\0';
//            }
//        }
//        //删除班级数据
//        for (x=0; x<p->choose_course_num; x++)
//        {
//            for (y=0; strcmp(p->course[x].name,inf_class[p->stu_class_num].course[y])!=0&&y<inf_class[p->stu_class_num].course_num; y++);
//            if (inf_class[p->stu_class_num].course_people[y]>=1)
//            {
//                for (z=y; z<inf_class[p->stu_class_num].course_num; z++)
//                {
//                    inf_class[p->stu_class_num].course_people[z]=inf_class[p->stu_class_num].course_people[z+1];
//                }
//                for (z=0; inf_class[p->stu_class_num].course[y][z]!='\0'; z++)
//                {
//                    inf_class[p->stu_class_num].course[y][z]='\0';
//                }
//                for (z=y; z<inf_class[p->stu_class_num].course_num; z++)
//                {
//                    strcpy(inf_class[p->stu_class_num].course[z],inf_class[p->stu_class_num].course[z+1]);
//                    for (m=0; inf_class[p->stu_class_num].course[z+1][m]!='\0'; m++)
//                    {
//                        inf_class[p->stu_class_num].course[z+1][m]='\0';
//                    }
//                }
//                for (z=y; z<inf_class[p->stu_class_num].course_num; z++)
//                {
//                    inf_class[p->stu_class_num].averscore[z]=inf_class[p->stu_class_num].averscore[z+1];
//                }
//                inf_class[p->stu_class_num].course_num--;
//            }
//            else
//            {
//                inf_class[p->stu_class_num].course_num--;
//                inf_class[p->stu_class_num].course_people[y]--;
//                inf_class[p->stu_class_num].averscore[y]=(inf_class[p->stu_class_num].averscore[y]*(inf_class[p->stu_class_num].course_people[y]+1)-p->course[x].result_score)/(inf_class[p->stu_class_num].course_people[y]*1.0);
//            }
//        }
//        inf_class[p->stu_class_num].inpustu--;
//        inf_class[p->stu_class_num].stu_num--;
//        l->next=p->next;
//        p->next=NULL;
//        return;
    case 2:
        break;
    }
    return;
};
