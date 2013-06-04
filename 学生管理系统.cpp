#include <stdio.h>
#include <stdlib.h>
/*主业务函数声明*/
void addStudent();
void deleteStudent();
void queryStudent();
void updateStudent();
void sort();
void displayAll();//显示所有信息
int readData();
int writeData();
/*辅助业务函数声明*/
int findIndex(int no);
void displayCurrent(int tag); //tag表示下标
void welcome();//欢迎
void mainmenu();//主菜单

/*数据结构和全局变量*/
struct student      	
{  
     int no;
     char name[20];
	 char sex;	
     int  age;
	 float  score;	
};
struct student  students[42]; //声明全局变量，存储42个学生信息
int maxTag = -1;//最大下标
FILE *fp;//文件指针
main()
{
	
	welcome();//欢迎界面
	maxTag = readData();//在业务选择界面前读文件，返回最大下标
    printf("maxTag=%d\n",maxTag);
	mainmenu();
}
void welcome()//欢迎
{
    printf("|-------------------------------|\n");
	printf("|    欢迎进入学生管理系统       |\n");
	printf("|-------------------------------|\n");
}
void mainmenu()//主菜单
{
	int chooser;
  	while(1)
	{
		printf("1 增加学生信息\n");
		printf("2 删除学生信息\n");
		printf("3 修改学生信息\n");
		printf("4 查找学生信息\n");
		printf("5 排序\n");
		printf("6 查询全部信息\n");
		printf("0 退出系统\n");
		printf("请选择业务：");
		scanf("%d",&chooser);
		switch(chooser)
		{
			case 1:addStudent();break;
			case 2:deleteStudent();break;
			case 3:updateStudent();break;
			case 4:queryStudent();break;
			case 5:sort();break;
			case 6:displayAll();break;
			case 0:exit(0);
			default:printf("您的选择有误\n");
		}

	}

}
//增加学生
void  addStudent()
{
   char answer;
   int flag=0;//写文件成功标志
   while(1)
   {
	  maxTag++;//增加数据之前下标先增1
	  printf("请输入学生信息：学号 姓名 性别  年龄 成绩\n");
	  scanf("%d %s %c %d %f",
		  &students[maxTag].no,
		  students[maxTag].name,
		  &students[maxTag].sex,
		  &students[maxTag].age,
		  &students[maxTag].score);
	  //显示当前学生信息
	  displayCurrent(maxTag);
	  //写文件
	  flag = writeData();
	  if(flag==1)
	  {
		printf("添加成功！\n");
	  }
	  else
	  {
		printf("添加失败！\n");
	  }
	  //提示是否继续
	  printf("是否继续：是(y)否(n):");
	  fflush(stdin);
	  scanf("%c",&answer);
	  if(answer=='y')
	  {
		continue;
	  }
	  else
	  {
		break;
	  }

   }
}
//删除学生
void deleteStudent()
{

}
//查找学生
void queryStudent()
{

}
//修改学生
void updateStudent()
{

}
//排序
void sort()
{

}
//读文件,返回最大下标
int readData()
{
  int i=0;
  //打开文件
  if((fp=fopen("studentinfo.txt","r"))==NULL)
  {
	 //提示错误
	  printf("打开文件失败！");
	  exit(1);//退出程序
  }
  //读文件,不确定文件有多少信息，使用循环
  while(1)
  {
	 //判断文件结束
	  if(feof(fp))
	  {
		 break;
	  }
	 fscanf(fp,"%d %s %c %d %f",
		 &students[i].no,
		 students[i].name,
		 &students[i].sex,
		 &students[i].age,
		 &students[i].score);
	 i++;//读完一条数据后下标增1
  }
  //关闭文件
  fclose(fp);
  return i-2;//多读两行
}
//写文件
int writeData()
{
  int i;
	//打开文件
  if((fp=fopen("studentinfo.txt","w"))==NULL)
  {
	 //提示错误
	  printf("打开文件失败！");
	  return 0;
  }
  //写文件
  for(i=0;i<=maxTag;i++)
  {
	 fprintf(fp,"%d %s %c %d %f\n",
		 students[i].no,
		 students[i].name,
		 students[i].sex,
		 students[i].age,
		 students[i].score);
  }
  //关闭文件
  fclose(fp);
  return 1;
}
// 查找位置
int findIndex(int no)
{
  return 0;
}
//显示当前信息
void displayCurrent(int tag) //tag表示下标
{
  printf("%-8s%-8s%-8s%-8s%-8s\n","学号","姓名","性别","年龄","成绩");
  printf("%-8d%-8s%-8c%-8d%-8.2f\n",
	  students[tag].no,
	  students[tag].name,
	  students[tag].sex,
	  students[tag].age,
	  students[tag].score);
}
void displayAll()//显示所有信息
{ 
	int i;
    printf("%-8s%-8s%-8s%-8s%-8s\n","学号","姓名","性别","年龄","成绩");
    for(i=0;i<=maxTag;i++)
	{
		printf("%-8d%-8s%-8c%-8d%-8.2f\n",
	  students[i].no,
	  students[i].name,
	  students[i].sex,
	  students[i].age,
	  students[i].score);
	}
}