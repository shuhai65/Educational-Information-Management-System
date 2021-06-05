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

void takestring(char c[],char take[],int i,int j)
{
    int x;
    for (x=0; i<=j; i++,x++)
    {
        take[x]=c[i];
    }
}


int search_course(Course inf_course[],char c[],char re_course[][40],linklocate_course S,int temp[])
{
    linklocate_course p;
    linklocate_course r;
    linklocate_course pp;
    linklocate_course rr;
    p=new locate_course;
    r=new locate_course;
    pp=new locate_course;
    rr=new locate_course;
    if (S->next==NULL)
    {
        printf ("\t\t\t\t\t未录入课程信息,请返回录入\n");
        return 0;
    }
    p=S->next;
    r=S;
    int i=0,j=0,flag=0,n=0,clean=0;
    int x=0,y=0;
    char take1[40];
    char take2[40];
    int tt=0;
    int temp1[100]={0};
    while(c[i]!='\0')
    {
        if (c[i]=='+')
        {
            n++;
        }
        i++;
    }
    if (n==0)
    {
        flag=1;
        n=1;
    }
    else
    {
        n++;
    }
    char name[n][40];
    for (i=0,j=0,x=0; c[i]!='\0'&&flag!=1; i++)
    {
        if (c[i]=='+')
        {
            takestring(c,take1,j,i-1);
            strcpy(name[x],take1);
            for (y=0; take1[y]!='\0'; y++)
            {
                take1[y]='\0';
            }
            x++;
            j=i+1;
        }
    }

    if (flag==1)
    {
        strcpy(name[0],c);
    }
    else
    {
        takestring(c,take1,j,i-1);
        strcpy(name[x],take1);
    }

    int flag1,big=0;
    char name1[400][40];
    y=0;
    pp=p;
    rr=r;
    tt=0;
    while(rr->next!=NULL)
    {

        for (i=0,flag1=0; i<strlen(inf_course[pp->num].name); i++)
        {
            flag1=0;
            for (j=i+1; j<=strlen(inf_course[pp->num].name); j++)
            {
                takestring(inf_course[pp->num].name,take2,i,j-1);
                if (strcmp(name[0],take2)==0)
                {
                    strcpy(name1[y],inf_course[pp->num].name);
                    temp1[tt]=inf_course[pp->num].numbering;

//                    printf ("第%d:%d\n",tt,temp1[tt]);
                    tt++;
                    big=1;
                    flag1=1;
                    break;
                }
                for (clean=0; take2[clean]!='\0'; clean++)
                {
                    take2[clean]='\0';
                }
            }
            if (flag1==1)
            {
                y++;
            }
        }
        if (pp->next!=NULL)
        {
            pp=pp->next;
        }
        rr=rr->next;
    }
//    printf ("y=%d big=%d\n",y,big);
    if (n==1)
    {
        if (big==1)
        {
            for (i=0;i<y;i++)
            {
                strcpy(re_course[i],name1[i]);
                temp[i]=temp1[i];
//                printf ("%d.%s",i+1,re_course[i]);
            }
            return y;
        }
        return 0;
    }

    if (big==0)
    {
        return 0;
    }

    int k,tempnum=y;
    int f;
    for (k=0,f=0,y=0,tt=0; k<tempnum&&n!=1; k++)
    {
        f=0;
        for (i=0; i<strlen(name1[k]); i++)
        {
            for (j=i+1; j<=strlen(name1[k]); j++)
            {
                takestring(name1[k],take2,i,j-1);
                if (strcmp(name[f+1],take2)==0)
                {
                    f++;
                    break;
                }
                for (clean=0; take2[clean]!='\0'; clean++)
                {
                    take2[clean]='\0';
                }
            }

        }
        if (f==n-1)
        {
            strcpy(re_course[y],name1[k]);
            temp[tt]=temp1[k];
//            printf ("temp[%d]=%d",tt,temp[tt]);
            tt++;
            y++;
        }
    }
    return y;
};
