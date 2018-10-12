#include <stdio.h>
#include <windows.h>
//递归选择排序 byHuaze 2018-10-12
//递归效率极慢 纯属娱乐
void findMax(int*numlist, int num)
{
	if (1 == num)
		return;
	int i, j,max,max_index,temp;
	max_index=max = 0;

	//找到最大值的索引
	for (i=0;i<num;i++)
	{
			if (numlist[i] > max)
			{
				max = numlist[i];
				max_index = i;
			}
	}
	//和最后一个交换
	temp = numlist[max_index];
	numlist[max_index] = numlist[num - 1];
	numlist[num - 1] = temp;
	findMax(numlist, num - 1);
}
//迭代版
void findMax2(int *numlist, int num)
{
	int i, j, max, max_index, temp;
	max_index = max = 0;
	//找到最大值的索引
	while (1 != num)
	{
		for (i = 0; i < num; i++)
		{
			if (numlist[i] > max)
			{
				max = numlist[i];
				max_index = i;
			}
		}
		temp = numlist[max_index];
		numlist[max_index] = numlist[num - 1];
		numlist[num - 1] = temp;
		num--;
		max_index = max = 0;
	}

}
int main()
{
	int k[] = { 1,3,2,6,4 ,100};
	findMax2(k, 6);
	/*生成一大串随机数据测试*/
	int len = 1000000;
	int *p = new int[len];
	for (int i=0;i<len;i++)
	{
		p[i] = rand();
	}
	findMax2(p, len);

    return 0;
}

