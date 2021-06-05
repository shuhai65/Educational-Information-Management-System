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

int getfile_class(Class L[],linklocate_class &S,int Max)
{
    //建立链表
    S=new locate_class;
    linklocate_class r;
    linklocate_class p;
    r=new locate_class;
    S->next=NULL;
    r=S;
    //建立链表
    FILE *fp,*fa,*fb,*fc;
    fp=fopen("class_base.txt","a+");
    fa=fopen("class_course.txt","a+");
    fb=fopen("class_score.txt","a+");
    fc=fopen("class_stu_name.txt","a+");
    int i=0,number;
    while((fscanf(fp,"%d",&number))!=EOF)
    {
        //读取位置储存
        p=new locate_class;
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
        L[number].numbing=number;
        fscanf(fp,"%s %d %s %s %d",L[number].class_num,
               &L[number].stu_num,L[number].class_name,L[number].grade,&L[number].course_num);
        for (i=0; i<L[number].course_num; i++)
        {
            fscanf(fa,"%d %s",&L[number].course_people[i],L[number].course[i]);
            fscanf(fb,"%f",&L[number].averscore[i]);
        }
        fscanf(fc,"%d",&L[number].inpustu);
        for (i=0;i<L[number].inpustu;i++)
        {
            fscanf(fc,"%s",L[number].stu_name[i]);
        }
        L[number].flag=1;
    }
    fclose(fp);
    fclose(fa);
    fclose(fb);
    return 0;
};
