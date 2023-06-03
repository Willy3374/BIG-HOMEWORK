#include<stdio.h>

int student,kemu;
int fenshu[100][100]={0},sum[100]={0};
char name[100][10],kemu_name[100][10];
int flag[100]={0};
//计算同学的平均成绩
void average_student(void)
{
	int sum;
	printf("************************************************************\n");
	int i,j;
	for(i=0;i<student;i++)
	{
		sum=0;
		for(j=0;j<kemu;j++)
		{
			sum+=fenshu[i][j];
		}
		printf("%s",name[i]);
		printf("同学的平均成绩为：%.2f\n",1.0*sum/kemu);
	}
	printf("************************************************************\n");
}

//计算科目的平均成绩
void average_kemu(void)
{
	int sum;
	printf("************************************************************\n");
	int i,j;
	for(i=0;i<kemu;i++)
	{
		sum=0;
		for(j=0;j<student;j++)
		{
			sum+=fenshu[j][i];
		}
		printf("%s",kemu_name[i]);
		printf("科目的平均成绩为：%.2f\n",1.0*sum/student);		
	}
	printf("************************************************************\n");
}
//初始化输入 
void shuru(void)
{
	printf("************************************************************\n欢迎使用基于数组和函数的成绩计算系统\n\n人数:");
	scanf("%d",&student);
	printf("科目数:");
	scanf("%d",&kemu);
	printf("\n"); 
	//输入科目名称
	int i,j;
	for(i=0;i<kemu;i++)
	{
		printf("科目%d:",i+1);
		scanf("%s",&kemu_name[i]);
	} 
	 printf("\n"); 
	 printf("//输入姓名和成绩\n") ;
	 //输入姓名和成绩
	 for(i=0;i<student;i++)
	 { 	printf("姓名 ");
	 	scanf("%s",&name[i]);	 
		for(j=0;j<kemu;j++)
		{
			printf("%s ",kemu_name[j]);
			scanf("%d",&fenshu[i][j]);
		}
		printf("\n");
	 }
}

//计算每位同学的总成绩 
void summ(void)
{
	printf("************************************************************\n");
	int i,j;
	for(i=0;i<student;i++)
	{
		sum[i]=0;
		for(j=0;j<kemu;j++)
		{
			sum[i]+=fenshu[i][j];
		}
		printf("%s",name[i]);
		printf("同学总分：%d\n",sum[i]);
	}
	printf("************************************************************\n");
}

//以关键字n降序编号 
//max---0............student-1---min
void jiangxu(int n)
{
	int i,j,max,max_name;
	
	for(i=0;i<100;i++)
	{
		flag[i]=-1;
	}
	
	for(i=0;i<student;i++)//分配编号 
	{
		max=0;max_name=0;
		for(j=0;j<student;j++)
		{
			if(fenshu[j][n]>max&&flag[j]==-1)
			{
				max=fenshu[j][n];
				max_name=j;
			}
		}
		//printf("%d %d",max_name ,i);
		flag[max_name]=i;
	}
}

//以关键字找前m位同学 
void xueba(void)
{
	int n,i,j,m;
	printf("关键字：\n");
	for(i=0;i<kemu;i++)
	{
		printf("%d %s\n",i,kemu_name[i]);
	}
	printf("\n");
	printf("输入编号即可\n");
	scanf("%d",&n);
	jiangxu(n);
	printf("\n");
	printf("寻找前m位同学\n"); 
	scanf("%d",&m);
	for(i=0;i<m&&i<student;i++)
	{
		for(j=0;j<student;j++)
		{
			if(flag[j]==i)
			{
				printf("%10s%10d\n",name[j],fenshu[j][n]);
			}
		}
	}
}

//以关键字找后n位同学 
void xuezha(void)
{
	int n,i,j,m;
	printf("关键字：\n");
	for(i=0;i<kemu;i++)
	{
		printf("%d %s\n",i,kemu_name[i]);
	}
	printf("\n");
	printf("输入编号即可\n");
	scanf("%d",&n);
	jiangxu(n);
	printf("\n");
	printf("寻找后m位同学\n"); 
	scanf("%d",&m);
	
	
	for(i=student-1;i>=student-m&&i>=0;i--)
	{
		for(j=0;j<student;j++)
		{
			if(flag[j]==i)
			{
				printf("%10s%10d\n",name[j],fenshu[j][n]);
			}
		}
	}
}

//增加新同学的成绩 
void add(void)
{	
	int i,j;
	int new_student;
	printf("************************************************************\n\n新增人数:");
	scanf("%d",&new_student);
	
			
	printf("//输入新增的姓名和成绩\n") ;
	 //输入姓名和成绩
	 for(i=student;i<student+new_student;i++)
	 { 	printf("姓名 ");
	 	scanf("%s",&name[i]);	 
		for(j=0;j<kemu;j++)
		{
			printf("%s ",kemu_name[j]);
			scanf("%d",&fenshu[i][j]);
		}
		printf("\n");
	 }
	 student+=new_student;
}

//等待界面 
void waiting(void)
{
	system("cls");	
	int i,j;
	printf("************************************************************\n\n");
	printf("%10s","姓名");
	for(i=0;i<kemu;i++)
	{
		printf("%10s",kemu_name[i]);
	}
	printf("\n");
	for(i=0;i<student;i++)
	{
		printf("%10s",name[i]);
		for(j=0;j<kemu;j++)
		{
			printf("%10d",fenshu[i][j]);
		}
		printf("\n");
	}
	printf("\n\n************************************************************\n\n");
	printf("************************************************************\n\n");
	printf("等待命令:\n1：计算总分\n2：计算科目的平均成绩\n3：计算同学的平均成绩\n4：找学霸\n5：找学渣\n6：增加同学\n\n");
	printf("************************************************************\n");
}

int main()
{
	shuru();
	while(1)
	{	
		waiting();		
		int mode;
		scanf("%d",&mode);
		switch (mode)
		{
			case 1:
				summ();
				break;
			case 2:
				average_kemu();
				break;
			case 3:
				average_student();
				break;
			case 4:
				xueba();
				break;
			case 5:
				xuezha();
				break;
			case 6:
				add();
				break;
		}
		system("pause");
	}
	return 0;
}
