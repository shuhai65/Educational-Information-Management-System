#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef struct locate_course
{
    int num;
    struct locate_course *next;
} locate_course,*linklocate_course;

typedef struct locate_class
{
    int num;
    struct locate_class *next;
} locate_class,*linklocate_class;

typedef struct inf_rebuilt
{
    char term[10][25];//重修学期
    float score[10]={0.0};//重修分数
}inf_rebuilt;

typedef struct Course
{
    int flag=0;
    int numbering=0;//课程编号
    int Stu_num=0;//课程学生人数
    int instu=0;//已经录入的学生人数
    int section=0;//上课次数
    int time[14][8]={0};//上课时间
    int score;//课程学分
    char name[40];//课程名称
    char stu_name[1000][10];//学生名字
    char stu_score[1000][10];//学生成绩
    struct Class *next;
} Course,*linkCourse;

typedef struct Stu_course
{
    int course_num=0;//课程编号
//    int section={0};//上课次数
//    int time[14][8]={0};//上课时间
    char name[40];//课程名称
    float test_score=0;//考试成绩
    float usual_score=0;//平时成绩
    float result_score=0;//综合成绩
    int credit=0;//学分
    int flag=0;//是否考试
//    char if_test[6];//是否考试
    char rebuilt[6];//是否重修
    int rebuilt_num=0;//重修次数
    inf_rebuilt rebuit_inf;//重修具体信息
} Stu_course;

typedef struct Student
{
    int flag=0;//判断是否是文件中最后一个节点
    char stu_num[20];//学号
    char name[10];//姓名
    char sex[10];//性别
    char phone_num[20];//手机号
    char grade[6];//年级
    char major[20];//专业
    int age=0;//年龄
    int dor_num=0;//宿舍号
    int stu_class_num=0;//班级编号
    char classnumber_char[15];//班级号
    char stu_class_name[40];//班级名称
    int classpoint=0;
    int coursepoint[50]={0};
    int credit=0;//已修学分
    int choose_course_num=0;//已选课程数(当前仍在修)
    Stu_course course[50];//所选课程的具体信息
    struct Student *next;
} Student,*linkStudent;


typedef struct Class
{
    int flag=0;
    int numbing=0;//班级编号
    char class_num[15];//班级号
    int stu_num=0;//学生人数
    char class_name[40];//班级名称
    char grade[25];//年级

    int inpustu=0;//已经录入的学生人数
    char stu_name[50][20];//学生姓名

    int course_num=0;//已选课程数
    int course_people[100]={0};//课程人数
    char course[100][20];//已选课程
    float averscore[100]= {0.0}; //平均成绩
    struct Class *next;
} Class,*linkClass;

struct Student *getfile_stu(linkStudent &L);
int getfile_class(Class L[],linklocate_class &S,int Max);
int getfile_course(Course L[],linklocate_course &S,int Max);

void welcome();
void gotoxy(int x,int y);
void print_head();

void menu(linkStudent inf_student,linkCourse inf_course,linkClass inf_class,linklocate_course lo_course,linklocate_class lo_class,int Max1,int Max2);

int login(char name[]);
void Register();
int if_loginuser(char username[],char password[]);
void get_password(char *pswd, int maxlen);



void input(linkStudent inf_student,Course inf_course[],Class inf_class[],
           linklocate_course lo_course,linklocate_class lo_class,int &Max1,int &Max2);
int input_class(Class L[],linklocate_class &lo_class,int Max,int flag);
int input_course(Course inf_course[],linklocate_course &lo_course,int Max,int flag);
void input_stu(linkStudent &inf_student,Course inf_course[],Class inf_class[],linklocate_course lo_course,linklocate_class lo_class);
void input_stu_score(linkStudent Stu,Course inf_course[],Class inf_class[]);
void input_stu_course(linkStudent &Stu,Course inf_course[],Class inf_class[],linklocate_course lo_course,linklocate_class lo_class);
void input_stu_self_course(linkStudent &Stu,Course inf_course[],Class inf_class[],linklocate_course lo_course,linklocate_class lo_class,char name[]);
void input_T(linkStudent inf_student,Course inf_course[],Class inf_class[],
           linklocate_course lo_course,linklocate_class lo_class,int &Max1,int &Max2);

void view(linkStudent inf_student,Course inf_course[],Class inf_class[],linklocate_course lo_course,linklocate_class lo_class);
void see_stu(linkStudent Stu);
void see_class(Class L[]);
void see_course(Course L[],linklocate_course lo_course);
void stu_see_self(linkStudent Stu,char name[]);
void see_all_stu(linkStudent Stu);
void see_stu_course(Course L[],linklocate_course lo_course);
void search_see_course(Course L[],linklocate_course lo_course);



void administrator(linkStudent inf_student,Course inf_course[],Class inf_class[],linklocate_course lo_course,linklocate_class lo_class,int Max1,int Max2);
void teacher(linkStudent inf_student,Course inf_course[],Class inf_class[],linklocate_course lo_course,linklocate_class lo_class,int Max1,int Max2);
void student(linkStudent inf_student,Course inf_course[],Class inf_class[],char name[],linklocate_course lo_course,linklocate_class lo_class);

struct locate_course *findlast_locourse(linklocate_course L);
struct locate_class *findlast_loclass(linklocate_class L);

int search_course(Course inf_course[],char c[],char re_course[][40],linklocate_course S,int temp[]);

void output_course(Course inf_course[],linklocate_course lo_course);
void output_class (Class inf_class[],linklocate_class lo_class);
void output_stu(linkStudent L);

void modify(linkStudent &inf_student,Course inf_course[],Class inf_class[],
           linklocate_course lo_course,linklocate_class lo_class,int &Max1,int &Max2);
void modify_stu(linkStudent &inf_student,Course inf_course[],Class inf_class[]);
void dele_stu(linkStudent &inf_student,Course inf_course[],Class inf_class[]);

//void modify_stu_self(linkStudent &inf_student,Course inf_course[],Class inf_class[],char name[]);

#endif // FUNCTION_H_INCLUDED
