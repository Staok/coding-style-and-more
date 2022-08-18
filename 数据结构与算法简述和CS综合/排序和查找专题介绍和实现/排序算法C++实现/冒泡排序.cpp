/* https://www.cnblogs.com/eniac12/p/5329396.html */

#include<iostream>
using namespace std;

void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
void BubbleSort(int A[], int n)
{
	for (int j = 0; j < n - 1; j++)         // 每次最大元素就像气泡一样"浮"到数组的最后
	{
		for (int i = 0; i < n - 1 - j; i++) // 依次比较相邻的两个元素,使较大的那个向后移
		{
			if (A[i] > A[i + 1])            // 如果条件改成A[i] >= A[i + 1],则变为不稳定的排序算法
			{
				Swap(A, i, i + 1);
			}
		}
	}
}
int main01() {

	int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };    // 从小到大冒泡排序
	int n = sizeof(A) / sizeof(int);
	BubbleSort(A, n);
	printf("冒泡排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}