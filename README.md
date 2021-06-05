# Educational-Information-Management-System
# 教务信息管理系统c/c++
> ### 注意：请使用code:bolcks打开 txt文档储存编码方式请使用ANSI。
> ### 您可以通过以下方式联系我
> gamil: shuhai.stack@gmail.com  
> qqmail: 562569322@qq.com  
> my Blog： https://blog.csdn.net/Tree_sea/article/details/117588842  
## 系统概述
当今时代是飞速发展的信息时代。在各行各业中离不开信息处理，这正是计算机被广泛应用于信息管理系统的环境。计算机的最大好处在于利用它能够进行信息管理。教务信息管理系统是一个教育单位不可缺少的部分，它的内容对于学校的决策者和管理者来说都至关重要，所以学生信息管理系统能为用户提供充足的信息和快捷的查询手段。系统主要功能分三类：一、用户登录。二、录入信息。三、查询信息。四、修改或删除信息。用户分为管理员，教师，学生三种身份，用户可以根据自己用户名和密码登录系统，系统会根据用户输入的用户名和密码确定用户身份，不同用户身份能使用系统的功能和权限不同。管理员拥有最高权限，可以为用户注册账号，管理员和教师均拥有录入，查询，修改信息权限，但是教师没有录入课程，班级信息权限，而学生仅能查看个人信息和选课。
## 功能需求描述
1. 登录模块：用户分为管理员，教师，学生三种身份，用户可以根据自己用户名和密码登录系统，系统会根据用户输入的用户名和密码确定用户身份，不同用户身份能使用系统的功能和权限不同。
2. 信息录入管理模块： 全部功能包括录入学生基本信息，课程基本信息，学生选课信息，学生成绩，班级信息。管理员拥有所有的录入信息权限；教师拥有录入学生基本信息，学生选课信息，学生成绩权限；学生仅拥有选课功能，即录入个人选课信息。
3. 信息查询管理模块：按学号查看学生信息，按班级编号查看班级信息(学生选课情况及考试成绩)，输入课程名称查询课程信息，查看所有学生已修学分及不及级课程。管理员和教师均拥有查看所以信息的权限，学生仅能查看自己个人信息和课程成绩。
4. 信息修改模块：修改学生信息，删除学生信息。仅教师和管理员拥有修改删除功能权限。
## 功能模块
1、总体开发思想：  
（1）主要的数据结构：  

系统对学生数据操作的主要数据结构是一个链表（如图），学生数据中储存学生基本信息和选课信息，选课信息为一个结构体数组，选课信息中储存选课基本信息和重修信息，重修信息为结构体数组储存于选课信息中。  
Student结构体是学生链表节点的类型，Stu_course结构体为student中学生所选课程数组的类型，inf_rebuilt结构体为Stu_course中学生课程重修信息数组的类型。        
        ![image](https://user-images.githubusercontent.com/68573382/120878332-3fe82980-c5ee-11eb-84b8-bb071410bd05.png)

   ![image](https://user-images.githubusercontent.com/68573382/120878378-9c4b4900-c5ee-11eb-8a51-52b25c03fff1.png)

对课程和班级的数据储存是结构体数组的形式，再分别以一个链表储存班级和课程数据储存位置。  
Course为储存课程信息的结构体数组类型，课程编号为课程储存位置，locate_course为储存课程信息于数组中位置的链表节点类型(如下图所示)。  
         ![image](https://user-images.githubusercontent.com/68573382/120878380-a705de00-c5ee-11eb-8842-f5893a928823.png)

  ![image](https://user-images.githubusercontent.com/68573382/120878389-aec58280-c5ee-11eb-8c89-77e4a1d4a3cb.png)

Class为储存班级信息的结构体数组类型，班级编号为班级储存位置，locate_class为储存班级信息于数组中位置的链表节点类型(如下图所示)。

  ![image](https://user-images.githubusercontent.com/68573382/120878398-c0a72580-c5ee-11eb-8511-3c4b50825915.png)
     ![image](https://user-images.githubusercontent.com/68573382/120878402-c43aac80-c5ee-11eb-8963-92cae7c4006a.png)

                      
（2）数据存贮方式：  
结构体数组，链表。  

（3）使用的语言：   
C++语言。  

2、
系统模块结构图：  
  ![image](https://user-images.githubusercontent.com/68573382/120878423-e03e4e00-c5ee-11eb-95e6-2be4c15f2a5f.png)


3、模块设计：以下为各个功能模块的流程图
 ![image](https://user-images.githubusercontent.com/68573382/120878437-ef250080-c5ee-11eb-9382-13e605573fba.png)
![image](https://user-images.githubusercontent.com/68573382/120878439-f21ff100-c5ee-11eb-84d3-3f0e152534af.png)
![image](https://user-images.githubusercontent.com/68573382/120878441-f51ae180-c5ee-11eb-843a-ab0f4c4051a0.png)
![image](https://user-images.githubusercontent.com/68573382/120878442-f8ae6880-c5ee-11eb-9bd6-336c318d8313.png)
![image](https://user-images.githubusercontent.com/68573382/120878443-fcda8600-c5ee-11eb-98c1-7f2d898df1f8.png)
![image](https://user-images.githubusercontent.com/68573382/120878445-ffd57680-c5ee-11eb-972a-97ad0a09a904.png)

       

                                                                
