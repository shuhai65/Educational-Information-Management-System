#include <iostream>
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


int main()
{
    welcome();
    linkStudent inf_student;
    linkCourse inf_course;
    linkClass inf_class;
    linklocate_course lo_course;
    linklocate_class lo_class;
    inf_course=(struct Course *)malloc(200*sizeof(struct Course));
    inf_class=(struct Class *)malloc(200*sizeof(struct Class));
    int Max1=200,Max2=200,num1=1,num2=1;
    inf_student=getfile_stu(inf_student);
    while((num1=getfile_class(inf_class,lo_class,Max1))!=0)
    {
        if (num1>Max1)
        {
            inf_class=(struct Class *)realloc(inf_class,(num1+10)*sizeof(struct Class));
            Max1=num1+10;
        }
    }
    while ((num2=getfile_course(inf_course,lo_course,Max2))!=0)
    {
        if (num2>Max2)
        {
            inf_course=(struct Course *)realloc (inf_course,(num2+10)*sizeof(struct Course));
            Max2=num2+10;
        }
    }
    menu(inf_student,inf_course,inf_class,lo_course,lo_class,Max1,Max2);
    return 0;
}
