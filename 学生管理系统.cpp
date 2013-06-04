#include <stdio.h>
#include <stdlib.h>
/*��ҵ��������*/
void addStudent();
void deleteStudent();
void queryStudent();
void updateStudent();
void sort();
void displayAll();//��ʾ������Ϣ
int readData();
int writeData();
/*����ҵ��������*/
int findIndex(int no);
void displayCurrent(int tag); //tag��ʾ�±�
void welcome();//��ӭ
void mainmenu();//���˵�

/*���ݽṹ��ȫ�ֱ���*/
struct student      	
{  
     int no;
     char name[20];
	 char sex;	
     int  age;
	 float  score;	
};
struct student  students[42]; //����ȫ�ֱ������洢42��ѧ����Ϣ
int maxTag = -1;//����±�
FILE *fp;//�ļ�ָ��
main()
{
	
	welcome();//��ӭ����
	maxTag = readData();//��ҵ��ѡ�����ǰ���ļ�����������±�
    printf("maxTag=%d\n",maxTag);
	mainmenu();
}
void welcome()//��ӭ
{
    printf("|-------------------------------|\n");
	printf("|    ��ӭ����ѧ������ϵͳ       |\n");
	printf("|-------------------------------|\n");
}
void mainmenu()//���˵�
{
	int chooser;
  	while(1)
	{
		printf("1 ����ѧ����Ϣ\n");
		printf("2 ɾ��ѧ����Ϣ\n");
		printf("3 �޸�ѧ����Ϣ\n");
		printf("4 ����ѧ����Ϣ\n");
		printf("5 ����\n");
		printf("6 ��ѯȫ����Ϣ\n");
		printf("0 �˳�ϵͳ\n");
		printf("��ѡ��ҵ��");
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
			default:printf("����ѡ������\n");
		}

	}

}
//����ѧ��
void  addStudent()
{
   char answer;
   int flag=0;//д�ļ��ɹ���־
   while(1)
   {
	  maxTag++;//��������֮ǰ�±�����1
	  printf("������ѧ����Ϣ��ѧ�� ���� �Ա�  ���� �ɼ�\n");
	  scanf("%d %s %c %d %f",
		  &students[maxTag].no,
		  students[maxTag].name,
		  &students[maxTag].sex,
		  &students[maxTag].age,
		  &students[maxTag].score);
	  //��ʾ��ǰѧ����Ϣ
	  displayCurrent(maxTag);
	  //д�ļ�
	  flag = writeData();
	  if(flag==1)
	  {
		printf("��ӳɹ���\n");
	  }
	  else
	  {
		printf("���ʧ�ܣ�\n");
	  }
	  //��ʾ�Ƿ����
	  printf("�Ƿ��������(y)��(n):");
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
//ɾ��ѧ��
void deleteStudent()
{

}
//����ѧ��
void queryStudent()
{

}
//�޸�ѧ��
void updateStudent()
{

}
//����
void sort()
{

}
//���ļ�,��������±�
int readData()
{
  int i=0;
  //���ļ�
  if((fp=fopen("studentinfo.txt","r"))==NULL)
  {
	 //��ʾ����
	  printf("���ļ�ʧ�ܣ�");
	  exit(1);//�˳�����
  }
  //���ļ�,��ȷ���ļ��ж�����Ϣ��ʹ��ѭ��
  while(1)
  {
	 //�ж��ļ�����
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
	 i++;//����һ�����ݺ��±���1
  }
  //�ر��ļ�
  fclose(fp);
  return i-2;//�������
}
//д�ļ�
int writeData()
{
  int i;
	//���ļ�
  if((fp=fopen("studentinfo.txt","w"))==NULL)
  {
	 //��ʾ����
	  printf("���ļ�ʧ�ܣ�");
	  return 0;
  }
  //д�ļ�
  for(i=0;i<=maxTag;i++)
  {
	 fprintf(fp,"%d %s %c %d %f\n",
		 students[i].no,
		 students[i].name,
		 students[i].sex,
		 students[i].age,
		 students[i].score);
  }
  //�ر��ļ�
  fclose(fp);
  return 1;
}
// ����λ��
int findIndex(int no)
{
  return 0;
}
//��ʾ��ǰ��Ϣ
void displayCurrent(int tag) //tag��ʾ�±�
{
  printf("%-8s%-8s%-8s%-8s%-8s\n","ѧ��","����","�Ա�","����","�ɼ�");
  printf("%-8d%-8s%-8c%-8d%-8.2f\n",
	  students[tag].no,
	  students[tag].name,
	  students[tag].sex,
	  students[tag].age,
	  students[tag].score);
}
void displayAll()//��ʾ������Ϣ
{ 
	int i;
    printf("%-8s%-8s%-8s%-8s%-8s\n","ѧ��","����","�Ա�","����","�ɼ�");
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