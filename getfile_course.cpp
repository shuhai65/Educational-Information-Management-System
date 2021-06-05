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

int getfile_course(Course L[],linklocate_course &S,int Max)
{
    //建立链表
    S=new locate_course;
    linklocate_course p,r;
    r=new locate_course;
    S->next=NULL;
    r=S;
    //建立链表
    FILE *fp,*fa,*fb,*fc;
    fp=fopen("course_base.txt","a+");
    fa=fopen("course_stuname.txt","a+");
    fb=fopen("course_stuscore.txt","a+");
    fc=fopen("course_time.txt","a+");
    int i=0,j=0;
    int number;
    while ((fscanf(fp,"%d",&number))!=EOF)
    {
        //读取位置储存
        p=new locate_course;
        p->num=number;
        p->next=NULL;
        r->next=p;
        r=p;
        //读取位置储存
        if (number>Max)
        {
            fclose(fp);
            fclose(fa);
            fclose(fb);
            return number;
        }
        L[number].numbering=number;
        fscanf(fp,"%d %d %d %s %d",&L[number].Stu_num,&L[number].instu,&L[number].score,L[number].name,&L[number].section);
//        printf ("%d %d %s %s\n",L[number].numbering,L[number].Stu_num,L[number].score,L[number].name);
        for (i=0; i<L[number].instu; i++)
        {
            fscanf(fa,"%s",L[number].stu_name[i]);
            fscanf(fb,"%s",L[number].stu_score[i]);
//            printf ("%s  %s\n",L[number].stu_name[i],L[number].stu_score[i]);
        }
//        L[number].time[1][1]={0};
        for (i=1;i<14;i++)
        {
            for (j=1;j<8;j++)
            {
                fscanf(fc,"%d",&L[number].time[i][j]);
//                printf ("%d ",L[number].time[i][j]);
            }
//            printf ("\n");
        }
        L[number].flag=1;
    }

    fclose(fp);
    fclose(fa);
    fclose(fb);
    fclose(fc);
    return 0;
};
