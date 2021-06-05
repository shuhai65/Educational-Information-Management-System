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

void output_class (Class inf_class[],linklocate_class lo_class)
{
    FILE *fp,*fa,*fb,*fc;
    fp=fopen("class_base.txt","w+");
    fa=fopen("class_course.txt","w+");
    fb=fopen("class_score.txt","w+");
    fc=fopen("class_stu_name.txt","w+");
    int i;
    linklocate_class p;
    p=new locate_class;
    p=lo_class->next;
    while(1)
    {
        fprintf(fp,"%d %s %d %s %s %d",inf_class[p->num].numbing,inf_class[p->num].class_num,
               inf_class[p->num].stu_num,inf_class[p->num].class_name,inf_class[p->num].grade,inf_class[p->num].course_num);
        fputc('\n',fp);
        for (i=0;i<inf_class[p->num].course_num;i++)
        {
            fprintf(fa,"%d %s ",inf_class[p->num].course_people[i],inf_class[p->num].course[i]);
            fprintf(fb,"%f ",inf_class[p->num].averscore[i]);
        }
        fputc('\n',fa);
        fputc('\n',fb);
        fprintf(fc,"%d ",inf_class[p->num].inpustu);
        for (i=0;i<inf_class[p->num].inpustu;i++)
        {
            fprintf(fc,"%s ",inf_class[p->num].stu_name[i]);
        }
        fputc('\n',fc);
        if (p->next==NULL)
        {
            break;
        }
        p=p->next;
    }
    fclose(fp);
    fclose(fa);
    fclose(fb);
    fclose(fc);
};
