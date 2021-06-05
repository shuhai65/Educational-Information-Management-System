/*超重要功能函数*/

//移动光标，整个程序就全靠它了//


#include "function.h"
#include <windows.h>

void gotoxy(int x,int y)
{
    COORD p={x,y};      //将光标的目标移动位置传递给结构体//
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);  //获取当前函数句柄//
    SetConsoleCursorPosition(handle,p); //移动光标//
};

