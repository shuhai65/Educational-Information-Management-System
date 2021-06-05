#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int if_loginuser(char username[],char password[])
{
    FILE *fp,*fq;
    char USERNAME[20][20];
    char PASSWORD[20][20];
    fp=fopen("name_M.txt","a+");
    fq=fopen("pass_M.txt","a+");
    int i=0,n,len;
    for(i=0;((fgets(USERNAME[i],20,fp))!=NULL);i++)
    {
        len=strlen(USERNAME[i]);
        if (USERNAME[i][len-1]=='\n')
        {
            USERNAME[i][len-1]='\0';
        }
    }
    n=i;
    for(i=0;((fgets(PASSWORD[i],20,fq))!=NULL);i++)
    {
        len=strlen(PASSWORD[i]);
        if (PASSWORD[i][len-1]=='\n')
        {
            PASSWORD[i][len-1]='\0';
        }
    }
    for (i=0;i<n;i++)
    {
        if (strcmp(USERNAME[i],username)==0&&strcmp(PASSWORD[i],password)==0)
        {
            fclose(fp);
            return 1;
        }
//        printf ("%s\n",PASSWORD[i]);
    }
    fclose(fq);
    fp=fopen("name_T.txt","a+");
    fq=fopen("pass_T.txt","a+");
    for(i=0;((fgets(USERNAME[i],20,fp))!=NULL);i++)
    {
        len=strlen(USERNAME[i]);
        if (USERNAME[i][len-1]=='\n')
        {
            USERNAME[i][len-1]='\0';
        }
    }
    n=i;
    for(i=0;((fgets(PASSWORD[i],20,fq))!=NULL);i++)
    {
        len=strlen(PASSWORD[i]);
        if (PASSWORD[i][len-1]=='\n')
        {
            PASSWORD[i][len-1]='\0';
        }
    }
    for (i=0;i<n;i++)
    {
        if (strcmp(USERNAME[i],username)==0&&strcmp(PASSWORD[i],password)==0)
        {
            fclose(fp);
            return 2;
        }
//        printf ("%s\n",PASSWORD[i]);
    }
    fclose(fq);
    fp=fopen("name_S.txt","a+");
    fq=fopen("pass_S.txt","a+");
    for(i=0;((fgets(USERNAME[i],20,fp))!=NULL);i++)
    {
        len=strlen(USERNAME[i]);
        if (USERNAME[i][len-1]=='\n')
        {
            USERNAME[i][len-1]='\0';
        }
    }
    n=i;
    for(i=0;((fgets(PASSWORD[i],20,fq))!=NULL);i++)
    {
        len=strlen(PASSWORD[i]);
        if (PASSWORD[i][len-1]=='\n')
        {
            PASSWORD[i][len-1]='\0';
        }
    }
    for (i=0;i<n;i++)
    {
        if (strcmp(USERNAME[i],username)==0&&strcmp(PASSWORD[i],password)==0)
        {
            fclose(fp);
            return 3;
        }
//        printf ("%s\n",PASSWORD[i]);
    }
    fclose(fq);
    return 0;
};
