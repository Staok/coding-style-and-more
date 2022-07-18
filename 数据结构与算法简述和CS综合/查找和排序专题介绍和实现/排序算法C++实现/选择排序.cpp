#include<iostream>
using namespace std;
void SelectionSort(int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] <A[min])
			{
				min = j;

			}
		}
		if (min != i)
		{
			int temp = A[min];
			A[min] = A[i];
			A[i] = temp;
		}
	}
}
int main02()
{     
	
	int A[] = { 8, 5, 2, 6, 9, 3, 1, 4, 0, 7 }; // 从小到大选择排序
	int n = sizeof(A)/ sizeof(int);
	SelectionSort(A, n);
	printf("选择排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	system("pause");

	return 0;
}