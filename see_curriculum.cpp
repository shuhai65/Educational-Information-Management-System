#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include"function.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
using namespace std;

void see_curriculum(linkStudent inf_student,Course inf_course[],Class inf_class[],linklocate_course lo_course,linklocate_class lo_class,char name[])
{
    gotoxy(40,3);
    printf ("查看课程\n");
    printf ("\t\t----------------------------------------------------------------\n");
    linkStudent p;
    p=new Student;
    p=inf_student;
    while (strcmp(name,p->stu_num)!=0&&p->next!=NULL)
    {
        p=p->next;
    }
    int curriculum[14][8]={0};

};
