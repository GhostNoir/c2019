#include<stdio.h>
#include<math.h>
#include<time.h>

clock_t start, stop;
double duration;

int main()
{
	start = clock();
	
	int num[999];
	for(int i=0;i<999;++i)//Ϊÿ����ƥ��һ��״̬�����Ĭ�Ͼ�Ϊ������1�� 
	{
		num[i]=1;
	}
	for(int shu=2;shu<=1000;++shu)//��ÿ���������ж� 
	{
		if(1==num[shu-2])// �����δ���жϲ������� (0)
		{
			for(int q=sqrt(shu);q>1;--q)//�����жϴ����Ƿ�Ϊ���� 
			{
				if(0==shu%q)//����������������״̬��0�� 
				{
					num[shu-2]=0;
				}
			}
			if(1==num[shu-2])//�������Ϊ���� 
			{
				for(int i=2;shu*i<=1000;++i)//��Ǵ������ı���Ϊ��������0�� 
				{
					num[shu*i-2]=0;
				}
			}
		}
	}
	for(int i=0;i<999;++i)//��ÿ�����������������1������� 
	{
		if(1==num[i])
		printf("%d\n",i+2);
	}
	
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
	printf("����ʱ��Ϊ%fs\n",duration);
	
	return 0;
}
