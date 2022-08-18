#include<iostream>
using namespace std;

const int INCRGAP = 3;
void ShellSort(int a[], int len)
{
	
	int insertNum = 0;
	unsigned gap = len / INCRGAP + 1; // 步长初始化,注意如果当len<INCRGAP时，gap为0，所以为了保证进入循环，gap至少为1！！！
	while (gap) // while gap>=1
	{
		for (unsigned i = gap; i < len; i++) // 分组，在每个子序列中进行插入排序
		{
			insertNum = a[i];//将当前的元素值先存起来方便后面插入
			unsigned j = i;
			while (j >= gap && insertNum < a[j - gap])//寻找插入位置
			{
				a[j] = a[j - gap];
				j -= gap;
			}
			a[j] = insertNum;
		}
		gap = gap / INCRGAP;
	}




}
int main05()
{

	int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };// 从小到大插入排序
	int n = sizeof(A) / sizeof(int);
	ShellSort(A, n);
	printf("希尔排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	system("pause");

	return 0;
}