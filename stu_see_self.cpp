#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include"function.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
using namespace std;
void stu_see_self(linkStudent Stu,char name[])
{
    gotoxy(40,3);
    printf ("查看个人信息\n");
    printf ("\t\t----------------------------------------------------------------\n");
    linkStudent p;
    p=new Student;
    p=Stu;
    while (strcmp(name,p->stu_num)!=0&&p->next!=NULL)
    {
        p=p->next;
    }

    printf ("\t\t\t姓名:%s\n",p->name);
    printf ("\t\t\t性别:%s\n",p->sex);
    printf ("\t\t\t手机号:%s\n",p->phone_num);
    printf ("\t\t\t年级:%s\n",p->grade);
    printf ("\t\t\t专业:%s\n",p->major);
    printf ("\t\t\t年龄:%d\n",p->age);
    printf ("\t\t\t宿舍号:%d\n",p->dor_num);
    printf ("\t\t\t班级编号:%d\n",p->stu_class_num);
    printf ("\t\t\t班级名称:%s\n",p->stu_class_name);
    printf ("\t\t\t所选课程数:%d\n",p->choose_course_num);
    printf ("\t\t\t已修学分:%d\n\n",p->credit);
    int i;
    if (p->choose_course_num>0)
    {
        printf ("\t\t\t\t课程具体信息\n\n");
    }

    for (i=0; i<p->choose_course_num; i++)
    {
        printf ("\t\t\t%d.%s\n",i+1,p->course[i].name);
        if (p->course[i].flag==1)
        {
            if(strcmp(p->course[i].rebuilt,"是")==0)
            {
                printf ("\t\t\t该课程属于重修\n");
            }
            printf ("\t\t\t考试成绩:%.2f\n\t\t\t平时成绩:%.2f\n\t\t\t综合成绩:%.2f\n\n",p->course[i].test_score,p->course[i].usual_score,p->course[i].result_score);
        }
        else
        {
            printf ("\t\t\t本课程暂时未录入成绩\n");
        }
    }
    printf ("\t\t\t\t\tComplete\n\n");
    printf ("\t\t----------------------------------------------------------------\n");
    printf ("\t\t\t");
    system("pause");
};
