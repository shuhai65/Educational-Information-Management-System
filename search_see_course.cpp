#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include"function.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
using namespace std;

void search_see_course(Course L[],linklocate_course lo_course)
{
    int i,num,j,k,flag=0,x,y,z=0;
    int t;
    printf ("\t\t\t请输入查询的课程名:");
    char po[50],re_course[400][40];
    int ppp,hhh;
    int temp[100]= {0};
    scanf ("%s",po);
    hhh=search_course(L,po,re_course,lo_course,temp);
    while (hhh==0)
    {
        printf ("\t\t\t无法查询到该课程\n");
        printf ("\t\t\t请重新输入查询:");
        for (i=0; po[i]!='\0'; i++)
        {
            po[i]='\0';
        }
        scanf("%s",po);
        hhh=search_course(L,po,re_course,lo_course,temp);
    }
    for (ppp=0; ppp<hhh; ppp++)
    {
        printf ("\t\t\t%s",re_course[ppp]);
        printf ("\t课程编号:%d\n\n",temp[ppp]);
    }
    printf ("\t\t\t请选择是否查询课程具体信息(输入1继续，输入2取消):");
    scanf ("%d",&z);
    if (z==2)
    {
        return ;
    }
    printf ("\n\t\t\t请输入所要查询的课程编号:");
    scanf ("%d",&num);
    printf ("\t\t\t课程名称:%s\n",L[num].name);
    printf ("\t\t\t课程人数:%d\n",L[num].Stu_num);
    printf ("\t\t\t课程学分:%d\n",L[num].score);
    printf ("\t\t\t\t\t课表\n");
    for (x=1,z=1; x<8; x++)
    {
        for (y=1; y<14; y++)
        {
            if (L[num].time[y][x]==1)
            {
                printf ("\t\t\t");
                printf ("星期");
                if (x==1)
                {
                    printf ("一");
                }
                else if (x==2)
                {
                    printf ("二");
                }
                else if (x==3)
                {
                    printf ("三");
                }
                else if (x==4)
                {
                    printf ("四");
                }
                else if (x==5)
                {
                    printf ("五");
                }
                else if (x==6)
                {
                    printf ("六");
                }
                else if (x==7)
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
    printf ("\t\t\t请选择是否查看该课程所有学生信息,输入1查看，输入2取消:");
    scanf("%d",&t);
    if (t==2)
    {
        return;
    }
    else
    {
        if(L[num].instu>=1)
        {
            printf ("\t\t\t\t学生信息\n");
        }else
        {
            printf ("\t\t\t\t暂未录入学生信息\n");
        }

        for (i=0; i<L[num].instu&&L[num].stu_name[i][0]!='\0'; i++)
        {
            flag=0;
            printf ("\t\t\t\t学生姓名:%s\n",L[num].stu_name[i]);
            printf ("\t\t\t\t成绩:");
            for(j=0,k=0; j<3&&L[num].stu_score[i][k]!='\0'; k++)
            {
                printf ("%c",L[num].stu_score[i][k]);
                if (L[num].stu_score[i][k]=='.')
                {
                    flag=1;
                }
                if (flag==1)
                {
                    j++;
                }
            }
            printf("\n\n");
        }
    }

};
