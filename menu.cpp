#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
void menu(linkStudent inf_student,linkCourse inf_course,linkClass inf_class,linklocate_course lo_course,linklocate_class lo_class,int Max1,int Max2)
{
    char flag;
    int flag1=0;
    char username[20];
    flag=login(username);
    system("cls");
    if (flag==1)//管理员
    {
        administrator(inf_student,inf_course,inf_class,lo_course,lo_class,Max1,Max2);
    }else if (flag==2)//教师
    {
        teacher(inf_student,inf_course,inf_class,lo_course,lo_class,Max1,Max2);
    }else if(flag==3)//学生
    {
        student(inf_student,inf_course,inf_class,username,lo_course,lo_class);
    }
};
