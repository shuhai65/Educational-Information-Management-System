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



struct Student *getfile_stu(linkStudent &L)
{
//    printf ("!!!");
    FILE *fp,*fq,*fa;
    fp=fopen("student.txt","a+");
    fq=fopen("student_course.txt","a+");
    fa=fopen("student_rebuilt.txt","a+");
    int i,j,flag=0;
    L=new Student;
    L->next=NULL;
    linkStudent p,head,r;
    p=new Student;
    head=new Student;
    r=new Student;
    r=L;
    L->next=p;
    head=L;
    while ((fscanf(fp,"%s %s %s %s %s %s %d %d %d %s %d %d %s %d",
                   p->stu_num,p->name,p->sex,p->phone_num,p->grade,p->major,
                   &p->age,&p->dor_num,&p->stu_class_num,p->stu_class_name,
                   &p->credit,&p->choose_course_num,p->classnumber_char,&p->classpoint))!=EOF)
    {
        for (j=0; j<p->choose_course_num; j++)
        {
            fscanf(fp,"%d",&p->coursepoint[j]);
        }
        p->next=NULL;
        r->next=p;
        p->flag=1;
        for(i=0; i<p->choose_course_num; i++)
        {
//            fscanf(fq,"%d %s %f %f %f %d %s %d",&p->course[i].course_num,p->course[i].name,
//                   &p->course[i].test_score,&p->course[i].usual_score,&p->course[i].result_score,
//                   &p->course[i].credit,p->course[i].rebuilt,&p->course[i].flag);
            fscanf(fq,"%d %s %d %s %d",&p->course[i].course_num,p->course[i].name,
                   &p->course[i].credit,p->course[i].rebuilt,&p->course[i].flag);
            if (p->course[i].flag==1)
            {
                fscanf(fq,"%f %f %f",&p->course[i].test_score,&p->course[i].usual_score,&p->course[i].result_score);
            }
            fscanf(fa,"%d",&p->course[i].rebuilt_num);
            for (j=0; j<p->course[i].rebuilt_num; j++)
            {
                fscanf(fa,"%s %f",p->course[i].rebuit_inf.term[j],&p->course[i].rebuit_inf.score[j]);
            }
        }
        flag=1;
        r=p;
        p=new Student;
    }
    if (flag==0)
    {
        L->next=NULL;
    }
    fclose(fp);
    return head;
};
