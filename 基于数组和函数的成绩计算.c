#include<stdio.h>

int student,kemu;
int fenshu[100][100]={0},sum[100]={0};
char name[100][10],kemu_name[100][10];
int flag[100]={0};
//����ͬѧ��ƽ���ɼ�
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
		printf("ͬѧ��ƽ���ɼ�Ϊ��%.2f\n",1.0*sum/kemu);
	}
	printf("************************************************************\n");
}

//�����Ŀ��ƽ���ɼ�
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
		printf("��Ŀ��ƽ���ɼ�Ϊ��%.2f\n",1.0*sum/student);		
	}
	printf("************************************************************\n");
}
//��ʼ������ 
void shuru(void)
{
	printf("************************************************************\n��ӭʹ�û�������ͺ����ĳɼ�����ϵͳ\n\n����:");
	scanf("%d",&student);
	printf("��Ŀ��:");
	scanf("%d",&kemu);
	printf("\n"); 
	//�����Ŀ����
	int i,j;
	for(i=0;i<kemu;i++)
	{
		printf("��Ŀ%d:",i+1);
		scanf("%s",&kemu_name[i]);
	} 
	 printf("\n"); 
	 printf("//���������ͳɼ�\n") ;
	 //���������ͳɼ�
	 for(i=0;i<student;i++)
	 { 	printf("���� ");
	 	scanf("%s",&name[i]);	 
		for(j=0;j<kemu;j++)
		{
			printf("%s ",kemu_name[j]);
			scanf("%d",&fenshu[i][j]);
		}
		printf("\n");
	 }
}

//����ÿλͬѧ���ܳɼ� 
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
		printf("ͬѧ�ܷ֣�%d\n",sum[i]);
	}
	printf("************************************************************\n");
}

//�Թؼ���n������ 
//max---0............student-1---min
void jiangxu(int n)
{
	int i,j,max,max_name;
	
	for(i=0;i<100;i++)
	{
		flag[i]=-1;
	}
	
	for(i=0;i<student;i++)//������ 
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

//�Թؼ�����ǰmλͬѧ 
void xueba(void)
{
	int n,i,j,m;
	printf("�ؼ��֣�\n");
	for(i=0;i<kemu;i++)
	{
		printf("%d %s\n",i,kemu_name[i]);
	}
	printf("\n");
	printf("�����ż���\n");
	scanf("%d",&n);
	jiangxu(n);
	printf("\n");
	printf("Ѱ��ǰmλͬѧ\n"); 
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

//�Թؼ����Һ�nλͬѧ 
void xuezha(void)
{
	int n,i,j,m;
	printf("�ؼ��֣�\n");
	for(i=0;i<kemu;i++)
	{
		printf("%d %s\n",i,kemu_name[i]);
	}
	printf("\n");
	printf("�����ż���\n");
	scanf("%d",&n);
	jiangxu(n);
	printf("\n");
	printf("Ѱ�Һ�mλͬѧ\n"); 
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

//������ͬѧ�ĳɼ� 
void add(void)
{	
	int i,j;
	int new_student;
	printf("************************************************************\n\n��������:");
	scanf("%d",&new_student);
	
			
	printf("//���������������ͳɼ�\n") ;
	 //���������ͳɼ�
	 for(i=student;i<student+new_student;i++)
	 { 	printf("���� ");
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

//�ȴ����� 
void waiting(void)
{
	system("cls");	
	int i,j;
	printf("************************************************************\n\n");
	printf("%10s","����");
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
	printf("�ȴ�����:\n1�������ܷ�\n2�������Ŀ��ƽ���ɼ�\n3������ͬѧ��ƽ���ɼ�\n4����ѧ��\n5����ѧ��\n6������ͬѧ\n\n");
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
