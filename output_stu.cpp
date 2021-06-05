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

void output_stu(linkStudent L)
{
    FILE *fp,*fq,*fa;
    fp=fopen("student.txt","w+");
    fq=fopen("student_course.txt","w+");
    fa=fopen("student_rebuilt.txt","w+");
    int i,j;
    linkStudent p;
    p=new Student;
    p=L->next;
    while(1)
    {
        fprintf(fp,"%s %s %s %s %s %s %d %d %d %s %d %d %s %d ",
                p->stu_num,p->name,p->sex,p->phone_num,p->grade,p->major,
                p->age,p->dor_num,p->stu_class_num,p->stu_class_name,
                p->credit,p->choose_course_num,p->classnumber_char,p->classpoint);
        for (i=0; i<p->choose_course_num; i++)
        {
            fprintf(fp,"%d ",p->coursepoint[i]);
        }
        putc('\n',fp);
        for (i=0; i<p->choose_course_num; i++)
        {
//            fprintf(fq,"%d %s %f %f %f %d %s %d ",p->course[i].course_num,p->course[i].name,
//                    p->course[i].test_score,p->course[i].usual_score,p->course[i].result_score,
//                    p->course[i].credit,p->course[i].rebuilt,p->course[i].flag);
            fprintf(fq,"%d %s %d %s %d ",p->course[i].course_num,p->course[i].name,
                    p->course[i].credit,p->course[i].rebuilt,p->course[i].flag);
            if (p->course[i].flag==1)
            {
                fprintf(fq,"%f %f %f ",p->course[i].test_score,p->course[i].usual_score,p->course[i].result_score);
            }
            fprintf(fa,"%d ",p->course[i].rebuilt_num);
            if (p->course[i].rebuilt_num>0)
            {
                for (j=0; j<p->course[i].rebuilt_num; j++)
                {
                    fprintf(fa,"%s %f ",p->course[i].rebuit_inf.term[j],p->course[i].rebuit_inf.score[j]);
                }
            }
        }
        putc('\n',fq);
        putc('\n',fa);
        if (p->next==NULL)
        {
            break;
        }
        p=p->next;
    }
    fclose(fp);
    fclose(fq);
}
