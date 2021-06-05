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
void output_course(Course inf_course[],linklocate_course lo_course)
{
    FILE *fp,*fb,*fc,*fd;
    fp=fopen("course_base.txt","w+");
    fb=fopen("course_stuname.txt","w+");
    fc=fopen("course_stuscore.txt","w+");
    fd=fopen("course_time.txt","w+");
    int i,j;
    linklocate_course p;
    p=new locate_course;
    p=lo_course->next;
    while(1)
    {
        fprintf(fp,"%d %d %d %d %s %d ",inf_course[p->num].numbering,
                inf_course[p->num].Stu_num,inf_course[p->num].instu,
                inf_course[p->num].score,inf_course[p->num].name,inf_course[p->num].section);
        fputc('\n',fp);
        for (i=0;i<inf_course[p->num].instu;i++)
        {
            fprintf(fb,"%s ",inf_course[p->num].stu_name[i]);
            fprintf(fc,"%s ",inf_course[p->num].stu_score[i]);
        }
        fputc('\n',fb);
        fputc('\n',fc);
        for (i=1;i<14;i++)
        {
            for (j=1;j<8;j++)
            {
                fprintf(fd,"%d ",inf_course[p->num].time[i][j]);
            }
            fputc('\n',fd);
        }
        if (p->next==NULL)
        {
            break;
        }
        p=p->next;
    }
    fclose(fp);
    fclose(fb);
    fclose(fc);
    fclose(fd);
};
