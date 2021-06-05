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

struct locate_course *findlast_locourse(linklocate_course L)
{
    linklocate_course r;
    r=new locate_course;
    r=L;
    while(L->next!=NULL)
    {
        L=L->next;
        r=L;
    }
    return r;
};

int input_course(Course inf_course[],linklocate_course &lo_course,int Max,int flag)
{
    //找到尾节点
    linklocate_course p,r;
    p=new locate_course;
    r=new locate_course;
    r=findlast_locourse(lo_course);
    //找到尾节点
    int num,i,j,k;
    gotoxy(40,3);
    printf("录入课程信息\n");
    printf ("\t\t----------------------------------------------------------------\n");
    if (flag==0)
    {
        printf ("\t\t\t请输入课程编号(大于0的正整数):");
        scanf ("%d",&num);
        if (num>Max)
        {
            system("cls");
            return num;
        }
    }
    else
    {
        num=flag;
        printf ("\t\t\t请输入课程编号(大于0的正整数):%d\n",num);
    }
    //读取储存位置
    p->num=num;
    p->next=NULL;
    r->next=p;
    r=p;
    //读取储存位置
    inf_course[num].numbering=num;
    printf ("\t\t\t请输入课程名称:");
    scanf ("%s",inf_course[num].name);
    printf ("\t\t\t请输入课程学分:");
    scanf ("%d",&inf_course[num].score);
    printf ("\t\t\t请输入本课程一周上课节数:");
    scanf ("%d",&inf_course[num].section);
    for (i=0;i<inf_course[num].section;i++)
    {
        printf ("\n\t\t\t录入第%d节课上课时间\n",i+1);
        printf ("\t\t\t请输入本课程第%d节课于星期几上课(请输入大于等于1，小于等于7的数字)\n",i+1);
        printf ("\t\t\t例:星期一请输入“1”，星期天请输入“7”\n\t\t\t请输入:");
        scanf ("%d",&j);
        printf ("\t\t\t\t\t录入具体时间\n");
        printf ("\t\t\t第一节课    编号:1   上课时间：8:00-8:45\n");
        printf ("\t\t\t第二节课    编号:2   上课时间：8:50-9:35\n");
        printf ("\t\t\t第三节课    编号:3   上课时间：10:05-10:50\n");
        printf ("\t\t\t第四节课    编号:4   上课时间：10:55-11:40\n");
        printf ("\t\t\t第五节课    编号:5   上课时间：12:30-13:15\n");
        printf ("\t\t\t第六节课    编号:6   上课时间：13:20-14:05\n");
        printf ("\t\t\t第七节课    编号:7   上课时间：14:30-15:15\n");
        printf ("\t\t\t第八节课    编号:8   上课时间：15:20-16:05\n");
        printf ("\t\t\t第九节课    编号:9   上课时间：16:35-17:20\n");
        printf ("\t\t\t第十节课    编号:10  上课时间：17:25-18:10\n");
        printf ("\t\t\t第十一节课  编号:11  上课时间：19:30-20:15\n");
        printf ("\t\t\t第十二节课  编号:12  上课时间：20:20-21:05\n");
        printf ("\t\t\t第十三节课  编号:13  上课时间：21:10-21:55\n");
        printf ("\t\t\t请输入当天上课时间编号:");
        scanf ("%d",&k);
        inf_course[num].time[k][j]=1;
    }
    inf_course[num].flag=1;
    printf ("\t\t\t\t\t录入完成\n");
    printf ("\t\t----------------------------------------------------------------\n");
    printf ("\t\t\t");
    system("pause");
    return 0;
}
