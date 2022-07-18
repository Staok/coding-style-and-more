#include<iostream>
using namespace std;
void InsertionSortDichotomy(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{    
		int get = A[i];
		int left = 0;
		int right = i - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (A[mid] > get)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (int j = i - 1; j >= left; j--)
		{
			A[j + 1] = A[j];
		}
		A[left] = get;
	}
}
int main04()
{

	int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };// 从小到大插入排序
	int n = sizeof(A) / sizeof(int);
	InsertionSortDichotomy(A, n);
	printf("二分插入排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	system("pause");

	return 0;
}